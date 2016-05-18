%%validation tests motor
function [] = validateSystem()

%motor
R = 1.2689;
L = 0.0024;
Gamma=-206.8;
Mc = 0.8840;
Ml = 0.493;
Km=321.7;
Kh=706.2;
Kl=226;

ChL =9.912;
ChNL = 7.7739;
CmL = 9.5963;
CmNL = 8.040;
ClL = 9.9788;
ClNL = 9.2761;

% 
%  cd KhKm-1M-1M
%     c(1)=testDirectory(sysBuilder2DOF(R,L,Gamma,Mc+Ml,C,K1,M2,C2,K2));
% cd ..


cd KhKm-noM-2M
    c(2)=testDirectory(sysBuilder2DOF(R,L,Gamma,Mc,ChNL,Kh,Mc+2*Ml,CmL,Km));
cd ..

cd KhKm-noM-noM
    c(3)=testDirectory(sysBuilder2DOF(R,L,Gamma,Mc,ChNL,Kh,Mc,CmNL,Km));
cd ..
    
% cd KlKh-1M-2M
%     c(4)=testDirectory(sysBuilder(R,L,Gamma,M,ClL,Kl));
% 
% cd ..

cd KlKh-noM-2M
   c(5)=testDirectory(sysBuilder2DOF(R,L,Gamma,Mc,ClNL,Kl,Mc+2*Ml,ChL,Kh));
cd ..

cd KlKh-noM-noM
    c(6)=testDirectory(sysBuilder2DOF(R,L,Gamma,Mc,ClNL,Kl,Mc,ChNL,Kh));
cd ..
    mean(c)
    std(c)


end

function c = testDirectory(sys)
     [t,i,x1,x2,v]=reads();
     y1 = lsim(sys, v, t);
     c1 = costFunction(y1(:,2),x1)
     c2 = costFunction(y1(:,3),x2)
     figure;
     plot(t,x1);hold on; plot(t,y1(:,2));
     grid; xlabel('Time [s]'); ylabel('Displacement [cm]');
     title('System validation');
     legend('Real displacement', 'Simulated Displacement');
     
     figure;
     plot(t,x2);hold on; plot(t,y1(:,3));
     grid; xlabel('Time [s]'); ylabel('Displacement [cm]');
     title('System validation');
     legend('Real displacement', 'Simulated Displacement');
     c=mean([c1,c2]);
end