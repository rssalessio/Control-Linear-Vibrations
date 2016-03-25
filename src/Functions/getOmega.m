function [wm, wvar] = getOmega(x, Ts)
    if (nargin==1)
        Ts=1/200;
    end
    [k,i] = findpeaks(x);
    i=i-1;
    index = k>mean(x);
    k = k(index);
    i = i(index);
    
    index = 1:1:length(k);
    index = logical(mod(index,3));
    k = k(index);
    i = i(index);
    T = diff(i) * 1/200;
    T = T(T<1);
    Tm = mean(T);
    wm = 2*pi/Tm;
    wvar =  sum((2*pi/(T-Tm)).^2)/length(T);
end
