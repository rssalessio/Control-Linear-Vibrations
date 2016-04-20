[t,i,v,x]=reads();

L=2*0.0111,
R = 2*0.63;
G = tf([1],[L R]);
G = ss(G);
G = c2d(G,1/200);
kalman(G,0,0.035,0);


close all;
figure;
i = lowPassFilter(i, 5, 4,1,1/200);
t=t(18.05*200:29*200);
i = i(18.05*200:29*200);
v = v(18.05*200:29*200);
x=x(18.05*200:29*200);

t=t-t(1);
%subplot(211);
%plot(t,x/56);
%subplot(212);
%hold on; plot(t,v);

plotyy(t,x/56,t,i);