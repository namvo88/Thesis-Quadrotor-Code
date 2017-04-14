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

mode = 2;

Tend_sim = 20;
Ts_sim   = 0.01;
t        = 0:Ts_sim:Tend_sim;

% xQdes = [0; 0; 0];
xLd = [0; 0; 0];
b1d   = [1; 0; 0];

phiLd   = 0;
phiQd   = 0;



%% Uncertainties

Deltax = [-0.5; 0.2; 1]; %Goodarzi2013a
DeltaR = [0.2; -0.1; 0.02]; %Goodarzi2013a

%% Constants
mQ    = 4.34; %Lee2010 %weight bebop 420 g
Ixx   = 0.0820; %Lee2010
Iyy   = 0; %Tang2014
Izz   = 0; %Tang2014
I     = diag([Ixx Iyy Izz]); %Tang2014
ctauf = 8.004e-3; %Lee2010c

mL    = 0.2;
lL    = 0.4;

b     = 0.1; %gok thrust factor
d     = 0.1; %gok drag factor
Ir    = 0.5; %gok
l     = 0.315; %Lee2010 %wingspan bebop 248 mm

g     = 9.81;
fc    = (mQ+mL)*g;

e3    = [0;0;1];

fsat  = [-1000 1000];

c_der = inf;

%% Initial Conditions
xL0     = 0;
yL0     = 0;
zL0     = 0;
dxL0    = 0;
dyL0    = 0;
dzL0    = 0;

phiL0   = deg2rad(190);
thetaL0 = 0;
psiL0   = 0;
pL0     = 0;
qL0     = 0;
rL0     = 0;

phiQ0   = deg2rad(0); %deg
thetaQ0 = 0;
psiQ0   = 0;
pQ0     = 0;
qQ0     = 0;
rQ0     = 0;

qvec0   = [0; sin(phiL0); cos(phiL0)];
omega0  = [0;0;0];

switch mode
    case 2
        modename = 'QRL QR Attitude Controlled Mode';
        disp(modename)
    case 3
        modename = 'QRL Load Attitude Controlled Mode';
        disp(modename)
    case 4
        modename = 'QRL Load Position Controlled Mode';
        disp(modename)
    otherwise
        disp('No Control Mode selected, Rinit = eye(3)');
        Rinit = eye(3);
end

Rx = [1 0 0;
      0 cos(phiQ0) sin(phiQ0);
      0 -sin(phiQ0) cos(phiQ0)];

Rinit = Rx


%% Gains

kpQ = 16*mQ;
kdQ = 5.6*mQ*.75;

kpL = 1.2;
kdL = 1.4;

kpxL = 5;
kdxL = 1;

% kx = 16*mQ;
% kv = 5.6*mQ;

kR_phi       = 8.81; %Lee2010
kR_theta     = 0.5;
kR_psi       = 0.5;
% kR           = diag([kR_phi;kR_theta;kR_psi]);
kR = kR_phi*eye(3);
% kR = 8.81;

kOmega_phi   = 2.54; %Lee2010
kOmega_theta = 0.5;
kOmega_psi   = 0.5;
% kOmega       = diag([kOmega_phi;kOmega_theta;kOmega_psi]);
kOmega = kOmega_phi*eye(3);
% kOmega = 2.54;

%% Simulation

open('QR2Dsim')
sim('QR2Dsim')

if norm(inittest.signals.values(1,:))>=1
    norm(inittest.signals.values(1,:))
    error('norm( - kpL*eL - kdL*deL + ddphiLd*mQ*lL/f ) >= 1 !!')
end

%% Plots

% QRplots
QRL2Dplots

%% Animation

QR2Dsimulation
