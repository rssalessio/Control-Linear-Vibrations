function [ret] = medianCondition(x)

    ret= sum(x==median(x))/length(x);

end