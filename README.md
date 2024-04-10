# robotore_logplot
このMATLABプログラムは、ロボトレース機体で取得したログデータをグラフや図で出力し、視覚的に分かりやすくする目的で使用しています。

## プログラムの説明
基本的に、プロットには[plot_log_VLT.m](https://github.com/kentotutui/robotore_logplot/blob/master/plot_log_VLT.m)を使用します。
このプログラムは、バーチャルライントレースをしている機体の状態を10mmごとにフラッシュに保存し、結果をグラフで出力しデバック作業に役立てます。
ログのデータを[VLT_log.txt](https://github.com/kentotutui/robotore_logplot/blob/master/VLT_log.txt)に保存してください。
例として現在開発中の機体[TLR2](https://www.ntf.or.jp/mouse/micromouse2023/Robot/AllJapan/TechRT63.html)の走行ログを入れてあります。