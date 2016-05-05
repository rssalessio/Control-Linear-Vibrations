%%validation tests motor
function [] = validateSystem()

%motor
R = 1.2689;
L = 0.0024;
Gamma=-206.8;
Mc = 0.8840;
M = Mc+0.493*2;
Km=321.7;
Kh=706.2;
Kl=226;

ChL =9.912;
ChNL = 7.7739;
CmL = 9.5963;
CmNL = 8.040;
ClL = 9.9788;
ClNL = 9.2761;

% R = 1.3;%resistance 
% L = 0.0220; %inductance 
% Gamma = -1.0000e+05; %electric stiffness and torque constant
% 
% s = tf('s');
% 
% %carts and load
% M = 1.35;
% Mc=M-0.493*2;
% 
% %spring
% ChL = 9; %spring damping
% ChNL=ChL;
% CmL = 6; 
% CmNL= CmL;
% ClL = 8;
% ClNL = ClL;
% 
% Kh = 625; %Stiffness high
% Km = 281; %Stiffness Med
% Kl = 162; %Stifness low
% 
 cd KmNoM
    c(1)=testDirectory(sysBuilder(R,L,Gamma,Mc,CmNL,Km));
cd ..


cd Km2M
    c(2)=testDirectory(sysBuilder(R,L,Gamma,M,CmL,Km));
cd ..

cd KlNoM
    c(3)=testDirectory(sysBuilder(R,L,Gamma,Mc,ClNL,Kl));
cd ..

cd Kl2M
    c(4)=testDirectory(sysBuilder(R,L,Gamma,M,ClL,Kl));

cd ..

cd KhNoM
   c(5)=testDirectory(sysBuilder(R,L,Gamma,Mc,ChNL,Kh));
cd ..

cd Kh2M
    c(6)=testDirectory(sysBuilder(R,L,Gamma,M,ChL,Kh));
cd ..
    mean(c)
    std(c)


end

function c = testDirectory(sys1)
    [t,i,x,v]=reads();
    x=x;
    y1 = lsim(sys1, v, t);
    c = costFunction(y1,x)
     figure;
     plot(t,x);hold on; plot(t,y1);
     grid; xlabel('Time [s]'); ylabel('Displacement [cm]');
     title('System validation');
     legend('Real displacement', 'Simulated Displacement');
end