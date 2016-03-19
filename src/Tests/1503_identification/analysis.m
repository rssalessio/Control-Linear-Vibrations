Ts = 1/100;
N = length(u);
t = 0:Ts:N*Ts-Ts;

figure;subplot 211;
plot(t,u); hold on; plot(t,i); hold on; grid;

subplot 212;
plot(t,u); hold on; plot(t,x); hold on; grid;

index = t<9.59;
uDat = u(index);
iDat = i(index);
xDat = x(index);
figure;subplot 211;
plot(t(index),uDat); hold on; plot(t(index),iDat); hold on; grid;

subplot 212;
plot(t(index),uDat); hold on; plot(t(index),xDat); hold on; grid;

dat = iddata(iDat,uDat,Ts);
G1i = tfest(dat, 1);
G2i = tfest(dat, 2);
G3i = tfest(dat, 3);

dat = iddata(xDat,uDat,Ts);
G1x = tfest(dat, 1);
G2x = tfest(dat, 2);
G3x = tfest(dat, 3);

%%
figure;
plot(t(index),lsim(G3x, uDat, t(index)));
hold on
plot(t(index), xDat)
hold on ; grid;
legend('sim', 'real');
%%
 rumore = idat2;
trumore = tind2;
plot(trumore, rumore)
%%
s= tf('s');
filtro = 100/(s+10)^2;
figure;
plot(trumore, lsim(filtro, rumore, trumore)); hold on;
plot(trumore, rumore); hold on; grid; legend('filtered', 'orig');


%%

notchf = ((s/w)^2+1)/(s/10000+1)^3;
yf = lsim(notchf, rumore2, trumore);
figure;
plot(trumore, rumore2- yf); grid;hold on;
plot(trumore, rumore2);

%%
temp = asin(i2);