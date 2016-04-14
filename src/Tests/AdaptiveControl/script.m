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

%% original system+baseline controller and observer
Ap = [-R/L,0,0; 0,0,1; 1/L, -Kh/M, -Ch/M];
Bp=[1;0;0];
Cp=[0,-10^5/M,0];
Dp=0;

Ki=-0.19405;
Lx=place(Ap',Cp',[-600,-500,-400])';
Kx=place(Ap,Bp,[-60, -50,-40]);

newSys = ss(Ap-Bp*Kx, Bp,Cp,Dp);
newSysTF = tf(newSys);
integrator = tf(Ki,[1 0]); %designed using root locus, LQR is also an option
CLSys = feedback(integrator*newSysTF,1);



%% unknown parameters

Theta = [10,10,10,10,10,10]; %constant parameters of the regression vector [x; x^3]
Gamma = 1+1e-01;
 


%%


Kx=place(A,B,[-60, -50,-40]);
Aref = Ap-Bp*Kx;