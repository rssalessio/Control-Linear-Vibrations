function [] = fourierPlot(x,Ts)
    [m,p,f] = fourierCoefficients(x,Ts);
    figure;
    subplot(211);
    plot(f,m); grid; xlabel('Hz'); title('Module');
    subplot(212);
    plot(f,p); grid; xlabel('Hz');title('Phase');
    
    %figure;
    %semilogx(f, 10*log10(m));grid;
end