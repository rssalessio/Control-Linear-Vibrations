function [xi] = estimateDampingRatio(x)
    [k,i] = findpeaks(x);
    xi=[];
    for j=1:length(k)-1
       d = 1/j * log(k(1)/k(j+1)); 
       xi= [xi;1/sqrt(1+(2*pi/d)^2)];
    end
    
    
    [k,i] = findpeaks(-x);
    for j=1:length(k)-1
       d = 1/j * log(k(1)/k(j+1)); 
       xi= [xi;1/sqrt(1+(2*pi/d)^2)];
    end
    
    xi = xi(logical(imag(xi)==0));
    plot(xi);
    hold on;
    xi=min(xi);
    
end