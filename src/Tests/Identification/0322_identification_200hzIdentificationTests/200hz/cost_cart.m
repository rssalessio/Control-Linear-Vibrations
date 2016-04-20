function J = cost_cart(par, data, sim)

    cart = tf(par(1), [par(2), par(3), par(4)]);
    
    % Uses "simulated current"
    if sim == 1
        i_sim = lsim(tf(1,[0.0221, 1.3033]), data.v, data.t);
        x_sim = lsim(cart, i_sim, data.t);
    % Uses "measured current"
    else
        x_sim = lsim(cart, data.i, data.t);
    end
    
    J = x_sim - data.x;
end