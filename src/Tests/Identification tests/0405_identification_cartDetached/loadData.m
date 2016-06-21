function [xKhighNomass, xKhigh2mass, xKmedNomass,xKmed2mass,xKlowNomass,xKlow2mass,xi1,xi2,xi3] = loadData()

xKhighNomass = [];
xKhigh2mass =[];

xKmedNomass = [];
xKmed2mass =[];

xKlowNomass = [];
xKlow2mass =[];



%%
xi1=[];
cd Khigh_hand_Nomass
    data = estimate();
    xi1=[xi1; data.xi];
    xKhighNomass=[xKhighNomass; data.Wm];
cd ..

cd Khigh_hand_Nomass2
    data = estimate();
    
    xi1=[xi1; data.xi];
    xKhighNomass=[xKhighNomass; data.Wm];
cd ..

cd Khigh_hand_Nomass3
    data = estimate();
    xi1=[xi1; data.xi];
    xKhighNomass=[xKhighNomass; data.Wm];
cd ..


cd Khigh_hand_2mass
    data = estimate();
   xi1=[xi1; data.xi];
    xKhigh2mass=[xKhigh2mass; data.Wm];
cd ..

cd Khigh_hand_2mass2
    data = estimate();
    
    xi1=[xi1; data.xi];
    xKhigh2mass=[xKhigh2mass; data.Wm];
cd ..

cd Khigh_hand_2mass3
    data = estimate();
    xi1=[xi1; data.xi];
    xKhigh2mass=[xKhigh2mass; data.Wm];
cd ..
%%
xi2=[];
cd Kmed_hand_Nomass
    data = estimate();
    xi2=[xi2; data.xi];
    xKmedNomass=[xKmedNomass; data.Wm];
cd ..

cd Kmed_hand_Nomass2
    data = estimate();
    xi2=[xi2; data.xi];
    xKmedNomass=[xKmedNomass; data.Wm];
cd ..

cd Kmed_hand_Nomass3
    data = estimate();
    xi2=[xi2; data.xi];
    xKmedNomass=[xKmedNomass; data.Wm];
cd ..

cd Kmed_hand_2mass
    data = estimate();
    xi2=[xi2; data.xi];
    xKmed2mass=[xKmed2mass; data.Wm];
cd ..

cd Kmed_hand_2mass2
    data = estimate();
    xi2=[xi2; data.xi];
    xKmed2mass=[xKmed2mass; data.Wm];
cd ..

cd Kmed_hand_2mass3
    data = estimate();
    xi2=[xi2; data.xi];
    xKmed2mass=[xKmed2mass; data.Wm];
cd ..
%%
xi3=[];
cd Klow_hand_Nomass
    data = estimate();
    xi3=[xi3; data.xi];
    xKlowNomass=[xKlowNomass; data.Wm];
cd ..

cd Klow_hand_Nomass2
    data = estimate();
    xi3=[xi3; data.xi];
    xKlowNomass=[xKlowNomass; data.Wm];
cd ..

cd Klow_hand_Nomass3
    data = estimate();
    
    xi3=[xi3; data.xi];
    xKlowNomass=[xKlowNomass;data.Wm];
cd ..

cd Klow_hand_2mass
    data = estimate();
    xi3=[xi3; data.xi];
    xKlow2mass=[xKlow2mass; data.Wm];
cd ..

cd Klow_hand_2mass2
    data = estimate();
    xi3=[xi3; data.xi];
    xKlow2mass=[xKlow2mass; data.Wm];
cd ..

cd Klow_hand_2mass3
    data = estimate();
    
    xi3=[xi3; data.xi];
    xKlow2mass=[xKlow2mass; data.Wm];
cd ..
%xi
end
