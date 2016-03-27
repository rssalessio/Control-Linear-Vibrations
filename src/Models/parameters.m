%% Model Parameter

%motor
R = 0.63;%resistance 
L = 1.05e-3; %inductance 
Ke = 0.059/2; %electric stiffness and torque constant
D = 0.0762; %diameter
J = 0.07; %inertia

%carts and load
Ml = 0.493; %load mass
Mc = 0.7552; %cart mass w/o load

N1 = 2; %# of loads for 1st cart
M1 = N1*Ml+Mc; %mass 1 cart+load

N2 = 1; %# of loads for 2nd cart
M2 = N2*Ml+Mc; %mass 2 cart + load

N3 = 1; %# of loads for 3rd cart
M3 = N3*Ml+Mc;



%spring
Ch = 5.0271; %spring damping
Cm = 2.9304; 
Cl = 2.9153;
Kh = 698.8326; %Stiffness high
Km = 299.2155; %Stiffness Med
Kl = 211.8954; %Stifness low


gamma = (4*Ke/D);