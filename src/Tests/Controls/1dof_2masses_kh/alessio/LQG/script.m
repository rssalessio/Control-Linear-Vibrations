R = 1.2689;
L = 0.0024;
Gamma=-206.8;
Mc = 0.8840;
Ml = 0.493*2;
Km=321.7;
Kh=706.2;
Kl=226;

ChL =9.912;
ChNL = 7.7739;
CmL = 9.5963;
CmNL = 8.040;
ClL = 9.9788;
ClNL = 9.2761;


K=Km;
C=CmL;
M=Mc+Ml;

tsim=20;

numM = 1;
denM = [L R];

numC = Gamma;
denC = [M C K];

A= [-R/L,0,0;
    0,0,1;
    Gamma/M, -K/M, -C/M];
B = [1/L; 0; 0];
Cy =[ 0,1,0];
D=0;
sys=ss(A,B,Cy,D);
Rn=1e-5;
Qn = 1e-5* eye(3);
%QXU = blkdiag(diag([1,1000,1]),eye(1));
%QWV = blkdiag(Qn,Rn);
% klqg = lqg(sys,QXU,QWV,1);

klq = lqr(sys, eye(3), 1, zeros(3,1));

gain = Cy*inv( -(A-B*klq))*B;

%%
sim('model');
figure;
plot(x); 
grid;
legend('Position');