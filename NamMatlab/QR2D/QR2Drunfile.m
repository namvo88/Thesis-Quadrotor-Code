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

% Attitude mode 1
% Position mode 0
mode = 1;
switch mode
    case 1
        disp('Attitude Controlled Mode')
    case 0
        disp('Position Controlled Mode')
end

Tend_sim = 10;
Ts_sim = 0.01;
t = 0:Ts_sim:Tend_sim;

xdes  = [0; 0; 0];
xLdes = [0; 0; 0];

b1d = [1; 0; 0];

% Develop test

%% Uncertainties

Deltax = [-0.5; 0.2; 1]; %Goodarzi2013a
DeltaR = [0.2; -0.1; 0.02]; %Goodarzi2013a

%% Constants
mQ      = 4.34; %Lee2010 %weight bebop 420 g
Ixx    = 0.0820; %Lee2010
Iyy    = 0; %Tang2014
Izz    = 0; %Tang2014
I      = diag([Ixx Iyy Izz]); %Tang2014
ctauf = 8.004e-3; %Lee2010c

mL = 0.5;
lL = 0.5;

b      = 0.1; %gok thrust factor
d      = 0.1; %gok drag factor
Ir     = 0.5; %gok
l      = 0.315; %Lee2010 %wingspan bebop 248 mm

g      = 9.81;

e3 = [0;0;1];

fsat = [-1000 1000];

c_der = inf;

%% Initial Conditions
x0      = 0;
y0      = 0;
z0      = 0;
dx0     = 0;
dy0     = 0;
dz0     = 0;
p0      = 0;
q0      = 0;
r0      = 0;

qvec0 = [0;0;1];
omega0 = [0;0;0];

switch mode
    case 1 %Attitude control
        phiQ0 = 0;
        Rx = [1 0 0;
            0 cosd(phiQ0) sind(phiQ0);
            0 -sind(phiQ0) cosd(phiQ0)];
        Rinit = Rx;

    case 0 %Position control
        Rinit = [1      0       0;
            0 -.9995 -0.0314;
            0 0.0314 -0.9995];
    otherwise
        disp('No Control Mode selected, Rinit = eye(3)');
        Rinit = eye(3);
end
Rinit

%% Gains

kx = 16*mQ;
kv = 5.6*mQ;

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


%% Plots

% QRplots
QRL2Dplots

%% Animation

QR2Dsimulation