[Mm, MVar, Km,Cm,g] = wboxGetCartMass();
[Rm, RVar] = wboxGetResistance();

R = 2*mean(Rm);%resistance 
L = 0.0024;%0.0111/2; %inductance 
s=tf('s');
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
    
    y1 = lsim(sys1, v, t);
    y2 = lsim(sys2, v, t);
    figure;
    plot(t,x); hold on; plot(t,y1); hold on; plot(t,y2); grid;
    legend('x','x1','xbemf');
    
    a=l2cost(y1,y2)
    
cd ..



