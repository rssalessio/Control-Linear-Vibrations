%
% Assicuarsi che:
% la variabile x contenga i dati di output della corrente
% la variabile u contenga la tensione in ingresso
% la variabile t contenga il vettore del tempo


V = 3.6; %ampiezza ingresso
N= length(x); %%numero di dati
S = t(end); %durata in secondi dell'esperimento
eps=6; %errore voluto( exp(-6))
t0=1; %%inizio dell'esperimento
Ts = t(2)-t(1); %sampling time
%devo ricavare inizio dell'esperimento
for i=1:N
   if (u(i) > 0.1)
       t0=t(i)+Ts;
       break;
   end
end

valRegime = x(N);
disp('Valore di R:');
V/(2*valRegime)
delta = exp(-eps);
for i=1:N
   if (1-x(i)/valRegime) < delta
       T = t(i)-t0;
       disp('Valore di L:');
        R*T/eps
       break;
   end
end

dat = iddata(x,u,Ts);
G1 = tfest(dat, 1);
G2 = tfest(dat, 3,2);