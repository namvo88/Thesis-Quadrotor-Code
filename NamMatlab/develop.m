clear; clc; close all;

%% Settings
% Warning: Using a default value of 0.2 for maximum step size.  The simulation step size will be
% equal to or less than this value.  You can disable this diagnostic by setting 'Automatic solver
% parameter selection' diagnostic to 'none' in the Diagnostics page of the configuration
% parameters dialog 
% >> Turned to 'none'

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

%% Initial Conditions
x0 = 0;
y0 = 0;
z0 = 0;
psi0 = 0;
phi0 = 0;
theta0 = 0;
dx0 = 0;
dy0 = 0;
dz0 = 0;
dpsi0 = 0;
dphi0 = 0;
dtheta0 = 0;

%%

% u = [t;u]';
% u      = timeseries(u');
% f      = timeseries(f);

open('developsim')
sim('developsim')

figure
subplot 211
plot(simout)
% subplot 212
% plot(simout.signal2)