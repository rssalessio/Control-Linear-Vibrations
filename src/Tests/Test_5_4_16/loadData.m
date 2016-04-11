function [xKhighNomass, xKhigh2mass, xKmedNomass,xKmed2mass,xKlowNomass,xKlow2mass] = loadData()

xKhighNomass = [];
xKhigh2mass =[];

xKmedNomass = [];
xKmed2mass =[];

xKlowNomass = [];
xKlow2mass =[];


%%
cd Khigh_hand_Nomass
    xKhighNomass=[xKhighNomass; estimatePulsation()];
cd ..

cd Khigh_hand_Nomass2
    xKhighNomass=[xKhighNomass; estimatePulsation()];
cd ..

cd Khigh_hand_Nomass3
    xKhighNomass=[xKhighNomass; estimatePulsation()];
cd ..


cd Khigh_hand_2mass
    xKhigh2mass=[xKhigh2mass; estimatePulsation()];
cd ..

cd Khigh_hand_2mass2
    xKhigh2mass=[xKhigh2mass; estimatePulsation()];
cd ..

cd Khigh_hand_2mass3
    xKhigh2mass=[xKhigh2mass; estimatePulsation()];
cd ..
%%
cd Kmed_hand_Nomass
    xKmedNomass=[xKmedNomass; estimatePulsation()];
cd ..

cd Kmed_hand_Nomass2
    xKmedNomass=[xKmedNomass; estimatePulsation()];
cd ..

cd Kmed_hand_Nomass3
    xKmedNomass=[xKmedNomass; estimatePulsation()];
cd ..

cd Kmed_hand_2mass
    xKmed2mass=[xKmed2mass; estimatePulsation()];
cd ..

cd Kmed_hand_2mass2
    xKmed2mass=[xKmed2mass; estimatePulsation()];
cd ..

cd Kmed_hand_2mass3
    xKmed2mass=[xKmed2mass; estimatePulsation()];
cd ..
%%
cd Klow_hand_Nomass
    xKlowNomass=[xKlowNomass; estimatePulsation()];
cd ..

cd Klow_hand_Nomass2
    xKlowNomass=[xKlowNomass; estimatePulsation()];
cd ..

cd Klow_hand_Nomass3
    xKlowNomass=[xKlowNomass; estimatePulsation()];
cd ..

cd Klow_hand_2mass
    xKlow2mass=[xKlow2mass; estimatePulsation()];
cd ..

cd Klow_hand_2mass2
    xKlow2mass=[xKlow2mass; estimatePulsation()];
cd ..

cd Klow_hand_2mass3
    xKlow2mass=[xKlow2mass; estimatePulsation()];
cd ..
end
