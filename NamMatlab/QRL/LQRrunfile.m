%% LQR RUNFILE
% x' = Ax + Bu
% y  = Cx + Du
% u  = (r-x)K

% x = [x y z phi the psi phiL theL dx dy dz dphi dthe dpsi dphiL dtheL]'
% u = [f Mphi Mthe Mpsi]'
% y = [x y z psi]'
 
%% A, B, C, D

mQ     = 4.34; %Lee2010 %weight bebop 420 g
Ixx    = 0.0820; %Lee2010
Iyy    = 0.0845; %Lee2010
Izz    = 0.1377; %Lee2010

mQ = 0.4; %Cornelis2014
Ixx    = 0.00223; %Cornelis2014
Iyy    = 0.00299; %Cornelis2014
Izz    = 0.00480; %Cornelis2014


I_L    = mL*L^2;
LQRM   = [mQ+mL 0 0, 0 0 0, 0 mL*L;%ddx
         0 mQ+mL 0, 0 0 0, mL*L 0;%ddy
         0 0 mQ+mL, 0 0 0, 0 0;% ddz
         0 0 0, Ixx 0 0, 0 0;% ddphi
         0 0 0, 0 Iyy 0, 0 0;% ddthe
         0 0 0, 0 0 Izz, 0 0;% ddpsi
         0 L*mL 0, 0 0 0, I_L+L^2*mL 0;%ddphiL        
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
% LQR0   = [-L*sin(pi/18) yL0 zL0+L*cos(pi/18) phiQ0 thetaQ0 psiQ0 phiL0 pi/18 zeros(1,8)]';
phiL0 = 0;
% phiL0 = deg2rad(30);
thetaL0 = 0;
% thetaL0 = deg2rad(30);
lqr0   = [xL0 yL0 zL0+L phiQ0 thetaQ0 psiQ0 phiL0 thetaL0 zeros(1,8)]';

% x = [x y z phi the psi phiL theL dx dy dz dphi dthe dpsi dphiL dtheL]'

% Qdiag = [2000 1 (0.1)^2, (2*pi/18)^2 (2*pi/18)^2 (2*pi/18)^2, 1 1, 0.001*ones(1,8)]; %sine on x
% Qdiag = [10 10 100 1 1 1 1/(2*pi/36)^2 1/(2*pi/36)^2 1 1 1 1 1 1 1 1];
% Qdiag = [10 10 100 1 1 1 500 500 1 1 1 1 1 1 1 1]; %Fast anti swing, slow QR
% Qdiag = [5000 5000 500 0.01 0.01 0.01 0.01 0.01 1 1 1 1 1 1 1 1]; %sine up down QR track
Qdiag = [50000 50000 500 0.001 0.001 0.001 100 100 1 1 1 1 1 1 1 1]; %sine up down min load swing
% Qdiag = [100 100 250 1 1 1 750 750 1 1 1 1 1 1 1 1]; 

% Qdiag = [1 1 1 1 1 1 1 1 ones(1,8)];
LQRQ = diag(Qdiag);

Rdiag = [1000 50 50 100];
% Rdiag = [ones(1,4)];
LQRR = diag(Rdiag); 

K = lqr(LQRA,LQRB,LQRQ,LQRR);

sim('QRLsim');

    
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



