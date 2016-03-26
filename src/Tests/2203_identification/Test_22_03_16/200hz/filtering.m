clear all, close all;

cd steps_kbig_nomass_compression

[t,v,i,x]=reads();

fourierPlot(i,t(end)-t(1));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
n = 12; %filter order
wn=0.1;
[b,a] = butter(n, wn);
i_filtered = filter(b, a, i);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

d = struct;
d.t = t;
d.i = i_filtered;
d.v = v;
d.x = x;
d.xv = x;

fourierPlot(d.i,d.t(end)-d.t(1));

figure; 
plot(t,i); hold on;
plot(t,i_filtered,'LineWidth',2);


dc = cutexp(d, 5.6, 7);
T = 7-5.6;
dc.i = detrend(dc.i);

figure; plot(dc.t, dc.i);

fourierPlot(dc.i,T);

[mod, ph, f] = fourierCoefficients(dc.i, T);
mod(6) = 0;
ph(6) = 0;

figure;
plot(dc.t, fourierSignalFromCoefficients(mod,ph,f,dc.t'));

