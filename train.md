# 物体検出の学習の回し方

1．Dataset/の中にdriveに挙げられた画像ファイルとラベル付けされた.txtをダウンロードする

2．mv コマンドを用いて、画像ディレクトリにr食べる付けされた.txtを移動する

220625_img_1_labels.zipと220625_img_1.zipはラベル付けされたものと画像のものをダウンロードした例

drive-download-20220706T104724Z-001.zipはdriveからダウンロードしたzipファイルの例

```
cd ~/Dataset/YOLO/
mkdir 日付
cd Download
mv drive-download-20220706T104724Z-001.zip ~/Dataset/YOLO/日付/
cd ~/Dataset/YOLO/日付/
unzip 220625_img_1.zip
unzip 220625_img_1_labels.zip
mv 220625_img_1_labels/* 220625_img_1/
```

3．reaklink -f */*txt >> train.txt でファイルのパスが書かれたtrain.txtができる(>>で追加、>で上書き保存)

">>" でテキストファイルに追記　">" で上書き保存

```
readlink -f 220625_img_1(ディレクトリ)/*txt >> train.txt
```

4．パスをテキストファイルに出力し、中身のtxtをjpgに変換する

```
vim train.txt
```
```
:%s/txt/jpg/g
```

5．vi roboinfo/v4tiny_3class.dataの中のtrain.txtのパスを更新し、バックアップ先も更新する(バックアップをする場合は、一応"mkdir 日付"して、そこを指定する)

```
cd
cd darknet/
vim roboinfo/v4tiny_3class.data
```
```
./run_train.bash
```

6．./run_train.bash を実行
