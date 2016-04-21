function [xi] = estimateDampingRatio(x)
    [k,i] = findpeaks(x);
    xi=[];
 %   a=1/(2*pi)  * log( k(1)/k(2));
 %   xi = [xi;(a/sqrt(a^2+1))];
 %   a=1/(2*pi)  * log( k(2)/k(3));
  %  (a/sqrt(a^2+1))
    
    xi = [xi; 1/(2*pi)  * log( k(1)/k(2));
        1/(2*pi)  * log( k(2)/k(3));
        1/(2*pi)  * log( k(3)/k(4))];
%     for j=1:length(k)-1
%        d = 1/j * log(k(1)/k(j+1)); 
%        xi= [xi;1/sqrt(1+(2*pi/d)^2)];
%        
%     end
%     
    
    [k,i] = findpeaks(-x);
  %  a=1/(2*pi)  * log( k(1)/k(2));
  %  xi = [xi;(a/sqrt(a^2+1))];
  %  a=1/(2*pi)  * log( k(2)/k(3));
  %  (a/sqrt(a^2+1))
%     for j=1:length(k)-1
%        d = 1/j * log(k(1)/k(j+1)); 
%        xi= [xi;1/sqrt(1+(2*pi/d)^2)];
%     end
    
   % xi = xi(logical(imag(xi)==0));
   % plot(xi);
  %  hold on;
   % xi=min(xi);
   xi = [xi; 1/(2*pi)  * log( k(1)/k(2));
        1/(2*pi)  * log( k(2)/k(3));
        1/(2*pi)  * log( k(3)/k(4))];
    
end