R = 1.3;%resistance 
L = 0.00220; %inductance 
gamma = -2.1;

s = tf('s');

%carts and load
M = 0.7+0.493*2;

%spring
Ch = 9; %spring damping
Cm = 6; 
Cl = 8;

Kh = 700;%Stiffness high

%% original system




%% reference system
wn = 5;
xi = 1;
p=10;
a0=p*wn^2;
a1=2*p*xi*wn+wn^2;
a2=p+2*xi*wn;
Aref = [0,1,0;
        0,0,1;
        -a0,-a1,-a2];
Bref = [0;0;a0];

%%
close all;
theta = [50,60];
GammaX = theta(1)*eye(3);
P=lyap(Aref',theta(2)*eye(3));
B=[0; gamma/(R*M);0];



% %%

sim('modelNew')
figure;
plot(XRef); grid;
figure;
plot(X);grid;

