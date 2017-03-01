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
d      = 1;
ctauf  = 8.004e-4; %Lee2010 c_tau_f
Ir     = 0; %gok
l      = 0.315; %Lee2010 %wingspan bebop 248 mm
g      = 9.81;

e3 = [0;0;1];

fsat = 300;

%% Initial Conditions
x0      = 0;
y0      = 0;
z0      = 0;
psi0    = 0;
phi0    = 0;
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

%% Mode
% mode = input('Choose mode: 1 = position controlled/2 = attitude controlled. Mode: ');
mode = 2;

switch mode
    case 1
        
    case 2
        x0      = 0;
        y0      = 0;
        z0      = 0;
        dx0     = 0;
        dy0     = 0;
        dz0     = 0;
        psi0    = 0;
        phi0    = degtorad(160);
        theta0  = 0;
        dx0     = 0;
        dy0     = 0;
        dz0     = 0;
        dpsi0   = 0;
        dphi0   = 0;
        dtheta0 = 0;
        xdes = [0;0;0];
        b1d = [1;0;0];
    otherwise
        disp('wrong value')
end

open('QRsim')
sim('QRsim')

%% Plots

t = scopeinputs.time;
f = scopeinputs.signals(1).values;
M = scopeinputs.signals(2).values;
omegarot = scopeinputs.signals(3).values;
fi = scopeinputs.signals(4).values;
Psi = scopeerrorfnc.signals.values;
Omega = scopeOmega.signals(1).values;
Omegades = scopeOmega.signals(2).values;
pos = scopepos.signals(1).values;
vel = scopepos.signals(2).values;
acc = scopepos.signals(3).values;

figure('Name','Inputs')
subplot 411
plot(t,fi(:,1),t,fi(:,2),t,fi(:,3),t,fi(:,4))
% ax1 = gca;
legend('f_1','f_2','f_3','f_4')
subplot 412
plot(t,f)
legend('f')
% ax2 = gca;
subplot 413
plot(t,M(:,1),t,M(:,2),t,M(:,3))
legend('\tau_\phi','\tau_\theta','\tau_\psi')
subplot 414
plot(t,omegarot(:,1),t,omegarot(:,2),t,omegarot(:,3),t,omegarot(:,4))
legend('\omega_{rot,1}','\omega_{rot,2}','\omega_{rot,3}','\omega_{rot,4}')

figure('Name','Error function')
plot(t,Psi)

figure('Name','Omega/Omegades')
subplot 311
plot(t,Omega(:,1),t,Omegades(:,1),'r-')
subplot 312
plot(t,Omega(:,2),t,Omegades(:,2),'r-')
subplot 313
plot(t,Omega(:,3),t,Omegades(:,3),'r-')
legend('\Omega','\Omega_d')

figure('Name','pos/vec/acc')
subplot 311
plot(t,pos(:,1),t,pos(:,2),t,pos(:,3))
subplot 312
plot(t,vel(:,1),t,vel(:,2),t,vel(:,3))
subplot 313
plot(t,acc(:,1),t,acc(:,2),t,acc(:,3))
