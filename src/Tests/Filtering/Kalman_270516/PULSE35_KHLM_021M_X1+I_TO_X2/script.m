

kalmanObserver([0,2,1],['h','l','m'],{'x1','i'})
[t,x2k, x2r] = reads();
figure;
plot(t,x2k); hold on; plot(t,x2r);
grid;
xlabel('Time [s]');
ylabel('Position [cm]');
title('Kalman: $x_2$ estimation using $x_1$, $i$', 'interpreter','latex');
legend('x_2 estimated', 'x_2 real position', 'interpreter','latex');
disp('cost function: ')
costFunction(x2r,x2k)

disp('relative infty error: ')
max(abs(x2r-x2k))/max(abs(x2r))

disp('Min svd :') 
0.16242