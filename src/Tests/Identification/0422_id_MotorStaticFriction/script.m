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



motor = tf([1],[L R]);
currentFilter = tf([1],[1/20,1]);

motor = feedback(motor, currentFilter);
cart = tf([Ke],[M, Ch, Kh]);

plant = series(motor,cart);
plant = series(plant, zpk([0],[-100,-150],[1]));

controller = zpk([],[0,0],[-276.55]);
controller2 = zpk([-14.806+i*28.504,-14.806-i*28.504],[0,0],[28.504]);
plant = series(controller, plant);
margin(plant);

plant = feedback(plant,1);
%bode(plant);
