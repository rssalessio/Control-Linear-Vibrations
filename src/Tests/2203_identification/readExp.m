function [t,v,i,x,xv] = readExp()

[t,v,i,x]=reads();

i = lowPassFilter(i,20,4,0,1/200);

ts = (find(i>0.2,1)-2)*1/200;
v(t<ts)=0;

x = 0.015*x./max(abs(x))

%%you have to set v to 0 by yourself
v(28*200:end)=0;
xv = cartSpeedFromEncoder(x);
end