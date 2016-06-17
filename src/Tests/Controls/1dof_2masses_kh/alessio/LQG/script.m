clear
close all;


sys = sysBuilder(2, 'h',{'i','x1','v1'},0);
sys=sys.NominalValue;

tsim=30;
klq = lqr(sys.a,sys.b,1*diag([0,10000,0]), 1);

 A=  sys.a;
 B = sys.b;
 Cy = sys.c;
 D=sys.d;       
gain = Cy*inv( -(A-B*klq))*B;
%gain = dcgain(sys);
%gain=1;


gain=gain(2)


%%
sim('modelLQR',tsim);
figure; 
plot(x.Time, x.Data(:,2)); 
grid;
legend('Position');