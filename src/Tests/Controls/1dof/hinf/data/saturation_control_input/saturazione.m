clear
close all

    [t,ref,v,i,x]=reads();
    plot(t,i);
    down12 = mean(i(i<-4.8));
    sigma_down = var (i(i<-4.8));
    figure;plot(i(i<-4.8));

