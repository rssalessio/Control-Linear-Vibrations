R=1.3;
L=0.0024;


sys = sysBuilder(2,'l');
sys=sys.NominalValue;
sys.c=[1/L,0,0;0,1,0];
systemc2d=  (c2d(sys,1/200));
sysd = ss(c2d(sys,1/200));

sysd2= ss(sysd.a,[sysd.b, sysd.b],sysd.c,sysd.d,1/200,'inputname',{'u'},'outputname',{'y'});


Q=0.00001;
R=0.001;

[kalmf,L,P,M,Z]=kalman(sysd2,Q,R);
kalmf=kalmf(1,:)

%[kalman_dis,L,P,M]=kalmd(sys,Q,R,1/200);
%kalman_dis=kalman_dis(1,:);


t = [0:1/200:100]';

n = length(t);

rng default
w = sqrt(Q)*randn(n,1);
v = sqrt(R)*randn(n,1);


u = sin(t/5);
yorig = lsim(sysd,u,t);

figure;
plot(t,yorig,'green');


y= lsim(sysd2,[u w],t)+v;

%hold on; plot(t,y,'blue');


y=lsim(kalmf, [u, y],t);
hold on;
plot(t,y,'red');

figure;
plot(t,abs(yorig-y));

