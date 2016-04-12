[Mm, MVar, Km,Cm] = wboxGetCartMass();
%[Cm] = wboxGetDamping();
%[Wm, WmVar, XIm, XIVar] = wboxGetPulsationDamping();
[Rm, RVar] = wboxGetResistance();
%[Km, KVar] = wboxGetStiffness();

L=    0.0111;
s=tf('s');
G1 = 1/(2*Rm+2*s*L);
ISim = lsim(G1,v,t);figure;
subplot 211; plot(t,ISim);grid; hold on; plot(t,i);legend('sim','real');

G2 = -5.163e04/(s^2+5.027*s+417.9);%1/(Mm+0.493*2*s^2 + 5.0271*s+Km(1));
XSim = lsim(G2, ISim, data.t)*927/678.6382;
subplot 212; plot(data.t,XSim);grid; hold on; plot(data.t, data.x);legend('sim','real');
disp(['Current fit: ', num2str(calculateFit(ISim, data.i)*100), '%']);
disp(['Position fit: ', num2str(calculateFit(XSim, data.x)*100), '%']);

close all;
figure; 
data=readexp();
temp=data.i;
data.i = lowPassFilter(data.i, 10, 4, 1, 1/200);
ipos = data.i(data.i>0);
ineg = data.i(data.i<0);
iposm = mean(ipos(ipos>mean(ipos)));
inegm = mean(ineg(ineg<mean(ineg)));
 plot(ipos); hold on; plot(iposm*ones(size(ipos)));

hold on; plot(ineg); hold on; plot(inegm*ones(size(ineg)));
figure; plot(data.i);hold on;  plot(iposm*ones(size(data.i)));
hold on; plot(inegm*ones(size(data.i)));

xdata=[-3,1;3,1];
ydata = [inegm;iposm];
theta = (xdata'*xdata)\xdata'*ydata;


R = 1/(2*theta(1));
I = (data.v)./(2*R) +theta(2);
data.i=temp;
figure;
plot(data.t,data.i);hold on; grid; plot(data.t,I); legend('real','sim');


L=    0.0111;
s=tf('s');
G1 = 1/(2*Rm+2*s*L);
ISim = lsim(G1,data.v,data.t)+1.6*theta(2);figure;
ISim(1:find(ISim>0.5,1))=0;
subplot 211; plot(data.t,ISim);grid; hold on; plot(data.t, data.i);legend('sim','real');

G2 = -7.028e04/(s^2+4.926*s+462.7);%1/(Mm+0.493*2*s^2 + 5.0271*s+Km(1));
XSim = lsim(G2, ISim, data.t);
XSim= XSim*max(data.x)/max(XSim);
subplot 212; plot(data.t,XSim);grid; hold on; plot(data.t, data.x);legend('sim','real');
disp(['Current fit: ', num2str(calculateFit(ISim, data.i)*100), '%']);
disp(['Position fit: ', num2str(calculateFit(XSim, data.x,'shape')*100), '%']);

RGBEst =[];
CEst = zeros(2,3);
XIEst =zeros(2,3);
WEst = zeros(2,3);
G2GainEst = zeros(2,3);

cd pulse_kbig_2mass/
    [r,w,g2g,c,xi]= BBEst();
%    RGBEst = [RGBEst;r];CEst(1,1)=c;
 %   XIEst(1,1)=xi; WEst(1,1) = w;
  %  G2GainEst(1,1)=g2g;
cd ..

cd pulse_kbig_nomass/
    [r,w,g2g,c,xi]= BBEst();
   % RGBEst = [RGBEst;r];CEst(2,1)=c;
    %XIEst(2,1)=xi; WEst(2,1) = w;
    %G2GainEst(2,1)=g2g;
cd ..
cd pulse_klow_2mass/ 
    [r,w,g2g,c,xi]= BBEst();
   % RGBEst = [RGBEst;r];CEst(1,3)=c;
    %XIEst(1,3)=xi; WEst(1,3) = w;
    %G2GainEst(1,3)=g2g;
cd ..
cd pulse_klow_nomass/
  [r,w,g2g,c,xi]= BBEst();
    %RGBEst = [RGBEst;r];CEst(2,3)=c;
    %XIEst(2,3)=xi; WEst(2,3) = w;
    %G2GainEst(2,3)=g2g;
cd ..
cd pulse_kmed_2mass/
    [r,w,g2g,c,xi]= BBEst();
    %RGBEst = [RGBEst;r];CEst(1,2)=c;
    %XIEst(1,2)=xi; WEst(1,2) = w;
    %G2GainEst(1,2)=g2g;
cd ..
cd pulse_kmed_nomass/
     [r,w,g2g,c,xi]= BBEst();
    %RGBEst = [RGBEst;r];CEst(2,2)=c;
    %XIEst(2,2)=xi; WEst(2,2) = w;
    %G2GainEst(2,2)=g2g;
cd ..

RGBM = mean(RGBEst);
RGBVar = sum((RGBEst-RGBM).^2)/length(RGBEst);