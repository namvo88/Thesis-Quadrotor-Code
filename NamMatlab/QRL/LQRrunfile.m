%% LQR RUNFILE
% x' = Ax + Bu
% y  = Cx + Du
% u  = (r-x)K

% x = [x y z phi the psi phiL theL dx dy dz dphi dthe dpsi dphiL dtheL]'
% u = [f Mphi Mthe Mpsi]'
% y = [x y z psi]'
 
%% A, B, C, D
lqr0   = [xL0 yL0 zL0+L phiQ0 thetaQ0 psiQ0 phiL0 thetaL0 zeros(1,8)]';
I_L    = mL*L^2;
LQRM   = [mQ+mL 0 0, 0 0 0, 0 mL*L;%ddx
         0 mQ+mL 0, 0 0 0, mL*L 0;%ddy
         0 0 mQ+mL, 0 0 0, 0 0;% ddz
         0 0 0, Ixx 0 0, 0 0;% ddphi
         0 0 0, 0 Iyy 0, 0 0;% ddthe
         0 0 0, 0 0 Izz, 0 0;% ddpsi
         0 -L*mL 0, 0 0 0, I_L+L^2*mL 0;%ddphiL        
         L*mL 0 0, 0 0 0, 0 I_L+L^2*mL];%ddtheL

LQRM2  = [0 0 0, 0 -g*(mQ+mL) 0, 0 0;%x
         0 0 0, g*(mQ+mL) 0 0, 0 0; %y
         0 0 0, 0 0 0, 0 0;         %z
         0 0 0, 0 0 0, 0 0;         %phi
         0 0 0, 0 0 0, 0 0;         %the
         0 0 0, 0 0 0, 0 0;         %psi
         0 0 0, 0 0 0, g*L*mL 0;    %phiL
         0 0 0, 0 0 0, 0 g*L*mL];   %theL
     
LQRM3  = [0 0 0 0; %x
         0 0 0 0; %y
         1 0 0 0; %z
         0 1 0 0; %phi
         0 0 1 0; %the
         0 0 0 1; %psi
         0 1 0 0; %phiL
         0 0 1 0];%theL
     
LQRA = [zeros(8) eye(8);
        -inv(LQRM)*LQRM2 zeros(8)];
LQRB = [zeros(8,4);
        inv(LQRM)*LQRM3];
LQRC = [eye(3) zeros(3,13);
        zeros(1,5) 1 zeros(1,10)];
LQRD = zeros(4);     
% 
% sys=ss(LQRA,LQRB,LQRC,LQRD,'StateName',{'x','y','z','phi','the','psi','phiL','theL','dx','dy','dz','dphi','dthe','dpsi','dphiL','dtheL'},...
%         'InputName',{'f','Mphi','Mthe','Mpsi'},...
%         'OutputName',{'x','y','z','psi'});

%% Q, R, K
Qdiag = [2000 1 (0.1)^2, (2*pi/18)^2 (2*pi/18)^2 (2*pi/18)^2, 1 1, 0.001*ones(1,8)]; %sine on x
LQRQ = diag(Qdiag);

Rdiag = [0.044 1 1 1];
LQRR = diag(Rdiag); 

K = lqr(LQRA,LQRB,LQRQ,LQRR);

    
%% A B C D 18 states
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



