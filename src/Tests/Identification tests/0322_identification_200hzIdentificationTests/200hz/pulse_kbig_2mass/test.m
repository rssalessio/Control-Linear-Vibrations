R = 1.24;
L = 0.0024;
Gamma=-20.68;
Mc = 0.8840;
M = Mc+0.493*2;
Km=321.7;
Kh=706.2;
Kl=226;


ChL =9.912;
ChNL = 7.7739;
CmL = 9.5963;
CmNL = 7.2040;
ClL = 9.9788;
ClNL = 9.2761;

sys1=sysBuilder(R,L,Gamma,Mc,ClNL,Kl);



[t,v,i,x]=reads();
    x=x./5600;
    y1 = lsim(sys1, v, t);
    c = costFunction(y1,x);
        figure;
    plot(t,x);hold on; plot(t,y1);
    grid; xlabel('Time [s]'); ylabel('Displacement [cm]');
    title('System validation');
    legend('Real displacement', 'Simulated Displacement');