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

xdes = [0;0;0]
b1d = [1;0;0]

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

fsat = 1000;

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

open('QRsim')
sim('QRsim')

% R0.signals.values(:,:,1)

%% Plots

t = simout.time;

pos = simout.signals.values(1:3,:);
vel = simout.signals.values(4:6,:);
acc = simout.signals.values(7:9,:);
posd = simposd.signals.values(1:3,:);
veld = simposd.signals.values(3:6,:);
accd = simposd.signals.values(7:9,:);

Omega = simout.signals.values(10:12,:);
Omegad = simOmegad.signals.values(:,:).';
Omegac = simOmegac.signals.values(:,:).';
dOmega = simout.signals.values(13:15,:);

eOmegac = simrotationcerror.signals.values(:,1:3);
eRc = simrotationcerror.signals.values(:,4:6);
eOmegad = simrotationerror.signals.values(:,1:3);
eRd = simrotationerror.signals.values(:,4:6);
errorfunc = simouterror.signals.values;

f = simout.signals.values(16,:);
M = simout.signals.values(17:19,:);
omegarot = simout.signals.values(20:23,:);
fi = simout.signals.values(24:27,:);

figure('Name','Input overview')
subplot(8,1,[1,2])
plot(t,f)
legend('f')
subplot(8,1,[3,4])
plot(t,M)
legend('\tau_\phi','\tau_\theta','\tau_\psi')
subplot 815
plot(t,fi(1,:))
legend('f_1')
subplot 816
plot(t,fi(2,:))
legend('f_2')
subplot 817
plot(t,fi(3,:))
legend('f_3')
subplot 818
plot(t,fi(4,:))
legend('f_4')


figure('Name','QR Pos/Vel/Acc overview')
subplot 311
plot(t,pos)
legend('x','y','z')
subplot 312
plot(t,vel)
subplot 313
plot(t,acc)
suptitle('Position/Velocity/Acceleration')

% figure
% plot(t,pos,'Linewidth',2)
% h_suptitle = suptitle('QR Position');
% set(h_suptitle,'FontSize',30);
% h_legend = legend('x','y','z');
% set(h_legend,'FontSize',25);

figure('Name','QR Position')
h_suptitle = suptitle('QR Position');
set(h_suptitle,'FontSize',30);
subplot 311
hold on
plot(t,pos(1,:),'Linewidth',2)
plot(t,xdes(1)*ones(size(pos(1,:))),'r--','Linewidth',2)
% h_t=ylabel('x');
% set(h_t, 'FontSize', 20);
h_legend = legend('x','x_d');
set(h_legend,'FontSize',25);
subplot 312
hold on
plot(t,pos(2,:),'Linewidth',2)
plot(t,xdes(2)*ones(size(pos(2,:))),'r--','Linewidth',2)
% h_t=ylabel('y');
% set(h_t, 'FontSize', 20);
h_legend = legend('y','y_d');
set(h_legend,'FontSize',25);
subplot 313
hold on
plot(t,pos(3,:),'Linewidth',2)
plot(t,xdes(3)*ones(size(pos(3,:))),'r--','Linewidth',2)
% h_t=ylabel('z');
% set(h_t, 'FontSize', 20);
h_legend = legend('z','z_d');
set(h_legend,'FontSize',25);



switch mode
    case 1 %Attitude
        figure('Name','Rotation Matrices')
        for j=1:3
            for n=1:3
                p=(j-1)*3+n;
                subplot(3,3,p)
                Rplot = reshape(R.signals.values(j,n,:),[length(R.signals.values),1]);
                Rdesplot = reshape(Rdes.signals.values(j,n,:),[length(Rdes.signals.values),1]);
                hold on
                axis([0 t(end) -1.2 1.2])
                plot(t,Rplot,'Linewidth',2)
                plot(t,Rdesplot,'r--','Linewidth',2)
            end
        end
        h_suptitle = suptitle('R and R_d \in\Re^{3\times3}');
        set(h_suptitle,'FontSize',30);
        h_legend = legend('R','R_d');
        set(h_legend,'FontSize',25,'Position',[.8,.8,.1,.1]);

        figure('Name','Attitude Errors')
        h_suptitle = suptitle('Attitude Errors');
        set(h_suptitle,'FontSize',30);
        subplot 211
        plot(t,eOmegad,'Linewidth',2)
        h_legend = legend('e_{\Omega}');
        set(h_legend,'FontSize',25);
        subplot 212
        plot(t,eRd,'Linewidth',2)
        h_legend = legend('e_{R}');
        set(h_legend,'FontSize',25);
        
        figure('Name','Attitude Error Function')
        plot(t,errorfunc,'Linewidth',2)
        h_suptitle = suptitle('Attitude Error function');
        set(h_suptitle,'FontSize',30);
        h_t=ylabel('\Psi(R,R_d)');
        set(h_t, 'FontSize', 20);
        
        figure('Name','Angular Velocity')
        subplot 311
        hold on
        plot(t,Omega(1,:),'Linewidth',2)
        plot(t,Omegad(1,:),'r--','Linewidth',2)
        h_t=ylabel('p');
        set(h_t, 'FontSize', 20);
        subplot 312
        hold on
        plot(t,Omega(2,:),'Linewidth',2)
        plot(t,Omegad(2,:),'r--','Linewidth',2)
        h_t=ylabel('q');
        set(h_t, 'FontSize', 20);
        subplot 313
        hold on
        plot(t,Omega(3,:),'Linewidth',2)
        plot(t,Omegad(3,:),'r--','Linewidth',2)
        h_t=ylabel('r');
        set(h_t, 'FontSize', 20);
        h_suptitle = suptitle('Angular Velocity');
        set(h_suptitle,'FontSize',30);
        h_legend = legend('\Omega','\Omega_d');
        set(h_legend,'FontSize',25);
        
    case 0 %Position
        figure('Name','Rotation Matrices')
        for j=1:3
            for n=1:3
                p=(j-1)*3+n;
                subplot(3,3,p)
                Rplot = reshape(R.signals.values(j,n,:),[length(R.signals.values),1]);
                Rcplot = reshape(Rc.signals.values(j,n,:),[length(Rc.signals.values),1]);
                hold on
                axis([0 t(end) -1.2 1.2])
                plot(t,Rplot,'Linewidth',2)
                plot(t,Rcplot,'r--','Linewidth',2)
            end
        end
        h_suptitle = suptitle('R and R_c \in\Re^{3\times3}');
        set(h_suptitle,'FontSize',30);
        h_legend = legend('R','R_c');
        set(h_legend,'FontSize',25,'Position',[.8,.8,.1,.1]);
        
        figure('Name','Attitude Errors')
        h_suptitle = suptitle('Attitude Errors');
        set(h_suptitle,'FontSize',30);
        subplot 211
        plot(t,eOmegac,'Linewidth',2)
        h_legend = legend('e_{\Omega}');
        set(h_legend,'FontSize',25);
        subplot 212
        plot(t,eRc,'Linewidth',2)
        h_legend = legend('e_{R}');
        set(h_legend,'FontSize',25);
                    
        figure('Name','Attitude Error Function')
        plot(t,errorfunc,'Linewidth',2)
        h_suptitle = suptitle('Attitude Error function');
        set(h_suptitle,'FontSize',30);
        h_t=ylabel('\Psi(R,R_d)');
        set(h_t, 'FontSize', 20);        
        
        figure('Name','Angular Velocity')
        subplot 311
        hold on
        plot(t,Omega(1,:),'Linewidth',2)
        plot(t,Omegac(1,:),'r--','Linewidth',2)
        h_t=title('p');
        set(h_t, 'FontSize', 20);
        subplot 312
        hold on
        plot(t,Omega(2,:),'Linewidth',2)
        plot(t,Omegac(2,:),'r--','Linewidth',2)
        h_t=title('q');
        set(h_t, 'FontSize', 20);
        subplot 313
        hold on
        plot(t,Omega(3,:),'Linewidth',2)
        plot(t,Omegac(3,:),'r--','Linewidth',2)
        h_t=title('r');
        set(h_t, 'FontSize', 20);
        h_suptitle = suptitle('Angular Velocity');
        set(h_suptitle,'FontSize',30);
        h_legend = legend('\Omega','\Omega_c');
        set(h_legend,'FontSize',25);
        
end
