function [data] = readexp()

% [t,v,i,x]=reads(); %identification
%[t,ref, v, i, x]=reads(); %1dof
%[t,ref, v, i, x1, x2]=reads(); %2dof
[t, v, i_ekf, i, x1_ekf, x1, k_ekf]=reads(); %ekf

% i = lowPassFilter(i,15,4,0,1/200);

xv = cartSpeedFromEncoder(x1);

data = struct;

data.t = t;
% data.ref = ref;
data.v = v;
data.i = i;
data.i_ekf = i_ekf;
data.x1 = x1;
data.x1_ekf = x1_ekf;
data.k_ekf = k_ekf;
% data.x2 = x2;
data.xv = xv;

end