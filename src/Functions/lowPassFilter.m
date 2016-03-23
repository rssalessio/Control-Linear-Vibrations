function [data] = lowPassFilter(data, fn, order, Ts)
%   LOWPASSFILTER - uses ButterWorth filter and filtfilt to remove phase
%   data: data to be filtered
%   fn: cutoff frequency
%   order: filter order, the higher the better (but increases gibbs effect)
%   Ts: sampling time
%   
%   order, Ts can be omitted

    if (nargin == 2)
        Ts = 1/200;
        order = 2;
    elseif(nargin == 3)
        Ts=1/200;
    end
    
    cutoff = 2*fn*Ts;
    [B,A] = butter(order, cutoff);
    data = filtfilt(B,A,data);
    
end