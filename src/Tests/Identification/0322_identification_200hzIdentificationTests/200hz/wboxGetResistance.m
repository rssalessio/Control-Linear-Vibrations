function [Rmean,Rvar] = wboxGetResistance()

    
    RPosM = zeros(6,1);
    RNegM = zeros(6,1);
    Rg = zeros(6,1);
    Lg = zeros(6,1);
    cd pulse_kbig_2mass/
        [RPosM(1), RNegM(1), Rg(1), Lg(1)]= getResistance();
    cd ..

    cd pulse_kbig_nomass/
        [RPosM(2), RNegM(2), Rg(2), Lg(2)]= getResistance();
    cd ..
    cd pulse_klow_2mass/ 
        [RPosM(3), RNegM(3), Rg(3), Lg(3)]= getResistance();
    cd ..
    cd pulse_klow_nomass/
        [RPosM(4), RNegM(4), Rg(4), Lg(4)]= getResistance();
    cd ..
    cd pulse_kmed_2mass/
         [RPosM(5), RNegM(5), Rg(5), Lg(5)]= getResistance();
    cd ..
    cd pulse_kmed_nomass/
         [RPosM(6), RNegM(6), Rg(6), Lg(6)]= getResistance();
    cd ..
    
    RM = 2*abs([RPosM, RNegM]);
    Rmean = mean(RM);
    Rvar = (var(RM));
    
    m1 = Rmean(1);
    m2 = Rmean(2);
    v1 = Rvar(1);
    v2 = Rvar(2);
    
    Rmean=(m1*v2+m2*v1)/(v1+v2);
    Rvar = (v1+v2)/2;
    Lg
   % mean(Rg), mean(Lg)
   % std(Rg), std(Lg)
end




function [RPos, RNeg,Rg,Lg] = getResistance()
    [t,v,i,x]=reads();
% i = lowPassFilter(i, 10/(2*pi), 4,1,1/200);
    vmax=max(v);

    i1 = find(i>0.2,1);
    i2 = find(i(i1:end)<0, 1);
    i3 = find(i(i2:end)>0, 1);

    inew=i(i1+i2:end-5*200);
    vnew = v(i1+i2:end-5*200);
    
    
    G = tfest(iddata(inew,vnew,1/200), 1, 0);
    Rg = 1/dcgain(G);
    Lg = -Rg/pole(G);
    

    ipos = inew(inew>0.2); 
    
    [a,b,c]=fourierCoefficients(ipos, length(ipos)/200);
    RPos = vmax/(2*a(1));
    inew = inew(i1+i2+i3:end);
    ineg = inew(inew<-0.2);
    [a,b,c]=fourierCoefficients(ineg, length(ineg)/200);
    RNeg = vmax/(2*a(1));
    
end