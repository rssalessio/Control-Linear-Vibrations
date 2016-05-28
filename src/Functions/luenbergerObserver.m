function [Obs,L] = luenbergerObserver(nLoad, springType, inputs)
%
% Example: luenbergerObserver([1,2], ['l','h'], {'x1','i'});
% Builds a  system with two dof as specified, returned in Obs.
% x1, i are the sensors used as input of the observer

    [sys,nDOF] = sysBuilder(nLoad,springType, inputs);
    Obs = sys.NominalValue;
    
    minSVD=min(svd(obsv(Obs.a,Obs.c)));
    disp(['Minimum singular value of the observability matrix:' , num2str(minSVD)]);
    if( minSVD<1e-4)
        disp('Notice, system nearly not observable!');
    end
    
    
    poles= real(eig(Obs.a));
    obsPoles=10.*poles;
    obsPoles = exp(obsPoles./200);
    
    Obs = c2d(Obs, 1/200,'zoh');

    k = place(Obs.a', Obs.c', obsPoles);
    L=k';

    

end