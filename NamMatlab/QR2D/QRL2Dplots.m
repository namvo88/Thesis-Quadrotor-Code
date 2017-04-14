%% Plots

lfont = 18; %Legend Fontsize
afont = 16; %Axis Fontsize
labfont = 20; %Label Fontsize
supfont = 25; %Suptitle Fontsize

foldername = 'C:\Users\Nam\Documents\Git\Thesis-Quadrotor-Code\NamMatlab\QR2D\MatlabImages\';

t        = simoutL.time;

posL     = simoutL.signals.values(:,1:3)';
velL     = simoutL.signals.values(:,4:6)';
accL     = simoutL.signals.values(:,7:9)';

angleL   = reshape(simoutL1.signals.values(1:3,:,:),3,length(t));
OmegaL   = reshape(simoutL1.signals.values(4:6,:,:),3,length(t));
dOmegaL  = reshape(simoutL1.signals.values(7:9,:,:),3,length(t));

angleQ   = reshape(simoutL2.signals.values(1:3,:,:),3,length(t));
OmegaQ   = reshape(simoutL2.signals.values(4:6,:,:),3,length(t));
dOmegaQ  = reshape(simoutL2.signals.values(7:9,:,:),3,length(t));

f        = simoutL3.signals.values(:,1);
M        = simoutL3.signals.values(:,2:4)';
omegarot = simoutL3.signals.values(:,5:8)';
fi       = simoutL3.signals.values(:,9:12)';

qvecplot = qvec.signals.values(:,:)';

posQ = posL - qvecplot*lL;

% posd = simposd.signals.values(1:3,:);
% veld = simposd.signals.values(3:6,:);
% accd = simposd.signals.values(7:9,:);

% Omegad = simOmegad.signals.values(:,:).';
% Omegac = simOmegac.signals.values(:,:).';


% eOmegac = simrotationcerror.signals.values(:,1:3);
% eRc = simrotationcerror.signals.values(:,4:6);
% eOmegad = simrotationerror.signals.values(:,1:3);
% eRd = simrotationerror.signals.values(:,4:6);
% errorfunc = simouterror.signals.values;

figure('Name','Input f')
h_suptitle = suptitle('Input $f$ [N]');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
subplot(6,1,[1,2])
plot(t,f,'Linewidth',2)
ylabel('f_{total}','FontSize',labfont)
set(gca,'FontSize',afont);
subplot 613
plot(t,fi(1,:),'Linewidth',2)
ylabel('f_1','FontSize',labfont)
set(gca,'FontSize',afont);
subplot 614
plot(t,fi(2,:),'Linewidth',2)
ylabel('f_2','FontSize',labfont)
set(gca,'FontSize',afont);
subplot 615
plot(t,fi(3,:),'Linewidth',2)
ylabel('f_3','FontSize',labfont)
set(gca,'FontSize',afont);
subplot 616
plot(t,fi(4,:),'Linewidth',2)
ylabel('f_4','FontSize',labfont)
xlabel('Time [s]','FontSize',labfont)
set(gca,'FontSize',afont);
filename = 'Inputf';
saveas(gcf,strcat(foldername,filename,modename,date),'png');

figure('Name','Input M')
h_suptitle = suptitle('Input $M$');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
plot(t,M,'Linewidth',2)
hl = legend('$\tau_\phi$','$\tau_\theta$','$\tau_\psi$');
set(hl,'Interpreter','latex','FontSize',lfont)
ylabel('M [Nm]','FontSize',labfont)
xlabel('Time [s]','FontSize',labfont)
set(gca,'FontSize',afont);
filename = 'InputM';
saveas(gcf,strcat(foldername,filename,modename,date),'png');

figure('Name','LPosOverview')
h_sup = suptitle('Load Pos./Vel./Acc.');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,posL,'Linewidth',2)
hl = legend('$x$','$y$','$z$');
ylabel('pos [m]','FontSize',labfont)
set(hl,'Interpreter','latex','FontSize',lfont);
subplot 312
plot(t,velL,'Linewidth',2)
hl = legend('$\dot{x}$','$\dot{y}$','$\dot{z}$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('vel [m/s]','FontSize',labfont)
subplot 313
plot(t,accL,'Linewidth',2)
hl = legend('$\ddot{x}$','$\ddot{y}$','$\ddot{z}$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('acc [m/s^2]','FontSize',labfont)
hLPosOverview = gcf;
filename = 'LPosOverview';
saveas(gcf,strcat(foldername,filename,modename,date),'png');

figure('Name','QRPosOverview')
h_sup = suptitle('QR Pos./Vel./Acc.');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,posQ,'Linewidth',2)
hl = legend('$x$','$y$','$z$');
ylabel('pos [m]','FontSize',labfont)
set(hl,'Interpreter','latex','FontSize',lfont);
% subplot 312
% plot(t,velQ,'Linewidth',2)
% hl = legend('$\dot{x}$','$\dot{y}$','$\dot{z}$');
% set(hl,'Interpreter','latex','FontSize',lfont);
% ylabel('vel [m/s]','FontSize',labfont)
% subplot 313
% plot(t,accQ,'Linewidth',2)
% hl = legend('$\ddot{x}$','$\ddot{y}$','$\ddot{z}$');
% set(hl,'Interpreter','latex','FontSize',lfont);
% ylabel('acc [m/s^2]','FontSize',labfont)
hQRPosOverview = gcf;
filename = 'QRPosOverview';
saveas(gcf,strcat(foldername,filename,modename,date),'png');

figure('Name','QRAngOverview')
h_sup = suptitle('QR Angle/$\Omega$/$\dot{\Omega}$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,angleQ,'Linewidth',2)
hl = legend('$\phi_Q$','$\theta_Q$','$\psi_Q$');
ylabel('ang [rad]','FontSize',labfont)
set(hl,'Interpreter','latex','FontSize',lfont);
set(gca,'color','none')
subplot 312
plot(t,OmegaQ,'Linewidth',2)
hl = legend('$p_Q$','$q_Q$','$r_Q$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('vel [rad/s]','FontSize',labfont)
subplot 313
plot(t,dOmegaQ,'Linewidth',2)
hl = legend('$\dot{p}_Q$','$\dot{q}_Q$','$\dot{r}_Q$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('acc [rad/s^2]','FontSize',labfont)
hQRAngOverview = gcf;
filename = 'QRAngOverview';
saveas(gcf,strcat(foldername,filename,modename,date),'png');

figure('Name','LAngOverview')
h_sup = suptitle('Load Angle/$\Omega$/$\dot{\Omega}$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,angleL,'Linewidth',2)
hl = legend('$\phi_L$','$\theta_L$','$\psi_L$');
ylabel('ang [rad]','FontSize',labfont)
set(hl,'Interpreter','latex','FontSize',lfont);
set(gca,'color','none')
subplot 312
plot(t,OmegaL,'Linewidth',2)
hl = legend('$p_L$','$q_L$','$r_L$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('vel [rad/s]','FontSize',labfont)
subplot 313
plot(t,dOmegaL,'Linewidth',2)
hl = legend('$\dot{p}_L$','$\dot{q}_L$','$\dot{r}_L$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('acc [rad/s^2]','FontSize',labfont)
hLAngOverview = gcf;
filename = 'LAngOverview';
saveas(gcf,strcat(foldername,filename,modename,date),'png');

% figure
% plot(t,pos,'Linewidth',2)
% h_suptitle = suptitle('QR Position');
% set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
% hl = legend('$x$','$y$','$z$');
% set(hl,'Interpreter','latex','FontSize',lfont)

figure('Name','QR and Load Position')
h_suptitle = suptitle('QR and Load Position');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
subplot 311
hold on
plot(t,posL(1,:),t,posQ(1,:),'Linewidth',2);
% plot(t,xdes(1)*ones(size(posL(1,:))),'r--','Linewidth',2);
ylabel('x [m]','FontSize',labfont);
set(gca,'FontSize',afont);
% h_t=ylabel('x');
% set(h_t, 'FontSize',labfont);
hl = legend('$x_L$','$x_Q$');
set(hl,'Interpreter','latex','FontSize',lfont);
subplot 312
hold on
plot(t,posL(2,:),t,posQ(2,:),'Linewidth',2);
% plot(t,xdes(2)*ones(size(posL(2,:))),'r--','Linewidth',2);
ylabel('y [m]','FontSize',labfont);
set(gca,'FontSize',afont);
% h_t=ylabel('y');
% set(h_t, 'FontSize',labfont);
hl = legend('$y_L$','$y_Q$');
set(hl,'Interpreter','latex','FontSize',lfont);
subplot 313
hold on
plot(t,posL(3,:),t,posQ(3,:),'Linewidth',2);
% plot(t,xdes(3)*ones(size(posL(3,:))),'r--','Linewidth',2);
xlabel('Time [s]','FontSize',labfont);
ylabel('z [m]','FontSize',labfont);
set(gca,'FontSize',afont);
% h_t=ylabel('z');
% set(h_t, 'FontSize',labfont);
hl = legend('$z_L$','$z_Q$');
set(hl,'Interpreter','latex','FontSize',lfont);
filename = 'QRLPosition';
saveas(gcf,strcat(foldername,filename,modename,date),'png');

figure('Name','qvec')
h_suptitle = suptitle('Unit vector $q$ from QR to Load');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
plot(t,qvecplot,'LineWidth',2)
xlabel('Time [s]','FontSize',labfont);
set(gca,'FontSize',afont);
hl = legend('$\vec{x}$','$\vec{y}$','$\vec{z}$');
set(hl,'Interpreter','latex','FontSize',lfont);
filename = 'qvec';
saveas(gcf,strcat(foldername,filename,modename,date),'png');

figure('Name','Rotation Matrices')
for j=1:3
    for n=1:3
        k=(j-1)*3+n;
        subplot(3,3,k)
        Rplot = reshape(R.signals.values(j,n,:),[length(R.signals.values),1]);
%         Rcplot = reshape(Rc.signals.values(j,n,:),[length(Rc.signals.values),1]);
        hold on
        axis([0 t(end) -1.2 1.2])
        plot(t,Rplot,'Linewidth',2)
%         plot(t,Rcplot,'r--','Linewidth',2)
        set(gca,'FontSize',afont);
        if k==8
            xlabel('Time [s]','FontSize',labfont)
        end
    end
end
h_suptitle = suptitle('$R \in\Re^{3\times3}$');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
hl = legend('$R$');
set(hl,'Interpreter','latex','FontSize',lfont,'Position',[.8,.8,.1,.1]);


% switch mode
%     case 1 %Attitude
%         modename = 'Attitude Mode';        
%         figure('Name','Rotation Matrices')
%         for j=1:3
%             for n=1:3
%                 k=(j-1)*3+n;
%                 subplot(3,3,k)
%                 Rplot = reshape(R.signals.values(j,n,:),[length(R.signals.values),1]);
%                 Rdesplot = reshape(Rdes.signals.values(j,n,:),[length(Rdes.signals.values),1]);
%                 hold on
%                 axis([0 t(end) -1.2 1.2])
%                 plot(t,Rplot,'Linewidth',2)
%                 plot(t,Rdesplot,'r--','Linewidth',2)
%                 set(gca,'FontSize',afont);
%                 if k==8
%                     xlabel('Time [s]','FontSize',labfont)
%                 end                
%             end
%         end
%         h_suptitle = suptitle('R and R_d \in\Re^{3\times3}');
%         set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
%         hl = legend('$R$','$R_d$');
%         set(hl,'Interpreter','latex','FontSize',lfont,'Position',[.8,.8,.1,.1]);
% filename = 'RotationMatrix';
% saveas(gcf,strcat(foldername,filename,modename,date),'png');

% 
%         figure('Name','Attitude Errors')
%         h_suptitle = suptitle(strcat('Attitude Errors: ',modename));
%         set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
%         subplot 211
%         plot(t,eOmegad,'Linewidth',2);
%         ylabel('e_{\Omega}','FontSize',labfont);
%         set(gca,'FontSize',afont);
%         hl = legend('$e_p$','$e_q$','$e_r$','FontSize',lfont);
%         set(hl,'Interpreter','latex','FontSize',lfont);
%         subplot 212
%         plot(t,eRd,'Linewidth',2)
%         ylabel('e_{R_d}','FontSize',labfont);
%         xlabel('Time [s]','FontSize',labfont)
%         set(gca,'FontSize',afont);
%         hl = legend('$e_{R,1}$','$e_{R,2}$','$e_{R,3}$','FontSize',lfont); 
%         set(hl,'Interpreter','latex','FontSize',lfont);
%         saveas(gcf,strcat(foldername,date,'AttitudeErrors1'),'png');        
% 
%         figure('Name','Attitude Error Function')
%         plot(t,errorfunc,'Linewidth',2)
%         xlabel('Time [s]','FontSize',labfont)
%         ylabel('\Psi(R,R_d)','FontSize',labfont);
%         h_suptitle = suptitle('Attitude Error function');
%         set(h_suptitle,'FontSize',supfont,'Interpreter','latex');      
%         set(gca,'FontSize',afont);        
%         saveas(gcf,strcat(foldername,date,'AttitudeErrorFunction1'),'png');        
% 
%         figure('Name','Angular Velocity')
%         h_suptitle = suptitle('QR Angular Velocity \Omega');
%         set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
%         subplot 311
%         hold on
%         plot(t,Omega(1,:),'Linewidth',2)
%         plot(t,Omegad(1,:),'r--','Linewidth',2)
%         ylabel('p [rad/s]', 'FontSize',labfont);
%         set(gca,'FontSize',afont);
%         subplot 312
%         hold on
%         plot(t,Omega(2,:),'Linewidth',2)
%         plot(t,Omegad(2,:),'r--','Linewidth',2)
%         ylabel('q [rad/s]', 'FontSize',labfont);
%         set(gca,'FontSize',afont);
%         subplot 313
%         hold on
%         plot(t,Omega(3,:),'Linewidth',2)
%         plot(t,Omegad(3,:),'r--','Linewidth',2)
%         ylabel('r [rad/s]', 'FontSize',labfont);
%         xlabel('Time [s]','FontSize',labfont)
%         hl = legend('$\Omega$','$\Omega_c$');
%         set(hl,'Interpreter','latex','FontSize',lfont);
%         set(gca,'FontSize',afont);
%         saveas(gcf,strcat(foldername,date,'AngularVelocity1'),'png');           
%         
%         saveas(hQRPosOverview,strcat(foldername,date,'PosVelAccOverview1'),'png');
% 
%         
%     case 0 %Position
%         modename = 'Position Mode';
%         figure('Name','Rotation Matrices')
%         for j=1:3
%             for n=1:3
%                 k=(j-1)*3+n;
%                 subplot(3,3,k)
%                 Rplot = reshape(R.signals.values(j,n,:),[length(R.signals.values),1]);
%                 Rcplot = reshape(Rc.signals.values(j,n,:),[length(Rc.signals.values),1]);
%                 hold on
%                 axis([0 t(end) -1.2 1.2])
%                 plot(t,Rplot,'Linewidth',2)
%                 plot(t,Rcplot,'r--','Linewidth',2)
%                 set(gca,'FontSize',afont);
%                 if k==8
%                     xlabel('Time [s]','FontSize',labfont)
%                 end
%             end
%         end
%         h_suptitle = suptitle('R and R_c \in\Re^{3\times3}');
%         set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
%         hl = legend('$R$','$R_c$');
%         set(hl,'Interpreter','latex','FontSize',lfont,'Position',[.8,.8,.1,.1]);
%         saveas(gcf,strcat(foldername,date,'RotationMatrix0'),'png');
%         
%         figure('Name','Attitude Errors')
%         h_suptitle = suptitle(strcat('Attitude Errors: ',modename));
%         set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
%         subplot 211
%         plot(t,eOmegac,'Linewidth',2);
%         ylabel('e_{\Omega}','FontSize',labfont);
%         set(gca,'FontSize',afont);
%         hl = legend('$e_p$','$e_q$','$e_r$');
%         set(hl,'Interpreter','latex','FontSize',lfont)
%         subplot 212
%         plot(t,eRc,'Linewidth',2)
%         ylabel('e_{R_c}','FontSize',labfont);
%         xlabel('Time [s]','FontSize',labfont)
%         set(gca,'FontSize',afont);
%         hl = legend('$e_{R,1}$','$e_{R,2}$','$e_{R,3}$');   
%         set(hl,'Interpreter','latex','FontSize',lfont)
%         saveas(gcf,strcat(foldername,date,'AttitudeErrors0'),'png');
%                             
%         figure('Name','Attitude Error Function')
%         plot(t,errorfunc,'Linewidth',2)
%         xlabel('Time [s]','FontSize',labfont)
%         ylabel('\Psi(R,R_d)','FontSize',labfont);
%         h_suptitle = suptitle('Attitude Error function');
%         set(h_suptitle,'FontSize',supfont,'Interpreter','latex');      
%         set(gca,'FontSize',afont);        
%         saveas(gcf,strcat(foldername,date,'AttitudeErrorFunction0'),'png');
%         
%         figure('Name','Angular Velocity')%         
%         h_suptitle = suptitle('QR Angular Velocity \Omega');
%         set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
%         subplot 311
%         hold on
%         plot(t,Omega(1,:),'Linewidth',2)
%         plot(t,Omegac(1,:),'r--','Linewidth',2)
%         ylabel('p [rad/s]', 'FontSize',labfont);
%         set(gca,'FontSize',afont);
%         subplot 312
%         hold on
%         plot(t,Omega(2,:),'Linewidth',2)
%         plot(t,Omegac(2,:),'r--','Linewidth',2)
%         ylabel('q [rad/s]', 'FontSize',labfont);
%         set(gca,'FontSize',afont);
%         subplot 313
%         hold on
%         plot(t,Omega(3,:),'Linewidth',2)
%         plot(t,Omegac(3,:),'r--','Linewidth',2)
%         ylabel('r [rad/s]', 'FontSize',labfont);
%         xlabel('Time [s]','FontSize',labfont)
%         hl = legend('$\Omega$','$\Omega_c$');
%         set(hl,'Interpreter','latex','FontSize',lfont)
%         set(gca,'FontSize',afont);
%         saveas(gcf,strcat(foldername,date,'AngularVelocity0'),'png');      
%         
%         saveas(hQRPosOverview,strcat(foldername,date,'PosVelAccOverview0'),'png');
%         
% end