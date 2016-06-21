
[t,v,i,x]=reads();
sim('deadzone_sim');
figure;

plot(t,i); hold on; plot(i1); hold on;
plot(i2);
legend('real','i1','i2');
figure;
plot(err1.Time, abs(err1.Data));hold on; plot(err3.Time, abs(err3.Data)); hold on; plot(err2.Time, abs(err2.Data));


grid;
legend('Abs. Value of Error with no deadzone','Abs value of error with c=0.35', 'Abs value of error with c=0.46');
xlabel('Time [s]'); ylabel('Current [A]'); title('Error model comparison');

 x = fsolve(@minDeadzone,[0;0],optimoptions('fsolve','Display','iter'))
 
 
 Options = gaoptimset('Display','iter',... %display every iteration
'Generations',70,... %maximum number of generations is 70
'TolFun',1,... %tolerance for optimisation is 1
'TolCon',1,...
'PlotFcns',@gaplotbestf);
ObjectiveFunction = @minDeadzone;
nvars = 2;    % Number of variables
LB = [0.1 0.1];   % Lower bound
UB = [1 1];  % Upper bound
[x,fval] = ga(ObjectiveFunction,nvars,[],[],[],[],LB,UB,[],[],Options)
