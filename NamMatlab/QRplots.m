%% Plots

foldername = 'C:\Users\Nam\Documents\Git\Thesis-Quadrotor-Code\NamMatlab\MatlabImages\';

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

figure('Name','Input f')
h_suptitle = suptitle('Input f [N]');
set(h_suptitle,'FontSize',30);
subplot(6,1,[1,2])
plot(t,f,'Linewidth',2)
ylabel('f_{total}','FontSize',20)
set(gca,'FontSize',16);
subplot 613
plot(t,fi(1,:),'Linewidth',2)
ylabel('f_1','FontSize',20)
set(gca,'FontSize',16);
subplot 614
plot(t,fi(2,:),'Linewidth',2)
ylabel('f_2','FontSize',20)
set(gca,'FontSize',16);
subplot 615
plot(t,fi(3,:),'Linewidth',2)
ylabel('f_3','FontSize',20)
set(gca,'FontSize',16);
subplot 616
plot(t,fi(4,:),'Linewidth',2)
ylabel('f_4','FontSize',20)
xlabel('Time [s]','FontSize',20)
set(gca,'FontSize',16);
saveas(gcf,strcat(foldername,'Inputf.png'));

figure('Name','Input M')
h_suptitle = suptitle('Input M [Nm]');
set(h_suptitle,'FontSize',30);
plot(t,M,'Linewidth',2)
h_legend = legend('\tau_\phi','\tau_\theta','\tau_\psi');
set(h_legend,'FontSize',25);
ylabel('M','FontSize',20)
xlabel('Time [s]','FontSize',20)
set(gca,'FontSize',16);
saveas(gcf,strcat(foldername,'InputM.png'));

figure('Name','QRPosOverview')
subplot 311
plot(t,pos)
legend('x','y','z')
subplot 312
plot(t,vel)
subplot 313
plot(t,acc)
suptitle('Position/Velocity/Acceleration')
hQRPosOverview = gcf;

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
plot(t,pos(1,:),'Linewidth',2);
plot(t,xdes(1)*ones(size(pos(1,:))),'r--','Linewidth',2);
ylabel('x [m]','FontSize', 20);
set(gca,'FontSize',16);
% h_t=ylabel('x');
% set(h_t, 'FontSize', 20);
h_legend = legend('x','x_d');
set(h_legend,'FontSize',25);
subplot 312
hold on
plot(t,pos(2,:),'Linewidth',2);
plot(t,xdes(2)*ones(size(pos(2,:))),'r--','Linewidth',2);
ylabel('y [m]','FontSize', 20);
set(gca,'FontSize',16);
% h_t=ylabel('y');
% set(h_t, 'FontSize', 20);
h_legend = legend('y','y_d');
set(h_legend,'FontSize',25);
subplot 313
hold on
plot(t,-pos(3,:),'Linewidth',2);
plot(t,xdes(3)*ones(size(pos(3,:))),'r--','Linewidth',2);
xlabel('Time [s]','FontSize', 20);
ylabel('z [m]','FontSize', 20);
set(gca,'FontSize',16);
% h_t=ylabel('z');
% set(h_t, 'FontSize', 20);
h_legend = legend('z','z_d');
set(h_legend,'FontSize',25);
saveas(gcf,strcat(foldername,'QRPosition.png'));



switch mode
    case 1 %Attitude
        modename = 'Attitude Mode';        
        figure('Name','Rotation Matrices')
        for j=1:3
            for n=1:3
                k=(j-1)*3+n;
                subplot(3,3,k)
                Rplot = reshape(R.signals.values(j,n,:),[length(R.signals.values),1]);
                Rdesplot = reshape(Rdes.signals.values(j,n,:),[length(Rdes.signals.values),1]);
                hold on
                axis([0 t(end) -1.2 1.2])
                plot(t,Rplot,'Linewidth',2)
                plot(t,Rdesplot,'r--','Linewidth',2)
                set(gca,'FontSize',16);
                if k==8
                    xlabel('Time [s]','FontSize', 20)
                end                
            end
        end
        h_suptitle = suptitle('R and R_d \in\Re^{3\times3}');
        set(h_suptitle,'FontSize',30);
        h_legend = legend('R','R_d');
        set(h_legend,'FontSize',25,'Position',[.8,.8,.1,.1]);
        saveas(gcf,strcat(foldername,'RotationMatrix1.png'));

        figure('Name','Attitude Errors')
        h_suptitle = suptitle(strcat('Attitude Errors: ',modename));
        set(h_suptitle,'FontSize',30);
        subplot 211
        plot(t,eOmegad,'Linewidth',2);
        ylabel('e_{\Omega}','FontSize',20);
        set(gca,'FontSize',16);
        legend('e_p','e_q','e_r','FontSize',25);
        subplot 212
        plot(t,eRd,'Linewidth',2)
        ylabel('e_{R_d}','FontSize',20);
        xlabel('Time [s]','FontSize', 20)
        set(gca,'FontSize',16);
        legend('e_{R,1}','e_{R,2}','e_{R,3}','FontSize',25);        
        saveas(gcf,strcat(foldername,'AttitudeErrors1.png'));        

        figure('Name','Attitude Error Function')
        plot(t,errorfunc,'Linewidth',2)
        xlabel('Time [s]','FontSize', 20)
        ylabel('\Psi(R,R_d)','FontSize', 20);
        h_suptitle = suptitle('Attitude Error function');
        set(h_suptitle,'FontSize',30);      
        set(gca,'FontSize',16);        
        saveas(gcf,strcat(foldername,'AttitudeErrorFunction1.png'));        

        figure('Name','Angular Velocity')
        subplot 311
        hold on
        plot(t,Omega(1,:),'Linewidth',2)
        plot(t,Omegad(1,:),'r--','Linewidth',2)
        ylabel('p [rad/s]', 'FontSize', 20);
        set(gca,'FontSize',16);
        subplot 312
        hold on
        plot(t,Omega(2,:),'Linewidth',2)
        plot(t,Omegad(2,:),'r--','Linewidth',2)
        ylabel('q [rad/s]', 'FontSize', 20);
        set(gca,'FontSize',16);
        subplot 313
        hold on
        plot(t,Omega(3,:),'Linewidth',2)
        plot(t,Omegad(3,:),'r--','Linewidth',2)
        ylabel('r [rad/s]', 'FontSize', 20);
        xlabel('Time [s]','FontSize', 20)
        h_suptitle = suptitle('Angular Velocity \Omega');
        set(h_suptitle,'FontSize',30);
        legend('\Omega','\Omega_c','FontSize',25);
        set(gca,'FontSize',16);
        saveas(gcf,strcat(foldername,'AngularVelocity1.png'));           
        
        saveas(hQRPosOverview,strcat(foldername,'PosVelAccOverview1.png'));

        
    case 0 %Position
        modename = 'Position Mode';
        figure('Name','Rotation Matrices')
        for j=1:3
            for n=1:3
                k=(j-1)*3+n;
                subplot(3,3,k)
                Rplot = reshape(R.signals.values(j,n,:),[length(R.signals.values),1]);
                Rcplot = reshape(Rc.signals.values(j,n,:),[length(Rc.signals.values),1]);
                hold on
                axis([0 t(end) -1.2 1.2])
                plot(t,Rplot,'Linewidth',2)
                plot(t,Rcplot,'r--','Linewidth',2)
                set(gca,'FontSize',16);
                if k==8
                    xlabel('Time [s]','FontSize', 20)
                end
            end
        end
        h_suptitle = suptitle('R and R_c \in\Re^{3\times3}');
        set(h_suptitle,'FontSize',30);
        h_legend = legend('R','R_c');
        set(h_legend,'FontSize',25,'Position',[.8,.8,.1,.1]);
        saveas(gcf,strcat(foldername,'RotationMatrix0.png'));
        
        figure('Name','Attitude Errors')
        h_suptitle = suptitle(strcat('Attitude Errors: ',modename));
        set(h_suptitle,'FontSize',30);
        subplot 211
        plot(t,eOmegac,'Linewidth',2);
        ylabel('e_{\Omega}','FontSize',20);
        set(gca,'FontSize',16);
        legend('e_p','e_q','e_r','FontSize',25);
        subplot 212
        plot(t,eRc,'Linewidth',2)
        ylabel('e_{R_c}','FontSize',20);
        xlabel('Time [s]','FontSize', 20)
        set(gca,'FontSize',16);
        legend('e_{R,1}','e_{R,2}','e_{R,3}','FontSize',25);        
        saveas(gcf,strcat(foldername,'AttitudeErrors0.png'));
                            
        figure('Name','Attitude Error Function')
        plot(t,errorfunc,'Linewidth',2)
        xlabel('Time [s]','FontSize', 20)
        ylabel('\Psi(R,R_d)','FontSize', 20);
        h_suptitle = suptitle('Attitude Error function');
        set(h_suptitle,'FontSize',30);      
        set(gca,'FontSize',16);        
        saveas(gcf,strcat(foldername,'AttitudeErrorFunction0.png'));
        
        figure('Name','Angular Velocity')
        subplot 311
        hold on
        plot(t,Omega(1,:),'Linewidth',2)
        plot(t,Omegac(1,:),'r--','Linewidth',2)
        ylabel('p [rad/s]', 'FontSize', 20);
        set(gca,'FontSize',16);
        subplot 312
        hold on
        plot(t,Omega(2,:),'Linewidth',2)
        plot(t,Omegac(2,:),'r--','Linewidth',2)
        ylabel('q [rad/s]', 'FontSize', 20);
        set(gca,'FontSize',16);
        subplot 313
        hold on
        plot(t,Omega(3,:),'Linewidth',2)
        plot(t,Omegac(3,:),'r--','Linewidth',2)
        ylabel('r [rad/s]', 'FontSize', 20);
        xlabel('Time [s]','FontSize', 20)
        h_suptitle = suptitle('Angular Velocity \Omega');
        set(h_suptitle,'FontSize',30);
        legend('\Omega','\Omega_c','FontSize',25);
        set(gca,'FontSize',16);
        saveas(gcf,strcat(foldername,'AngularVelocity0.png'));      
        
        saveas(hQRPosOverview,strcat(foldername,'PosVelAccOverview0.png'));
        
end