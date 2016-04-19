function [ret] = removeOutliers(x, range, opt)
% RemoveOutliers - Assumes x is normally distributed. 
% opt = 1 -> keep only those data that are in the range mean(x)+-2 std(x)
% opt = 2 -> mean(x)+-3std(x)
    if (nargin == 2)
        opt = 1;
    end
    if (opt == 1) coeff = 2+eps;
    else coeff = 3+eps; end
    
%     warning('off','all');
%     distrib=fitdist(x,'tLocationScale');
% 
%     
%     warning('on','all');

    
       
    m=mean(x);
    sigma =sqrt(var(x));
    M = (x-m);
    ret = x( abs(M) < range);
    
    m = mean(ret);
    sigma = sqrt(var(ret));
    M=(ret-m)/sigma;
    ret = ret(abs(M)<coeff);

end