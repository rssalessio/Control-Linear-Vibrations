function [Mm,MVar,Km, C,g] = wboxGetCartMass()
    [Wm, ~,XIm,~,g] = wboxGetPulsationDamping();
    Mload= 0.493*2;

   Wm = [20.21, 13.0633, 10.75;
          30.43, 18.3767, 15.624];
    
    [a1]=linsolve([1 -Wm(1,1)^2; 1 -Wm(2,1)^2], [Mload*Wm(1,1)^2; 0]);
    [a2]=linsolve([1 -Wm(1,2)^2; 1 -Wm(2,2)^2], [Mload*Wm(1,2)^2; 0]);
    [a3]=linsolve([1 -Wm(1,3)^2; 1 -Wm(2,3)^2], [Mload*Wm(1,3)^2; 0]);
    Km = [a1(1);a2(1);a3(1)];
    Mm = [a1(2); a2(2); a3(2)];
    MVar = var(Mm);
    Mm = mean(Mm);
    
    XIm = [0.1356,0.1949,0.2230;
            0.1670,0.2569,0.2973];
    Mtotal = Mload+Mm;
    C=Wm.*XIm*2;
    C(1,:) = C(1,:) *Mtotal;
    C(2,:) = C(2,:) *Mm;
    
    

end