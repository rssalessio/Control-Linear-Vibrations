[t,i,v,x]= reads();

x=x./560;


index = abs(x) < 2;

t=t(index);
t=t-t(1);
x=x(index);
i=i(index);
v=v(index);




grid;

M= tf([1], [0.0024, 1.3]);
D=deadzone([-0.36,0.36]);
v=evaluate(D,v);
y = lsim(M, gainNonLinear(v), t);
figure;
plot(t,i); hold on; plot(t,y);
xlabel('Time [s]');
ylabel('Current [A]');
title('Current'); legend('Measured current','Estimated current');
grid;

figure;
plot(t,x);
grid;
xlabel('Time [s]');
ylabel('Cart position [cm]');
title('Cart position');
