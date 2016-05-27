
[t,i]=reads();
xlabel('Time [s]'); ylabel('Current [A]'); title('Motor current test');
index1 = 1:5*200;
index2 = 10.5*200:14*200;
index3 = 15.5*200:19.5*200;
index4 = 20.5*200:24.5*200;
index5 = 25.5*200:29*200;     
index6 = 31*200:34*200;     


m= [mean(i(index1));
    mean(i(index2));
    mean(i(index3));
    mean(i(index4));
    mean(i(index5));
    mean(i(index6))];
v = [var(i(index1));
    var(i(index2));
    var(i(index3));
    var(i(index4));
    var(i(index5));
    var(i(index6))];
a1=v(1);
vd=v-v(1);
A= [m];

alpha=inv(A'*A) *A'*vd;
y=a1+alpha*m;
figure;
plot(m,v); hold on; plot(m, y); legend('real','estimated');
xlabel('Current [A]');
ylabel('Variance sensor noise');
title('Variance sensor noise');

T=max(abs(m));
a1-alpha*T/2