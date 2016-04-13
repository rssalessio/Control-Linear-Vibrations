
clear all; close all; clc;
WVar_2mass = zeros(3,3);
mload=0.493*2;
Wm=zeros(2,3);
[wKhNom, wKh2m, wKmNom,wKm2m,wKlNom,wKl2m]= loadData();
%%
if (medianCondition(wKh2m) > 0.5)
    Wm(1,1) = median(wKh2m);
else
    Wm(1,1) = mean(wKh2m);
end

if (medianCondition(wKhNom) > 0.5)
    Wm(2,1) = median(wKhNom);
else
    Wm(2,1) = mean(wKhNom);
end

if (medianCondition(wKm2m) > 0.5)
    Wm(1,2) = median(wKm2m);
else
    Wm(1,2) = mean(wKm2m);
end

if (medianCondition(wKmNom) > 0.5)
    Wm(2,2) = median(wKmNom);
else
    Wm(2,2) = mean(wKmNom);
end


if (medianCondition(wKl2m) > 0.5)
    Wm(1,3) = median(wKl2m);
else
    Wm(1,3) = mean(wKl2m);
end

if (medianCondition(wKlNom) > 0.5)
    Wm(2,3) = median(wKlNom);
else
    Wm(2,3) = mean(wKlNom);
end

linsolve([1 -Wm(1,1)^2; 1 -Wm(2,1)^2], [mload*Wm(1,1)^2; 0])
linsolve([1 -Wm(1,2)^2; 1 -Wm(2,2)^2], [mload*Wm(1,2)^2; 0])
linsolve([1 -Wm(1,3)^2; 1 -Wm(2,3)^2], [mload*Wm(1,3)^2; 0])






