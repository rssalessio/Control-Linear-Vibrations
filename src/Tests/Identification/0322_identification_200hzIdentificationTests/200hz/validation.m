close all; clear all; clc;
R = 1.3;%resistance 
L = 0.0220; %inductance 
Ke = -1.0000e+05/56000; %electric stiffness and torque constant

s=tf('s');
%carts and load     
M = 1.35;
Mload = 0.493;
MCart = M-2*Mload;

%spring
Ch = 9; %spring damping
Cm = 6; 
Cl = 8;

Kh = 625; %Stiffness high
Km = 281; %Stiffness Med
Kl = 162; %Stifness low

cd pulse_kbig_2mass/
    [t,v,i,x]= reads();
    x=x/56000;
    i1 = find(i>0.2,1);
    v(1:i1)=0;
    [plant1,plant2]=sysBuilder(R,L,Ke,M,Ch,Kh);
    xsim=lsim(plant1, v, t); cost=l2cost(x,xsim)
    figure; plot(t,xsim); hold on;
    xsim=lsim(plant2, v, t); cost=l2cost(x,xsim)
    plot(t,xsim); hold on; plot(t,x); grid;
    legend('sys','sysBemf','real');
    
cd ..

cd pulse_kbig_nomass/
    [t,v,i,x]= reads();
    x=x/56000;
    i1 = find(i>0.2,1);
    v(1:i1)=0;
    [plant1,plant2]=sysBuilder(R,L,Ke,MCart,Ch,Kh);
    xsim=lsim(plant1, v, t); cost=l2cost(x,xsim)
    figure; plot(t,xsim); hold on;
    xsim=lsim(plant2, v, t); cost=l2cost(x,xsim)
    plot(t,xsim); hold on; plot(t,x); grid;
    legend('sys','sysBemf','real');
cd ..
cd pulse_klow_2mass/ 
    [t,v,i,x]= reads();
    x=x/56000;
    i1 = find(i>0.2,1);
    v(1:i1)=0;
    [plant1,plant2]=sysBuilder(R,L,Ke,M,Cl,Kl);
    xsim=lsim(plant1, v, t); cost=l2cost(x,xsim)
    figure; plot(t,xsim); hold on;
    xsim=lsim(plant2, v, t); cost=l2cost(x,xsim)
    plot(t,xsim); hold on; plot(t,x); grid;
    legend('sys','sysBemf','real');
cd ..
cd pulse_klow_nomass/
    [t,v,i,x]= reads();
    x=x/56000;
    i1 = find(i>0.2,1);
    v(1:i1)=0;
    [plant1,plant2]=sysBuilder(R,L,Ke,MCart,Cl,Kl);
    xsim=lsim(plant1, v, t); cost=l2cost(x,xsim)
    figure; plot(t,xsim); hold on;
    xsim=lsim(plant2, v, t); cost=l2cost(x,xsim)
    plot(t,xsim); hold on; plot(t,x); grid;
    legend('sys','sysBemf','real');
cd ..
cd pulse_kmed_2mass/
    [t,v,i,x]= reads();
    x=x/56000;
    i1 = find(i>0.2,1);
    v(1:i1)=0;
    [plant1,plant2]=sysBuilder(R,L,Ke,M,Cm,Km);
    xsim=lsim(plant1, v, t); cost=l2cost(x,xsim)
    figure; plot(t,xsim); hold on;
    xsim=lsim(plant2, v, t); cost=l2cost(x,xsim)
    plot(t,xsim); hold on; plot(t,x); grid;
    legend('sys','sysBemf','real');
cd ..
cd pulse_kmed_nomass/
    [t,v,i,x]= reads();
    x=x/56000;
    i1 = find(i>0.2,1);
    v(1:i1)=0;
    [plant1,plant2]=sysBuilder(R,L,Ke,MCart,Cm,Km);
    xsim=lsim(plant1, v, t); cost=l2cost(x,xsim)
    figure; plot(t,xsim); hold on;
    xsim=lsim(plant2, v, t); cost=l2cost(x,xsim)
    plot(t,xsim); hold on; plot(t,x); grid;
    legend('sys','sysBemf','real');
cd ..
