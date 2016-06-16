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
c=[];
cd KmNoM
    c=[c;testDirectory(G)];
cd ..


cd Km2M
   c=[c;testDirectory(G)];
cd ..

cd KlNoM
    c=[c;testDirectory(G)];
cd ..

cd Kl2M
    c=[c;testDirectory(G)];

cd ..

cd KhNoM
    c=[c;testDirectory(G)];
cd ..

cd Kh2M
   c=[c;testDirectory(G)];
cd ..

disp(['Mean: ', num2str(mean(c)), ' - STD: ', num2str(std(c))]);


end

function c = testDirectory(sys1)
    [t,i,x,v]=reads();
%    y1 = lsim(sys1, gainNonLinear(v), t);
    y1 = lsim(sys1, v, t);
    c = costFunction(y1,i);
    g = relativeErr(i,y1);
    c=[c,g];

%     figure;
%     plot(t,i);hold on; plot(t,y1);hold on; plot(t,y2);
%     grid; xlabel('Time [s]'); ylabel('Current [A]');
%     title('Current validation');
%     legend('Real current', 'Simulated current w/ g(v)', 'Simulated current w/out g(v)');
end