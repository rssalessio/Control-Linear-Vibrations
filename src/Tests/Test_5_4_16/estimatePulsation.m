function [Wm] = estimatePulsation()
    [~,x] = reads(1);
    [k,a]=findpeaks(x);
    Wm = 2*pi*200./diff(a(2:end-2));
    
    
    
    
    
    [k,a]=findpeaks(-x);
    a = 2*pi*200./diff(a(2:end-2));
    Wm = [Wm; a];
    
    xi=estimateDampingRatio(x);
    
end