[t,i,v,x]=reads();

L=2*0.0111;
R = 2*0.63;
G = tf([1],[L R]);
G = ss(G);
G.b=[ 8 8];
[kest,l,p]=kalman(G,0.00001,5);


y= lsim(kest,[v i],t);
figure;
plot(t, y(:,1)); hold on; plot(t,i); hold on; plot(t,v);

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