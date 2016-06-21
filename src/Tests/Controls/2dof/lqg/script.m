clear all, close all

%load kalman;

[plant, Q,R,P,L] = kalmanObserver([2,2], ['m','l'], {'i','x1','x2'});
K=dlqr(plant.a, plant.b,diag([0,0,0.1,0,0]), 1) 

%g=plant.c *inv(1-plant.a)*plant.b

gain = 1./dcgain(plant);
gain= gain(3);