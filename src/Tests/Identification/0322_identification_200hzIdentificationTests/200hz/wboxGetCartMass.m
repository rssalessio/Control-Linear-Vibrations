function [Mm,MVar,Km, C,g] = wboxGetCartMass()
    [Wm, ~,XIm,~,g] = wboxGetPulsationDamping();
    Mload= 0.493*2;


    
    
    [a1]=linsolve([1 -Wm(1,1)^2; 1 -Wm(2,1)^2], [Mload*Wm(1,1)^2; 0]);
    [a2]=linsolve([1 -Wm(1,2)^2; 1 -Wm(2,2)^2], [Mload*Wm(1,2)^2; 0]);
    [a3]=linsolve([1 -Wm(1,3)^2; 1 -Wm(2,3)^2], [Mload*Wm(1,3)^2; 0]);
    Km = [a1(1);a2(1);a3(1)];
    Mm = [a1(2); a2(2); a3(2)];
    MVar = var(Mm);
    Mm = mean(Mm);
    
    Mtotal = Mload+Mm;
    XIm(1,1)=0.1366;
    C=Wm.*XIm*2;
    C(1,:) = C(1,:) *Mtotal;
    C(2,:) = C(2,:) *Mm;
    
    



end