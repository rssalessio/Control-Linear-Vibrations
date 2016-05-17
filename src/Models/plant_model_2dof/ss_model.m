clear all, close all

M = 1.35-0.493*2;

%motor
R = 1.3;%resistance 
L = 0.0220; %inductance 
Ke = -1.0000e+05; %electric stiffness and torque constant

%spring
Ch = 9; %spring damping
Cm = 6; 
Cl = 8;

Kh = 625; %Stiffness high
Km = 281; %Stiffness Med
Kl = 162; %Stifness low

c1 = Cl;
c2 = Cm;
k1 = Kl;
k2 = Km;

A = [0          1          0           0;
    -(k1+k2)/M  -(c1+c2)/M k2/M        c2/M;
    0           0          0           1;
    k2/M        c2/M       -k2/M       -c2/M];

B = [0; 1; 0; 0];
C = [1 0 0 0;
     0 0 1 0];
D = zeros(2,1);

carts = ss(A,B,C,D);
carts.StateName = {'x1', 'x1d', 'x2', 'x2d'};
motor = ss(tf(1, [L R]));
motor.StateName = {'i'};

plant = series(motor, carts)
plant_tf = tf(plant(2,1))

%% controller design
s = tf('s');
ctrl = 500/s;
%ctrl = 9.2389*(s^2-19.04*s+100.6)/(s*(s+100));

ol = ctrl*plant_tf;
figure; bode(ol); grid;
pole( feedback(ol,1) )