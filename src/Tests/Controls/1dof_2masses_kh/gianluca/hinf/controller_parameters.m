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

motor = tf(1, [L R]);
cart = tf(Ke,[M,Ch,Kh]);

%figure; margin(motor); grid;

%% position loop design
close all; set(cstprefs.tbxprefs,'FrequencyUnits','Hz');

plant = motor*cart;
%figure; margin(plant); grid;
w_motor = damp(motor)/2/pi
w_cart = damp(cart)/2/pi

%% position loop design
Ws = tf(makeweight(10, 2*pi*1, 0.9));
Wt = tf(makeweight(0.9, 2*pi*1, 10));
Wk = tf(makeweight(0.9, 2*pi*1, 10));

[Hinf, CL, GAM, INFO] = mixsyn(plant, Ws, Wk, Wt);

%figure; margin(Hinf*plant); grid;