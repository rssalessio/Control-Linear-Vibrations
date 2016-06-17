cd Data/

% exp = 'kl pulse';
% exp = 'kl sin 0.5 Hz';
exp = 'km pulse';
% exp = 'km sin 0.5 Hz';
path = ['17_06 ' exp];

cd(path)
d = readexp();

i = [d.t, d.i];
x1 = [d.t d.x1];
v = [d.t, d.v];
k = [d.t, d.k_ekf];
x1_est_ard = [d.t, d.x1_ekf];
i_est_ard = [d.t, d.i_ekf];

cd .. 
cd ..

sim('ekf_scheme_realdata');

plot([0 30], [340 340]);
hold on;
plot(K_est(:,1), K_est(:,2));
plot(K_est(:,1), K_est(:,3));

xlabel('time');
ylabel('stiffness');
title('Estimation of K');
grid;
legend('True', 'Estimated on Simulink', 'Estimated Online');