%%validation tests motor
function [] = validateSystem()
clc; clear all; close all;
c=[];
  cd KhKm-1M-1M
     c=[c;testDirectory(sysBuilder([1,1],['h','m']))];
 cd ..


cd KhKm-noM-2M
    c=[c;testDirectory(sysBuilder([0,2],['h','m']))];
cd ..

cd KhKm-noM-noM
    c=[c;testDirectory(sysBuilder([0,0],['h','m']))];
cd ..
    
 cd KlKh-1M-2M
    c=[c;testDirectory(sysBuilder([1,2],['l','h']))];
 
 cd ..

cd KlKh-noM-2M
   c=[c;testDirectory(sysBuilder([0,2],['l','h']))];
cd ..

cd KlKh-noM-noM
    c=[c;testDirectory(sysBuilder([0,0],['l','h']))];
cd ..
    mean(c)
    std(c)


end

function [c] = testDirectory(sys)
format long
     [t,i,x1,x2,v]=reads();
     y1 = lsim(sys, v, t);
     c1 = costFunction(y1(:,2),x1)
     c2 = costFunction(y1(:,3),x2)

    % disp('sys')
     %pole(t1)
     %zero(t1)
    % dcgain(t1)
     %disp('sys2')
     %figure;
     %plot(t,x1);hold on; plot(t,y1(:,2));
     %grid; xlabel('Time [s]'); ylabel('Displacement [cm]');
     %title('System validation');
     %legend('Real displacement', 'Simulated Displacement');
 %    dat=iddata(x2,v,1/200);
    % sys2=tfest(dat,5,1);
    % t2=sys2;
    % pole(t2)
    % zero(t2)
    % dcgain(t2)
   %  figure;
    % bode(t1); hold on; bode(t2); legend('mine','matlab')
    %figure;plot(t,i);
     figure;
    plot(t,x2);hold on; plot(t,y1(:,3));
    grid; xlabel('Time [s]'); ylabel('Displacement [cm]');
    title('System validation');
    legend('Real displacement', 'Simulated Displacement');
c=[c1,c2];
     
end