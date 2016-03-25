clear all; 
close all;

cd pulse_kbig_2mass/
d = cutexp(readexp(), 4, 9); % CUTTING PARAMETERS TO BE SET
cd ..

% scale data from 0 to 1
d.i = (d.i + 2.5)/5;
d.v = (d.v + 3)/6;

var0 = [1; 0.6; 1; 1; 5; 600];
options = optimoptions('lsqnonlin', 'Algorithm', 'levenberg-marquardt', ...
                        'MaxFunEvals', 2000, 'Display', 'iter');

var_opt = lsqnonlin( @(var)cost_motor_bemf(var,d), var0, [], [], options)

L = var_opt(1);
R = var_opt(2);
Ke = var_opt(3);
M = var_opt(4);
C = var_opt(5);
K = var_opt(6);

% CHECK FITTING

D = 0.0762;
    
motor = tf(1, [L R]);
gain = -Ke*2/D;

cart = tf(1, [M, C, K]);
speedometer = tf([1 0], 1);

v_to_x = feedback(motor*gain*cart, speedometer*gain);
v_to_i = feedback(motor, gain*cart*speedometer*gain);

i_sim = lsim(v_to_i, d.v, d.t);
x_sim = lsim(v_to_x, d.v, d.t);

figure;
plot(d.t, d.i, 'blue');
hold on;
plot(d.t, i_sim, 'red');

figure;
plot(d.t, d.x, 'blue');
hold on;
plot(d.t, x_sim, 'red');