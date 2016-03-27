[Mm, MVar] = wboxGetCartMass();
[Cm] = wboxGetDamping();
[Wm, WmVar, XIm, XIVar] = wboxGetPulsationDamping();
[Rm, RVar] = wboxGetResistance();
[Km, KVar] = wboxGetStiffness();

L=    0.0111;
s=tf('s');
G1 = 1/(2*Rm+2*s*L);
ISim = lsim(G1,data.v,data.t);
G2 = -5.163e04/(s^2+5.027*s+417.9);%1/(Mm+0.493*2*s^2 + 5.0271*s+Km(1));
XSim = lsim(G2, ISim, data.t)*927/678.6382;
figure;
subplot 211; plot(data.t,ISim);grid; hold on; plot(data.t, data.i);legend('sim','real');
subplot 212; plot(data.t,XSim);grid; hold on; plot(data.t, data.x);legend('sim','real');
disp(['Current fit: ', num2str(calculateFit(ISim, data.i)*100), '%']);
disp(['Position fit: ', num2str(calculateFit(XSim, data.x)*100), '%']);



RGBEst =[];
CEst = [];
XIEst =[];
WEst = [];
G2GainEst = [];

cd pulse_kbig_2mass/
    [r,w,g2g,c,xi]= BBEst();
    RGBEst = [RGBEst;r];CEst = [CEst;c];
    XIEst=[XIEst; xi]; WEst =[WEst; w];
    G2GainEst = [G2GainEst; g2g];
cd ..

cd pulse_kbig_nomass/
    [r,w,g2g,c,xi]= BBEst();
    RGBEst = [RGBEst;r];CEst = [CEst;c];
    XIEst=[XIEst; xi]; WEst =[WEst; w];
    G2GainEst = [G2GainEst; g2g];
cd ..
cd pulse_klow_2mass/ 
    [r,w,g2g,c,xi]= BBEst();
    RGBEst = [RGBEst;r];CEst = [CEst;c];
    XIEst=[XIEst; xi]; WEst =[WEst; w];
    G2GainEst = [G2GainEst; g2g];
cd ..
cd pulse_klow_nomass/
  [r,w,g2g,c,xi]= BBEst();
    RGBEst = [RGBEst;r];CEst = [CEst;c];
    XIEst=[XIEst; xi]; WEst =[WEst; w];
    G2GainEst = [G2GainEst; g2g];
cd ..
cd pulse_kmed_2mass/
    [r,w,g2g,c,xi]= BBEst();
    RGBEst = [RGBEst;r];CEst = [CEst;c];
    XIEst=[XIEst; xi]; WEst =[WEst; w];
    G2GainEst = [G2GainEst; g2g];
cd ..
cd pulse_kmed_nomass/
     [r,w,g2g,c,xi]= BBEst();
    RGBEst = [RGBEst;r];CEst = [CEst;c];
    XIEst=[XIEst; xi]; WEst =[WEst; w];
    G2GainEst = [G2GainEst; g2g];
cd ..

RGBM = mean(RGBEst);
RGBVar = sum((RGBEst-RGBM).^2)/length(RGBEst);