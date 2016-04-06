
Wm_nomass = zeros(3,3);
WVar_nomass = zeros(3,3);

Wm_2mass = zeros(3,3);
WVar_2mass = zeros(3,3);

Wm=zeros(2,3);



mload = 2*0.493;
%%
cd Khigh_hand_Nomass
    [Wm_nomass(1,1), WVar_nomass(1,1)] = estimatePulsation();
cd ..

cd Khigh_hand_Nomass2
    [Wm_nomass(2,1), WVar_nomass(2,1)] = estimatePulsation();
cd ..

cd Khigh_hand_Nomass3
    [Wm_nomass(3,1), WVar_nomass(3,1)] = estimatePulsation();
cd ..

cd Khigh_hand_2mass
    [Wm_2mass(1,1), WVar_2mass(1,1)] = estimatePulsation();
cd ..

cd Khigh_hand_2mass2
    [Wm_2mass(2,1), WVar_2mass(2,1)] = estimatePulsation();
cd ..

cd Khigh_hand_2mass3
    [Wm_2mass(3,1), WVar_2mass(3,1)] = estimatePulsation();
cd ..
%%
cd Kmed_hand_Nomass
    [Wm_nomass(1,2), WVar_nomass(1,2)] = estimatePulsation();
cd ..

cd Kmed_hand_Nomass2
    [Wm_nomass(2,2), WVar_nomass(2,2)] = estimatePulsation();
cd ..

cd Kmed_hand_Nomass3
    [Wm_nomass(3,2), WVar_nomass(3,2)] = estimatePulsation();
cd ..

cd Kmed_hand_2mass
    [Wm_2mass(1,2), WVar_2mass(1,2)] = estimatePulsation();
cd ..

cd Kmed_hand_2mass2
    [Wm_2mass(2,2), WVar_2mass(2,2)] = estimatePulsation();
cd ..

cd Kmed_hand_2mass3
    [Wm_2mass(3,2), WVar_2mass(3,2)] = estimatePulsation();
cd ..
%%
cd Klow_hand_Nomass
    [Wm_nomass(1,3), WVar_nomass(1,3)] = estimatePulsation();
cd ..

cd Klow_hand_Nomass2
    [Wm_nomass(2,3), WVar_nomass(2,3)] = estimatePulsation();
cd ..

cd Klow_hand_Nomass3
    [Wm_nomass(3,3), WVar_nomass(3,3)] = estimatePulsation();
cd ..

cd Klow_hand_2mass
    [Wm_2mass(1,3), WVar_2mass(1,3)] = estimatePulsation();
cd ..

cd Klow_hand_2mass2
    [Wm_2mass(2,3), WVar_2mass(2,3)] = estimatePulsation();
cd ..

cd Klow_hand_2mass3
    [Wm_2mass(3,3), WVar_2mass(3,3)] = estimatePulsation();
cd ..


%%
Wm(1,1) = mean(Wm_2mass(:,1));
Wm(2,1) = mean(Wm_nomass(:,1));
Wm(1,2) = mean(Wm_2mass(:,2));
Wm(2,2) = mean(Wm_nomass(:,2));
Wm(1,3) = mean(Wm_2mass(:,3));
Wm(2,3) = mean(Wm_nomass(:,3));

a = Wm(1,:).^2 ./ Wm(2,:).^2;
mcart=ml*a./(1-a)
linsolve([1 -Wm(1,1)^2; 1 -Wm(2,1)^2], [mload*Wm(1,1)^2; 0])
linsolve([1 -Wm(1,2)^2; 1 -Wm(2,2)^2], [mload*Wm(1,2)^2; 0])
linsolve([1 -Wm(1,3)^2; 1 -Wm(2,3)^2], [mload*Wm(1,3)^2; 0])



