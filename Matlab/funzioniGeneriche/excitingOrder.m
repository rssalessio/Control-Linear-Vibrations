function [n] = excitingOrder(x, Ts)

    dat = iddata([],x,Ts);
    n = pexcit(dat);
end