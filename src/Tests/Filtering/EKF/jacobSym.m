    clear all
    
    %% Compute Jacobian of Nonlinear system
    
    syms curr x1 dx1 k

    % data
    M = 1.8;
    C = 8.9973;
    R = 1.3;
    L = 0.0024;
    Gamma = -2.068;

    x = [curr; x1; dx1; k]; %state vector

    % nonlinear state 
    f = [ -R/L*x(1); x(3); Gamma/M*x(1) - x(4)*x(2)/M - C/M*x(3); 0 ];

    Jsym = jacobian(f, x) %linearization