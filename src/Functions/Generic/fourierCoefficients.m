function [mod,phase, f] = fourierCoefficients(x,T)
% FOURIERCOEFFICIENTS calculates phase and module cofficients of a signal.
%   INPUTS:
%       x - signal to be analysed
%       T - duration in seconds of the signal
%   OUTPUTS:
%       mod - module coefficients
%       phase - phase coefficients
%       f - frequency components
%
    N = length(x);
    df=1/T;
    fmax=df*(N/2-1);
    f = (0:df:fmax)';
    xfft= fft(x);
    mod = zeros(floor(N/2),1);
    phase = zeros(floor(N/2),1);
    mod(1) = abs(xfft(1))/N;
    mod(2:end) = abs(xfft(2:floor(N/2)))*2/N;
    phase(1:end) = angle(xfft(1:floor(N/2)));
end