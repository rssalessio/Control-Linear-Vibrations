[t,v,I_real]=reads();

M = tf([1],[0.0024 1.3]);


close all;

I_real = I_real(v >0 & v  <5);
v = v(v>0 & v  <5);
t = t(v>0 & v  <5);
I_ideal = lsim(M, v, t);

 k=zeros(length(t),1);
for i=1:84
    if(i<84)
        k(1+5*(i-1)*200+200*3: 5*i*200) = mean( I_real(1+5*(i-1)*200+3*200: 5*i*200));
        
        k(1+5*(i-1)*200:5*(i-1)*200+200*3)=k(1+5*(i-1)*200+200*3);
        I_real(1+5*(i-1)*200:5*(i-1)*200+200*3)=k(1+5*(i-1)*200+200*3);
        
    else
        k(1+5*(i-1)*200+200*3: end) = mean( I_real(1+5*(i-1)*200+3*200: end));
        k(1+5*(i-1)*200: 5*(i-1)*200+200*3)= k(1+5*(i-1)*200+200*3);
        I_real(1+5*(i-1)*200: 5*(i-1)*200+200*3)=k(1+5*(i-1)*200+200*3);
    end
end

figure;
plot(t,k); hold on; plot(t,I_real);

index = k  < 0.14;
k(index) = k(index)./k(index) * 0.6091;

index = k  < 0.32;
k(index) = k(index)./k(index) * 0.6091;

%
%   g(v)*i_ideal = i_real
%   
figure;
plot(t, I_real./I_ideal);


%g(v) seems quadratic, we can try with g(v)=bv+v^2 

X= [ I_ideal, v.*I_ideal, (v.^2).*I_ideal, (v.^3).*I_ideal];
Y= k;

theta = inv(X'*X)*X'*Y;


I_sim = I_ideal .* (theta(1)+ theta(2).*v +theta(3).* (v.^2)+theta(4).*(v.^3));
figure;
plot(t, k); hold on; plot(t, I_sim);
