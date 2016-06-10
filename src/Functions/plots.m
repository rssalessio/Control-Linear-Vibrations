function plots(data, n)
    
    Ts = 1/200;
    
    if nargin == 1
        n = 3;
    end
   
    tmin = min(data.t);
    tmax = max(data.t);
    lim = [tmin,tmax];
    
    figure;
    subplot 311; plot(data.t,data.v); hold on; grid; hold on;
    ylabel('Voltage [V]');
    xlabel('Seconds [s]'); 
    xlim(lim); ylim([min(data.v)-0.5, max(data.v)+0.5]);
    
    subplot 312; plot(data.t,data.i); hold on; grid; hold on;
    ylabel('Current [A]');
    xlabel('Seconds [s]'); xlim(lim);
    
    subplot 313; plot(data.t,data.x1); hold on; grid; hold on;
    ylabel('Cart pos. [cm]');
    xlabel('Seconds [s]'); xlim(lim);
    
    
    if n > 3
        figure;
        subplot 311; plot(t,s4); hold on; grid; hold on;
        xlabel('Seconds [s]'); xlim(lim);

        subplot 312; plot(t,s5); hold on; grid; hold on;
        xlabel('Seconds [s]'); xlim(lim);

        subplot 313; plot(t,s6); hold on; grid; hold on;
        xlabel('Seconds [s]'); xlim(lim);
    end
    
end