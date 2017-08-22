%% Dataconversion

t         = simoutL.time;

lqrposL   = lqrsimoutL.signals.values(:,1:3)';
posL      = simoutL.signals.values(:,1:3)';
velL      = simoutL.signals.values(:,4:6)';
accL      = simoutL.signals.values(:,7:9)';

lqrangleL = wrapTo180((lqrsimoutL1.signals.values(:,1:2)));
angleL    = wrapTo180(rad2deg(simoutL1.signals.values(:,1:3)));
OmegaL    = rad2deg(simoutL1.signals.values(:,4:6));

r11       = reshape(simoutR.signals.values(1,1,:),1,length(t));
r21       = reshape(simoutR.signals.values(2,1,:),1,length(t));
r31       = reshape(simoutR.signals.values(3,1,:),1,length(t));
r32       = reshape(simoutR.signals.values(3,2,:),1,length(t));
r33       = reshape(simoutR.signals.values(3,3,:),1,length(t));

psi       = atan(r21./r11);
theta     = atan(-r31./sqrt(r32.^2+r33.^2));
phi       = atan(r32./r33);

angleQ    = rad2deg([phi;theta;psi])';
lqrangleQ = lqrsimoutL2.signals.values(:,1:3);

OmegaQ    = rad2deg(simoutL2.signals.values(:,4:6));
dOmegaQ   = rad2deg(simoutL2.signals.values(:,7:9));

f         = simoutL3.signals.values(:,1);
M         = simoutL3.signals.values(:,2:4)';
omegarot  = simoutL3.signals.values(:,5:8)';
fi        = simoutL3.signals.values(:,9:12)';

q         = simoutq.signals.values(:,1:3)';
dq        = simoutq.signals.values(:,4:6)';
ddq       = simoutq.signals.values(:,7:9)';

eq        = simouteq.signals.values(:,1:3);
edq       = simouteq.signals.values(:,4:6);
eR        = simouterrorR.signals.values(:,1:3);
eOmega    = simouterrorR.signals.values(:,4:6);
Psiq      = simoutPsiq.signals.values(:,1);
PsiR      = simoutPsiR.signals.values(:,1);

xLd       = simoutxLd.signals.values(:,1:3)';
dxLd      = simoutxLd.signals.values(:,4:6)';
ddxLd     = simoutxLd.signals.values(:,7:9)';

exL       = simoutexL.signals.values(:,1:3)';
edxL      = simoutexL.signals.values(:,4:6)';
lqrexL    = lqrsimoutexL.signals.values(:,1:3)';

qcplot    = reshape(simoutqc.signals.values,[3,length(simoutqc.signals.values)]);

posQ      = posL - q*L;
lqrposQd  = lqrsimoutL4.signals.values(:,1:3)';
lqrposQ   = lqrsimoutL3.signals.values(:,1:3)';
exQ       = lqrposQ - lqrposQd;

caseBsigA = simoutsinegrowing.signals.values(:,1)';
caseBsigB = simoutsinegrowing.signals.values(:,2)';
caseBsigC = simoutsinegrowing.signals.values(:,3)';
% if nfile > 74
caseBsigD = simoutsinegrowing1.signals.values(:,4)';
caseBsigE = simoutsinegrowing1.signals.values(:,5)';
% end

exLperc = abs(exL)./xLd*100;
lqrexLperc = abs(lqrexL)./xLd*100;

%%
lfont = 23; %Legend Fontsize
afont = 18; %Axis Fontsize
labfont = 24; %Label Fontsize
supfont = 26; %Suptitle Fontsize

%%
for nfile = 40:100
    
    savename = strcat(foldername,'Gains',num2str(nfile),'.mat');
    if exist(savename,'file') == 0
    
        save(savename,'comment','comment2','epsi','facR','kR','kOmega','facq','kq','komega',...
            'facx','kpx','kdx','omega_n1_xL','omega_n2_xL','omega_n1_q',...
            'omega_n2_q','omega_n1_R','omega_n2_R','omega_n1_CFP','omega_n2_CFP','zeta_xL','zeta_q',...
            'zeta_R','LQRA','LQRB','LQRC','LQRD','K','LQRQ','LQRR','stept','stepamp','fsat','Msat');
        %         save(strcat(num2str(nfile),'.txt'),'kR','kOmega','kq','komega','kpx','kdx','mQ','mL','I','l','L','-ascii');
        
        % Write to Excel
        excelname = 'parameters.xlsx';
        %         exceldata = {'mQ',mQ;'mL',mL;'l',l;'L',L;'Ixx',Ixx;'Iyy',Iyy;'Izz',Izz;'kR',kR;'kOmega',kOmega;'kq',kq;'komega',komega;'kpx',kpx;'kdx',kdx};
        par = {'mQ';'mL';'l';'L';'Ixx';'Iyy';'Izz';'kR';'kOmega';'kq';'komega';'kpx';'kdx'};
        val = {mQ;mL;l;L;Ixx;Iyy;Izz;kR;kOmega;kq;komega;kpx;kdx};
        cfpar = {'omega_n1_xL';'omega_n2_xL';'omega_n1_CFP';'omega_n2_CFP';'zeta_xL';'omega_n1_q';'omega_n2_q';'zeta_q';'omega_n1_R';'omega_n2_R';'zeta_R';'eps'};
        cfval = {omega_n1_xL;omega_n2_xL;omega_n1_CFP;omega_n2_CFP;zeta_xL;omega_n1_q;omega_n2_q;zeta_q;omega_n1_R;omega_n2_R;zeta_R;eps};
        exceldata = [{'filenumber'},{nfile};par,val;cfpar,cfval];
        sheet = num2str(nfile);
        xlswrite(excelname,exceldata,sheet)
        
        break
    end
end
%%
save(strcat(foldername,modecode,num2str(nfile),'.mat'))
save(strcat(foldername,modecode,num2str(nfile),comment,'.mat'))

%% Inputs

filename = 'f';
figure('Name',filename)
h_suptitle = suptitle(strcat(filename,' $[N]$'));
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
subplot(6,1,[1,2])
plot(t,f,'Linewidth',2)
ylabel('\boldmath$f_{total}$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 613
plot(t,fi(1,:),'Linewidth',2)
ylabel('\boldmath$f_1$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 614
plot(t,fi(2,:),'Linewidth',2)
ylabel('\boldmath$f_2$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 615
plot(t,fi(3,:),'Linewidth',2)
ylabel('\boldmath$f_3$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 616
plot(t,fi(4,:),'Linewidth',2)
ylabel('\boldmath$f_4$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

filename = 'M';
figure('Name',filename)
h_suptitle = suptitle(strcat(filename,' $[Nm]$'));
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
plot(t,M,'Linewidth',2)
hl = legend('\boldmath$\tau_\phi$','\boldmath$\tau_\theta$','\boldmath$\tau_\psi$');
set(hl,'Interpreter','latex','FontSize',lfont)
ylabel('\boldmath$M$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

%%
% filename = 'Lpos';
% figure('Name',filename)
% h_sup = suptitle('Load Pos./Vel./Acc.');
% set(h_sup,'FontSize',supfont,'Interpreter','latex');
% subplot 311
% plot(t,posL,'Linewidth',2)
% hl = legend('\boldmath$x$','\boldmath$y$','\boldmath$z$');
% set(hl,'Interpreter','latex','FontSize',lfont);
% ylabel('\boldmath$[m]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% subplot 312
% plot(t,velL,'Linewidth',2)
% hl = legend('\boldmath$\dot{x}$','\boldmath$\dot{y}$','\boldmath$\dot{z}$');
% set(hl,'Interpreter','latex','FontSize',lfont);
% ylabel('\boldmath$[m/s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% subplot 313
% plot(t,accL,'Linewidth',2)
% hl = legend('\boldmath$\ddot{x}$','\boldmath$\ddot{y}$','\boldmath$\ddot{z}$');
% set(hl,'Interpreter','latex','FontSize',lfont);
% ylabel('\boldmath$[m/s^2]$','FontSize',labfont,'Interpreter','latex')
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% hLPosOverview = gcf;
% saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')
   
filename = 'xL';
figure('Name',filename)
h_sup = suptitle('Load Position $[m]$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,posL(1,:),t,xLd(1,:),'r--','Linewidth',2)
hl = legend('\boldmath$x_L$','\boldmath$x_{L,d}$');
ylabel('\boldmath$x$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 312
plot(t,posL(2,:),t,xLd(2,:),'r--','Linewidth',2)
ylabel('\boldmath$y$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 313
plot(t,posL(3,:),t,xLd(3,:),'r--','Linewidth',2)
ylabel('\boldmath$z$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')  

filename = 'dxL';
figure('Name',filename)
h_sup = suptitle('Load Velocity $[m/s]$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
if casename == 'C'
    subplot 311
    plot(t,velL(1,:),t,dxLd(1,:),'r--','Linewidth',2)
    hl = legend('\boldmath$x_L$','\boldmath$x_{L,d}$');
    ylabel('\boldmath$\dot{x}$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    subplot 312
plot(t,velL(2,:),t,dxLd(2,:),'r--','Linewidth',2)
end

if casename ~= 'C'
    subplot 211
    plot(t,velL(2,:),t,dxLd(2,:),'r--','Linewidth',2)
    hl = legend('\boldmath$x_L$','\boldmath$x_{L,d}$');
end
ylabel('\boldmath$\dot{y}$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
if casename == 'C'
    subplot 313
end
if casename ~= 'C'
    subplot 212
end
plot(t,velL(3,:),t,dxLd(3,:),'r--','Linewidth',2)
ylabel('\boldmath$\dot{z}$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

if casename ~= 'C'
    filename = 'dxLd-ddxLd';
    figure('Name',filename)
    h_sup = suptitle('Load Vel./Acc.');
    set(h_sup,'FontSize',supfont,'Interpreter','latex');
    subplot 211
    plot(t,velL(2,:),t,dxLd(2,:),'r--','Linewidth',2)
    hl = legend('\boldmath$\dot{y}_L$','\boldmath$\dot{y}_{L,d}$');
    set(hl,'Interpreter','latex','FontSize',lfont);
    ylabel('\boldmath$[m/s]$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    subplot 212
    plot(t,accL(2,:),t,ddxLd(2,:),'r--','Linewidth',2)
    hl = legend('\boldmath$\ddot{y}_L$','\boldmath$\ddot{y}_{L,d}$');
    ylabel('\boldmath$[m/s^2]$','FontSize',labfont,'Interpreter','latex')
    xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    set(hl,'Interpreter','latex','FontSize',lfont);
    saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')
end

filename = 'xLdes';
figure('Name',filename)
h_sup = suptitle('Desired Load Pos. $[m]$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,xLd(1,:),'r--','Linewidth',2)
hl = legend('\boldmath$x_{L,d}$');
ylabel('\boldmath$x$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 312
plot(t,xLd(2,:),'r--','Linewidth',2)
ylabel('\boldmath$y$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 313
plot(t,xLd(3,:),'r--','Linewidth',2)
ylabel('\boldmath$z$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png') 

filename = 'dxLdes';
figure('Name',filename)
h_sup = suptitle('Desired Load Vel.$[m/s]$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,dxLd(1,:),'r--','Linewidth',2)
hl = legend('\boldmath$\dot{x}_{L,d}$');
ylabel('\boldmath$\dot{x}$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 312
plot(t,dxLd(2,:),'r--','Linewidth',2)
ylabel('\boldmath$\dot{y}$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 313
plot(t,dxLd(3,:),'r--','Linewidth',2)
ylabel('\boldmath$\dot{z}$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

filename = 'ddxLdes';
figure('Name',filename)
h_sup = suptitle('Desired Load Acc.$[m/s^2]$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,ddxLd(1,:),'r--','Linewidth',2)
hl = legend('\boldmath$\ddot{x}_{L,d}$');
ylabel('\boldmath$\ddot{x}$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 312
plot(t,ddxLd(2,:),'r--','Linewidth',2)
ylabel('\boldmath$\ddot{y}$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 313
plot(t,ddxLd(3,:),'r--','Linewidth',2)
ylabel('\boldmath$\ddot{z}$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')
%% all xLd
if casename == 'A'
    filename = 'allxLd';
    figure('Name',filename)
    h_sup = suptitle('Desired Load Pos./Vel./Acc.');
    set(h_sup,'FontSize',supfont,'Interpreter','latex');
    subplot 311
    plot(t(1:200),xLd(2,1:200),'r--','Linewidth',2)
    hl = legend('\boldmath$y_{L,d}$');
    set(hl,'Interpreter','latex','FontSize',lfont);
    ylabel('\boldmath$[m]$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    subplot 312
    plot(t(1:200),dxLd(2,1:200),'r--','Linewidth',2)
        hl = legend('\boldmath$\dot{y}_{L,d}$');
    set(hl,'Interpreter','latex','FontSize',lfont);
    ylabel('\boldmath$[m/s]$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    subplot 313
    plot(t(1:200),ddxLd(2,1:200),'r--','Linewidth',2)
        hl = legend('\boldmath$\ddot{y}_{L,d}$');
    set(hl,'Interpreter','latex','FontSize',lfont);
    ylabel('\boldmath$[m/s^2]$','FontSize',labfont,'Interpreter','latex')
    xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    hLPosOverview = gcf;
    saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')
elseif casename == 'B'
        filename = 'allxLd';
    figure('Name',filename)
    h_sup = suptitle('Desired Load Pos./Vel./Acc.');
    set(h_sup,'FontSize',supfont,'Interpreter','latex');
    subplot 311
    plot(t,xLd(2,:),'r--','Linewidth',2)
    hl = legend('\boldmath$y_{L,d}$');
    set(hl,'Interpreter','latex','FontSize',lfont);
    ylabel('\boldmath$[m]$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    subplot 312
    plot(t,dxLd(2,:),'r--','Linewidth',2)
        hl = legend('\boldmath$\dot{y}_{L,d}$');
    set(hl,'Interpreter','latex','FontSize',lfont);
    ylabel('\boldmath$[m/s]$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    subplot 313
    plot(t,ddxLd(2,:),'r--','Linewidth',2)
        hl = legend('\boldmath$\ddot{y}_{L,d}$');
    set(hl,'Interpreter','latex','FontSize',lfont);
    ylabel('\boldmath$[m/s^2]$','FontSize',labfont,'Interpreter','latex')
    xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    hLPosOverview = gcf;
    saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')
    
end

%% xLdesplot
filename = 'xLdesplot';
figure('Name',filename)
h_sup = suptitle('Desired Load Position');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
hold on
plot3(xLd(1,:),xLd(2,:),xLd(3,:),'LineWidth',3)
plot3(xLd(1,1),xLd(2,1),xLd(3,1),'go','LineWidth',3)
plot3(xLd(1,end),xLd(2,end),xLd(3,end),'rd','LineWidth',3)
grid on
hold off
hl = legend('\boldmath$x_{L,d}$','Start','End');
view(-80,30)
xlabel('\boldmath$x [m]$','FontSize',labfont,'Interpreter','latex')
ylabel('\boldmath$y [m]$','FontSize',labfont,'Interpreter','latex')
zlabel('\boldmath$z [m]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')  

filename = 'xLdesplot';
for nplot = 1:3
    figure('Name',filename)
    if nplot == 1
        h_sup = suptitle('Desired Load Position (x,y)');
        set(h_sup,'FontSize',supfont,'Interpreter','latex');
        plot(xLd(1,:),xLd(2,:),'LineWidth',3)
            xlabel('\boldmath$x [m]$','FontSize',labfont,'Interpreter','latex')
    ylabel('\boldmath$y [m]$','FontSize',labfont,'Interpreter','latex')
    elseif nplot == 2
        h_sup = suptitle('Desired Load Position (x,z)');
        set(h_sup,'FontSize',supfont,'Interpreter','latex');
                plot(xLd(1,:),xLd(3,:),'LineWidth',3)
            xlabel('\boldmath$x [m]$','FontSize',labfont,'Interpreter','latex')
    ylabel('\boldmath$z [m]$','FontSize',labfont,'Interpreter','latex')
    else
        h_sup = suptitle('Desired Load Position (y,z)');
        set(h_sup,'FontSize',supfont,'Interpreter','latex');
                plot(xLd(2,:),xLd(3,:),'LineWidth',3)
            xlabel('\boldmath$y [m]$','FontSize',labfont,'Interpreter','latex')
    ylabel('\boldmath$z [m]$','FontSize',labfont,'Interpreter','latex')
    end

    set(gca,'FontSize',afont);
    saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nplot),'-',num2str(nfile)),'png')
end

%%

% filename = 'QRpos';
% figure('Name',filename)
% h_sup = suptitle('QR Pos./Vel./Acc.');
% set(h_sup,'FontSize',supfont,'Interpreter','latex');
% subplot 311
% plot(t,posQ,'Linewidth',2)
% hl = legend('\boldmath$x$','\boldmath$y$','\boldmath$z$');
% ylabel('\boldmath$[m]$','FontSize',labfont,'Interpreter','latex')
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% set(hl,'Interpreter','latex','FontSize',lfont);
% % subplot 312
% % plot(t,velQ,'Linewidth',2)
% % hl = legend('$\dot{x}$','$\dot{y}$','$\dot{z}$');
% % set(hl,'Interpreter','latex','FontSize',lfont);
% % ylabel('vel [m/s]','FontSize',labfont)
% % subplot 313
% % plot(t,accQ,'Linewidth',2)
% % hl = legend('$\ddot{x}$','$\ddot{y}$','$\ddot{z}$');
% % set(hl,'Interpreter','latex','FontSize',lfont);
% % ylabel('acc [m/s^2]','FontSize',labfont)
% saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

% filename = 'QRLpos';
% figure('Name',filename)
% h_suptitle = suptitle('QR-Load Position');
% set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
% subplot 311
% hold on
% plot(t,posL(1,:),t,posQ(1,:),'Linewidth',2);
% ylabel('\boldmath$x [m]$','FontSize',labfont,'Interpreter','latex');
% set(gca,'FontSize',afont);
% hl = legend('\boldmath$x_L$','\boldmath$x_Q$');
% subplot 312
% hold on
% plot(t,posL(2,:),t,posQ(2,:),'Linewidth',2);
% ylabel('\boldmath$y [m]$','FontSize',labfont,'Interpreter','latex');
% set(gca,'FontSize',afont);
% set(hl,'Interpreter','latex','FontSize',lfont,'Interpreter','latex');
% subplot 313
% hold on
% plot(t,posL(3,:),t,posQ(3,:),'Linewidth',2);
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
% ylabel('\boldmath$z [m]$','FontSize',labfont,'Interpreter','latex');
% set(gca,'FontSize',afont);
% set(hl,'Interpreter','latex','FontSize',lfont,'Position',[.8,.8,.1,.1]);
% saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

%%
% filename = 'QRang';
% figure('Name',filename)
% h_sup = suptitle('QR Angle');
% set(h_sup,'FontSize',supfont,'Interpreter','latex');
% subplot 211
% plot(t,angleQ(:,1),t,angleQ(:,2),'Linewidth',2)
% hl = legend('\boldmath$\phi_Q$','\boldmath$\theta_Q$');
% ylabel('\boldmath$[^\circ]$','FontSize',labfont,'Interpreter','latex')
% set(hl,'Interpreter','latex','FontSize',lfont);
% set(gca,'color','none','FontSize',afont)
% set(gca,'FontSize',afont);
% subplot 212
% plot(t,angleQ(:,3),'r','Linewidth',2)
% hl = legend('\boldmath$\psi_Q$');
% ylabel('\boldmath$[^\circ]$','FontSize',labfont,'Interpreter','latex')
% set(hl,'Interpreter','latex','FontSize',lfont);
% set(gca,'color','none','FontSize',afont)
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')
% 
% filename = 'QRvel';
% figure('Name',filename)
% h_sup = suptitle('QR $\Omega$/$\dot{\Omega}$');
% set(h_sup,'FontSize',supfont,'Interpreter','latex');
% subplot 211
% plot(t,OmegaQ,'Linewidth',2)
% hl = legend('\boldmath$p_Q$','\boldmath$q_Q$','\boldmath$r_Q$');
% set(hl,'Interpreter','latex','FontSize',lfont);
% ylabel('\boldmath$[^\circ/s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% subplot 212
% plot(t,dOmegaQ,'Linewidth',2)
% hl = legend('\boldmath$\dot{p}_Q$','\boldmath$\dot{q}_Q$','\boldmath$\dot{r}_Q$');
% set(hl,'Interpreter','latex','FontSize',lfont);
% ylabel('\boldmath$[^\circ/s^2]$','FontSize',labfont,'Interpreter','latex')
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

% filename = 'Lang';
% figure('Name',filename)
% h_sup = suptitle('Load Angle/$\Omega$');
% set(h_sup,'FontSize',supfont,'Interpreter','latex');
% subplot 311
% % plot(t,angleL,'Linewidth',2)
% % hl = legend('\boldmath$\phi_L$','\boldmath$\theta_L$','\boldmath$\psi_L$');
% plot(t,angleL(:,1),t,angleL(:,2),'Linewidth',2)
% hl = legend('\boldmath$\phi_L$','\boldmath$\theta_L$');
% ylabel('\boldmath$[^\circ]$','FontSize',labfont,'Interpreter','latex')
% set(hl,'Interpreter','latex','FontSize',lfont);
% set(gca,'color','none','FontSize',afont)
% subplot 312
% % plot(t,OmegaL,'Linewidth',2)
% % hl = legend('\boldmath$p_L$','\boldmath$q_L$','\boldmath$r_L$');
% plot(t,OmegaL(:,1),t,OmegaL(:,2),'Linewidth',2)
% hl = legend('\boldmath$p_L$','\boldmath$q_L$');
% set(hl,'Interpreter','latex','FontSize',lfont);
% ylabel('\boldmath$[^\circ/s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% % subplot 313
% % plot(t,dOmegaL,'Linewidth',2)
% % hl = legend('$\dot{p}_L$','$\dot{q}_L$','$\dot{r}_L$');
% % set(hl,'Interpreter','latex','FontSize',lfont);
% % ylabel('\boldmath$acc [^\circ/s^2]$','FontSize',labfont,'Interpreter','latex')
% % xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
% saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

% figure
% plot(t,pos,'Linewidth',2)
% h_suptitle = suptitle('QR Position');
% set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
% hl = legend('$x$','$y$','$z$');
% set(hl,'Interpreter','latex','FontSize',lfont)

%% Rotation Matrix
% 
% filename = 'Rotations';
% figure('Name',filename)
% h_sup = suptitle('Rotation $R\in\Re^{3\times3}$');
% set(h_sup,'FontSize',supfont,'Interpreter','latex');
% for j=1:3
%     for n=1:3
%         k=(j-1)*3+n;
%         subplot(3,3,k)
%         Rplot = reshape(simoutR.signals.values(j,n,:),[length(simoutR.signals.values),1]);
%         Rcplot = reshape(simoutRc.signals.values(j,n,:),[length(simoutRc.signals.values),1]);
%         hold on
%         axis([0 t(end) -1.1 1.1])
% %         axis([0 4 -1.2 1.2])
%         plot(t,Rplot,'Linewidth',2)
%         plot(t,Rcplot,'r--','Linewidth',2)
%         set(gca,'FontSize',afont);
%         if k==8
%             xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
%         end
%     end
% end
% switch mode
%     case 2 % QRL Attitude Controlled Mode
%         hl = legend('\boldmath$R$','\boldmath$R_d$');
%     otherwise
%         hl = legend('\boldmath$R$','\boldmath$R_c$');
% end
% set(hl,'Interpreter','latex','FontSize',lfont,'Position',[.8,.8,.1,.1]);
% saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

%% q

% filename = 'q';
% figure('Name',filename)
% h_suptitle = suptitle('Unit vector $q$ from QR to Load');
% set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
% plot(t,q,'LineWidth',2)
% 
% % hl = legend('$\vec{q}\cdot\vec{b}_1$','$\vec{q}\cdot\vec{b}_2$','$\vec{q}\cdot\vec{b}_3$');
% switch mode
%     case 3 % QRL Load Attitude Controlled Mode
%         subplot 311
%         plot(t,q(1,:),t,qcplot(1,:),'r--','Linewidth',2)
%         ylabel('\boldmath$\vec{q}\cdot\vec{b}_1$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%         subplot 312
%         plot(t,q(2,:),t,qcplot(2,:),'r--','Linewidth',2)
%         ylabel('\boldmath$\vec{q}\cdot\vec{b}_2$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%         subplot 313
%         plot(t,q(3,:),t,qcplot(3,:),'r--','Linewidth',2)
%         ylabel('\boldmath$\vec{q}\cdot\vec{b}_3$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%         hl = legend('\boldmath$\vec{q}$','\boldmath$\vec{q}_d$');        
%     case 4 % QRL Load Position Controlled Mode
%         subplot 311
%         plot(t,q(1,:),t,qcplot(1,:),'r--','Linewidth',2)
%         ylabel('\boldmath$\vec{q}\cdot\vec{b}_1$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%         subplot 312
%         plot(t,q(2,:),t,qcplot(2,:),'r--','Linewidth',2)
%         ylabel('\boldmath$\vec{q}\cdot\vec{b}_2$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%         subplot 313
%         plot(t,q(3,:),t,qcplot(3,:),'r--','Linewidth',2)
%         ylabel('\boldmath$\vec{q}\cdot\vec{b}_3$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%         hl = legend('\boldmath$\vec{q}$','\boldmath$\vec{q}_c$');  
% end
% set(hl,'Interpreter','latex','FontSize',lfont,'Position',[.8,.8,.1,.1]);
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex');
% saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

%% qplots

% filename = 'qplots';
% figure('Name',filename)
% h_suptitle = suptitle('Unit vector $q$ from QR to Load');
% set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
% plot(t,q,'LineWidth',2)
% subplot 311
% plot(t,q,'LineWidth',2)
% ylabel('\boldmath$q$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% subplot 312
% plot(t,dq,'LineWidth',2)
% ylabel('\boldmath$\dot{q}$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% subplot 313
% plot(t,ddq,'LineWidth',2)
% ylabel('\boldmath$\ddot{q}$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% hl = legend('\boldmath$\vec{b}_1$','\boldmath$\vec{b}_2$','\boldmath$\vec{b}_3$');  
% 
% set(hl,'Interpreter','latex','FontSize',lfont,'Position',[.8,.8,.1,.1]);
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex');
% saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

%% Errors

filename = 'eR';
figure('Name',filename)
h_suptitle = suptitle('QR Attitude Error $\in TSO(3)$');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
subplot 211
plot(t,eR,'Linewidth',2)
ylabel('\boldmath$e_{R}$','FontSize',labfont,'Interpreter','latex');
set(gca,'FontSize',afont);
hl = legend('\boldmath$e_{R,1}$','\boldmath$e_{R,2}$','\boldmath$e_{R,3}$','FontSize',lfont);
set(hl,'Interpreter','latex','FontSize',lfont);
subplot 212
plot(t,eOmega,'Linewidth',2);
ylabel('\boldmath$e_{\Omega}$','FontSize',labfont,'Interpreter','latex');
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
hl = legend('\boldmath$e_{\Omega,1}$','\boldmath$e_{\Omega,2}$','\boldmath$e_{\Omega,3}$','FontSize',lfont);
set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

filename = 'eq';
figure('Name',filename)
h_suptitle = suptitle('Load Attitude Error $\in TS^2$');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
subplot 211
plot(t,eq,'Linewidth',2);
ylabel('\boldmath$e_{q}$','FontSize',labfont,'Interpreter','latex');
set(gca,'FontSize',afont);
hl = legend('\boldmath$e_{q,1}$','\boldmath$e_{q,2}$','\boldmath$e_{q,3}$','FontSize',lfont);
set(hl,'Interpreter','latex','FontSize',lfont);
subplot 212
plot(t,edq,'Linewidth',2)
ylabel('\boldmath$e_{\dot{q}}$','FontSize',labfont,'Interpreter','latex');
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
hl = legend('\boldmath$e_{\dot{q},1}$','\boldmath$e_{\dot{q},2}$','\boldmath$e_{\dot{q},3}$','FontSize',lfont);
set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

filename = 'exL';
figure('Name',filename)
h_suptitle = suptitle('Load Error Pos.$[m]$/Vel.$[m/s]$');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
subplot 211
plot(t,exL,'Linewidth',2)
ylabel('\boldmath$e_{x}$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
hl = legend('\boldmath$e_{x}$','\boldmath$e_{y}$','\boldmath$e_{z}$');
set(hl,'Interpreter','latex','FontSize',lfont);
subplot 212
plot(t,edxL,'Linewidth',2)
ylabel('\boldmath$e_{v}$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
hl = legend('\boldmath$e_{\dot{x}}$','\boldmath$e_{\dot{y}}$','\boldmath$e_{\dot{z}}$');
set(hl,'Interpreter','latex','FontSize',lfont);
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')  

%% Error functions
       
filename = 'PsiR';
figure('Name',filename)
h_suptitle = suptitle('QR Attitude Error function');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
plot(t,PsiR,'Linewidth',2)
ylabel('\boldmath$\Psi_R$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')  

filename = 'Psiq';
figure('Name',filename)
h_suptitle = suptitle('Load Attitude Error function');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
plot(t,Psiq,'Linewidth',2)
ylabel('\boldmath$\Psi_q$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')  

%% Plot Case B
filename = 'sineCaseB';
figure('Name',filename)
h_sup = suptitle('Trajectory generation $[m]$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,caseBsigA,'r--','Linewidth',2)
% hl = legend('\boldmath$x_{L,d}$');
ylabel('\boldmath$sign.A$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 312
plot(t,caseBsigB,'r--','Linewidth',2)
ylabel('\boldmath$sign.B$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 313
plot(t,caseBsigC,'r--','Linewidth',2)
ylabel('\boldmath$sign.C$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
% set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png') 

% Plot Case B2
if nfile > 74
filename = 'sineCaseBB';
figure('Name',filename)
h_sup = suptitle('Trajectory generation $[m]$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,caseBsigC,'r--','Linewidth',2)
hl = legend('\boldmath$x_{L,d}$');
ylabel('\boldmath$sign.C$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 312
plot(t,caseBsigD,'r--','Linewidth',2)
ylabel('\boldmath$sign.D$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 313
plot(t,caseBsigE,'r--','Linewidth',2)
ylabel('\boldmath$sign.E$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png') 
end

%% Plot signals all cases 
if nfile > 77
allcasesigA = simoutwokkel1.signals.values(:,1)';
allcasesigB = simoutwokkel1.signals.values(:,2)';
allcasesigC = simoutwokkel1.signals.values(:,3)';
allcasesigD = simoutwokkel1.signals.values(:,4)';

filename = 'allcasesig';
figure('Name',filename)
h_sup = suptitle('Trajectory generation Signals:');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 411
plot(t,allcasesigA,'r--','Linewidth',2)
% hl = legend('\boldmath$x_{L,d}$');
ylabel('\boldmath$A$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 412
plot(t,allcasesigB,'r--','Linewidth',2)
ylabel('\boldmath$B$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 413
plot(t,allcasesigC,'r--','Linewidth',2)
ylabel('\boldmath$C$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 414
plot(t,allcasesigD,'r--','Linewidth',2)
ylabel('\boldmath$D$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
% set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png') 
end