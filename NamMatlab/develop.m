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

m      = 0.42; %weight bebop 420 g
Ixx    = 1.5;
Iyy    = 1.5;
Izz    = 1.5;
I      = diag([Ixx Iyy Izz]);
b      = 0.1;
d      = 0.1;
Ir     = 0.5;
l      = 0.12; %wingspan bebop 248 mm
g      = 9.81;

e3 = [0;0;1];

%% Initial Conditions
x0 = 0;
y0 = 0;
z0 = -2;
psi0 = 0;
phi0 = 0;
theta0 = 0;
dx0 = 0;
dy0 = 0;
dz0 = 0;
dpsi0 = 0;
dphi0 = 0;
dtheta0 = 0;

R = timeseries(zeros(3,3));
M = timeseries(zeros(3,1));

%%

% u = [t;u]';
% u      = timeseries(u');
% f      = timeseries(f);

open('developsim')
sim('developsim')
