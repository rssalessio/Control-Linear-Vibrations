clear all, close all

%% Initialize Simulink Scheme

plant = sysBuilder(2, 'm', {'i', 'x1','v1'}, 1);
plant = plant.NominalValue;

sim('ekf_scheme');

plot([0 30], [340 340]);
hold on;
plot(K_est(:,1), K_est(:,3));

xlabel('time');
ylabel('stiffness');
title('Estimation of K');
grid;
legend('True', 'Estimated');