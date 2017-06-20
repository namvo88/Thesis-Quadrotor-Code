%% LQR RUNFILE
% x' = Ax + Bu
% y  = Cx
% u  = r-Kx

% x = [x y z phi the psi phiL theL dx dy dz dphi dthe dpsi dphiL dtheL]'
% u = [f Mphi Mthe Mpsi]'
% y = [x y z psi]'
 
%% A B C D 16 states

IL = mL*L^2;
LQRM = [mQ+mL 0 0, 0 0 0, mL*L 0;%ddx
        0 mQ+mL 0, 0 0 0, 0 mL*L;%ddy
        0 0 mQ+mL, 0 0 0, 0 0;% ddz
        0 0 0, Ixx 0 0, 0 0;% ddphi
        0 0 0, 0 Iyy 0, 0 0;% ddthe
        0 0 0, 0 0 Izz, 0 0;% ddpsi
       -L*mL 0 0, 0 0 0, IL+L^2*mL 0;%ddtheL        
        0 L*mL 0, 0 0 0, 0 IL+L^2*mL];%ddphiL

LQRM2 = [0 0 0, -g*(mQ+mL) 0 0, 0 0;%x
         0 0 0, 0 g*(mQ+mL) 0, 0 0;%y
         0 0 0, 0 0 0, 0 0;% z
         0 0 0, 0 0 0, 0 0;% phi
         0 0 0, 0 0 0, 0 0;% the
         0 0 0, 0 0 0, 0 0;% psi
         0 0 0, 0 0 0, g*L*mL 0;%theL
         0 0 0, 0 0 0, 0 g*L*mL];%phiL
     
LQRM3 = [0 0 0 0;
         0 0 0 0;
         1 0 0 0;
         0 -1 0 0;
         0 0 -1 0;
         0 0 0 1;
         0 1 0 0;
         0 0 1 0];
     
LQRA = [zeros(8) eye(8);
        -inv(LQRM)*LQRM2 zeros(8)];
LQRB = [zeros(8,4);
        inv(LQRM)*LQRM3];
LQRC = [eye(3) zeros(3,13);
        zeros(1,5) 1 zeros(1,10)];
LQRD = zeros(4);     

sys=ss(LQRA,LQRB,LQRC,LQRD,'StateName',{'x','y','z','phi','the','psi','theL','phiL','dx','dy','dz','dphi','dthe','dpsi','dtheL','dphiL'},...
        'InputName',{'f','Mphi','Mthe','Mpsi'},...
        'OutputName',{'x','y','z','psi'});

%% A B C D 16 states

IL = mL*L^2;
LQRM = [mQ+mL 0 0, 0 0 0, mL*L 0;%ddx
        0 mQ+mL 0, 0 0 0, 0 mL*L;%ddy
        0 0 mQ+mL, 0 0 0, 0 0;% ddz
        0 0 0, Ixx 0 0, 0 0;% ddphi
        0 0 0, 0 Iyy 0, 0 0;% ddthe
        0 0 0, 0 0 Izz, 0 0;% ddpsi
       -L*mL 0 0, 0 0 0, IL+L^2*mL 0;%ddtheL        
        0 L*mL 0, 0 0 0, 0 IL+L^2*mL];%ddphiL

LQRM2 = [0 0 0, 0 -g*(mQ+mL) 0 0, 0 0;%x
         0 0 0, g*(mQ+mL) 0 0, 0 0;%y
         0 0 0, 0 0 0, 0 0;% z
         0 0 0, 0 0 0, 0 0;% phi
         0 0 0, 0 0 0, 0 0;% the
         0 0 0, 0 0 0, 0 0;% psi
         0 0 0, 0 0 0, g*L*mL 0;%theL
         0 0 0, 0 0 0, 0 g*L*mL];%phiL
     
LQRM3 = [0 0 0 0;
         0 0 0 0;
         1 0 0 0;
         0 -1 0 0;
         0 0 -1 0;
         0 0 0 1;
         0 1 0 0;
         0 0 1 0];
     
LQRA = [zeros(8) eye(8);
        -inv(LQRM)*LQRM2 zeros(8)];
LQRB = [zeros(8,4);
        inv(LQRM)*LQRM3];
LQRC = [eye(3) zeros(3,13);
        zeros(1,5) 1 zeros(1,10)];
LQRD = zeros(4);     

sys=ss(LQRA,LQRB,LQRC,LQRD,'StateName',{'x','y','z','phi','the','psi','theL','phiL','dx','dy','dz','dphi','dthe','dpsi','dtheL','dphiL'},...
        'InputName',{'f','Mphi','Mthe','Mpsi'},...
        'OutputName',{'x','y','z','psi'});    
    
% %% A B C D 18 states
% 
% IL = mL*L^2;
% LQRM = [mQ 0 0, 0 0 0, mL 0 0;%ddx
%         0 mQ 0, 0 0 0, 0 mL 0;%ddy
%         0 0 mQ, 0 0 0, 0 0 mL;% ddz
%         0 0 0, Ixx 0 0, 0 0 0;% ddphi
%         0 0 0, 0 Iyy 0, 0 0 0;% ddthe
%         0 0 0, 0 0 Izz, 0 0 0;% ddpsi
%         -1 0 0, 0 0 0, 1 0 0;% ddxL 
%         0 -1 0, 0 0 0, 0 1 0;% ddyL
%         0 0 -1, 0 0 0, 0 0 1];% ddzL

% 
% LQRM2 = [0 0 0, 0 -g*(mQ+mL) 0 0, 0 0 0;%x
%          0 0 0, g*(mQ+mL) 0 0, 0 0 0;%y
%          0 0 0, 0 0 0, 0 0 0;% z
%          0 0 0, 0 0 0, 0 0 0;% phi
%          0 0 0, 0 0 0, 0 0 0;% the
%          0 0 0, 0 0 0, 0 0 0;% psi
%          0 0 0, 0 0 0, 0 0 0;% xL 
%          0 0 0, 0 0 0, 0 0 0;% yL
%          0 0 0, 0 0 0, 0 0 0];% zL

%      
% LQRM3 = [0 0 0 0;
%          0 0 0 0;
%          1 0 0 0;
%          0 -1 0 0;
%          0 0 -1 0;
%          0 0 0 1;
%          0 0 0 0;
%          0 0 0 0;
%          0 0 0 0];

%      
% LQRA = [zeros(9) eye(9);
%         -inv(LQRM)*LQRM2 zeros(9)];
% LQRB = [zeros(9,4);
%         inv(LQRM)*LQRM3];
% LQRC = [eye(3) zeros(3,15);
%         zeros(1,5) 1 zeros(1,12)];
% LQRD = zeros(4);
% 
% sys=ss(LQRA,LQRB,LQRC,LQRD,'StateName',{'x','y','z','phi','the','psi','xL','yL','zL','dx','dy','dz','dphi','dthe','dpsi','dxL','dyL','dzL'},...
%         'InputName',{'f','Mphi','Mthe','Mpsi'},...
%         'OutputName',{'x','y','z','psi'});

%% Q R K
Qdiag = [10 10 100 ones(1,13)];
LQRQ = diag(Qdiag);

% u = [f Mphi Mthe Mpsi]'
Rdiag = [0.044 1.56 1.56 1.56];
LQRR = diag(Rdiag); 

K = lqr(LQRA,LQRB,LQRQ,LQRR);

% sim('LQR_FULL');

