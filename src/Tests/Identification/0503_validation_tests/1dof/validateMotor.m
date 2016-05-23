%%validation tests motor
function [] = validateMotor()

%valori alessio
disp(['R: 1.2689 - L: 0.0024']);
R=1.3;
L = 0.0024;


%valori gian
% disp(['R: 1.3 - L: 0.0220']);
% R = 1.3;
% L = 0.0220; 

G = tf([1],[L R]);
c=zeros(6,1);

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

disp(['Mean: ', num2str(mean(c)), ' - STD: ', num2str(std(c))]);


end

function c = testDirectory(sys1)
    [t,i,x,v]=reads();
    y1 = lsim(sys1, v, t);
    c = costFunction(y1(:,2),x);

    figure;
    plot(t,i);hold on; plot(t,y1); hold on; plot (t,v);
    grid; xlabel('Time [s]'); ylabel('Current [A]');
    title('Current validation');
    legend('Real current', 'Simulated current');
end