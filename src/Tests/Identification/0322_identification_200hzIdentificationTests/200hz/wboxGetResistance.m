function [Rmean,Rvar] = wboxGetResistance()

    
    RPosM = zeros(6,1);
    RNegM = zeros(6,1);
    cd pulse_kbig_2mass/
        [RPosM(1), RNegM(1)]= getResistance();
    cd ..

    cd pulse_kbig_nomass/
        [RPosM(2), RNegM(2)]= getResistance();
    cd ..
    cd pulse_klow_2mass/ 
        [RPosM(3), RNegM(3)]= getResistance();
    cd ..
    cd pulse_klow_nomass/
        [RPosM(4), RNegM(4)]= getResistance();
    cd ..
    cd pulse_kmed_2mass/
         [RPosM(5), RNegM(5)]= getResistance();
    cd ..
    cd pulse_kmed_nomass/
         [RPosM(6), RNegM(6)]= getResistance();
    cd ..
    
    RM = abs([RPosM, RNegM]);
    Rmean = mean(RM);
    Rvar = var(RM);
    RM
end




function [RPos, RNeg] = getResistance()
    [t,v,i,x]=reads();
% i = lowPassFilter(i, 10/(2*pi), 4,1,1/200);
    vmax=max(v);

    i1 = find(i>0.2,1);
    i2 = find(i(i1:end)<0, 1);
    i3 = find(i(i2:end)>0, 1);

    inew=i(i1+i2:end);

    ipos = inew(inew>0.2);  
    
    [a,b,c]=fourierCoefficients(ipos, length(ipos)/200);
    RPos = vmax/(2*a(1));
    inew = inew(i1+i2+i3:end);
    ineg = inew(inew<-0.2);
    [a,b,c]=fourierCoefficients(ineg, length(ineg)/200);
    RNeg = vmax/(2*a(1));
    
end