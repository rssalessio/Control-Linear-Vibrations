function J = cost_motor(x, vs, is, t)

    motor = tf([1], [x(1) x(2)]);
    
    i_sim = lsim(motor, vs, t);
    
    J = i_sim - is;
    
end
