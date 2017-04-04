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
mode = 0;
switch mode
    case 1
        disp('Attitude Controlled Mode')
    case 0
        disp('Position Controlled Mode')
end

xdes = [0 0 0]';
b1d = [1 0 0]';

% Develop test

%% Uncertainties

Deltax = [-0.5; 0.2; 1]; %Goodarzi2013a
DeltaR = [0.2; -0.1; 0.02]; %Goodarzi2013a

%% Constants
m      = 4.34; %Lee2010 %weight bebop 420 g
Ixx    = 0.0820; %Lee2010
Iyy    = 0.0845; %Lee2010
Izz    = .1377; %Lee2010
I      = diag([Ixx Iyy Izz]); %Goodarzi2014
ctauf = 8.004e-3; %Lee2010c

b      = 0.1; %gok
d      = 0.1; %gok
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

switch mode
    case 1
        phi = 20;
        theta = 0;
        psi = 0;
        Rz = [cosd(psi) sind(psi) 0;
            -sind(psi) cosd(psi) 0;
            0 0 1];
        Ry = [cosd(theta) 0 -sind(theta);
            0 1 0;
            sin(theta) 0 cosd(theta)];
        Rx = [1 0 0;
            0 cosd(phi) sind(phi);
            0 -sind(phi) cosd(phi)];
        Rzyx = (Rx*Ry*Rz);
        Rinit = Rzyx;
    case 0
        Rinit = [1      0       0;
            0 -.9995 -0.0314;
            0 0.0314 -0.9995];
    otherwise
        disp('No Control Mode selected, Rinit = eye(3)');
        Rinit = eye(3);
end
Rinit

%% Gains

kx = 16*m;
kv = 5.6*m;

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

open('QRsim')
sim('QRsim')


%% Plots

QRplots

%% Animation

QRsimulation
