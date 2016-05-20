clear
close all;

R = 1.2689;
L = 0.0024;
Gamma=-206.8;
Mc = 0.8840;
Ml = 0.493;
Km=321.7;
Kh=706.2;
Kl=226;

ChL =9.912;
ChNL = 7.7739;
CmL = 9.5963;
CmNL = 8.040;
ClL = 9.9788;
ClNL = 9.2761;


K=Kl;
C=ClL;
M=Mc+Ml*2;

tsim=30;

numM = 1;
denM = [L R];

numC = Gamma;
denC = [M C K];

A= [-R/L,0,0;
    0,0,1;
    Gamma/M, -K/M, -C/M];
B = [1/L; 0; 0];
Cy =[ 0,1,0];
D=[0];        
sys=ss(A,B,Cy,D);

syscd = c2d(sys,1/200);

Rn=1e-5;
Qn = 1e-5* eye(3);
klq = lqr(sys,0.1*diag([1,1,1]), 1.5, zeros(3,1));

gain = Cy*inv( -(A-B*klq))*B;

Aref= A-B*klq;
Bref= [1/(L*gain);0;0];

refSys = ss(Aref,Bref, Cy, D);
P = lyap(Aref', eye(3));
tsim=30;
sim('LQRAdaptive',tsim);
figure; 
plot(x); 
grid;
legend('Position');



