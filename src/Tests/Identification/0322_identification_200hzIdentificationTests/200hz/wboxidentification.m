[Mm, MVar, Km,Cm,g] = wboxGetCartMass();
[Rm, RVar] = wboxGetResistance();

R = 2*mean(Rm);%resistance 
L = 0.0024;%0.0111/2; %inductance 
s=tf('s');

%%
Rg = 1.3;%resistance 
Lg = 0.0220; %inductance 
Keg = -1.0000e+05; %electric stiffness and torque constant

s = tf('s');

%carts and load
Mg = 1.35;

%spring
Chg = 9; %spring damping
Cmg = 6; 
Clg = 8;

Khg = 625; %Stiffness high
Kmg = 281; %Stiffness Med
Klg = 162; %Stifness low
%%



%%
cd pulse_kbig_2mass/
    [t,v,i,x]=reads();
    x=x./56000;
    i1 = find(i>0.2,1);
    v(1:i1)=0;
    d=iddata(i,v,1/200);
    compare(d,tfest(d,1,0))
    pole(tfest(d,1,0))%0.9*Mmsotto
    [sys1,sys2]=sysBuilder(R,L,gamma, 0.91*Mm+0.493*2, Cm(1,1), Km(1));
    [sysG1,sysG2] =sysBuilder(Rg,Lg, Keg/56000, Mg,Chg,Khg);
    y1 = lsim(sys1, v, t);
    y2 = lsim(sys2, v, t);
    y1g = lsim(sysG1,v,t);
    y2g = lsim(sysG2,v,t);
    figure;
    plot(t,x); hold on; plot(t,y1); hold on; plot(t,y1g); grid;
    legend('x','x1','xbemf');
    
    l2cost(x,y1)
    l2cost(x,y2)
    l2cost(x,y1g)
    l2cost(x,y2g)
    
cd ..



