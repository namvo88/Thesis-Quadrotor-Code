for nfile = 50:65
    
    
    foldername = 'C:\Users\Nam\Documents\Git\Thesis-Quadrotor-Code\NamMatlab\QRL\MatlabImages\';
    loadname = strcat('LPOSQRL',num2str(nfile),'.mat');
    
    if exist(loadname,'file') == 2
        
        load(strcat(foldername,loadname));
        
        filename = 'QRang';
        figure('Name',filename)
        h_sup = suptitle('QR Angle [deg]');
        set(h_sup,'FontSize',supfont,'Interpreter','latex');
        subplot 211
        plot(t,angleQ(:,1),'-k',t,lqrangleQ(:,1),'r-.','Linewidth',3)
        grid on
        % hl = legend('\boldmath$NGC$','\boldmath$LQR$');
        ylabel('\boldmath$\phi$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        % set(hl,'Interpreter','latex','FontSize',lfont);
        subplot 212
        plot(t,angleQ(:,2),'-k',t,lqrangleQ(:,2),'r-.','Linewidth',3)
        grid on
        ylabel('\boldmath$e_y$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
        ylabel('\boldmath$\theta$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')
        
        filename = 'Lang';
        figure('Name',filename)
        h_sup = suptitle('Load Angle [deg]');
        set(h_sup,'FontSize',supfont,'Interpreter','latex');
        subplot 211
        plot(t,angleL(:,1),'-k',t,lqrangleL(:,1),'r-.','Linewidth',3)
        grid on
        % hl = legend('\boldmath$NGC$','\boldmath$LQR$');
        ylabel('\boldmath$\phi_L$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        % set(hl,'Interpreter','latex','FontSize',lfont);
        subplot 212
        plot(t,angleL(:,2),'-k',t,lqrangleL(:,2),'r-.','Linewidth',3)
        grid on
        ylabel('\boldmath$e_y$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
        ylabel('\boldmath$\theta_L$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')
        
        filename = 'exL';
        figure('Name',filename)
        h_suptitle = suptitle('Load Position Error $[m]$');
        set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
        subplot 311
        plot(t,exL(1,:),'-k',t,lqrexL(1,:),'r-.','Linewidth',3)
        grid on
        % hl = legend('\boldmath$NGC$','\boldmath$LQR$');
        ylabel('\boldmath$e_x$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        % set(hl,'Interpreter','latex','FontSize',lfont);
        subplot 312
        plot(t,exL(2,:),'-k',t,lqrexL(2,:),'r-.','Linewidth',3)
        grid on
        ylabel('\boldmath$e_y$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        subplot 313
        plot(t,exL(3,:),'-k',t,lqrexL(3,:),'r-.','Linewidth',3)
        grid on
        xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
        ylabel('\boldmath$e_z$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')
        
        close all
        
    end
    
end