close all;

EQ = @(a,b,w,c, x) ...
    a.*exp(-b*w*x).*sin(w*sqrt(1-b^2)*x+c);

AlgometryEffect = fit( tn,xn, EQ, ...
    'StartPoint', [400, 0.1, 20, 0.8], ...
    'Lower', [0, 0,15,0], ...
    'Upper', [600, 0.5, 25, 10], ...
    'Robust', 'LAR' )
plot( AlgometryEffect,tn,xn)