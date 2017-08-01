pausefactor = 1;

afont = 16; %Axis Fontsize
labfont = 24; %Label Fontsize
supfont = 25; %Suptitle Fontsize

%% GC
t            = simoutL.time;
xLd          = simoutxLd.signals.values(:,1:3)';
posL         = simoutL.signals.values(:,1:3)';
q            = simoutq.signals.values(:,1:3)';
posQ         = posL - q*L;

POSL = posL;
XL = POSL(1,:);
YL = POSL(2,:);
ZL = POSL(3,:);

POSLd = xLd;
XLd = POSLd(1,:);
YLd = POSLd(2,:);
ZLd = POSLd(3,:);

POSQR = posQ;
XQR = POSQR(1,:);
YQR = POSQR(2,:);
ZQR = POSQR(3,:);

%% LQR
lqrxQd         = lqrsimoutL4.signals.values(:,1:3)';
lqrposL        = lqrsimoutL.signals.values(:,1:3)';
% q            = simoutq.signals.values(:,1:3)';
% posQ         = posL - q*L;
lqrposQ        = lqrsimoutL3.signals.values(:,1:3)';

lqrPOSL        = lqrposL;
lqrXL          = lqrPOSL(1,:);
lqrYL          = lqrPOSL(2,:);
lqrZL          = lqrPOSL(3,:);

lqrPOSQd       = lqrxQd;
lqrXQd         = lqrPOSQd(1,:);
lqrYQd         = lqrPOSQd(2,:);
lqrZQd         = lqrPOSQd(3,:);

lqrPOSQR       = lqrposQ;
lqrXQ         = lqrPOSQR(1,:);
lqrYQ         = lqrPOSQR(2,:);
lqrZQ         = lqrPOSQR(3,:);

%%
tend = t(end);
ts = tend/length(t);

% I Frame Coord
Ix = [0.1;0;0];
Iy = [0;0.1;0];
Iz = [0;0;0.1];
Iframe = [Ix Iy Iz];

% B Frame Coord
Blength = 0.6;
Bframe = simoutR.signals.values(:,:,1);
for k=1:length(t)
Bx(:,k) = [XQR(k); YQR(k); ZQR(k)] + Blength*(simoutR.signals.values(:,1,k));
By(:,k) = [XQR(k); YQR(k); ZQR(k)] + Blength*(simoutR.signals.values(:,2,k));
Bz(:,k) = [XQR(k); YQR(k); ZQR(k)] + Blength*(simoutR.signals.values(:,3,k));

BxQ(:,k) = [XQR(k); YQR(k); ZQR(k)] + l*(simoutR.signals.values(:,1,k));
ByQ(:,k) = [XQR(k); YQR(k); ZQR(k)] + l*(simoutR.signals.values(:,2,k));
BzQ(:,k) = [XQR(k); YQR(k); ZQR(k)] + l*(simoutR.signals.values(:,3,k));

lqrBx(:,k) = [lqrXQ(k); lqrYQ(k); lqrZQ(k)] + Blength*(lqrsimoutR.signals.values(:,1,k));
lqrBy(:,k) = [lqrXQ(k); lqrYQ(k); lqrZQ(k)] + Blength*(lqrsimoutR.signals.values(:,2,k));
lqrBz(:,k) = [lqrXQ(k); lqrYQ(k); lqrZQ(k)] + Blength*(lqrsimoutR.signals.values(:,3,k));

lqrBxQ(:,k) = [lqrXQ(k); lqrYQ(k); lqrZQ(k)] + l*(lqrsimoutR.signals.values(:,1,k));
lqrByQ(:,k) = [lqrXQ(k); lqrYQ(k); lqrZQ(k)] + l*(lqrsimoutR.signals.values(:,2,k));
lqrBzQ(:,k) = [lqrXQ(k); lqrYQ(k); lqrZQ(k)] + l*(lqrsimoutR.signals.values(:,3,k));
end

minax = min(min(min(XQR,YQR),ZQR));  
maxax = max(max(max(XQR,YQR),ZQR));
difax = (maxax-minax)/2+1;

figure
screenSize = get(0,'Screensize');
set(gcf, 'Position', screenSize*.8);

subplot 121
plottitle = title('NGC Controller');
set(plottitle,'FontSize',supfont,'Interpreter','latex');
hold on

% draw Iframe
hIx  = line([0 Ix(1)],[0 Ix(2)],[0 Ix(3)],'Color','red','LineWidth',2);
hIy  = line([0 Iy(1)],[0 Iy(2)],[0 Iy(3)],'Color','green','LineWidth',2);
hIz  = line([0 Iz(1)],[0 Iz(2)],[0 Iz(3)],'Color','blue','LineWidth',2);

% QR initial position
hBx  = line([XQR(1) Bx(1)],[YQR(1) Bx(2)],[ZQR(1) Bx(3)],'Color','red','LineWidth',2);
hBy  = line([XQR(1) By(1)],[YQR(1) By(2)],[ZQR(1) By(3)],'Color','green','LineWidth',2);
hBz  = line([XQR(1) Bz(1)],[YQR(1) Bz(2)],[ZQR(1) Bz(3)],'Color','blue','LineWidth',2);
line([XQR(1) Bx(1)],[YQR(1) Bx(2)],[ZQR(1) Bx(3)],'Color','red','LineWidth',1);
line([XQR(1) By(1)],[YQR(1) By(2)],[ZQR(1) By(3)],'Color','green','LineWidth',1);
line([XQR(1) Bz(1)],[YQR(1) Bz(2)],[ZQR(1) Bz(3)],'Color','blue','LineWidth',1);
hQRx = line([-BxQ(1) BxQ(1)],[2*YQR(1)-BxQ(2) BxQ(2)],[2*ZQR(1)-BxQ(3) BxQ(3)],'Color','black','LineWidth',5);
hQRy = line([-ByQ(1) ByQ(1)],[2*YQR(1)-ByQ(2) ByQ(2)],[2*ZQR(1)-ByQ(3) ByQ(3)],'Color','black','LineWidth',5);
% hrot1 = plot3(BxQ(1),BxQ(2),BxQ(3),'ko','MarkerSize',15);

% draw initial cable
hC   = line([XQR(1) XL(1)],[YQR(1) YL(1)],[ZQR(1) ZL(1)],'Color','black');
line([XQR(1) XL(1)],[YQR(1) YL(1)],[ZQR(1) ZL(1)],'Color','black');

% draw initial Load
hLk  = plot3(XL(1),YL(1),ZL(1),'ko','LineWidth',6,'MarkerSize',4);
plot3(XL(1),YL(1),ZL(1),'ko','LineWidth',1);

% draw initial Load path
hL   = plot3(XL(1),YL(1),ZL(1),'--k','LineWidth',1);
hLd  = plot3(XLd(1),YLd(1),ZLd(1),':r','LineWidth',2);
hLdk = plot3(XLd(1),YLd(1),ZLd(1),'rx','LineWidth',2,'MarkerSize',15);

% axis([XQR(1)-difax XQR(1)+difax minax maxax ZQR(1)-difax ZQR(1)+difax],'vis3d')
% axis([min(XQR)-difax max(XQR)+difax min(YQR)-difax max(YQR)+difax min(ZQR)-difax max(ZQR)+difax],'vis3d')
% axis([minax maxax minax maxax minax maxax],'vis3d')
axis([-1.5 1.5 -1.5 1.5 -1.5 1.5],'vis3d')
% view(150,30)
view(90,0)
grid on
xlabel('$x$','FontSize',labfont,'Interpreter','latex')
ylabel('$y$','FontSize',labfont,'Interpreter','latex') 
zlabel('$z$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
% lfont = 18; %Legend Fontsize
% hleg = legend([hL hLd],'$x_L$','$x_{L,des}$');
% set(hleg,'Interpreter','latex','FontSize',lfont);

subplot 122
plottitle = title('LQR Controller');
set(plottitle,'FontSize',supfont,'Interpreter','latex');
hold on

% draw Iframe
hIx  = line([0 Ix(1)],[0 Ix(2)],[0 Ix(3)],'Color','red','LineWidth',2);
hIy  = line([0 Iy(1)],[0 Iy(2)],[0 Iy(3)],'Color','green','LineWidth',2);
hIz  = line([0 Iz(1)],[0 Iz(2)],[0 Iz(3)],'Color','blue','LineWidth',2);

% lqr QR initial position
lqrhBx  = line([lqrXQ(1) lqrBx(1)],[lqrYQ(1) lqrBx(2)],[lqrZQ(1) lqrBx(3)],'Color','red','LineWidth',2);
lqrhBy  = line([lqrXQ(1) lqrBy(1)],[lqrYQ(1) lqrBy(2)],[lqrZQ(1) lqrBy(3)],'Color','green','LineWidth',2);
lqrhBz  = line([lqrXQ(1) lqrBz(1)],[lqrYQ(1) lqrBz(2)],[lqrZQ(1) lqrBz(3)],'Color','blue','LineWidth',2);
line([lqrXQ(1) lqrBx(1)],[lqrYQ(1) lqrBx(2)],[lqrZQ(1) lqrBx(3)],'Color','red','LineWidth',1);
line([lqrXQ(1) lqrBy(1)],[lqrYQ(1) lqrBy(2)],[lqrZQ(1) lqrBy(3)],'Color','green','LineWidth',1);
line([lqrXQ(1) lqrBz(1)],[lqrYQ(1) lqrBz(2)],[lqrZQ(1) lqrBz(3)],'Color','blue','LineWidth',1);
lqrhQRx = line([-lqrBxQ(1) lqrBxQ(1)],[2*lqrYQ(1)-lqrBxQ(2) lqrBxQ(2)],[2*lqrZQ(1)-lqrBxQ(3) lqrBxQ(3)],'Color','black','LineWidth',5);
lqrhQRy = line([-lqrByQ(1) lqrByQ(1)],[2*lqrYQ(1)-lqrByQ(2) lqrByQ(2)],[2*lqrZQ(1)-lqrByQ(3) lqrByQ(3)],'Color','black','LineWidth',5);

% draw initial QR path
lqrhQ   = plot3(lqrXQ(1),lqrYQ(1),lqrZQ(1),'--b','LineWidth',1);
lqrhQd  = plot3(lqrXQd(1),lqrYQd(1),lqrZQd(1),':m','LineWidth',2);
lqrhQdk = plot3(lqrXQd(1),lqrYQd(1),lqrZQd(1),'mx','LineWidth',2,'MarkerSize',15);

% lqr draw initial cable
lqrhC   = line([lqrXQ(1) lqrXL(1)],[lqrYQ(1) lqrYL(1)],[lqrZQ(1) lqrZL(1)],'Color','black');
line([lqrXQ(1) lqrXL(1)],[lqrYQ(1) lqrYL(1)],[lqrZQ(1) lqrZL(1)],'Color','black');

% lqr draw initial Load
lqrhLk  = plot3(lqrXL(1),lqrYL(1),lqrZL(1),'ko','LineWidth',6,'MarkerSize',4);
plot3(lqrXL(1),lqrYL(1),lqrZL(1),'ko','LineWidth',1);

% lqr draw initial Load path
lqrhL   = plot3(lqrXL(1),lqrYL(1),lqrZL(1),'--k','LineWidth',1);
lqrhLd  = plot3(XLd(1),YLd(1),ZLd(1),':r','LineWidth',2);
lqrhLdk = plot3(XLd(1),YLd(1),ZLd(1),'rx','LineWidth',2,'MarkerSize',15);

% axis([XQR(1)-difax XQR(1)+difax minax maxax ZQR(1)-difax ZQR(1)+difax],'vis3d')
% axis([min(XQR)-difax max(XQR)+difax min(YQR)-difax max(YQR)+difax min(ZQR)-difax max(ZQR)+difax],'vis3d')
% axis([minax maxax minax maxax minax maxax],'vis3d')
axis([-1.5 1.5 -1.5 1.5 -1.5 1.5],'vis3d')
% view(150,30)
view(90,0)
grid on
xlabel('$x$','FontSize',labfont,'Interpreter','latex')
ylabel('$y$','FontSize',labfont,'Interpreter','latex') 
zlabel('$z$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
% lfont = 18; %Legend Fontsize
% hleg = legend([hL hLd],'$x_L$','$x_{L,des}$');
% set(hleg,'Interpreter','latex','FontSize',lfont);


% pause(10)
while waitforbuttonpress ~= 0 ; 
  pause(0.01) ; % allow for ctrl-c
end
for k=1:length(t)
%     axis([XQR(k)-1.5 XQR(k)+1.5 YQR(k)-1.5 YQR(k)+1.5 ZQR(k)-1.5 ZQR(k)+1.5],'square'); %Uncomment to zoom in into QR
    set(hBx,'xdata',[XQR(k) Bx(1,k)],'ydata',[YQR(k) Bx(2,k)],'zdata',[ZQR(k) Bx(3,k)]);
    set(hBy,'xdata',[XQR(k) By(1,k)],'ydata',[YQR(k) By(2,k)],'zdata',[ZQR(k) By(3,k)]);
    set(hBz,'xdata',[XQR(k) Bz(1,k)],'ydata',[YQR(k) Bz(2,k)],'zdata',[ZQR(k) Bz(3,k)]);
    set(lqrhBx,'xdata',[lqrXQ(k) lqrBx(1,k)],'ydata',[lqrYQ(k) lqrBx(2,k)],'zdata',[lqrZQ(k) lqrBx(3,k)]);
    set(lqrhBy,'xdata',[lqrXQ(k) lqrBy(1,k)],'ydata',[lqrYQ(k) lqrBy(2,k)],'zdata',[lqrZQ(k) lqrBy(3,k)]);
    set(lqrhBz,'xdata',[lqrXQ(k) lqrBz(1,k)],'ydata',[lqrYQ(k) lqrBz(2,k)],'zdata',[lqrZQ(k) lqrBz(3,k)]);    
   
    set(hQRx,'xdata',[2*XQR(k)-BxQ(1,k) BxQ(1,k)],'ydata',[2*YQR(k)-BxQ(2,k) BxQ(2,k)],'zdata',[2*ZQR(k)-BxQ(3,k) BxQ(3,k)]);
    set(hQRy,'xdata',[2*XQR(k)-ByQ(1,k) ByQ(1,k)],'ydata',[2*YQR(k)-ByQ(2,k) ByQ(2,k)],'zdata',[2*ZQR(k)-ByQ(3,k) ByQ(3,k)]);
%     [-Bx(1) Bx(1)],[2*YQR(1)-Bx(2) Bx(2)],[2*ZQR(1)-Bx(3) Bx(3)]
    set(lqrhQRx,'xdata',[2*lqrXQ(k)-lqrBxQ(1,k) lqrBxQ(1,k)],'ydata',[2*lqrYQ(k)-lqrBxQ(2,k) lqrBxQ(2,k)],'zdata',[2*lqrZQ(k)-lqrBxQ(3,k) lqrBxQ(3,k)]);
    set(lqrhQRy,'xdata',[2*lqrXQ(k)-lqrByQ(1,k) lqrByQ(1,k)],'ydata',[2*lqrYQ(k)-lqrByQ(2,k) lqrByQ(2,k)],'zdata',[2*lqrZQ(k)-lqrByQ(3,k) lqrByQ(3,k)]);
       
    set(hL,'xdata',XL(1:k),'ydata',YL(1:k),'zdata',ZL(1:k));
    set(hLk,'xdata',XL(k),'ydata',YL(k),'zdata',ZL(k));
    set(hC,'xdata',[XQR(k) XL(k)],'ydata',[YQR(k) YL(k)],'zdata',[ZQR(k) ZL(k)]);
    set(lqrhL,'xdata',lqrXL(1:k),'ydata',lqrYL(1:k),'zdata',lqrZL(1:k));
    set(lqrhLk,'xdata',lqrXL(k),'ydata',lqrYL(k),'zdata',lqrZL(k));
    set(lqrhC,'xdata',[lqrXQ(k) lqrXL(k)],'ydata',[lqrYQ(k) lqrYL(k)],'zdata',[lqrZQ(k) lqrZL(k)]);

    set(lqrhQ,'xdata',lqrXQ(1:k),'ydata',lqrYQ(1:k),'zdata',lqrZQ(1:k));    
    set(lqrhQd,'xdata',lqrXQd(1:k),'ydata',lqrYQd(1:k),'zdata',lqrZQd(1:k));
    set(lqrhQdk,'xdata',lqrXQd(k),'ydata',lqrYQd(k),'zdata',lqrZQd(k));
        
    set(hLd,'xdata',XLd(1:k),'ydata',YLd(1:k),'zdata',ZLd(1:k));
    set(hLdk,'xdata',XLd(k),'ydata',YLd(k),'zdata',ZLd(k));
    set(lqrhLd,'xdata',XLd(1:k),'ydata',YLd(1:k),'zdata',ZLd(1:k));
    set(lqrhLdk,'xdata',XLd(k),'ydata',YLd(k),'zdata',ZLd(k));    
    
    pause(ts*pausefactor);
    mov(k)=getframe(gcf);
    
end



