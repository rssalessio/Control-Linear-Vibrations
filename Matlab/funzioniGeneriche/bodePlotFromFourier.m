function [] = bodePlotFromFourier(m,p,f,Fs)
    %Plots bode  from fourier coefficients. Fs is the sampling frequency
    figure;
    title('Bode Plot');hold on;
    %%magnitude plot
    subplot(211);
    semilogx(f, 10*log10(m)); hold on; grid;
    ylabel('dB');
    xlabel('\omega [rad/sec]');
    yl=ylim;
    xl = xlim;
    p1=[Fs/2, yl(1)];
    p2 =[Fs/2, yl(2)];
    hold on;
    plot([p1(1),p2(1)],[p1(2),p2(2)],'Color','r','LineWidth',1)
    hold on;
    text(Fs/2+0.05*(xl(2)-xl(1)),p1(2)+0.1*(p2(2)-p1(2)),'fs/2[Hz]','HorizontalAlignment','left');
    
    %%phase plot
    subplot(212);
    semilogx(f, p); hold on;grid;
    yl=ylim;
    xl = xlim;
    p1=[Fs/2, yl(1)];
    p2 =[Fs/2,yl(2)];
    hold on;
    plot([p1(1),p2(1)],[p1(2),p2(2)],'Color','r','LineWidth',1);
     hold on;
    text(Fs/2+0.05*(xl(2)-xl(1)),p1(2)+0.1*(p2(2)-p1(2)),'fs/2[Hz]','HorizontalAlignment','left');
    ylabel('Angle [rad]');
    xlabel('\omega [rad/sec]');

end