function [] = fourierPlot(x,T)
    [m,p,f] = fourierCoefficients(x,T);
    figure;
    subplot(211);
    bar(f,m); grid; xlabel('Hz'); title('Module');
    subplot(212);
    bar(f,p); grid; xlabel('Hz');title('Phase');
    
    %figure;
    %semilogx(f, 10*log10(m));grid;
end