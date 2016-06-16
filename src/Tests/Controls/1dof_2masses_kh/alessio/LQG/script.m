clear
close all;


sys = sysBuilder(2, 'h',{'x1'});
sys=sys.NominalValue;






Rn=1e-5;
Qn = 1e-5* eye(3);
tsim=30;
syscd = c2d(sys,1/200);
klq = lqrd(syscd.a,syscd.b,1*diag([1,1,1]), 1,1/200);

 A=  sys.a;
 B = sys.b;
 Cy = sys.c;
 D=sys.d;       
gain = 1;%Cy*inv( -(A-B*klq))*B;
%gain = dcgain(sys);






%%
sim('modelLQR',tsim);
figure; 
plot(x); 
grid;
legend('Position');