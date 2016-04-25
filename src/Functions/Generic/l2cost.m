function [ cost, cumCost] = l2cost(x,y)
% l2cost(x,y) - calculates   1/(1+||x-y||_2)
%
%   
%   x,y: rows are time samples, columns may have more signals.
%   opt: 'scale' used to verify if y fits x in the shape
%        'noscale' without scaling
%
%   RETURN: 
%   - Cost: calculated cost, it's a percentage (from 0 to 1)

    if (nargin < 2)
        disp('At least 2 parameters are needed');
        return;
    end
    
    if (size(x) ~= size(y))
        disp('x,y need to be of the same size');
        return;
    end
    
    
    N = length(x);
    l2 = sqrt(cumsum((x-y).^2));
    
    cumCost = 1./(1+l2);
    cost=cumCost(end);
    
end