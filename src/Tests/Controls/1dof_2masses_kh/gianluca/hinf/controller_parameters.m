%% Model Parameter
clear all; 
close all;

%motor
R = 1.3;%resistance 
L = 0.0220; %inductance 
Ke = -1.0000e+05/560; %electric stiffness and torque constant

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
% High
Ws = tf(makeweight(10, 2*pi*1, 0.9));
Wt = tf(makeweight(0.9, 2*pi*1, 10));
Wk = 100*tf(makeweight(0.9, 2*pi*1, 10));
% Med
% Ws = tf(makeweight(10, 2*pi*1, 0.9));
% Wt = tf(makeweight(0.9, 2*pi*1, 10));
% Wk = 0.01*tf(makeweight(0.9, 2*pi*1, 10));
% 

[Hinf, CL, GAM, INFO] = mixsyn(plant, Ws, Wk, Wt);

figure; margin(series(Hinf,plant)); grid;
figure; pzplot(Hinf); grid;
figure; bodemag(1/(1+series(Hinf,plant))); title('S'), grid;
figure; bodemag(Hinf/(1+series(Hinf,plant))); title('K'), grid;


% Hinf_zpk = zpk(Hinf);
% 
% Hinf_zpk.p{1} = Hinf_zpk.p{1}(2:5);
% Hinf_zpk.p{1} = Hinf_zpk.z{1}(1:3);
% 
% Hinf_red = reduce(Hinf, 3);
% figure; pzplot(Hinf_red); grid;
 Hinf = reduce(Hinf, 3);

