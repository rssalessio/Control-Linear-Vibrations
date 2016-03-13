t=[3.016,3.132,3.265,3.398,3.531,3.665,3.779,3.9,4.033,4.165];
x=[-1,2.5,-0.15,1.8,0.35,1.5,0.7,1.15,0.85,1];
close all;
u = ones(size(t));
Ts = diff(t);
Ts = sum(Ts)/length(Ts);
uest= [zeros(1,20), u];
xest = [-1*ones(1,20), x];
dat = iddata(xest',uest', Ts);
G= tfest(dat, 4);
figure;
bode(G);
grid;


index = 1:1:length(t);
% we have a peak every even index

figure;
subplot(211);
plot(t,x); grid; xlabel('sec'); ylabel('cm'); title('Cart displacement estimation');
K=450;

tEven = t(logical(mod(index+1,2))); 
tNEven = t(logical(mod(index,2)));
xEven = x(logical(mod(index+1,2)));
xNEven = logical(mod(index,2));

sigma=5/(4.165-t(1));


disp('Sinusoid estimation');


T = [diff(tEven), diff(tNEven)];
omega = 2*pi/(sum(T)/length(T));
hold on;
plot(t, 1+sin(omega*t));

legend('Displacement', 'Estimated oscillation');

disp('---------')
disp('Exponential estimation');

xTemp = x(2:end-1);
xTemp = xTemp -ones(size(xTemp));
xTemp = xTemp./ sin(omega*t(2:end-1));
xTemp = log(xTemp);
A = [ ones(length(xTemp),1), t(2:end-1)'];

theta = (A'*A)\A'*xTemp';
hold on;
plot(t, 1+exp(theta(2)*t+theta(1)));
legend('Displacement', 'Estimated sinusoid','Estimated exponential');

%
disp('-------');
disp('Estimated response');
hold on;
subplot(212);
plot(t,x); grid;hold on;
plot(t, 1+exp(theta(2)*t+theta(1)).*sin(omega*t));
legend('Displacement', 'Estimated response (1+exp*sin)');
xlabel('sec'); ylabel('cm');
%

a = theta(1);
b = theta(2);
t0=t(1);
t = t-t(1);
figure;
plot(t,x); hold on;
tNew = t(1):0.0001:t(end);
plot(tNew, 1+exp(b*tNew+t0*b+a).*sin(omega*tNew+t0*omega));
grid;
xlabel('s');ylabel('cm');title('Displacement and estimated displacement');
legend('Displacement', 'Estimated response (1+exp*sin)');

disp('------');
disp('Parameters estimated');

csi = 1/sqrt((omega/sigma)^2+1);
w0= sigma/csi;
disp(['System settling time: ', num2str(5/sigma)]);
disp(['Csi: ', num2str(csi)]);
disp(['W0: ', num2str(w0)]);
disp(['Peak in w0*sqrt(1-csi^2): ', num2str(w0*sqrt(1-csi^2))]);
disp('------');
disp('Mass estimation');

M = (K/(4*pi^2)).*(T.^2);
meanM = sum(M)/length(M);
varianceM= sum((M-meanM*ones(size(M))).^2)/length(M);
sigmaM = sqrt(varianceM);

disp(['Average Mass estimated kart+load: ', num2str(meanM)]);
disp(['Variance: ', num2str(varianceM), ' - Sd: ', num2str(sigmaM)]);
disp(['The Mass cart+load is between: [', num2str(meanM-3*sigmaM), ',', num2str(meanM+3*sigmaM), '] with Probability 99.7']);
    


