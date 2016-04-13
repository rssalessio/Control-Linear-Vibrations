close all;
motor = tf(1, [2*L 2*R]);
cart = tf(1,[M1,Ch,Kh]);
s=tf('s');
G = motor*cart*gamma;

G = feedback(G, s*gamma);



figure; margin(G); grid;


controller = -1323.4*(1+0.0096*s)*(1+0.34*s)/(s*(1+0.28*s));
controller2= -1808.2*(1+0.035*s)/s;

T = controller*G;
figure; margin(T); grid;


% 
% v= zeros(200*10,1);
% v(2*200:end)=3;
% t=0:1/200:10-1/200;
% t=t';
% 
% 
% 
% 
% y = lsim(G, v,t);
% plot(t,y);


%%%%%

Ass=[-R/L, 0, -gamma/M1; 0,0,1; gamma/(2*L), -Kh/M1,-Ch/M1];
Bss=[1;0;0];
Css=[0,1/M1,0];
Dss=[0];
O = obsv(Ass,Css)
rank(O)

Lx=place(Ass',Css',[-200,-150,-100])';
Kx=place(Ass,Bss,[-100, -70,-50]);


