clear all; 
close all;

cd steps_kmed_2mass

t_start = 9;
t_end = 14;
d = cutexp(readexp(), t_start, t_end); % CUTTING PARAMETERS TO BE SET

cd ..

par0 = [-100000; 1; 8; 250]; %Ke, M, C, K
sim_current = 0;

options = optimoptions('lsqnonlin', 'Algorithm', 'levenberg-marquardt', ...
                        'MaxFunEvals', 2000, 'Display', 'iter');

[par_opt, ~, ~, flag] = ...
    lsqnonlin( @(par)cost_cart(par,d,sim_current), par0, [], [], options);

par_opt = par_opt'
disp(['EXIT FLAG: ' num2str(flag)]);

Ke = par_opt(1);
M = par_opt(2);
C = par_opt(3);
K = par_opt(4);

disp('ROOTS:');
disp(roots([M C K]));

%% USE MEASURED CURRENT

cart = tf(Ke, [M, C, K]);
x_sim = lsim(cart, d.i, d.t);

figure; 
plot(d.t, d.x, 'blue'); title('Measured Current as input');
hold on;
plot(d.t, x_sim, 'red');
legend('measured', 'simulated');

%% USE SIMULATED CURRENT
L = [0.022];
R = [1.22];

i_s = lsim(tf(1,[L, R]), d.v, d.t);
x_s = lsim(cart, i_s, d.t);

figure;
plot(d.t,d.x);  title('Simulated Current as input');
hold on
plot(d.t,x_s);
legend('measured', 'simulated');
