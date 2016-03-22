%% Model Parameter

%motor
R = 4;%resistance 
L = 2e-3; %inductance 
Ke = 0.02; %electric stiffness
D = 2*0.0762; %diameter
J = 0.07; %inertia

%carts and load
Ml = 0.5; %load mass
Mc = 0.3; %cart mass w/o load

N1 = 1; %# of loads for 1st cart
M1 = N1*Ml+Mc; %mass 1 cart+load

N2 = 1; %# of loads for 2nd cart
M2 = N2*Ml+Mc; %mass 2 cart + load

N3 = 1; %# of loads for 3rd cart
M3 = N3*Ml+Mc;



%spring
Ch = 0.1; %spring damping
Cm = 0.1; 
Cl = 0.1;
Kh = 800; %Stiffness high
Km = 450; %Stiffness Med
Kl = 150; %Stifness low


gamma = (4*Ke/D)^2;
s=tf('s');
G=170.9/(s^2+7.092*s+580.4);