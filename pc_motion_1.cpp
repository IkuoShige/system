#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>//正規表現
#include <boost/filesystem.hpp>
#include <boost/tokenizer.hpp>

void load_pc_motion(const char *dirpath)
{
	std::vector<boost::filesystem::path> file_vec;
	boost::filesystem::path dir(dirpath);
	boost::filesystem::directory_iterator end;
	if ( boost::filesystem::exists(dir)) {
		std::copy(boost::filesystem::directory_iterator(dir), boost::filesystem::directory_iterator(), std::back_inserter(file_vec));

		for(int i = 0; i < (int)file_vec.size(); i ++) {
			boost::filesystem::path &p = file_vec[i];
			if (boost::filesystem::is_directory(p)) {
				//ディレクトリは無視
			} else {
				std::regex rx(R"(\d{8})");
				std::regex rx2(R"(\d{4})");
				std::string fleaf = p.filename().string();
				std::string ext = p.extension().string();
				int motion_no = 0;
				sscanf(fleaf.substr(0, 3).c_str(), "%d", &motion_no);
				std::cout << fleaf << ": No." << motion_no << std::endl;
				std::ifstream ifs(p.string().c_str());
				std::smatch m;

				if (ext == ".txt") {
					if (!(std::regex_search(fleaf, m, rx))) {
						std::cout << "motionfile" << std::endl;
					}else if (!(std::regex_search(fleaf, m, rx2))){
						std::cout << "this is backupfile" << std::endl;
					}else {
						std::cout << "this is backupfile" << std::endl;
					}
					
				}else if (ext == ".vm") {
						std::cout << "vmfile" << std::endl;
				}else{
					std::cout << "this is backupfile" << std::endl;
				}
					

				
				// if(ext == ".txt")      std::cout << "txt_file" << std::endl;
				// else if(ext == ".vm")  std::cout << "vm_file" << std::endl;
			}
		}
	} else {
		std::cerr << "dir not found" << std::endl;
	}
}

int main() {
	load_pc_motion("/home/shigeikuo/motions/161/");
	return 0;
}