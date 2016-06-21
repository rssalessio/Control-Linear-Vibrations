


[t,v,i,x]=reads();

vmax=max(v);
ifilt =lowPassFilter(i, 5, 4, 1, 1/200);
%%
i1 = find(i>0.2,1);
i2 = find(i(i1:end)<0, 1);
i3 = find(i(i2:end)>0, 1);

inew=i(i1+i2:end);
%%
ipos = inew(inew>0.2);
ifilt =lowPassFilter(ipos, 5, 4, 1, 1/200);
imean = mean(ifilt);
R = vmax/(2*imean);

inew = inew(i1+i2+i3:end);
ineg = inew(inew<-0.2);
ifilt =lowPassFilter(ineg, 5, 4, 1, 1/200);
imean = mean(ifilt);
R2 = vmax/(2*imean);
