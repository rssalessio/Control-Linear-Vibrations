function J = cost_motor(par, data)

    motor = tf(1, [par(1) par(2)]);
    
    i_sim = lsim(motor, data.v, data.t);
    
    J = i_sim - data.i;
    
end
