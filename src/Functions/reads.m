function [t, s1,s2,s3,s4,s5,s6] = reads(Ts)
    
    if nargin == 0
        Ts=1/200;
    end
    
    i = 0;
    nZeros = 4;
    format = '.txt';
    s1=[]; s2=[];s3=[];s4=[];s5=[]; s6=[];
    
    while 1
        str = getName(i,nZeros,format);
        if (~exist(str, 'file'))
            break;
        end
        [st1, st2, st3, st4, st5, st6] = textread(str, '%f %f %f %f %f %f');
        s1=[s1;st1]; s2=[s2;st2]; s3=[s3;st3]; s4=[s4;st4]; s5=[s5;st5]; s6=[s6;st6];
        i=i+1;
    end
    len = length(s1)-1;    
    
    t = 0:Ts:len*Ts;
    t=t';
    
end

function str= getName(i, nZeros, format)
    orderI = floor(log10(i+1));
    str='';
    for k=1:nZeros-orderI-1
        str=strcat(str, '0');
    end
    str = strcat(str, num2str(i));
    str = strcat(str, format);
    str = strcat('data', str);
end