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
% figure;
% cd pulse_klow_2mass/ 
%     data =readexp();
%     plot(data.t, data.i,'blue'); hold on; grid;hold on;
%     max(data.v)
% cd ..
% cd pulse_klow_nomass/
%   data =readexp();
%     plot(data.t, data.i,'red'); hold on; grid;hold on;
%     max(data.v)
% cd ..
% figure;
cd pulse_kmed_2mass/
    data =readexp();
    plot(data.t, data.i,'green'); hold on; grid;hold on;
    max(data.v)
cd ..
cd pulse_kmed_nomass/
     data =readexp();
    plot(data.t, data.i,'black'); hold on; grid;hold on;
    max(data.v)
cd ..
