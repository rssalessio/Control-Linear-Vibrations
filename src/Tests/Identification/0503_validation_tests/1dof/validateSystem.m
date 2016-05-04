%%validation tests motor
function [] = validateSystem()

%motor
R = 1.3;%resistance 
L = 0.0220; %inductance 
Ke = -1.0000e+05/560; %electric stiffness and torque constant


%carts and load
M = 1.35;
Mc=M-0.496*2;

Ch = 9; %spring damping
Cm = 6; 
Cl = 8;

Kh = 625; %Stiffness high
Km = 281; %Stiffness Med
Kl = 162; %Stifness low

cd KmNoM
    c(1)=testDirectory(sysBuilder(R,L,Ke,Mc,Cm,Km));
cd ..


cd Km2M
    c(2)=testDirectory(sysBuilder(R,L,Ke,M,Cm,Km));
cd ..

cd KlNoM
    c(3)=testDirectory(sysBuilder(R,L,Ke,Mc,Cl,Kl));
cd ..

cd Kl2M
    c(4)=testDirectory(sysBuilder(R,L,Ke,M,Cl,Kl));

cd ..

cd KhNoM
   c(5)=testDirectory(sysBuilder(R,L,Ke,Mc,Ch,Kh));
cd ..

cd Kh2M
    c(6)=testDirectory(sysBuilder(R,L,Ke,M,Ch,Kh));
cd ..
    mean(c)
    std(c)


end

function c = testDirectory(sys1)
    [t,i,x,v]=reads();
    y1 = lsim(sys1, v, t);
    c = costFunction(y1,x)
    figure;
    plot(t,x);hold on; plot(t,y1);
    grid; xlabel('Time [s]'); ylabel('Displacement [cm]');
    title('System validation');
    legend('Real displacement', 'Simulated Displacement');
end