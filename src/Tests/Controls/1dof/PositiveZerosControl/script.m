close all;
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



motor = tf([1],[L R]);
cart = tf([Ke],[M, Ch, Kh]);


controller = zpk([9.52+3.16i,9.52-3.16i],[0,-100],-0.016498*560);


OL = series(controller,motor);
OL = series(OL, cart);
figure;
bode(OL); grid;

plant = feedback(OL,1);
figure;
bode(plant); grid;
figure; step(plant);