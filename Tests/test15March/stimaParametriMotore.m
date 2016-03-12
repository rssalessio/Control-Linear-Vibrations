
N= length(x.Data);

V = 1; %ampiezza ingresso
S = 10; %durata in secondi dell'esperimento
eps=6; %errore

valRegime = x.Data(N);
disp('Valore di R:');
V/(2*valRegime)
delta = exp(-eps);
for i=1:N
   if (1-x.Data(i)/valRegime) < delta
       T = x.Time(i);
       disp('Valore di L:');
        R*T/eps
       break;
   end
end
