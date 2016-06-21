
obs=kalmanObserver([0,2,1],['h','l','m'],{'i'});

[t,ir,ik,x1k,x1r,x2k,x2r] = reads();
figure;
subplot(221);
plot(t,x2k); hold on; plot(t,x2r);



grid;
xlabel('Time [s]');
ylabel('Current [A]');
title('Kalman: $i$ estimation using $x_1$', 'interpreter','latex');
legend('i estimated', 'i real ', 'interpreter','latex');
disp('cost function: ')
costFunction(x2r,x2k)

disp('relative infty error: ')
max(abs(x2r-x2k))/max(abs(x2r))

disp('Min svd :') 
0.16242