
clear all; close all; clc;
WVar_2mass = zeros(3,3);
mload=0.493*2;
Wm=zeros(2,3);
WVar = var(2,3);
[wKhNom, wKh2m, wKmNom,wKm2m,wKlNom,wKl2m,xi1,xi2,xi3]= loadData();
%%
if (medianCondition(wKh2m) > 0.5)
    Wm(1,1) = median(wKh2m);
else
    Wm(1,1) = mean(wKh2m);
end

WVar(1,1) = var(wKh2m);

if (medianCondition(wKhNom) > 0.5)
    Wm(2,1) = median(wKhNom);
else
    Wm(2,1) = mean(wKhNom);
end
WVar(2,1) = var(wKhNom);


if (medianCondition(wKm2m) > 0.5)
    Wm(1,2) = median(wKm2m);
else
    Wm(1,2) = mean(wKm2m);
end
WVar(1,2) = var(wKm2m);


if (medianCondition(wKmNom) > 0.5)
    Wm(2,2) = median(wKmNom);
else
    Wm(2,2) = mean(wKmNom);
end
WVar(2,2) = var(wKmNom);

if (medianCondition(wKl2m) > 0.5)
    Wm(1,3) = median(wKl2m);
else
    Wm(1,3) = mean(wKl2m);
end
WVar(1,3) = var(wKl2m);


if (medianCondition(wKlNom) > 0.5)
    Wm(2,3) = median(wKlNom);
else
    Wm(2,3) = mean(wKlNom);
end
WVar(2,3) = var(wKlNom);

a=linsolve([1 -Wm(1,1)^2; 1 -Wm(2,1)^2], [mload*Wm(1,1)^2; 0])
b=linsolve([1 -Wm(1,2)^2; 1 -Wm(2,2)^2], [mload*Wm(1,2)^2; 0])
c=linsolve([1 -Wm(1,3)^2; 1 -Wm(2,3)^2], [mload*Wm(1,3)^2; 0])

mc = mean([a(2),b(2),c(2)]);

kh=a(1);
km=b(1)
kl=c(1)
M=mc+0.493*2;

xi=[0.0179, 0.0301, 0.0379; 0.0128, 0.0238, 0.0346]

C=2*xi;
C(1,:) = C(1,:)*sqrt(mc).*sqrt([kh,km,kl]);
C(2,:) = C(2,:)*sqrt(M).*sqrt([kh,km,kl]);


