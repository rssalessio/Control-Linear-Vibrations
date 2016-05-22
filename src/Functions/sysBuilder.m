function [sysSS] = sysBuilder( nLoad, springType)

    %motor
    R = 1.2689;
    L = 0.0024;
    Gamma=-206.8;
    
    %mass
    Mmotor = 0.3155;
    Mcart = 0.5685;
    Mload = 0.493;
    
    %stiffness
    Km=321.7;
    Kh=706.2;
    Kl=226;
    
    %damping
    ChL =9.912;
    ChNL = 7.7739;
    CmL = 9.5963;
    CmNL = 8.040;
    ClL = 9.9788;
    ClNL = 9.2761;
    
    if (length(nLoad)~= length(springType) && length(nLoad) > 3)
        disp('Error, nLoad and springType should be vectors of the same size specified by nDOF'); 
        return;
    end
    nDOF = length(nLoad);
    
    %% Mass, Damping and Stiffness matrix
    
    M = zeros(nDOF, nDOF);
    C = zeros(nDOF, nDOF);
    K = zeros(nDOF, nDOF);
    
    
    for i=1:nDOF
        M(i,i) = Mcart+Mload*nLoad(i);
    end
    M(1,1)= M(1,1)+Mmotor;
    
    
    c = zeros(nDOF,1);
    
    %% for the first cart we need to consider damping with motor attached
    
    if (springType(i) == 'l')
        c(1) =  ClNL+ 0.7127 * (M(1,1)- (Mcart+Mmotor));
    elseif (springType(i) == 'm')
        c(1) =  CmNL+ 2.4263 * (M(1,1)- (Mcart+Mmotor));
    else 
        c(1) = ChNL +2.1685 *(M(1,1)-(Mcart+Mmotor));
    end
    
    
    for i=2:nDOF
        if (springType(i) == 'l')
            c(i)= ClNL+ 0.3911 * (M(i,i)- (Mcart));
        elseif (springType(i) == 'm')
            c(i)= CmNL+ 0.2514 * (M(i,i)- (Mcart));
        else
            c(i)= ChNL+ 0.1334 * (M(i,i)- (Mcart));
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
    A = zeros(1+nDOF*2, 1+nDOF*2);
    B = zeros(1+nDOF*2,1);
    Cy = zeros(1+nDOF, 1+nDOF*2);
    D = zeros(1+nDOF,1);
    
    %% C Matrix
    Cy(1,1) = 1/L;
    for i=1:nDOF
       Cy(i+1,i+1)=1; 
    end
    
    %% B Matrix
    B(1) = 1;
    
    
    %% A Matrix
    A(1,1)= -R/L;
    
    for i=1:nDOF
       A(i+1,1+nDOF+i)=1; 
    end
    Bg = zeros(nDOF, 1);
    Bg(1)=1;
    A(1+nDOF+1:end, 1:end) = [inv(M)*Bg*Gamma/L, -inv(M)*K, -inv(M)*C];
    
    %%
    
    sysSS = ss(A,B,Cy,D);
%     
%     motor = tf([gamma],[L R]);
%     
%     
%     cart = tf([Gamma],[M, C, K]);
%     sys = series(motor,cart);
%     sysBemf =feedback(sys, s*Gamma);


end