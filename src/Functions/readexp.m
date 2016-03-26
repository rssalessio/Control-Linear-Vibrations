function [data] = readexp()

[t,v,i,x]=reads();

i = lowPassFilter(i,30,4,0,1/200);

ts = (find(i>0.2,1)-2)*1/200;
v(t<ts)=0;

%%you have to set v to 0 by yourself
v(28*200:end)=0;
xv = cartSpeedFromEncoder(x);

data = struct;

data.t = t;
data.v = v;
data.i = i;
data.x = x;
data.xv = xv;

end