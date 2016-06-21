clear
close all

    [t,ref,v,i,x]=reads();
    plot(t,i);
    down12 = mean(i(t>15&t<40));
    sigma_down = var (i(t>15&t<40));
    figure;plot(i(t>15&t<40));

