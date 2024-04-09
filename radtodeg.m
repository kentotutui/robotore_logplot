% 入力ファイル名
inputFileName = 'input.txt';

% 出力ファイル名
outputFileName = 'output.txt';

% テキストファイルからラジアンの値を読み取る
radians = importdata(inputFileName);

% ラジアンからデグリに変換
degrees = rad2deg(radians);

% 出力ファイルにデグリの値を書き込む
fid = fopen(outputFileName, 'w');
fprintf(fid, '%f\n', degrees);
fclose(fid);

disp('変換が完了しました。');
