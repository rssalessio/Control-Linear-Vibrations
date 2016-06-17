function [Obs,Q,R,P,L] = kalmanObserver(nLoad, springType, inputs)
%
% Example: kalmanObserver([1,2], ['l','h'], {'x1','i'});
% Builds a  system with two dof as specified, returned in Obs.
% x1, i are the sensors used as input of the kalman filter
% Q, R are the state noise and sensors noise covariance matrices.
    stateNoiseVar = 1e-9;
    encoderNoiseVar = 1e-9;
    currentNoiseVar =  0.0127;
    [sys,nDOF] = sysBuilder(nLoad,springType, inputs,1);
    Obs = sys.NominalValue;
    Q = eye(1+2*nDOF)*stateNoiseVar;
    R = eye(length(inputs));
    
    obsM=obsv(Obs.a,Obs.c);
    minSVD=min(svd(obsM));
    disp(['Minimum singular value of the observability matrix:' , num2str(minSVD)]);
    if( minSVD<1e-4)
        disp('Notice, system nearly not observable!');
    end
    for j=1:length(inputs)
       switch char(inputs(j))
            case 'i'
                R(j,j) = currentNoiseVar;
            case 'x1'
                if (nDOF >= 1)
                    R(j,j) = encoderNoiseVar;
                end
            case 'x2'
                if (nDOF >= 2)
                    R(j,j) = encoderNoiseVar;
                end
            otherwise
                disp('Input error. Those sensors are not available');
        end
    end
    
    Obs = c2d(Obs, 1/200,'zoh');
    [P,eigs,k,~] = dare(Obs.a',Obs.c',Q,R);


% Build Kalman estimator (Ae,Be,Ce,De)
    L=k';

    

end