function [ cost, cumCost] = costFunction(x,y)
% l2cost(x,y) - calculates   d(x,y) = 1/(1+n(x-y)), n = E[(x-y)^2]
%
%   x,y: rows are time samples, columns may have more signals.



    if (nargin < 2)
        disp('At least 2 parameters are needed');
        return;
    end
    
    if (size(x) ~= size(y))
        disp('x,y need to be of the same size');
        return;
    end
    
    
    N = length(x);
    l2 = sqrt(cumsum((x-y).^2)./N);
    
    cumCost = 1./(1+l2);
    cost=cumCost(end);
    
end