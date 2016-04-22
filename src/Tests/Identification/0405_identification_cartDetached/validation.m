[t,x]=reads();
[a,b]=findpeaks(x);
t=t(b:end);
t=t-t(1);
x=x(b:end);
plot(t,x);


M=0.5685+0.493*2;
C=1.0542;
K=315.5074;
G=tf(1,[M C K]);
G=ss(G);
close all;
figure;
y=initial(G,[0,max(x)],t); hold on;
plot(t,x*max(y)/max(x)); hold on; plot(t,y);


[a,b]=l2cost(y,x*max(y)/max(x));
figure;
plot(t,b)

compare(y,x*max(y)/max(x))