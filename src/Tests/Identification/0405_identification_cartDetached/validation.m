function costs = validation()

    Mc = 0.5685;
    Mload = 0.493*2;
    K=[712.5990, 315.5074, 175.28];
    C=[0.8520,1.0542,1.1423; 0.7206, 0.8063, 0.7567];
    costs= zeros(18,1);
cd Khigh_hand_Nomass
    costs(1)=validate(Mc, K(1), C(2,1));
cd ..

cd Khigh_hand_Nomass2
    costs(2)=validate(Mc, K(1), C(2,1));
cd ..

cd Khigh_hand_Nomass3
    costs(3)=validate(Mc, K(1), C(2,1));
cd ..


cd Khigh_hand_2mass
    costs(4)=validate(Mc+Mload, K(1), C(1,1));
cd ..

cd Khigh_hand_2mass2
    costs(5)=validate(Mc+Mload, K(1), C(1,1));
cd ..

cd Khigh_hand_2mass3
   costs(6)= validate(Mc+Mload, K(1), C(1,1));
cd ..
%%
xi2=[];
cd Kmed_hand_Nomass
    costs(7)=validate(Mc, K(2), C(2,2));
cd ..

cd Kmed_hand_Nomass2
    costs(8)=validate(Mc, K(2), C(2,2));
cd ..

cd Kmed_hand_Nomass3
    costs(9)=validate(Mc, K(2), C(2,2));
cd ..

cd Kmed_hand_2mass
    costs(10)=validate(Mc+Mload, K(2), C(1,2));
cd ..

cd Kmed_hand_2mass2
    costs(11)=validate(Mc+Mload, K(2), C(1,2));
cd ..

cd Kmed_hand_2mass3
    costs(12)=validate(Mc+Mload, K(2), C(1,2));
cd ..
%%
xi3=[];
cd Klow_hand_Nomass
    costs(13)=validate(Mc, K(3), C(2,3));
cd ..

cd Klow_hand_Nomass2
    costs(14)=validate(Mc, K(3), C(2,3));
cd ..

cd Klow_hand_Nomass3
    costs(15)=validate(Mc, K(3), C(2,3));
cd ..

cd Klow_hand_2mass
    costs(16)=validate(Mc+Mload, K(3), C(1,3));
cd ..

cd Klow_hand_2mass2
    costs(17)=validate(Mc+Mload, K(3), C(1,3));
cd ..

cd Klow_hand_2mass3
    costs(18)=validate(Mc+Mload, K(3), C(1,3));
cd ..
    mean(costs)
    std(costs)

end

function a = validate(M,K,C)
    [t,x]=reads();
    [a,b]=findpeaks(x);
    t=t(b:end);
    t=t-t(1);
    x=x(b:end);

   


    G=tf(1,[M C K]);
    G=ss(G);
    y=initial(G,[0,max(x)],t);
    a=costFunction(y,x*max(y)/max(x));

end