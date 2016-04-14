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

%% OBSERVER AND STATE FEEDBACK + ext integrator
A = [-R/L,0,0; 0,0,1; 1/L, -Kh/M, -Ch/M];
B=[1;0;0];
C=[0,-10^5/M,0];
D=0;

O = obsv(A,C)
rank(O)

Lx=place(A',C',[-600,-500,-400])';
Kx=place(A,B,[-60, -50,-40]);

newSys = ss(A-B*Kx, B,C,D);
newSysTF = tf(newSys);
Ki=-0.19405;
integrator = tf(Ki,[1 0]); %designed using root locus, LQR is also an option
CLSys = feedback(integrator*newSysTF,1);

