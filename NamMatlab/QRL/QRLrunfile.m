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

% OPTIONS
animation = 0;
plots     = 1;
savegain  = 1;

comment = strcat('Step',date);
comment2 = ('Fpd is afhankelijk van kq en kOmega, betere demping/voorspelling');

%% Input signals

% CONTROL MODE
% QR Position Controlled mode 0
% QR Attitude Controlled mode 1
% QRL QR Attitude Controlled mode 2
% QRL Load Attitude Controlled mode 3
% QRL Load Position Controlled mode 4
mode      = 4;

% LOAD ATTITUDE MODE
% Normal -1
% Inverted 1
qmode     = -1;

Tsim_end  = 15;
Tsim_s    = 0.01;

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

T0 = 3; %Time period of oscillation of load

% xLd = [zeros(1,length(t)); sin(2*pi*t/T0); zeros(1,length(t))];
b1d = [1; 0; 0];
Rd  = eye(3);
qd  = [0; 0; qmode];


%% Constants
mQ     = 4.34; %Lee2010 %weight bebop 420 g
Ixx    = 0.0820; %Lee2010
Iyy    = 0.0845; %Lee2010
Izz    = 0.1377; %Lee2010
I      = diag([Ixx Iyy Izz]); %Tang2014
lamb_m = min(eig(I));
lamb_M = max(eig(I));
ctauf  = 8.004e-3; %Lee2010c

% mL     = 0.045; %Praveen
% lL         = 1.12; %Praveen
mL     = 0.1;
lL     = 0.7;

b      = 0.1; %gok thrust factor
d      = 0.1; %gok drag factor
Ir     = 0.5; %gok
l      = 0.315; %Lee2010 %wingspan bebop 248 mm

g      = 9.81;
e3     = [0;0;1];

% fc     = (mQ+mL)*g;
fsat   = inf*[1 -1];
Msat   = inf*[1 -1];

%% Initial Conditions QR

phiQ0deg   = 0;
thetaQ0deg = 0;
psiQ0deg   = 0;

phiQ0      = deg2rad(phiQ0deg);
thetaQ0    = deg2rad(thetaQ0deg);
psiQ0      = deg2rad(psiQ0deg);
pQ0        = 0;
qQ0        = 0;
rQ0        = 0;

Rz         = [cos(psiQ0) -sin(psiQ0) 0;
                sin(psiQ0) cos(psiQ0) 0;
                0 0 1];
Ry         = [cos(thetaQ0) 0 sin(thetaQ0);
                0 1 0;
                -sin(thetaQ0) 0 cos(thetaQ0)];
Rx         = [1 0 0;
                0 cos(phiQ0) -sin(phiQ0);
                0 sin(phiQ0) cos(phiQ0)];
Rzyx       = (Rx*Ry*Rz);
R0         = Rzyx;

%% Initial Conditions Load
dxL0       = 0;
dyL0       = 0;
dzL0       = 0;

phiL0deg   = 0;
thetaL0deg = 0;

phiL0      = deg2rad(phiL0deg);
thetaL0    = deg2rad(thetaL0deg);
psiL0      = 0;

pL0        = 0;
qL0        = 0;
rL0        = 0;

dq0        = [0;0;0];
% omega0     = [0;0;0];

Ry         = [cos(thetaL0) 0 sin(thetaL0);
                0 1 0;
                -sin(thetaL0) 0 cos(thetaL0)];
Rx         = [1 0 0;
                0 cos(phiL0) -sin(phiL0);
                0 sin(phiL0) cos(phiL0)];
Rzyx       = (Rx*Ry);
q0         = Rzyx*e3*qmode;

% xL0        = q0(1)*lL;
% yL0        = q0(2)*lL;
% zL0        = q0(3)*lL;

xL0        = 0;
yL0        = 0;
zL0        = 0;

% x0 = [xL0;yL0;zL0];

%% Simulation

eps = 0.99; % 0<eps<1
psi_1 = .9; % Constant Psiq(0)<Psi_1<1 Lee2010 
exLmax = 5; %Fixed constant


% Gains QR Attitude
facR = 4.5;
kR = 8.81*facR; %Lee2010
kOmega = 2.4*facR;

% Gains Load Attitude
facq = 5; %2.9;
kq = facq*10;
komega = facq*2.5;%*4;

% Gains Load Position
facx = 1; %4;
kpx = facx*17.5;
kdx = facx*5; %*7.8;


% % Command Filter Low Pass filter 2nd order
% omega_n_xL = 2*pi*.5;
% omega_n_q = 2*pi*.8;
% omega_n_R = 2*pi*.05;

% Command Filter Low Pass filter 3th order
omega_n1_xL = 2*pi*0.4;
omega_n2_xL = 2*pi*0.55;
omega_n1_CFP = 2*pi*2;%*30;
omega_n2_CFP = 2*pi*2;%*20;
zeta_xL = 0.975;
omega_n1_q = 2*pi*10;
omega_n2_q = 2*pi*10;
zeta_q = 0.975;
omega_n1_R = 2*pi*20; %15
omega_n2_R = 2*pi*15;
zeta_R = 0.98;

% Save gains in mat-files
if savegain == 1
    foldername = 'C:\Users\Nam\Documents\Git\Thesis-Quadrotor-Code\NamMatlab\QRL\GainFiles\';
%     foldername = 'C:\Users\Nam\Documents\Git\Thesis-Quadrotor-Code\NamMatlab\QRL\MatlabImages\';
        
    for nfile = 1:100
        savename = strcat(foldername,num2str(nfile),'.mat');
                
        if exist(savename,'file') == 0
            save(savename,'comment','comment2','facR','kR','kOmega','facq','kq','komega','facx','kpx','kdx','omega_n1_CFP','omega_n2_CFP','omega_n1_xL','omega_n2_xL','omega_n1_q','omega_n2_q','omega_n1_R','omega_n2_R','zeta_xL','zeta_q','zeta_R')
            break
        end
    end
end

% loadpath = 'C:\Users\Nam\Documents\Git\Thesis-Quadrotor-Code\NamMatlab\QRL\GainFiles\';
% loadfile = strcat(loadpath,'13','.mat');
% load(loadfile)

%%
LQRrunfile
sim('QRLsim');


% Dataconversion

t        = simoutL.time;

posL     = simoutL.signals.values(:,1:3)';
velL     = simoutL.signals.values(:,4:6)';
accL     = simoutL.signals.values(:,7:9)';

angleL   = wrapTo180(rad2deg(simoutL1.signals.values(:,1:3)));
OmegaL   = (rad2deg(simoutL1.signals.values(:,4:6)));

r11 = reshape(simoutR.signals.values(1,1,:),1,length(t));
r21 = reshape(simoutR.signals.values(2,1,:),1,length(t));
r31= reshape(simoutR.signals.values(3,1,:),1,length(t));
r32= reshape(simoutR.signals.values(3,2,:),1,length(t));
r33= reshape(simoutR.signals.values(3,3,:),1,length(t));

psi = atan(r21./r11);
theta = atan(-r31./sqrt(r32.^2+r33.^2));
phi = atan(r32./r33);

angleQ = rad2deg([phi;theta;psi])';
OmegaQ   = (rad2deg(simoutL2.signals.values(:,4:6)));
dOmegaQ  = (rad2deg(simoutL2.signals.values(:,7:9)));

f        = simoutL3.signals.values(:,1);
M        = simoutL3.signals.values(:,2:4)';
omegarot = simoutL3.signals.values(:,5:8)';
fi       = simoutL3.signals.values(:,9:12)';

q        = simoutq.signals.values(:,1:3)';
dq       = simoutq.signals.values(:,4:6)';
ddq      = simoutq.signals.values(:,7:9)';

eq       = simouteq.signals.values(:,1:3);
edq      = simouteq.signals.values(:,4:6);
eR       = simouterrorR.signals.values(:,1:3);
eOmega   = simouterrorR.signals.values(:,4:6);
Psiq     = simoutPsiq.signals.values(:,1);
PsiR     = simoutPsiR.signals.values(:,1);

xLd      = simoutxLd.signals.values(:,1:3)';
dxLd     = simoutxLd.signals.values(:,4:6)';
ddxLd    = simoutxLd.signals.values(:,7:9)';

exL      = simoutexL.signals.values(:,1:3)';

F        = reshape(simoutF.signals.values,3,length(t));
qcplot   = reshape(simoutqc.signals.values,[3,length(simoutqc.signals.values)]);

posQ     = posL - q*lL;

%% Conditions check

% Prop.1 Sreenath2013b
if PsiR(1) >= 2
    error('PsiR(0) >= 2');
end
if norm(eOmega(1),2)^2 >= 2/lamb_M * kR/eps^2 * (2-PsiR(1))
    error('eOmega(0) too big')
end

% Prop.2 Sreenath2013b
if mode >= 3
    if Psiq(1) >= 2
        error('Psiq(0) >= 2');
    end
    if norm(edq(1),2)^2 >= 2/(mQ*lL)*kq*(2-Psiq(1))
        error('edq(0) too big');
    end
end

% Prop.3 Sreenath2013b
if mode == 4
    if Psiq(1) >= psi_1
        error('Psiq(0) >= psi_1')
    end
    if norm(exL(:,1)) >= exLmax
        error('norm(exL(:,1)) >= exLmax')
    end
    if norm(edq(1,:))^2 >= 2/(mQ*lL)*kq*(psi_1-Psiq(1))
        error('edq(0) too big. Prop.3 Sreenath2013b')
    end
end

%% Plots
if plots == 1
    QRLplots
end

%% Animation
if animation == 1
    QRLanimation
end