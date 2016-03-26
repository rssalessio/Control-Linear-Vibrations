function [C] = wboxGetDamping()
    [Wm, ~,XIm,~] = wboxGetPulsationDamping();
    [Mm, ~] = wboxGetCartMass();
    Mload= 0.493*2
    Mtotal = Mload+Mm;
    C=Wm.*XIm*2;
    C(1,:) = C(1,:) *Mtotal;
    C(2,:) = C(2,:) *Mm;
end