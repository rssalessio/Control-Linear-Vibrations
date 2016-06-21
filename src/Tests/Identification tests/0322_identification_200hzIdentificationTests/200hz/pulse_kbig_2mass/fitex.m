[t,v,i,x]=reads();
close all;

x = x(x>mean(x));

[a,b]=findpeaks(x);
b=b(3:end);

Ts=1/200;
z=3;
tn = zeros(z, 350);
xn=zeros(z,350);

for i=1:z
    k=(3)*(i-1)+1;
    tn(i,:) = Ts*(0:349);
    xn(i,:) = x(b(k):b(k)+349)';
    xn(i,:) = xn(i,:)-mean(xn(i,:));
end



EQ = @(a,w,b, x) ...
    a.*exp(-b*w*x).*cos(w*x);
omega =zeros(z,1);
xi = zeros(z,1);
for i=1:z

AlgometryEffect = fit( tn(i,:)',xn(i,:)', EQ, ...
    'StartPoint', [xn(i,1),20, 0.1], ...
    'Lower', [xn(i,1), 5, 0], ...
    'Upper', [xn(i,1), 35, 0.5], ...
    'Robust', 'off' )
figure;
plot(AlgometryEffect,tn(i,:)', xn(i,:)');

omega(i)= AlgometryEffect.w;
xi(i) = AlgometryEffect.b;

end

mean(omega)
std(omega)

mean(xi)
std(xi)


