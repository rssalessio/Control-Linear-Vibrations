%% Model Parameter
clear all; 
close all;

%motor
R = 1.3;%resistance 
L = 0.0220; %inductance 
Ke = -1.0000e+05; %electric stiffness and torque constant

s = tf('s');

%carts and load
M = 1.35;

%spring
Ch = 9; %spring damping
Cm = 6; 
Cl = 8;

Kh = 625; %Stiffness high
Km = 281; %Stiffness Med
Kl = 162; %Stifness low

%% current loop design

close all;

motor = tf(1, [L R]);
cart = tf(Ke,[M,Ch,Kh]);

controller_c = 1;
filter = tf(1,[1/20 1]);

motor_ol = controller_c*motor*filter;
motor_cl = feedback(motor_ol, 1);

figure; margin(motor_ol); grid;

%% position loop design
close all;

plant = motor_cl*cart;

zero1 = -5+22i;
zero2 = -5-22i;
pole1 = -100;
gain = -0.01;
controller_p = zpk([zero1,zero2], [0, pole1], gain)

plant_ol = controller_p*plant;
plant_cl = feedback(plant_ol,1);

figure; rlocus(plant_ol);
figure;     margin(plant); grid;
hold on;    margin(plant_ol);  legend('real','shaped');
poles_cl = pole(plant_cl)
figure; rlocus(plant_cl);
