[t,v,i,x]=reads();

t=t(16.15*200:17.39*200);
i=i(16.15*200:17.39*200);

t=t-t(1);

figure;
plot(t,i);
grid;
xlabel('Time [s]');
ylabel('Current [A]');
title('Current sensor signal at steady state');

figure;
hist(i-mean(i),20); grid; title('Histogram of the current sensor signal at steady state')

[m,p,f] = fourierCoefficients(i-mean(i),1/200);
index = f < 100;
figure;
plot(f(index), m(index)); grid;
xlabel('Frequency [Hz]');
ylabel('Module');
title('FFT of the current sensor signal');
