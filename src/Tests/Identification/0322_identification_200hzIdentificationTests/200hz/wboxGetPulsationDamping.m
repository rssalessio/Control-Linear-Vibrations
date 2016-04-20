function [Wm, WVar, XIm, XIVar,g] = wboxGetPulsationDamping()
    Wm = zeros(2,3);
    WVar = zeros(2,3);
    XIm = zeros(2,3);
    XIVar = zeros(2,3);
    g = zeros(6,2);
    cd pulse_kbig_2mass/
        [Wm(1,1), WVar(1,1), XIm(1,1), XIVar(1,1), g(1,1), g(1,2)]= getPDR();
    cd ..

    cd pulse_kbig_nomass/
        [Wm(2,1), WVar(2,1), XIm(2,1), XIVar(2,1), g(2,1), g(2,2)]= getPDR();
    cd ..
    cd pulse_klow_2mass/ 
        [Wm(1,3), WVar(1,3), XIm(1,3), XIVar(1,3), g(3,1), g(3,2)]= getPDR();
    cd ..
    cd pulse_klow_nomass/
        [Wm(2,3), WVar(2,3), XIm(2,3), XIVar(2,3), g(4,1), g(4,2)]= getPDR();
    cd ..
    cd pulse_kmed_2mass/
         [Wm(1,2), WVar(1,2), XIm(1,2), XIVar(1,2), g(5,1), g(5,2)]= getPDR();
    cd ..
    cd pulse_kmed_nomass/
         [Wm(2,2), WVar(2,2), XIm(2,2), XIVar(2,2), g(6,1), g(6,2)]= getPDR();
    cd ..
    

end

function [wm, wvar, xim, xivar, gn, gp] = getPDR( Ts)
    if (nargin==0)
        Ts=1/200;
    end
    [t,in,i,x] = reads();
    x=x./560;
    index = find(i<-0.2,1);
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
        d = log(temp(p))/log(temp(p+1));
        xiest = [xiest; 1/sqrt(1+(2*pi/d)^2)]; 
    end
    T = diff(Inew) * 1/200;
    T = T(T<2.2);
    w = 2*pi./T;
    wm = mean(w);
    wvar = sum( (w-wm).^2)./length(w);
    xim = mean(xiest);
    xivar = sum( (xiest-xim).^2)/length(xiest);
end


