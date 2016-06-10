function [data] = readexp()

% [t,v,i,x]=reads(); %identification
%[t,ref, v, i, x]=reads(); %1dof
[t,ref, v, i, x1, x2]=reads(); %2dof

i = lowPassFilter(i,15,4,0,1/200);

xv = cartSpeedFromEncoder(x1);

data = struct;

data.t = t;
data.ref = ref;
data.v = v;
data.i = i;
data.x1 = x1;
data.x2 = x2;
data.xv = xv;

end