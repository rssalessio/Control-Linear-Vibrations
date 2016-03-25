function [J] = calculateFit(x,y)
% CALCULATEFIT - calculates   J = 1/N integral (x(t)-y(t))^2 dt from 0 to N
%
%   rows are time samples, columns may have more signals.

    if (nargin ~= 2)
        disp('At least 2 parameters are needed');
        return;
    end
    
    if (size(x) ~= size(y))
        disp('x,y need to be of the same size');
        return;
    end
    
    K = size(x,2);
    J= zeros(1,K);
    for i=1:K
        J(i) =  sum((x(:,i)-y(:,i)).^2)/N;
    end

end