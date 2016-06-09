clear all, close all

%% Initialize Simulink Scheme

plant = sysBuilder(2, 'l', {'i', 'x1','v1'}, 1);
plant = plant.NominalValue;