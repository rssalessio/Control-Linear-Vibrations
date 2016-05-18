function [sys] = sysBuilder2DOF(R,L,Gamma,M1,C1,K1,M2,C2,K2)
    M = diag([M1,M2]);
    K = [K1+K2, -K2; -K2,   K2];
    C = [C1+C2, -C2; -C2, C2];

    A = [-R/L, 0, 0, 0, 0;
         0, 0, 0, 1 ,0;
         0 ,0 ,0 ,0 ,1;
         inv(M)*[1;0]*Gamma/L, -inv(M)*K, -inv(M)*C];

    B = [1;0;0;0;0];

    Cy= [1,0,0,0,0;
        0,1,0 ,0,0;
        0,0,1,0,0];
    D=[0;0;0];
    sys = ss(A,B,Cy,D);


        

end