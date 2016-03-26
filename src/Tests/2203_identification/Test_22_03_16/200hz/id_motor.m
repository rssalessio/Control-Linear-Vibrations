clear all; 
close all;

cd steps_kbig_mass_compression/
%cd pulse_kbig_nomass/
d = cutexp(readexp(), 3, 9); % CUTTING PARAMETERS TO BE SET
cd ..

par0 = [1; 1]; %L, R
options = optimoptions('lsqnonlin', 'Algorithm', 'levenberg-marquardt', ...
                        'MaxFunEvals', 2000, 'Display', 'iter');

par_opt = lsqnonlin( @(par)cost_motor(par,d), par0, [], [], options)

L = par_opt(1);
R = par_opt(2);

motor = tf(1, [L R]);
i_sim = lsim(motor, d.v, d.t);

figure;
plot(d.t, d.i, 'blue');
hold on;
plot(d.t, i_sim, 'red');
