R=2*0.63;
L=2*0.0111;


sys = tf(1,[L, R]);
sysd = ss(c2d(sys,1/200));

sysd2= ss(sysd.a,[sysd.b, sysd.b],sysd.c,sysd.d,1/200,'inputname',{'u'},'outputname',{'y'});


Q=0.00001;
R=0.001;

[kalmf,L,P,M]=kalman(sysd2,Q,R);
kalmf=kalmf(1,:)





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

