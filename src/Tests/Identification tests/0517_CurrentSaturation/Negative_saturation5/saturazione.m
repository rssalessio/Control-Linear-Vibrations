clear
close all

[t,r,v,i,x]=reads();


M = tf([1],[0.0024 1.3]);


y1 = lsim(M, v, t);
y2 = lsim(M, gainNonLinear(v),t);

figure;
plot(t,y1);hold on;
plot(t,y2); plot(t,i);
grid;
legend('y1','y2','i');

    [t,ref,v,i,x]=reads();
    plot(t,i);
    down12 = mean(i(t>7&t<30));
    sigma_down = var (i(t>7&t<30));
    figure;plot(i(t>7&t<30));

