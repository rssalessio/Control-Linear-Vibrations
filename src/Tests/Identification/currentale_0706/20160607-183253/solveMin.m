%function J = solveMin(x)

    M = tf([1],[0.0024, 1.3]);
    [t,ir,ik]=reads();
    v=zeros(size(t));
    k=-1;
    b=1;
    for i=1:10
        if (i<=5 )
            
            j=b;
            b=b+1;
        else
            b=0;
            j=k;
            k=k-1;
        end
        v(5*200+1+(i-1)*5*200:5*200+5*200*i)=j;
    end
    v(55*200+1:105*200) = v(5*200+1:55*200);
    v(105*200+1:end) = v(5*200+1:9991);
    close all;
    
    index1=v<0;
    index2 = v>0;
  
    id = lsim(M,v,t);
    k=zeros(length(t),1);
    for i=1:30
        if(i<30)
        k(1+5*(i-1)*200+200*3: 5*i*200) = mean( ir(1+5*(i-1)*200+3*200: 5*i*200));
        k(1+5*(i-1)*200:5*(i-1)*200+200*3)=k(1+5*(i-1)*200+200*3);
        else
        k(1+5*(i-1)*200+200*3: end) = mean( ir(1+5*(i-1)*200+3*200: end));
        k(1+5*(i-1)*200: 5*(i-1)*200+200*3)= k(1+5*(i-1)*200+200*3);
        end
    end
    v1=v(index1);
    id1=id(index1);
    k1=k(index1);
    X=[(v1).*id1, (v1.^2).*id1,(v1.^3).*id1];
    
    theta1 = [0;inv(X'*X)*X'*k1];
    
    v1=v(index2);
    id1=id(index2);
    k1=k(index2);
    X=[(v1).*id1, (v1.^2).*id1,(v1.^3).*id1];
    
    theta2 = [0;inv(X'*X)*X'*k1];
    
    k1 = theta1(1)+theta1(2).*v(index1)+theta1(3).*(v(index1).^2)+theta1(4).*(v(index1).^3);
    k2 =theta2(1)+theta2(2).*v(index2)+theta2(3).*(v(index2).^2)+theta2(4).*(v(index2).^3);
    v(index1)= v(index1).*k1;
    v(index2)=v(index2).*k2;
    id = lsim(M,v,t);
    figure; plot(t, ir);hold on; plot(t,id ); hold on; plot(t,k);
    legend('ir','id','k');
    figure;
    v=-5:0.1:0;
    plot(v, theta1(1)+theta1(2)*v +theta1(3).*(v.^2)+ theta1(4).*(v.^3));
    hold on;
    v=0:0.1:5;
    plot(v, theta2(1)+theta2(2)*v+theta2(3).*(v.^2)+ theta2(4).*(v.^3));
    grid
    
    
    
%end