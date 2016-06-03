clear
close all
% cd Saturazione_dcbus6
%     [t,v,i,x]=reads();
%     up6 = max(i);
%     down6 = mean(i(i<-4.5));
%     figure;plot(i(i<-4.5));
% cd ..

cd Saturazione_dcbus12
    [t,v,i,x]=reads();
    up12 = max(i);
    sigma_up = var (i);    
    figure;plot(i);
    xlabel('Time [s]'); ylabel('Current [A]'); title('Positive maximum current');
    down12 = mean(i(i<-10.5));
    sigma_down = var (i(i<-10.5));
    figure;plot(i(i<-10.5));
    xlabel('Time [s]'); ylabel('Current [A]'); title('Negative maximum current');
cd ..

% cd Saturazione_dcbus24
%     [t,v,i,x]=reads();
%     up24 = max(i);
%     down24 = mean(i(i<-5));
%     figure;plot(i(i<-5));
% cd ..