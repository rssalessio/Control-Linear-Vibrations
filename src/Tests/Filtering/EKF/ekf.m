function x_filtered  = ekf(u, y)
    %% Discrete Kalman filter for continous system
    % Inputs:
    % u: input to the system
    % y: output of the system
    % Output:
    % x_filtered: Kalman state estimate
    
    
    % P and xhat need to be updated each iteration
    % The other variables are parameters of the real vector.
    persistent P xhat Q R Res L M Gamma C B H
    
    if isempty(P)%First iteration, initialize values
        P = eye(4);
        xhat = [0; 0; 0; 100];
        Q = 1e-10*eye(4);
        R = diag([0.0127; 1e-10]);
        
        M = 1.8;
        C = 8.9973;
        Res = 1.3;
        L = 0.0024;
        Gamma = -2.068;
        
        B = 1/200.*[1/L; 0; 0; 0]; %Discretized Input Matrix B
        H = [1 0 0 0; 0 100 0 0]; % Output current and position
    end
    
    % Linearize the continuos system around xhat
    A = [ -Res/L,       0,              0,      0; ...
          0,            0,              1,      0; ...
        Gamma/M,        -xhat(4)/M,     -C/M,   -xhat(2)/M; ...
        0,              0,              0,      0];
    
    A = eye(4) + 1/200.*A; %Discretize A

    % Real nonlinear system computed in xhat
    f = [ -Res/L*xhat(1); ...
          xhat(3); ...
          Gamma/M*xhat(1) - xhat(4)*xhat(2)/M - C/M*xhat(3); ...
          0 ];
     
    % Discretize f 
    f = 1/200.*f;
    f = f + xhat;
    
    % Update Prediction
    x_pred = f + B*u;   % x_k+1 = f(x_k) + Bu_k
    y_pred = H*x_pred;  % y_k+1 = H*x_k+1
    
    % Update P
    P = A*P*A' + Q;
    
    % Update Kalman Gain
    K = P*H'/(H*P*H'+R);
    
    %Update Prediction
    xhat = x_pred + K*(y - y_pred);
    
    % Update P
    P = (eye(size(K*H)) - K*H)*P;
    
    % Output the state-estimate
    x_filtered = xhat;