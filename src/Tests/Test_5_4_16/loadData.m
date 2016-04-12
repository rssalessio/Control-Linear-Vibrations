function [xKhighNomass, xKhigh2mass, xKmedNomass,xKmed2mass,xKlowNomass,xKlow2mass] = loadData()

xKhighNomass = [];
xKhigh2mass =[];

xKmedNomass = [];
xKmed2mass =[];

xKlowNomass = [];
xKlow2mass =[];

xi = zeros(6,3);

%%
figure;
cd Khigh_hand_Nomass
    data = estimate();
    xi(1,1) = data.xi;
    xKhighNomass=[xKhighNomass; data.Wm];
cd ..

cd Khigh_hand_Nomass2
    data = estimate();
    
    xi(2,1) = data.xi;
    xKhighNomass=[xKhighNomass; data.Wm];
cd ..

cd Khigh_hand_Nomass3
    data = estimate();
    xi(3,1) = data.xi;
    xKhighNomass=[xKhighNomass; data.Wm];
cd ..


cd Khigh_hand_2mass
    data = estimate();
    xi(4,1) = data.xi;
    xKhigh2mass=[xKhigh2mass; data.Wm];
cd ..

cd Khigh_hand_2mass2
    data = estimate();
    
    xi(5,1) = data.xi;
    xKhigh2mass=[xKhigh2mass; data.Wm];
cd ..

cd Khigh_hand_2mass3
    data = estimate();
    xi(6,1) = data.xi;
    xKhigh2mass=[xKhigh2mass; data.Wm];
cd ..
%%
figure;
cd Kmed_hand_Nomass
    data = estimate();
    xi(1,2) = data.xi;
    xKmedNomass=[xKmedNomass; data.Wm];
cd ..

cd Kmed_hand_Nomass2
    data = estimate();
    xi(2,2) = data.xi;
    xKmedNomass=[xKmedNomass; data.Wm];
cd ..

cd Kmed_hand_Nomass3
    data = estimate();
    xi(3,2) = data.xi;
    xKmedNomass=[xKmedNomass; data.Wm];
cd ..

cd Kmed_hand_2mass
    data = estimate();
    xi(4,2) = data.xi;
    xKmed2mass=[xKmed2mass; data.Wm];
cd ..

cd Kmed_hand_2mass2
    data = estimate();
    xi(5,2) = data.xi;
    xKmed2mass=[xKmed2mass; data.Wm];
cd ..

cd Kmed_hand_2mass3
    data = estimate();
    xi(6,2) = data.xi;
    xKmed2mass=[xKmed2mass; data.Wm];
cd ..
%%
figure;
cd Klow_hand_Nomass
    data = estimate();
    xi(1,3) = data.xi;
    xKlowNomass=[xKlowNomass; data.Wm];
cd ..

cd Klow_hand_Nomass2
    data = estimate();
    xi(2,3) = data.xi;
    xKlowNomass=[xKlowNomass; data.Wm];
cd ..

cd Klow_hand_Nomass3
    data = estimate();
    
    xi(3,3) = data.xi;
    xKlowNomass=[xKlowNomass;data.Wm];
cd ..

cd Klow_hand_2mass
    data = estimate();
    xi(4,3) = data.xi;
    xKlow2mass=[xKlow2mass; data.Wm];
cd ..

cd Klow_hand_2mass2
    data = estimate();
    xi(5,3) = data.xi;
    xKlow2mass=[xKlow2mass; data.Wm];
cd ..

cd Klow_hand_2mass3
    data = estimate();
    
    xi(6,3) = data.xi;
    xKlow2mass=[xKlow2mass; data.Wm];
cd ..
xi
end
