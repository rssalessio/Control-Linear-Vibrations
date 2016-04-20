[Mm, MVar, Km,Cm,g] = wboxGetCartMass();
[Rm, RVar] = wboxGetResistance();

L=    0.0111;
Rm=  0.656;
s=tf('s');
G1 = 1/(2*Rm+2*s*L);

G2= -g(1,1)/((Mm+0.493*2)*s^2+ Cm(1,1)*s+Km(1));
cd pulse_kbig_2mass/
    [t,v,i,x]=reads();
    x=x./560;
    i = lowPassFilter(i, 15, 4, 0, 1/200);
    dat1 = iddata(i,v,1/200);
    dat2 = iddata(x,v,1/200);
    dat3 = iddata(x,i,1/200);
    compare(dat1,G1);
    compare(dat2,G2*G1);
    compare(dat3,G2);
    
cd ..



