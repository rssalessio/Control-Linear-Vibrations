function [Wm,WVar] = estimatePulsation()
    [t,x]=reads();
    [k,i]=findpeaks(x);

    T= diff(i)/200;
    w=2*pi./T;
    w=removeOutliers(w);
    Wm = mean(w);
    WVar = var(w);
end