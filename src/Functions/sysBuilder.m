function [sysSS,nDOF,bemfTf] = sysBuilder( nLoad, springType, Outputs,bemfOn)
%
% Eg: sysBuilder([1,2], ['l','h'], {'i','x1'} defines a system with two
% carts. the first one with1  load of 0.493kg, the second one with a  load
% of 2*0.493kg. The first spring is Kl. The second one is Kh. The outputs
% of the system (the sensors) are the current and the position of the first
% cart
% sensors available: i, x1, x2
% not available: x3,v1,v2,v3.


%     
%     for j=1:length(Outputs)
%        if (strcmp(Outputs(j),'v1') | ...
%            strcmp(Outputs(j),'v2') | ...
%            strcmp(Outputs(j),'v3') | ...
%            strcmp(Outputs(j),'x3'))
%            disp('Sensors not available!');
%            return
%        end
%     end
  
    
    R = ureal('R',1.3,'PlusMinus',0.1);
    L = ureal('L', 0.0024, 'Percentage', [-5,5]);
    Gamma=ureal('Gamma',-206.8/100, 'Percentage', [-10,10]);
    
    %mass
    Mcart = ureal('Mcart', 0.5685, 'PlusMinus',[-3*0.0141,+3*0.0141]);
    Mload = ureal('Mload', 0.493, 'PlusMinus', 0.005);
    Mmotor = ureal('Mtotal',0.8906,'PlusMinus', [-3*0.1146,3*0.1145])-Mcart;
    
    %stiffness
    Km=ureal('Km', 340.14, 'PlusMinus', 20);
    Kh=ureal('Kh',720.56, 'PlusMinus', 20);
    Kl=ureal('Kl', 216.38, 'PlusMinus', 20);
    
    %damping
    ChL = ureal('ChL', 10.2855, 'PlusMinus',0.5);
    ChNL =ureal('ChNL', 9.0517, 'PlusMinus',0.5);
    CmL =ureal('CmL', 9.5558, 'PlusMinus',0.5);
    CmNL = ureal('CmNL', 8.4089, 'PlusMinus',0.5);
    ClL = ureal('ClL', 8.9973, 'PlusMinus',0.5);
    ClNL = ureal('ClNL', 8.2736, 'PlusMinus',0.5);
    
    if (length(nLoad)~= length(springType) && length(nLoad) > 3)
        disp('Error, nLoad and springType should be vectors of the same size specified by nDOF'); 
        return;
    end
    nDOF = length(nLoad);
    
    %% Mass, Damping and Stiffness matrix
    
   
    
    for i=1:nDOF
        M(i,i) = Mcart+Mload*nLoad(i);
    end
    M(1,1)= M(1,1)+Mmotor;
    
    
    
    %% for the first cart we need to consider damping with motor attached
    
    if (springType(1) == 'l')
        c(1) =  ClNL+ (ClL-ClNL) * (M(1,1)- (Mcart+Mmotor))/(0.493*2);
    elseif (springType(1) == 'm')
        c(1) =  CmNL+ (CmL-CmNL) * (M(1,1)- (Mcart+Mmotor))/(0.493*2);
    else 
        c(1) = ChNL +(ChL-ChNL) *(M(1,1)-(Mcart+Mmotor))/(0.493*2);
    end
    
    
    for i=2:nDOF
        if (springType(i) == 'l')
            c(i)= ClNL+ (ClL-ClNL) * (M(i,i)- (Mcart))/(0.493*2);
        elseif (springType(i) == 'm')
            c(i)= CmNL+(CmL-CmNL) * (M(i,i)- (Mcart))/(0.493*2);
        else
            c(i)= ChNL+ (ChL-ChNL) * (M(i,i)- (Mcart))/(0.493*2);
        end
    end    
    
    for i=1:nDOF
       if (springType(i) == 'l')
           k(i) = Kl;
       elseif (springType(i)== 'm')
           k(i) = Km;
       else
           k(i)=Kh;
       end
    end
    
    if (nDOF==1)
        K = k(1);
        C = c(1);
    elseif (nDOF ==2)
        K = [k(1)+k(2),-k(2); -k(2),k(2)];
        C = [c(1)+c(2),-c(2); -c(2),c(2)];
    else 
        K = [k(1)+k(2),-k(2),0;-k(2),k(2)+k(3),-k(3); 0,-k(3),k(3)];
        C = [c(1)+c(2),-c(2),0;-c(2),c(2)+c(3),-c(3); 0,-c(3),c(3)];
    end

     
    
    
    %% State space initialization
    B = zeros(1+nDOF*2,1);
    %D= zeros(1+2*nDOF,1);
    D=zeros(length(Outputs),1);
    %% C Matrix
%     Cy(1,1) = 1/L;
%     for i=1:nDOF
%        Cy(i+1,i+1)=1; 
%     end
%     for i=nDOF+2:1+2*nDOF
%         Cy(i,i)=0;
%     end

    for i=1:length(Outputs)
        Cy(i,1:1+2*nDOF)=0;
        switch char(Outputs(i))
            case 'i'
                Cy(i, 1) = 1;
            case 'x1'
                if (nDOF >= 1)
                    Cy(i, 2) = 100;
                end
            case 'x2'
                if (nDOF >= 2)
                    Cy(i, 3) = 100;
                end
            case 'x3'
                if (nDOF == 3)
                    Cy(i, 4) = 100;
                end
            case 'v1'
                if (nDOF >= 1)
                    Cy(i, 1+nDOF+1) = 100;
                end
            case 'v2'
                if (nDOF >= 2)
                    Cy(i, 1+nDOF+2) = 100;
                end
            case 'v3'
                if (nDOF == 3)
                    Cy(i, 1+nDOF+3) = 100;
                end
            otherwise
                disp('Outputs error');
        end
    end
    
    %% B Matrix
    B(1,1) = 1/L;
    %B(3,2)= 1;
    
    
    %% A Matrix
    A(1,1)= -R/L;
    if (bemfOn ~=0)
        A(1,2+nDOF)= -Gamma/L;
    end
    
    for i=1:nDOF
       A(i+1,1+nDOF+i)=1; 
    end
    Bg = zeros(nDOF, 1);
    Bg(1)=1;
    temp =[inv(M)*Bg*Gamma, -inv(M)*K, -inv(M)*C];
    for i=1+nDOF+1:1+2*nDOF
        A(i, :) = temp(i-1-nDOF,:);
    end
    
    
    %%
    
    sysSS = ss(A,B,Cy,D);
  


end