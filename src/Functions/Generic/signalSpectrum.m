function [] = signalSpectrum(x, Ts)

    [pxx,f] = pwelch(x,[],[],[],1/Ts);

    figure;
    plot(f,10*log10(pxx));
    grid;
    xlabel('Frequency (Hz)');
    ylabel('Magnitude (dB)');

end