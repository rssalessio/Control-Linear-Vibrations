function [t, s1,s2,s3,s4,s5,s6] = plots(file, gr, n)

    if nargin == 1
        n = 3;
        gr = 0;
    end
    
    if nargin == 2
        n = 3;
    end
    
    [s1, s2, s3, s4, s5, s6] = textread(file, '%f %f %f %f %f %f');
    
    ts = 1/200; %sampling frequency 100Hz
    t = 0:ts:(length(s1)-1)*ts;
    
    figure;
    subplot 311; plot(t,s1); if gr grid; end
    subplot 312; plot(t,s2); if gr grid; end
    subplot 313; plot(t,s3); if gr grid; end
    
    if n > 3
        figure;
        subplot 311; plot(t,s4); if gr grid; end
        subplot 312; plot(t,s5); if gr grid; end
        subplot 313; plot(t,s6); if gr grid; end
    end
    
end