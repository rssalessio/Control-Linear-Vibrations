function [Percentage, Cost] = calculateFit(x,y,opt)
% CALCULATEFIT(x,y) - calculates   J = 1/N integral (x(t)-y(t))^2 dt from 0 to N
%
%   
%   x,y: rows are time samples, columns may have more signals.
%   opt: 'scale' used to verify if y fits x in the shape
%        'noscale' without scaling
%
%   RETURN: 
%   - Percentage: a percetange of the fit from 0 to 1 of the signal.
%   Calculated from the cost
%   - Cost: calculated cost. 

    if (nargin < 2)
        disp('At least 2 parameters are needed');
        return;
    end
    if (nargin ==2)
        opt = 'shape';
    end
    
    if (size(x) ~= size(y))
        disp('x,y need to be of the same size');
        return;
    end
    
    K = size(x,2);
    Cost= zeros(1,K);
    N = size(x,1);
    %scale both signals
    if(opt=='scale')
        x=x./max(x);
        y = y./max(y);
    end
    for i=1:K
        Cost(i) =  sum((x(:,i)-y(:,i)).^2);
        Cost(i) = Cost(i)/(sum(x(:,i).^2)+sum(y(:,i).^2));
    end
    Percentage = exp(-Cost);
end