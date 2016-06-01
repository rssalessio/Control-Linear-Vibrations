[t,v,i,x]=reads();

figure;
plot(t,i);


dat = iddata(i,v, 1/200);

sys=tfest(dat,3);

hold on; plot(t, lsim(sys,v,t));
[t,v,i,x]=reads();
v=v(1:2000);
i=i(1:2000);
alpha=1;
step=1e-2;

% for j = 1: 1000
%     index= abs(v) < alpha;
%    k=isWhite(i(index),0.01, 1,'') 
%    if (k ==1)
%        break;
%    else
%        alpha=alpha-step;
%    end
% end
% alpha
% while(isWhite(i(abs(i)<0.05),0.1, 1,'') ==0)
%     
%     
% end
alpha=0.06;

index=abs(i) < 0.06;
tn=t(index);
vn=v(index);
in=i(index);
close all;
figure;
plot(t,i); hold on; plot(isim); grid;

index = abs(v-0.35) < 0.05;
figure; plot(v(index)); hold on; plot(i(index))

close all;
in = lowPassFilter(i,15, 4, 1, 1/200);
figure;
plot(t,i); hold on; plot(t,in);


close all;

xx = t(1):.1:t(end);
yy = spline(t,i,xx);
figure; plot(t,i); hold on; plot(xx,yy); grid;
figure;
close all;
index = abs(i) < 0.04;
tn=t(index);
in = i(index);
vn = v(index);
plot(tn,in); hold on; plot(tn,vn);

in2 = lowPassFilter(in,4,1,1/200);
hold on; plot(tn,in2);


in = lowPassFilter(i,5, 4, 1, 1/200);
plot(t,in);
ind = diff(in)/(1/200);
ind(end+1)=ind(end);
hold on; plot(t, ind);

[AX,H1,H2] = plotyy(t,i,t,x);
xlabel('Time [s]')
title('Current vs Position');
set(get(AX(1),'Ylabel'),'String','Current [A]') 
set(get(AX(2),'Ylabel'),'String','Cart position [cm]') 
