data = load("Distance, Theta.txt");
data2 = load("log_data.txt");
distance = data(:, 1);
theta = data(:, 2);
x_table = data2(:, 1);
y_table = data2(:, 2);
%euclidean_dist = data2(:, 3);
%theta_smooth = data2(:, 4);
%theta_10mm = data(:, 3);
%smooththeta_10mm = smoothdata(theta_10mm);

% データが有るところだけ抽出
distance = nonzeros(distance);
theta = theta(1:size(distance));

theta_adj = theta .* 1;

x = 0;
y = 0;
th = 0;

X = [];
Y = [];
for i = 1:size(distance)
    x = x + distance(i) * cos(th + theta_adj(i)/2);
    y = y + distance(i) * sin(th + theta_adj(i)/2);
    th = th + theta_adj(i);
    X = [X x];
    Y = [Y y];
end

SC_X = [];
SC_Y = [];

for i = 1:size(x_table)
    x = x_table(i);%x座標
    y = y_table(i);%y座標
    th = th + theta_adj(i);
    SC_X = [SC_X x];
    SC_Y = [SC_Y y];
end

figure(1);
scatter(X, Y, 'red')
hold on
scatter(SC_X, SC_Y, 'blue')
xline(0,"-r")
xline(-1000,"-r")
yline(0,"-r")
grid on
grid minor
axis equal

%figure(2);
%plot(theta_10mm)
%grid on