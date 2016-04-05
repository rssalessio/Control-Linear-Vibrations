
cd Khigh_hand_Nomass3
    x = textread('data0000.txt', '%f');
    [k,i]=findpeaks(x);

    T= diff(i)/200;
    T=T(1:end-2);
    w=2*pi./T;
    Wm = mean(w)
    Wvar = var(w);
cd ..