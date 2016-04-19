function [t,y] = frequencySignalConstructor(m,f,Ts,T)
    t = (0:Ts:T-Ts)'
    y = zeros(length(t),1);
    for i=1:length(f)
        if (rem(f(i),1/T)==0)
            y = y+cos(2*pi*f(i)*t);
        end
    end

end