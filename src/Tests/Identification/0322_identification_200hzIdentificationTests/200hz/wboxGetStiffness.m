function [Km, KVar]= wboxGetStiffness()
    [Wm, ~,~,~] = wboxGetPulsationDamping();
    [Mm, ~] = wboxGetCartMass();
    Mload= 0.493*2;
    MTotal = Mm+Mload;
    Wm = Wm.^2;
    KEst = [MTotal*Wm(1,:); Mm*Wm(2,:) ];
    Km = mean(KEst,1);
    KVar = (KEst - repmat(Km,size(KEst,1),1)).^2;
    KVar = sum(KVar)./size(KEst,1);
end