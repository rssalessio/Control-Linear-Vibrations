function [] = spectrumRatio(in,out,T)
    [modIN,phaseIN,fIN] = fourierCoefficients(in,T);
    [modOUT,phaseOUT,fOUT] = fourierCoefficients(out,T);
    
    mod = zeros(size(modIN));
    phase = zeros(size(phaseIN));
    
    mod = modOUT./modIN;
    
    

end