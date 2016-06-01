function F = minDeadzone(c)
    [t,v,i,x]=reads();
    options = simset('SrcWorkspace','current');

    a=c(1);
    b=c(2);
    if (b < a)
        F = Inf;
    else
        sim('deadzone_sim',[],options);
        F=0.5*sum(err2.Data.^2);
    end
end
    
    
