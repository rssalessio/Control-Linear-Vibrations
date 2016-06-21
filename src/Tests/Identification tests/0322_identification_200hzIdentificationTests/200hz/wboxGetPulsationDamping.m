function [Wm, WVar, XIm, XIVar,g] = wboxGetPulsationDamping()
    Wm = zeros(2,3);
    WVar = zeros(2,3);
    XIm = zeros(2,3);
    XIVar = zeros(2,3);
    g = zeros(6,2);
    cd pulse_kbig_2mass/
        [Wm(1,1), WVar(1,1), XIm(1,1), XIVar(1,1), g(1,1), g(1,2)]= getPDR(706.1992);
    cd ..

    cd pulse_kbig_nomass/
        [Wm(2,1), WVar(2,1), XIm(2,1), XIVar(2,1), g(2,1), g(2,2)]= getPDR(706.1992);
    cd ..
    cd pulse_klow_2mass/ 
        [Wm(1,3), WVar(1,3), XIm(1,3), XIVar(1,3), g(3,1), g(3,2)]= getPDR(226.0565);
    cd ..
    cd pulse_klow_nomass/
        [Wm(2,3), WVar(2,3), XIm(2,3), XIVar(2,3), g(4,1), g(4,2)]= getPDR(226.0565);
    cd ..
    cd pulse_kmed_2mass/
         [Wm(1,2), WVar(1,2), XIm(1,2), XIVar(1,2), g(5,1), g(5,2)]= getPDR(321.7001);
    cd ..
    cd pulse_kmed_nomass/
         [Wm(2,2), WVar(2,2), XIm(2,2), XIVar(2,2), g(6,1), g(6,2)]= getPDR(321.7001);
    cd ..
    mean( abs(mean(g)))
    std ( abs(mean(g)))

end

function [wm, wvar, xim, xivar, gn, gp] = getPDR( stiff)
    Ts=1/200;
    [t,in,i,x] = reads();
    x=x./56000;
    index = find(i<-0.2,1)-1;
    i = i(index:end);
    x = x(index:end);
    
    v = diff(x)/Ts;
    v(end+1)=v(end);
    xg = x(v==0);

    xg=xg(abs(xg)>0);
    gn = xg(xg>0);
    gp = xg(xg<0);
    gn = mean(gn);
    gp = mean(gp);
    
    [k,i] = findpeaks(x);
    index = k>mean(x);
    k = k(index);
    i = i(index);
    
    Inew =[];
    prevp=0;
    for p=1:length(i)
       if (prevp ~=0 && i(p)-prevp < 900) continue; end
       Inew = [Inew; i(p);i(p+1)];
       prevp=i(p);
    end
    

    temp = x(Inew);
    xiest=[];
    for (p=1:2:length(temp))
        d = log(temp(p)/temp(p+1));
        xiest = [xiest; 1/sqrt(1+(2*pi/d)^2)]; 
    end
    T = diff(Inew)/200;
    T = T(T<2.2);
    w = 2*pi./T;
    wm = mean(w);
    wvar = var(w);
    xim = mean(xiest);
    xivar = var(xiest);
    
    [t,v,i,x]=reads();
    i1 = find(i>0.2,1);
    i2 = find(i(i1:end)<0, 1);
    i3 = find(i(i2:end)>0, 1);
    inew=i(i1+i2:end-5*200);
    ipos = inew(inew>0.2); 
    [a,b,c]=fourierCoefficients(ipos, length(ipos)/200);
    gn=stiff*gn/a(1);
    
    inew = inew(i1+i2+i3:end);
    ineg = inew(inew<-0.2);
    [a,b,c]=fourierCoefficients(ineg, length(ineg)/200);
   gp= stiff*gp/a(1);
end


