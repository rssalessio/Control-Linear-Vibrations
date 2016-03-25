function J = cost_motor_bemf(var, data)
    
    % var:
    % 1)L 
    % 2)R
    % 3)Ke
    % 4)M
    % 5)C
    % 6)K
    
    D = 0.0762;
    
    motor = tf(1, [var(1) var(2)]);
    gain = -var(3)*2/D;
    
    cart = tf(1, [var(4), var(5), var(6)]);
    speedometer = tf([1 0], 1);
    
    v_to_x = feedback(motor*gain*cart, speedometer*gain);
    v_to_i = feedback(motor, gain*cart*speedometer*gain);
    
    i_sim = lsim(v_to_i, data.v, data.t);
    x_sim = lsim(v_to_x, data.v, data.t);
    
    alfa = 1;
    beta = 1-alfa;
    
    J = alfa*(i_sim - data.i) + beta*(x_sim-data.x);
    
end
