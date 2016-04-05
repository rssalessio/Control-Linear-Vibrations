function [data] = readexp()

[t,v,i,x]=reads();

i = lowPassFilter(i,30,4,0,1/200);

xv = cartSpeedFromEncoder(x);

data = struct;

data.t = t;
data.v = v;
data.i = i;
data.x = x;
data.xv = xv;

end