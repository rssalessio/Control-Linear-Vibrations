function [] = estimateTF(out,in,t,np)
%   SPECTRUMRATIO - estimates TF given input and output signal.
%   out,in: output and input
%   t: time vector
%   np: number of poles estimated
    T= max(t)-min(t);
    Ts=t(2)-t(1);
    Fs=1/Ts;
    [modIN,phaseIN,fIN] = fourierCoefficients(in,T);
    [modOUT,phaseOUT,fOUT] = fourierCoefficients(out,T);
    
    mod = zeros(size(modIN));
    phase = zeros(size(phaseIN));
    
    mod = modOUT./modIN;
    phase = phaseOUT-phaseIN;
    
    bodePlotFromFourier(mod,phase,fIN,Fs);
    dat=iddata(out',in', Ts);
    figure;
    bode(tfest(dat, np));

end