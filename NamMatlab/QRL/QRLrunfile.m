clear; clc; close all;

%% Settings
% Warning: Using a default value of 0.2 for maximum step size.  The simulation step size will be
% equal to or less than this value.  You can disable this diagnostic by setting 'Automatic solver
% parameter selection' diagnostic to 'none' in the Diagnostics page of the configuration
% parameters dialog
% >> Changed to 'none'

% The 'Array' format for saving outputs to the workspace requires all signals connected to the
% root outports to be scalar or 1-D arrays. For model 'QRsim' set the Format option in the
% 'Data Import/Export' page of the Configuration Parameters dialog to either 'Structure' or 'Structure with time'.
% >> Changed to 'Structure with time'

%% Input signals

% Position QR mode 0
% Attitude QR mode 1

% QRL QR Attitude Controlled mode 2
% QRL Load Attitude Controlled mode 3
% QRL Load Position Controlled mode 4

mode = 4;
switch mode
    case 2
        modename = 'QRL QR Attitude Controlled Mode';
        modecode = 'QRATTQRL';
        disp(modename)
    case 3
        modename = 'QRL Load Attitude Controlled Mode';
        modecode = 'LATTQRL';
        disp(modename)
    case 4
        modename = 'QRL Load Position Controlled Mode';
        modecode = 'LPOSQRL';
        disp(modename)
    otherwise
        disp('No Control Mode selected');
end

Tsim_end = 8;
Tsim_s   = 0.01;
t = 0:Tsim_s:Tsim_end;
fsine = 2*(2*pi)/Tsim_end;
T0 = Tsim_end*4; %Time period of oscillation of load

% xLd = [zeros(1,length(t)); sin(2*pi*t/T0); zeros(1,length(t))];
b1d = [1; 0; 0];
Rd  = eye(3);
qd  = [0; 0; -1];

% phiLd   = 0;
% phiQd   = 0;

%% Uncertainties

Deltax = [-0.5; 0.2; 1]; %Goodarzi2013a
DeltaR = [0.2; -0.1; 0.02]; %Goodarzi2013a

%% Constants
mQ    = 4.34; %Lee2010 %weight bebop 420 g
Ixx   = 0.0820; %Lee2010
Iyy   = 0.1; %not Tang2014
Izz   = 0.1; %not Tang2014
I     = diag([Ixx Iyy Izz]); %Tang2014
ctauf = 8.004e-3; %Lee2010c

mL    = 0.2;
lL    = 0.4;

b     = 0.1; %gok thrust factor
d     = 0.1; %gok drag factor
Ir    = 0.5; %gok
l     = 0.315; %Lee2010 %wingspan bebop 248 mm

g     = 9.81;
e3    = [0;0;1];

fc    = (mQ+mL)*g;
fgain = 1;
fsat  = [-1000 1000];

c_der = inf;

%% Initial Conditions
xL0     = 0;
yL0     = 0;
zL0     = 0;
dxL0    = 0;
dyL0    = 0;
dzL0    = 0;

phiL0   = deg2rad(0); % -e3 = 180 deg
thetaL0 = 0;
psiL0   = 0;
pL0     = 0;
qL0     = 0;
rL0     = 0;

phiQ0   = deg2rad(0); %deg
thetaQ0 = deg2rad(0);
psiQ0   = deg2rad(0);
pQ0     = 0;
qQ0     = 0;
rQ0     = 0;

q0      = [0; sin(phiL0); -cos(phiL0)];
dq0     = [0;0;0];
omega0  = [0;0;0];

% Rx = [1 0 0;
%       0 cos(phiQ0) sin(phiQ0);
%       0 -sin(phiQ0) cos(phiQ0)];
% 
% Rinit = Rx

        Rz = [cos(psiQ0) -sin(psiQ0) 0;
            sin(psiQ0) cos(psiQ0) 0;
            0 0 1];
        Ry = [cos(thetaQ0) 0 sin(thetaQ0);
            0 1 0;
            -sin(thetaQ0) 0 cos(thetaQ0)];
        Rx = [1 0 0;
            0 cos(phiQ0) -sin(phiQ0);
            0 sin(phiQ0) cos(phiQ0)];
        Rzyx = (Rx*Ry*Rz);
        R0 = Rzyx;


%% Gains

kR = 8.81; %Lee2010
kOmegaQ = 2.54; %Lee2010

kq = kR*1;
komega = kOmegaQ*1;

% kpL = 1.2;
% kdL = 1.4;

kpx = 3;
kdx = 6;

% kx = 2*16*mQ;
% kv = 2*5.6*mQ;



% kR_phi       = 8.81; %Lee2010
% kR_theta     = 0.5;
% kR_psi       = 0.5;
% % kR           = diag([kR_phi;kR_theta;kR_psi]);
% kR = kR_phi*eye(3);
% % kR = 8.81;

% kOmega_phi   = 2.54; %Lee2010
% kOmega_theta = 0.5;
% kOmega_psi   = 0.5;
% % kOmega       = diag([kOmega_phi;kOmega_theta;kOmega_psi]);
% kOmega = kOmega_phi*eye(3);
% % kOmega = 2.54;

%% Simulation

open('QRLsim')
sim('QRLsim')

% if norm(inittest.signals.values(1,:))>=1
%     norm(inittest.signals.values(1,:))
%     error('norm( - kpL*eL - kdL*deL + ddphiLd*mQ*lL/f ) >= 1 !!')
% end

t        = simoutL.time;

posL     = simoutL.signals.values(:,1:3)';
velL     = simoutL.signals.values(:,4:6)';
accL     = simoutL.signals.values(:,7:9)';

% angleL   = reshape(simoutL1.signals.values(1:3,:,:),3,length(t));
% OmegaL   = reshape(simoutL1.signals.values(4:6,:,:),3,length(t));
% dOmegaL  = reshape(simoutL1.signals.values(7:9,:,:),3,length(t));
% 
% angleQ   = reshape(simoutL2.signals.values(1:3,:,:),3,length(t));
% OmegaQ   = reshape(simoutL2.signals.values(4:6,:,:),3,length(t));
% dOmegaQ  = reshape(simoutL2.signals.values(7:9,:,:),3,length(t));

angleL   = simoutL1.signals.values(:,1:3);
OmegaL   = simoutL1.signals.values(:,4:6);

angleQ   = simoutL2.signals.values(:,1:3);
OmegaQ   = simoutL2.signals.values(:,4:6);
dOmegaQ  = simoutL2.signals.values(:,7:9);

f        = simoutL3.signals.values(:,1);
M        = simoutL3.signals.values(:,2:4)';
omegarot = simoutL3.signals.values(:,5:8)';
fi       = simoutL3.signals.values(:,9:12)';

q      = simoutq.signals.values(:,1:3)';
dq     = simoutq.signals.values(:,4:6)';
ddq    = simoutq.signals.values(:,7:9)';

eq     = simouteq.signals.values(:,1:3);
edq    = simouteq.signals.values(:,4:6);
eR     = simouteAttitude.signals.values(:,1:3);
eOmega = simouteAttitude.signals.values(:,4:6);
Psiq   = simoutPsiq.signals.values(:,1);
PsiR   = simoutPsiR.signals.values(:,1);

xLd      = simoutxLd.signals.values(:,1:3)';
dxLd     = simoutxLd.signals.values(:,4:6)';
ddxLd    = simoutxLd.signals.values(:,7:9)';

F = reshape(simoutF.signals.values,3,length(t));
qcplot = reshape(simoutqc.signals.values,[3,length(simoutqc.signals.values)]);

posQ = posL - q*lL;

% Prop.1
if PsiR(1) >= 2
    error('PsiR(0) too big')
end
% lambdaMJQ = ?
% eps = ?
% if norm(eOmega(1),2)^2 >= 2/lambdaMJQ * kR/eps^2 * (2-PsiR(1))
%     error('eOmega(0) too big')
% end

% Prop.2
if Psiq(1) >= 2
    error('Psiq(0) too big')
end
if norm(edq(1),2)^2 >= 2/(mQ*lL)*kq*(2-Psiq(1))
    error('edq(0) too big')
end

%% Plots

lfont = 18; %Legend Fontsize
afont = 16; %Axis Fontsize
labfont = 20; %Label Fontsize
supfont = 25; %Suptitle Fontsize

foldername = 'C:\Users\Nam\Documents\Git\Thesis-Quadrotor-Code\NamMatlab\QRL\MatlabImages\';

% QRLplots

%% Animation

% QRLanimation
