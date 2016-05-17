clear
close all

    [t,ref,v,i,x]=reads();
    plot(t,i);
    down12 = mean(i(t>7&t<30));
    sigma_down = var (i(t>7&t<30));
    figure;plot(i(t>7&t<30));

