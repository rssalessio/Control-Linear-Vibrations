clear all; 
close all;

cd steps_kmed_2mass

t_start = 9;
t_end = 14;
d = cutexp(readexp(), t_start, t_end); % CUTTING PARAMETERS TO BE SET

cd ..

par0 = [10; 10]; %L, R
options = optimoptions('lsqnonlin', 'Algorithm', 'levenberg-marquardt', ...
                        'MaxFunEvals', 2000, 'Display', 'iter');

par_opt = lsqnonlin( @(par)cost_motor(par,d), par0, [], [], options)'

L = par_opt(1);
R = par_opt(2);

motor = tf(1, [L R]);
i_sim = lsim(motor, d.v, d.t);

figure;
plot(d.t, d.i, 'blue');
hold on;
plot(d.t, i_sim, 'red');
