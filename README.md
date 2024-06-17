# robotore_logplot
このMATLABプログラムは、ロボトレース機体で取得したログデータをグラフや図で出力し、視覚的に分かりやすくする目的で使用しています。

## プログラムの説明
### plot_log_VLT.m
基本的に、プロットには[plot_log_VLT.m](https://github.com/kentotutui/robotore_logplot/blob/master/plot_log_VLT.m)を使用します。

このプログラムは、バーチャルライントレースをしている機体の状態を10mmごとにフラッシュに保存し、結果をグラフで出力しデバック作業に役立てます。

目標経路とのずれ
<img width="960" alt="コースずれ" src="https://github.com/kentotutui/robotore_logplot/assets/74086911/00bdd9ca-2592-4a9f-a779-e6b9a936ab09">
速度・角速度のずれ
<img width="960" alt="速度・角速度ずれ" src="https://github.com/kentotutui/robotore_logplot/assets/74086911/1b1a8cfe-ceb3-4d52-a595-8d8c9a5a3904">
xy座標のError
<img width="960" alt="xyError" src="https://github.com/kentotutui/robotore_logplot/assets/74086911/cba8b4db-4d5e-495e-8982-d9873fd87848">

### log_data.txt
ログのデータを[log_data.txt](https://github.com/kentotutui/robotore_logplot/blob/master/log_data.txt)に保存してください。

例として現在開発中の機体[TLR2](https://www.ntf.or.jp/mouse/micromouse2023/Robot/AllJapan/TechRT63.html)の走行ログを入れてあります。

ログの保存情報は左から、

目標x座標・目標y座標・目標車体角速度(絶対座標系)(rad/s)・現在x座標・現在y座標・現在車体角速度(rad/s)・x座標誤差・y座標誤差・車体角速度誤差(rad/s)・目標速度(m/s)・目標車体角速度(ローカル座標系)(rad/s)・現在速度(m/s)・現在車体角速度(rad/s)

### plot_log.m
コース図を10mmごとの距離・角速度からプロットするプログラムです。主にログが正しく取れているかを確認するときに使います。

### Distance, Theta.txt
[plot_log.m](https://github.com/kentotutui/robotore_logplot/blob/master/plot_log.m)にプロットするときに参照するテキストファイルです。
データの種類は、距離(mm),車体角速度(rad/s)です。
