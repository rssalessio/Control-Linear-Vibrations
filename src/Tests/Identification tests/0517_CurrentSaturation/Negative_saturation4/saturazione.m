clear
close all

    [t,ref,v,i,x]=reads();
    plot(t,i);
    down12 = mean(i(t>8&t<35));
    sigma_down = var (i(t>8&t<35));
    figure;plot(i(t>8&t<35));

