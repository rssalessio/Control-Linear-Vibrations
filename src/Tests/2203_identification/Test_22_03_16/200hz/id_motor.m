clear all; 
close all;

cd pulse_kbig_2mass/
d = cutexp(readexp(), 4, 9); % CUTTING PARAMETERS TO BE SET
cd ..

% scale data from 0 to 1
is = (d.i + 2.5)/5;
vs = (d.v + 3)/6;
t = d.t;

x0 = [1; 1];
options = optimoptions('lsqnonlin', 'Algorithm', 'levenberg-marquardt', ...
                        'MaxFunEvals', 2000, 'Display', 'iter');

x_opt = lsqnonlin( @(x)cost_motor(x,vs,is,t), x0, [], [], options)

L = x_opt(1);
R = x_opt(2);


motor = tf([1], [L R]);
i_sim = lsim(motor, vs, t);

figure;
plot(t, is, 'blue');
hold on;
plot(t, i_sim, 'red');
