function r = relativeErr(ref,y)
    k = abs(ref-y);
    
    r = max(k)/max(abs(ref));

end