%% LQR RUNFILE
% x' = Ax + Bu
% y  = Cx
% u  = r-Kx

% x = [x y z phi the psi phiL theL dx dy dz dphi dthe dpsi dphiL dtheL]'
% u = [f Mphi Mthe Mpsi]'
% y = [x y z psi]'

clear;clc;close all;

%% Settings
% Warning: Using a default value of 0.2 for maximum step size.  The simulation step size will be
% equal to or less than this value.  You can disable this diagnostic by setting 'Automatic solver
% parameter selection' diagnostic to 'none' in the Diagnostics page of the configuration
% parameters dialog
% >> Changed to max to 0.1

Tsim_end  = 22;
Tsim_s    = 0.01;

g = 9.81;
Ixx    = 0.0820; %Lee2010
Iyy    = 0.0845; %Lee2010
Izz    = 0.1377; %Lee2010

mQ     = 4.34; %Lee2010 %weight bebop 420 g
mL     = 0.1;
lL     = 0.7;

% Command Filter Low Pass filter 3th order
omega_n1_xL = 2*pi*.4;
omega_n2_xL = 2*pi*.4;
zeta_xL = 0.975;
omega_n1_q = 2*pi*3;
omega_n2_q = 2*pi*5;
zeta_q = 0.975;
omega_n1_R = 2*pi*6.5;
omega_n2_R = 2*pi*8;
zeta_R = 0.98;

LQRA = [zeros(8) eye(8);
    zeros(1,4) g zeros(1,11); %Depends on Rotation matrix!
    zeros(1,3) -g zeros(1,12); %Depends on Rotation matrix!
    zeros(6,16)]; 
LQRB = [zeros(10,4);
    1/mQ 0 0 0;
    0 1/Ixx 0 0;
    0 0 1/Iyy 0;
    0 0 0 1/Izz;
    0 1/mL 0 0;
    0 0 1/mL 0];   
% LQRC = [eye(3) zeros(3,13);
%     zeros(1,5) 1 zeros(1,10)];
LQRC = eye(16);

Qdiag = [100 100 10 ones(1,13)];
Q = diag(Qdiag);

R = eye(4);

K = lqr(LQRA,LQRB,Q,R);

sim('LQR_QRLsim');

