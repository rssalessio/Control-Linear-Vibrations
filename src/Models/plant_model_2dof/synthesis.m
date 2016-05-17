%% Model Parameter
clear all; 
close all;

%motor
R = 1.3;%resistance 
L = 0.0220; %inductance 
Ke = -1.0000e+05; %electric stiffness and torque constant

s = tf('s');

%carts and load
M1 = 1.35;
M2 = 1.35;

%spring
Ch = 9; %spring damping
Cm = 6; 
Cl = 8;

Kh = 625; %Stiffness high
Km = 281; %Stiffness Med
Kl = 162; %Stifness low

motor = tf(1, [L R]);
cart1 = tf(Ke,[M1,Ch,Kh]);
cart2 = tf(Ke,[M2,Cm,Km]);


%figure; margin(motor); grid;
%%
sim('Model_copied',20);
figure; 
plot(Position1); 
grid;
legend('Position');

%% position loop design
close all; set(cstprefs.tbxprefs,'FrequencyUnits','Hz');

plant = series( motor, series(cart1, feedback(Km*cart2,1)));
figure; margin(plant); grid;
w_motor = damp(motor)/2/pi
w_cart1 = damp(cart1)/2/pi
w_cart2 = damp(cart2)/2/pi

%% position loop design
close all;
controller = (s/0.1+1)^4/s/(s/10);
ol = series(controller, plant);
figure; margin(ol); grid;
cl = feedback(ol,1);
rlocus(ol); grid;

ol_poles = pole(ol)
cl_poles = pole(cl)

% % High
% w_cut = 2*pi*0.1;
% Ws = tf(makeweight(10, w_cut, 0.9));
% Wt = tf(makeweight(0.9, w_cut, 10));
% Wk = tf(makeweight(0.9, w_cut, 10));
% 
% [Hinf, CL, GAM, INFO] = mixsyn(plant, Ws, Wk, Wt);
% 
% figure; margin(series(Hinf,plant)); grid; title('Open Loop');
% figure; pzplot(Hinf); grid;
% figure; bodemag(1/(1+series(Hinf,plant))); title('S'), grid;
% figure; bodemag(Hinf/(1+series(Hinf,plant))); title('K'), grid;


% Hinf_zpk = zpk(Hinf);
% 
% Hinf_zpk.p{1} = Hinf_zpk.p{1}(2:5);
% Hinf_zpk.p{1} = Hinf_zpk.z{1}(1:3);
% 
% Hinf_red = reduce(Hinf, 3);
% figure; pzplot(Hinf_red); grid;
% Hinf = reduce(Hinf, 3);

