function [Mm,MVar,Km, C,g] = wboxGetCartMass()
    [Wm, ~,XIm,~,g] = wboxGetPulsationDamping();
    Mload= 0.493*2;

   Wm = [20.0753, 13.1359, 10.9848;
          30.3578, 19.1376, 15.9605];
    
    [a1]=linsolve([1 -Wm(1,1)^2; 1 -Wm(2,1)^2], [Mload*Wm(1,1)^2; 0]);
    [a2]=linsolve([1 -Wm(1,2)^2; 1 -Wm(2,2)^2], [Mload*Wm(1,2)^2; 0]);
    [a3]=linsolve([1 -Wm(1,3)^2; 1 -Wm(2,3)^2], [Mload*Wm(1,3)^2; 0]);
    Km = [a1(1);a2(1);a3(1)];
    Mm = [a1(2); a2(2); a3(2)];
    MVar = var(Mm);
    Mm = mean(Mm);
    
    XIm = [0.1349,0.1996,0.2482;
            0.1517,0.223,0.3443];
    Mtotal = Mload+Mm;
    C=Wm.*XIm*2;
    C(1,:) = C(1,:) *Mtotal;
    C(2,:) = C(2,:) *Mm;
    
    

end