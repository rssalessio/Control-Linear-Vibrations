close all;

Ts=1/200;
[t,in,i,x] = reads();
x=x./56000;
index = find(i<-0.2,1)-1;
i = i(index:end);
x = x(index:end);
t=t(index:end);
t=t-t(1);
t=t(x>0); t=t-t(1);
x=x(x>0);
[a,b]=findpeaks(x)
figure;
plot(x);

xn=x(2019:2019+200);
tn=t(2019:2019+200);tn=tn-tn(1); mean(xn)


xn=xn-mean(xn);


EQ = @(a,b,w, c,x) ...
    a.*exp(-b*w*x).*sin(sqrt(1-b^2)*w*x+c);

AlgometryEffect = fit( tn,xn, EQ, ...
    'StartPoint', [xn(1), 0.4, 7,pi/2], ...
    'Lower', [0, 0,5,0], ...
    'Upper', [2, 1, 35,2], ...
    'Robust', 'LAR' )
figure;
plot( AlgometryEffect,tn,xn)


15
516
1017
1518

2019
