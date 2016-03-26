function [data] = lowPassFilter(data, fn, order, zeroPhase, Ts)
%   LOWPASSFILTER - uses ButterWorth filter and filtfilt to remove phase
%   data: data to be filtered
%   fn: cutoff frequency
%   order: filter order, the higher the better (but increases gibbs effect)
%   zeroPhase: set to 1 if you want to use filtfilt algorithm to remove filter phase. It's an
%   offline acausal algorithm. Otherwise rely on the order to mitigate
%   phase
%   Ts: sampling time
%   
%   order, Ts can be omitted

    if (nargin == 2)
        zeroPhase = 0;
        Ts = 1/200;
        order = 2;
    elseif(nargin == 3)
        Ts=1/200;
        zeroPhase = 0;
    elseif(nargin==4)
        Ts=1/200;
    end
    
    cutoff = 2*fn*Ts;
    [B,A] = butter(order, cutoff);
    if(zeroPhase ==1)
        data = filtfilt(B,A,data);
    else
        data = filter(B,A,data);
    end
    
end