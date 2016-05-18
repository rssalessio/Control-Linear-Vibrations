function [sys,sysBemf] = sysBuilder1DOF(R,L,Gamma,M,C,K)

    s=tf('s');
    motor = tf([1],[L R]);
    cart = tf([Gamma],[M, C, K]);
    sys = series(motor,cart);
    sysBemf =feedback(sys, s*Gamma);


end