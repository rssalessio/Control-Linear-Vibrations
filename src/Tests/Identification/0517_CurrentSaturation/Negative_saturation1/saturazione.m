clear
close all

    [t,ref,v,i,x]=reads();
    plot(t,i);
    down12 = mean(i(t>25&t<51));
    sigma_down = var (i(t>25&t<51));
    figure;plot(i(t>25&t<51));

