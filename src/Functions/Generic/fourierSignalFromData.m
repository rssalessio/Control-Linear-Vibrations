function [y] = fourierSignalFromData(x,T,t)
    [mod,phase,f] = fourierCoefficients(x,T);
    y = zeros(length(t),1);
    for i = 1:length(mod)
        omega = 2*pi*f(i);
        y= y+mod(i)*sin(omega*t+pi/2+phase(i)); 
    end

end