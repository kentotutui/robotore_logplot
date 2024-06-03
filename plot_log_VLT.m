data = load("log_data.txt");
target_x_point = data(:, 1);%目標x座標
target_y_point = data(:, 2);%目標y座標
theta_10mm = data(:, 3);%目標車体角速度
now_x_point = data(:, 4);%現在x座標
now_y_point = data(:, 5);%現在y座標
now_theta = data(:,6);%現在車体角速度
error_x = data(:, 7);%x座標の誤差
error_y = data(:, 8);%y座標の誤差
error_theta = data(:, 9);%車体角速度の誤差
target_velocity = data(:, 10);%目標並進速度
target_angularvelocity = data(:, 11);%目標車体角速度
now_velociy = data(:, 12);%現在速度
now_angularvelocity = data(:, 13);%現在角速度

% データが有るところだけ抽出
target_x_point = nonzeros(target_x_point);
target_y_point = target_y_point(1:size(target_x_point));
now_x_point = nonzeros(now_x_point);
now_y_point = now_y_point(1:size(now_x_point));

theta_adj = target_y_point .* 1;

x_r = 0;
y_r = 0;
x_c = 0;
y_c = 0;
th = 0;

X_R = [];
Y_R = [];
X_C = [];
Y_C = [];
for i = 1:size(target_x_point)
    x_r = target_x_point(i);
    y_r = target_y_point(i);
    x_c = now_x_point(i);
    y_c = now_y_point(i);
    X_R = [X_R x_r];
    Y_R = [Y_R y_r];
    X_C = [X_C x_c];
    Y_C = [Y_C y_c];
end

figure(1);%コースxy座標をプロット
scatter(X_R, Y_R, 'red')
hold on
scatter(X_C, Y_C, 'blue')
xline(0,"-r")
xline(-1000,"-r")
yline(0,"-r")
grid on
grid minor
axis equal
legend('Target Point (red)', 'Now Point (blue)')

figure(2);%速度・角速度の差をプロット
subplot(2, 1, 1)
plot(target_velocity, 'color', 'red')
hold on
plot(now_velociy, 'color', 'blue')
grid on
title('Velocity(m/s)')
legend('Target Velocity (red)', 'Now Velocity (blue)')

subplot(2, 1, 2)
plot(target_angularvelocity, 'color', 'red')
hold on
plot(now_angularvelocity, 'color', 'blue')
yline(0,"-g")
grid on
title('AngularVelocity(rad/s)')
legend('Target Angularvelocity (red)', 'Now Angularvelocity (blue)')

figure(3);%Error分を出力
subplot(2, 1, 1)
plot(error_x)
yline(0,"-r")
yline(10,"-g")
%ylim([-10 50])
grid on
title('Error X')

subplot(2, 1, 2)
plot(error_y)
yline(0,"-r")
grid on
title('Error Y')
