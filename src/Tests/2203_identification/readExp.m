function [t,v,i,x] = readExp()

[t,v,i,x]=reads();

i = lowPassFilter(i,30);

ts = (find(i>0.2,1)-2)*1/200;
v(t<ts)=0;
plot(t,v); hold on; plot(t,i); grid;

x = x./max(abs(x));

%%you have to set v to 0 by yourself
end