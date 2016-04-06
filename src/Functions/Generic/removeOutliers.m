function [ret] = removeOutliers(x, opt)
% RemoveOutliers - Assumes x is normally distributed. 
% opt = 1 -> keep only those data that are in the range mean(x)+-2 std(x)
% opt = 2 -> mean(x)+-3std(x)
    if (nargin == 1)
        opt = 1;
    end
    if (opt == 1) coeff = 2;
    else coeff = 3; end
    
    warning('off','all');
    distrib=fitdist(x,'tLocationScale');
    warning('on','all');
       
    m=distrib.mu;
    sigma =distrib.sigma;
    ret = x( x <= m+coeff*sigma);
    ret = ret( ret >= m-coeff*sigma);

end