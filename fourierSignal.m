function [y] = fourierSignal(mod, phase, f, t)
% FOURIERSIGNAL  Given the module,phase coefficients and the frequency
% components, plots the signal over the period defined by the vector t
%
% Example:
% t = 0:0.01:10;
% x = t.^2;
% [mod,phase,f] = fourierCoefficients(x,10);
% figure; plot(t,x); hold on; plot(t, fourierSignal(mod,phase,f,t));
% legend(['Original signal', 'Reconstructed Signal']);
    y = zeros(length(t),1);
    for i = 1:length(mod)
        omega = 2*pi*f(i);
        y= y+mod(i)*cos(omega*t+phase(i)); 
    end

end