function [Wm, WVar, XIm, XIVar] = wboxGetPulsationDamping()
    Wm = zeros(2,3);
    WVar = zeros(2,3);
    XIm = zeros(2,3);
    XIVar = zeros(2,3);
    cd pulse_kbig_2mass/
        [Wm(1,1), WVar(1,1), XIm(1,1), XIVar(1,1)]= getPDR();
    cd ..

    cd pulse_kbig_nomass/
        [Wm(2,1), WVar(2,1), XIm(2,1), XIVar(2,1)]= getPDR();
    cd ..
    cd pulse_klow_2mass/ 
        [Wm(1,3), WVar(1,3), XIm(1,3), XIVar(1,3)]= getPDR();
    cd ..
    cd pulse_klow_nomass/
        [Wm(2,3), WVar(2,3), XIm(2,3), XIVar(2,3)]= getPDR();
    cd ..
    cd pulse_kmed_2mass/
         [Wm(1,2), WVar(1,2), XIm(1,2), XIVar(1,2)]= getPDR();
    cd ..
    cd pulse_kmed_nomass/
         [Wm(2,2), WVar(2,2), XIm(2,2), XIVar(2,2)]= getPDR();
    cd ..
    

end

function [wm, wvar, xim, xivar] = getPDR(x, Ts)
    if (nargin==1)
        Ts=1/200;
    end
    [t,~,i,x] = reads();
    index = find(i<-0.2,1);
    i = i(index:end);
    x = x(index:end);
    
    [k,i] = findpeaks(x);
    i=i-1;
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
        d = log(temp(p)/(temp(p+1)));
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


