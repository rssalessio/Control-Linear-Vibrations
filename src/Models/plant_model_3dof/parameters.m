%% Model Parameter

%motor
R = 4;%resistance 
L = 1e-3; %inductance 
Ke = 0.02; %electric stiffness
D = 2*0.0762; %diameter
J = 0.7; %inertia

%carts
M = 0.8; %mass



%spring
C = 0.01; %spring damping
Kh = 800; %Stiffness high
Km = 450; %Stiffness Med
Kl = 150; %Stifness low


gamma = 4*Ke^2/(Rd^2*M);
