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

% t      = 1:10;


%% Variables

m      = 4.34; %Lee2010 %weight bebop 420 g
Ixx    = 0.0820; %Lee2010
Iyy    = 0.0845; %Lee2010
Izz    = .1377; %Lee2010
I      = diag([Ixx Iyy Izz]); %Goodarzi2014
b      = 1; %Geen thrust factor
d      = 8.004e-4; %Lee2010 c_tau_f
Ir     = 0.5; %gok
l      = 0.315; %Lee2010 %wingspan bebop 248 mm
g      = 9.81;

e3 = [0;0;1];

%% Initial Conditions
x0      = 0;
y0      = 0;
z0      = 0;
psi0    = 0;
phi0    = degtorad(2);
theta0  = 0;
dx0     = 0;
dy0     = 0;
dz0     = 0;
dpsi0   = 0;
dphi0   = 0;
dtheta0 = 0;

% syms phi theta psi

% R = [];
% M = timeseries(zeros(3,1));

%% Uncertainty Vectors
Deltax = [0; 0; 0]; %Goodarzi2013a
DeltaR = [0; 0; 0]; %Goodarzi2013a

%% Gain Matrices

kx = 16*m; %Lee2010
kv = 5.6*m; %Lee2010

kR_phi       = 8.81; %Lee2010
kR_theta     = 0.5;
kR_psi       = 0.5;
% kR           = diag([kR_phi;kR_theta;kR_psi]);
kR = kR_phi*eye(3);

kOmega_phi   = 2.54; %Lee2010
kOmega_theta = 0.5;
kOmega_psi   = 0.5;
% kOmega       = diag([kOmega_phi;kOmega_theta;kOmega_psi]);
kOmega = kOmega_phi*eye(3);

open('QRsim')
sim('QRsim')
