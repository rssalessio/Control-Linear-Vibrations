function [T,err] = signalPeriod(x,Ts)
    if (nargin==1)
        Ts=1/200;
    end
    sigCorrelation = xcorr(x,x);
    [~,index] = findpeaks(sigCorrelation);
    T = mean(diff(index))*Ts;
    
    [p,f]=periodogram(x,[],[],1/Ts);
    [~,index2]=max(p);
    
    T2=1/f(index2);
    err = T-T2;
    

end