data = load("Distance, Theta.txt");
distance = data(:, 1);
theta = data(:, 2);
%theta_10mm = data(:, 3);
%smooththeta_10mm = smoothdata(theta_10mm);

% データが有るところだけ抽出
distance = nonzeros(distance);
theta = theta(1:size(distance));

theta_adj = theta .* 1;

x = 0;
y = 0;
th = 0;
atanth = 0;
deltaX = 0;
deltaY = 0;
prev_x = 0;
prev_y = 0;

X = [];
Y = [];
DeltaX = [];
DeltaY = [];
TH = [];
for i = 1:size(distance)

    prev_x = x;
    prev_y = y;

    x = x + distance(i) * cos(th + theta_adj(i)/2);
    y = y + distance(i) * sin(th + theta_adj(i)/2);
    th = th + theta_adj(i);
    deltaX = x - prev_x;
    deltaY = y - prev_y;
    atanth = atan2(deltaY, deltaX);
    % 角度の不連続性を補正
    if i > 1
        prev_atanth = TH(end);
        if abs(atanth - prev_atanth) > pi
            if atanth > prev_atanth
                atanth = atanth - 2 * pi;
            else
                atanth = atanth + 2 * pi;
            end
        end
    end

    X = [X x];
    Y = [Y y];
    DeltaX = [DeltaX deltaX];
    DeltaY = [DeltaY deltaY];
    TH = [TH atanth];
end

figure(1);
scatter(X, Y)
xline(0,"-r")
xline(-1000,"-r")
yline(0,"-r")
grid on
grid minor
axis equal

output_file = 'atanth.txt';
fid = fopen(output_file, 'w');
fprintf(fid, 'DeltaX DeltaY Theta\n');
fprintf(fid, '%f %f %f\n', [DeltaX; DeltaY; TH]);
fclose(fid);
disp('ファイルに保存されました。');

%figure(2);
%plot(theta_10mm)
%grid on