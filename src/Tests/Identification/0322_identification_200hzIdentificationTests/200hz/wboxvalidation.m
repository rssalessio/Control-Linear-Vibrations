[Mm, MVar] = wboxGetCartMass();
[Cm] = wboxGetDamping();
[Wm, WmVar, XIm, XIVar] = wboxGetPulsationDamping();
[Rm, RVar] = wboxGetResistance();
[Km, KVar] = wboxGetStiffness();

%%
theta = [0.8141; -0.0995];
Rm =1/(2*0.8141);
G1 = 1/(2*Rm+2*s*L);
%G2 = -7.028e04/(s^2+4.926*s+462.7);%1/(Mm+0.493*2*s^2 + 5.0271*s+Km(1));
L=    0.0111;
s=tf('s');

cd pulse_kbig_2mass/
data =readexp();
figure;
ISim = lsim(G1,data.v,data.t)+1.6*theta(2);figure;
ISim(1:find(ISim>0.5,1))=0;
G2 = tfest(iddata(data.x,ISim, 1/200), 2,0);
subplot 211; plot(data.t,ISim);grid; hold on; plot(data.t, data.i);legend('sim','real');
XSim = lsim(G2, ISim, data.t);
XSim= XSim*max(data.x)/max(XSim);
subplot 212; plot(data.t,XSim);grid; hold on; plot(data.t, data.x);legend('sim','real');
disp(['Current fit: ', num2str(calculateFit(ISim, data.i)*100), '%']);
disp(['Position fit: ', num2str(calculateFit(XSim, data.x,'shape')*100), '%']);
cd ..

cd pulse_kbig_nomass
data =readexp();
figure;
ISim = lsim(G1,data.v,data.t)+1.6*theta(2);figure;
ISim(1:find(ISim>0.5,1))=0;
G2 = tfest(iddata(data.x,ISim, 1/200), 2,0);
subplot 211; plot(data.t,ISim);grid; hold on; plot(data.t, data.i);legend('sim','real');
XSim = lsim(G2, ISim, data.t);
XSim= XSim*max(data.x)/max(XSim);
subplot 212; plot(data.t,XSim);grid; hold on; plot(data.t, data.x);legend('sim','real');
disp(['Current fit: ', num2str(calculateFit(ISim, data.i)*100), '%']);
disp(['Position fit: ', num2str(calculateFit(XSim, data.x,'shape')*100), '%']);

cd ..

%%
figure;
cd pulse_kbig_2mass/
    data =readexp();
    plot(data.t, data.i,'blue'); hold on; grid;hold on;
    max(data.v)
cd ..

cd pulse_kbig_nomass/
    data =readexp();
   plot(data.t, data.i,'red'); hold on; grid;
    max(data.v)
cd ..
legend('2mass','nomass'); hold on; grid;
figure;
cd pulse_klow_2mass/ 
    data =readexp();
    plot(data.t, data.i,'blue'); hold on; grid;hold on;
    max(data.v)
cd ..
cd pulse_klow_nomass/
  data =readexp();
    plot(data.t, data.i,'red'); hold on; grid;hold on;
    max(data.v)
cd ..
figure;
cd pulse_kmed_2mass/
    data =readexp();
    plot(data.t, data.x,'green'); hold on; grid;hold on;
    max(data.v)
cd ..
cd pulse_kmed_nomass/
     data =readexp();
    plot(data.t, data.i,'black'); hold on; grid;hold on;
    max(data.v)
cd ..


%%


cd pulse_kbig_2mass/
    [t,v,i,x]= reads();
    i = lowPassFilter(i, 15, 4, 0, 1/200);
    i1 = find(x>50,1)-1;
    i2 = 0;%find(x(i1:end)<0, 1);
    i(1:i1)=0;
    v(1:i1)=0;
    x(1:i1)=0;
    ISim = lsim(G1,v,t);
   compare(iddata(i, v, 1/200), G1);
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




subplot 211; plot(t,ISim);grid; hold on; plot(t,i);legend('sim','real');

G2 = -5.163e04/(s^2+5.027*s+417.9);%1/(Mm+0.493*2*s^2 + 5.0271*s+Km(1));

%%
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