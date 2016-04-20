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

figure; margin(motor); grid;

%% position loop design
close all; set(cstprefs.tbxprefs,'FrequencyUnits','Hz');

plant = motor*cart;
figure; margin(plant); grid;
w_motor = damp(motor)/2/pi
w_cart = damp(cart)/2/pi

%% position loop design
close all;

zero1 = -3.5+22i;
zero2 = -3.5-22i;
pole1 = -100;
gain = -0.02; 
controller = zpk([zero1 zero2],...
                 [0 pole1], gain)

plant_ol = controller*plant
plant_cl = feedback(plant_ol,1);

%figure; pzmap(plant_ol); grid;
poles_cl = pole(plant_cl)
%figure; pzmap(plant_cl); grid;

% figure;     margin(plant); grid;
% hold on;    margin(plant_ol);  legend('real','shaped');

% figure; bodeplot(plant_cl); grid;
% hold on; bodeplot(feedback(controller,plant)); 
% legend('T','K');


