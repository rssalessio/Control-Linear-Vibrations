function m = getMeanComponent(x, Ts)

    [a,b,c]= fourierCoefficients(x, length(x)*Ts);
    
    m=a(1);

end