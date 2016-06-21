sys=sysBuilder(2,'l');

sys=sys.NominalValue;
close all;
figure;
bode(sys);

z1 = -2.5+10.47i;
z2 = -2.5-10.47i;
p1=-200;
p2=0;
gain=-5;
controller = zpk([z1,z2],[p1,p2],gain);

figure;
margin(sys*controller);

figure;
nyquist(sys*controller);