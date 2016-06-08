clear
close all;


sys = sysBuilder([2,2], ['m','l'],{'i','x1'});
sys=sys.NominalValue;

syscd = c2d(sys,1/200);

Rn=1e-5;
Qn = 1e-5* eye(5);
tsim=30;
klq = lqrd(syscd.a,syscd.b,Qn,Rn, zeros(5,1),1/200);
% A=  sys.a;
% B = sys.b;
% Cy = sys.c;
% D=[0;0];        
%gain = Cy*inv( -(A-B*klq))*B;
gain = dcgain(syscd);


%%
% sim('modelLQR',tsim);
% figure; 
% plot(x); 
% grid;
% legend('Position');