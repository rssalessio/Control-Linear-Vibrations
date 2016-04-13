Ts=1/100;
t = 0:Ts:length(u)*Ts-Ts;
t2 = t(i>2);
i2 = i(i>2);
i2 = i2-mean(i2);
[m,p,f] = fourierCoefficients(i2, t2(end)-t2(1));
[a,b]= max(m);
1/f(b)
%%
w1 = f(b)*2*pi;
w2 = f(b)*4*pi;
t3 = 0:Ts:3-Ts;
notchf =1/(s/30+1)^3;
yf = lsim(notchf, i, t);
figure;
plot(t, i); grid;hold on;
plot(t, yf);


%%