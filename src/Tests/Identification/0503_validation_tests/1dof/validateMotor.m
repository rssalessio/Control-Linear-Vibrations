%%validation tests motor
function [] = validateMotor()

R=1.2689;
L = 0.0024;

G = tf([1],[L R]);
c=zeros(6,1);
% pole(G)
% dcgain(G)

cd KmNoM
    c(1)=testDirectory(G);
cd ..


cd Km2M
    c(2)=testDirectory(G);
cd ..

cd KlNoM
    c(3)=testDirectory(G);
cd ..

cd Kl2M
    c(4)=testDirectory(G);

cd ..

cd KhNoM
    c(5)=testDirectory(G);
cd ..

cd Kh2M
    c(6)=testDirectory(G);
cd ..
    mean(c)
    std(c)


end

function c = testDirectory(sys1)
    [t,i,x,v]=reads();
    y1 = lsim(sys1, v, t);
    c = costFunction(y1,i);
    figure;
    plot(t,i);hold on; plot(t,y1);
    grid; xlabel('Time [s]'); ylabel('Current [A]');
    title('Current validation');
    legend('Real current', 'Simulated current');
    
    dat= iddata(i,v,1/200);
    g = tfest(dat, 3);
    y2 = lsim(g,v,t);
    c=costFunction(y2,i);
end