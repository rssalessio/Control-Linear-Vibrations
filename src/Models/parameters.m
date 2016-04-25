%% Model Parameter

%motor
R = 0.6305;%resistance 
L = 0.0111; %inductance 
Ke =0.040122; %electric stiffness and torque constant
D = 0.0762; %diameter
J = 0.07; %inertia

%carts and load
Ml = 0.493; %load massx\
Mc = 0.7552; %cart mass w/o load

N1 = 2; %# of loads for 1st cart
M1 = N1*Ml+Mc; %mass 1 cart+load

N2 = 1; %# of loads for 2nd cart
M2 = N2*Ml+Mc; %mass 2 cart + load

N3 = 1; %# of loads for 3rd cart
M3 = N3*Ml+Mc;



%spring
Ch = 11.4882; %spring damping w/ 2 mass, otherwise 7.5728
Cm = 7.5847; % otherwise 5.1534
Cl = 6.4027;% otherwise 4.2662
Kh = 706.2008; %Stiffness high
Km = 302.3423; %Stiffness Med
Kl = 207.4248; %Stifness low


gamma = -(4*Ke/D);