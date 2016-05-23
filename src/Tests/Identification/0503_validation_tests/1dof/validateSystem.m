%%validation tests motor
function [] = validateSystem()

% 
 cd KmNoM
    c(1)=testDirectory(sysBuilder(0,'m'));
cd ..
disp('----------------')

cd Km2M
    c(2)=testDirectory(sysBuilder(2,'m'));
cd ..
disp('----------------')
cd KlNoM
    c(3)=testDirectory(sysBuilder(0,'l'));
cd ..
disp('----------------')
cd Kl2M
    c(4)=testDirectory(sysBuilder(2,'l'));

cd ..
disp('----------------')
cd KhNoM
   c(5)=testDirectory(sysBuilder(0,'h'));
cd ..
disp('----------------')
cd Kh2M
    c(6)=testDirectory(sysBuilder(2,'h'));
cd ..
    mean(c)
    std(c)


end

function c = testDirectory(sys)
    [t,i,x,v]=reads();
    y1 = lsim(sys, v, t);
    y1=y1(:,2);
    c = costFunction(y1,x)

     figure;
     plot(t,x);hold on; plot(t,y1);
     grid; xlabel('Time [s]'); ylabel('Displacement [cm]');
     title('System validation');
     legend('Real displacement', 'Simulated Displacement');
end