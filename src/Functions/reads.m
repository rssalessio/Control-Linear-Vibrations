function [t, s1,s2,s3,s4,s5,s6] = reads(file)
    
    [s1, s2, s3, s4, s5, s6] = textread(file, '%f %f %f %f %f %f');
    
    ts = 1/100; %sampling frequency 100Hz
    t = 0:ts:(length(s1)-1)*ts;
    
end