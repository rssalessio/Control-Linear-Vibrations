clear all; 
close all;

cd steps_kbig_2mass_compression/
%cd pulse_kbig_nomass/
d = cutexp(readexp(), 3, 9); % CUTTING PARAMETERS TO BE SET
cd ..

par0 = [-100000; 1; 10; 900]; %Ke, M, C, K
sim_current = 0;

options = optimoptions('lsqnonlin', 'Algorithm', 'levenberg-marquardt', ...
                        'MaxFunEvals', 2000, 'Display', 'iter');

par_opt = lsqnonlin( @(par)cost_cart(par,d,sim_current), par0, [], [], options)

Ke = par_opt(1);
M = par_opt(2);
C = par_opt(3);
K = par_opt(4);

%% USE MEASURED CURRENT

cart = tf(Ke, [M, C, K]);
x_sim = lsim(cart, d.i, d.t);

figure;
plot(d.t, d.x, 'blue');
hold on;
plot(d.t, x_sim, 'red');
legend('measured', 'simulated');

%% USE SIMULATED CURRENT

i_s = lsim(tf(1,[0.0221, 1.3033]), d.v, d.t);
x_s = lsim(cart, i_s, d.t);

figure;
plot(d.t,d.x);
hold on
plot(d.t,x_s);
legend('measured', 'simulated');
