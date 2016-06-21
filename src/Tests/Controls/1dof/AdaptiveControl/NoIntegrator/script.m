R = 1.26;%resistance 
L = 0.00220; %inductance 
gamma = -2.01;

s = tf('s');

%carts and load
M = 0.7+0.493*2;

%spring
Ch = 9; %spring damping
Cm = 6; 
Cl = 8;

Kh = 700;%Stiffness high
Km=321; 
Kl=226;     
%G=sysBuilder(R,L, gamma, M, Cl, Kl);
%% original system




%% reference system
wn = 2*pi*5;
xi = 1;
a0=wn^2;
a1=2*xi*wn;
Aref = [0,1;
        -a0,-a1];
Bref = [0;a0];

%%
close all;
theta = [50,600,900];
GammaX = theta(1)*eye(2);
GammaR = theta(3);
P=lyap(Aref',theta(2)*eye(2));
B=[0; gamma/(R*M)];

tsim=90;

% %%

sim('modelNew')
figure;
plot(XRef.Data(:,1)); grid;
figure;
plot(X.Data(:,1));grid;
