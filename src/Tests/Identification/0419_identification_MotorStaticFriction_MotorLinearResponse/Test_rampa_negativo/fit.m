
[t,i,v,x]=reads();
in = lowPassFilter(i, 10, 4,1,1/200);
in = in(6.68*200:22.75*200);
 tn = t(6.68*200:22.75*200);
 tn = tn-tn(1);
 k= [tn, ones(size(tn))];
theta =inv(k'*k)*k'*in
figure; plot(tn, in); hold on; plot(tn, theta(2)+tn.*theta(1));
