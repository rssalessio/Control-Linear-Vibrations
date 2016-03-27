function [Mm,MVar] = wboxGetCartMass()
    [Wm, ~,Xim,~] = wboxGetPulsationDamping();
    Mload= 0.493*2;
    
    Wdiff = diff(Wm.^2,1);
    MCartEst = Mload*Wm(1,:).^2;
    MCartEst = MCartEst./Wdiff;
    
    Mm = mean(MCartEst);
    MVar = sum((MCartEst-Mm).^2)/length(MCartEst);

end