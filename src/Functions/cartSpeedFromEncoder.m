function  [v1,v2] = cartSpeedFromEncoder(data,Ts)
%   CARTSPEEDFROMENCODER - differentiate and lowpass filter the data.
%   Cutoff frequency 50Hz, 2nd order filter
    if (nargin==1)
        Ts=1/200;
    end
    v1 = diff(data)./(Ts);
    v1(end+1)=v1(end);
    v2=lowPassFilter(v1, 50, 2, 0, Ts);
    
    s=tf('s');
    G= s * (2*pi*30)/(s+2*pi*30);
    temp = 0:Ts:(length(data)-1)*Ts;
    v1 = lsim(G,data, temp);
    v1 = lowPassFilter(v1,50,2,0,Ts);
end