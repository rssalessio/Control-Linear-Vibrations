function [data] = estimate()
    [~,x] = reads(1);
    [k,a]=findpeaks(x);
    Wm = 2*pi*200./diff(a(2:3));
    
    
    
    
    
    [k,a]=findpeaks(-x);
    a = 2*pi*200./diff(a(2:3));
    Wm = [Wm; a];
    
    
    xi=estimateDampingRatio(x);
    field1 = 'Wm'; data1=Wm;
    field2 = 'xi'; data2=xi;
    
    data = struct(field1,data1,field2,data2);
    
end