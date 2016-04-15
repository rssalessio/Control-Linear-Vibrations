function [gamma] = estimateGamma()

    gamma=zeros(6,1);

    cd pulse_kbig_2mass/
        gamma(1) = estimate();
    cd ..

    cd pulse_kbig_nomass/
        gamma(2) = estimate();
    cd ..
    cd pulse_klow_2mass/ 
       gamma(3) = estimate();
    cd ..
    cd pulse_klow_nomass/
      gamma(4) = estimate();
    cd ..
    cd pulse_kmed_2mass/
       gamma(5) = estimate();
    cd ..
    cd pulse_kmed_nomass/
         gamma(6) = estimate();
    cd ..



end

function [gamma] = estimate()

    [t,v,i,x]=reads();
    x=x./560;
    i = lowPassFilter(i, 15, 4, 0, 1/200);
    i1 = find(abs(i)>0.1,1)-1;
    i2 = 0;


    i(1:i1)=0;
    v(1:i1)=0;
    x(1:i1)=0;


    x=x(abs(v)>0);
    i=i(abs(v)>0);
    
    

     vel=diff(x);vel(end+1)=1;
     x=x(vel==0);
     i=i(vel==0);
    


    % x = lowPassFilter(x, 1, 4, 0, 1/200);
    % i= lowPassFilter(i, 1, 4, 0, 1/200);
    % 
    % figure;
    % plot(i);hold on;
    % plot(x);

    k1=x./i;
    k2 =i./x;
    
    figure;subplot(211); plot(k1); subplot(212); plot(k2);
    a=mean(k1);
    b=mean(k2);

    gamma = (a+1/b)/2;
end