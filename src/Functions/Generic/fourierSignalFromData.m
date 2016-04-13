function [y] = fourierSignalFromData(x,Ts,t)
    [mod,phase,f] = fourierCoefficients(x,Ts);
    y = zeros(length(t),1);
    for i = 1:length(mod)
        omega = 2*pi*f(i);
        y= y+mod(i)*sin(omega*t+pi/2+phase(i)); 
    end

end