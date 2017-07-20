pausefactor = 1;

t           = simoutL.time;
xLd         = simoutxLd.signals.values(:,1:3)';
lqrxQd         = lqrsimoutL4.signals.values(:,1:3)';
lqrposL        = lqrsimoutL.signals.values(:,1:3)';
% q            = simoutq.signals.values(:,1:3)';
% posQ         = posL - q*L;
lqrposQ        = lqrsimoutL3.signals.values(:,1:3)';

lqrPOSL        = lqrposL;
lqrXL          = lqrPOSL(1,:);
lqrYL          = lqrPOSL(2,:);
lqrZL          = lqrPOSL(3,:);

lqrPOSLd       = xLd;
XLd         = lqrPOSLd(1,:);
YLd         = lqrPOSLd(2,:);
ZLd         = lqrPOSLd(3,:);

lqrPOSQd       = lqrxQd;
lqrXQd         = lqrPOSQd(1,:);
lqrYQd         = lqrPOSQd(2,:);
lqrZQd         = lqrPOSQd(3,:);

lqrPOSQR       = lqrposQ;
lqrXQR         = lqrPOSQR(1,:);
lqrYQR         = lqrPOSQR(2,:);
lqrZQR         = lqrPOSQR(3,:);

%%
tend = t(end);
ts = tend/length(t);

% I Frame Coord
Ix = [0.1;0;0];
Iy = [0;0.1;0];
Iz = [0;0;0.1];
Iframe = [Ix Iy Iz];

% lqr B Frame Coord
Blength = 0.6;
Bframe = simoutR.signals.values(:,:,1);
for k=1:length(t)
lqrBx(:,k) = [lqrXQR(k); lqrYQR(k); lqrZQR(k)] + Blength*(lqrsimoutR.signals.values(:,1,k));
lqrBy(:,k) = [lqrXQR(k); lqrYQR(k); lqrZQR(k)] + Blength*(lqrsimoutR.signals.values(:,2,k));
lqrBz(:,k) = [lqrXQR(k); lqrYQR(k); lqrZQR(k)] + Blength*(lqrsimoutR.signals.values(:,3,k));

lqrBxQ(:,k) = [lqrXQR(k); lqrYQR(k); lqrZQR(k)] + l*(lqrsimoutR.signals.values(:,1,k));
lqrByQ(:,k) = [lqrXQR(k); lqrYQR(k); lqrZQR(k)] + l*(lqrsimoutR.signals.values(:,2,k));
lqrBzQ(:,k) = [lqrXQR(k); lqrYQR(k); lqrZQR(k)] + l*(lqrsimoutR.signals.values(:,3,k));
end

figure
screenSize = get(0,'Screensize');
set(gcf, 'Position', screenSize*.8);

hold on

% draw Iframe
hIx  = line([0 Ix(1)],[0 Ix(2)],[0 Ix(3)],'Color','red','LineWidth',2);
hIy  = line([0 Iy(1)],[0 Iy(2)],[0 Iy(3)],'Color','green','LineWidth',2);
hIz  = line([0 Iz(1)],[0 Iz(2)],[0 Iz(3)],'Color','blue','LineWidth',2);

% lqr QR initial position
lqrhBx  = line([lqrXQR(1) lqrBx(1)],[lqrYQR(1) lqrBx(2)],[lqrZQR(1) lqrBx(3)],'Color','red','LineWidth',2);
lqrhBy  = line([lqrXQR(1) lqrBy(1)],[lqrYQR(1) lqrBy(2)],[lqrZQR(1) lqrBy(3)],'Color','green','LineWidth',2);
lqrhBz  = line([lqrXQR(1) lqrBz(1)],[lqrYQR(1) lqrBz(2)],[lqrZQR(1) lqrBz(3)],'Color','blue','LineWidth',2);
line([lqrXQR(1) lqrBx(1)],[lqrYQR(1) lqrBx(2)],[lqrZQR(1) lqrBx(3)],'Color','red','LineWidth',1);
line([lqrXQR(1) lqrBy(1)],[lqrYQR(1) lqrBy(2)],[lqrZQR(1) lqrBy(3)],'Color','green','LineWidth',1);
line([lqrXQR(1) lqrBz(1)],[lqrYQR(1) lqrBz(2)],[lqrZQR(1) lqrBz(3)],'Color','blue','LineWidth',1);
lqrhQRx = line([-lqrBxQ(1) lqrBxQ(1)],[2*lqrYQR(1)-lqrBxQ(2) lqrBxQ(2)],[2*lqrZQR(1)-lqrBxQ(3) lqrBxQ(3)],'Color','black','LineWidth',5);
lqrhQRy = line([-lqrByQ(1) lqrByQ(1)],[2*lqrYQR(1)-lqrByQ(2) lqrByQ(2)],[2*lqrZQR(1)-lqrByQ(3) lqrByQ(3)],'Color','black','LineWidth',5);
% hrot1 = plot3(BxQ(1),BxQ(2),BxQ(3),'ko','MarkerSize',15);

% lqr draw initial cable
lqrhC   = line([lqrXQR(1) lqrXL(1)],[lqrYQR(1) lqrYL(1)],[lqrZQR(1) lqrZL(1)],'Color','black');
line([lqrXQR(1) lqrXL(1)],[lqrYQR(1) lqrYL(1)],[lqrZQR(1) lqrZL(1)],'Color','black');

% lqr draw initial Load
lqrhL   = plot3(lqrXL(1),lqrYL(1),lqrZL(1),'--b','LineWidth',1);
lqrhLk  = plot3(lqrXL(1),lqrYL(1),lqrZL(1),'ko','LineWidth',6,'MarkerSize',4);
plot3(lqrXL(1),lqrYL(1),lqrZL(1),'ko','LineWidth',1);

% lqr draw initial Load path
lqrhLd  = plot3(XLd(1),YLd(1),ZLd(1),':r','LineWidth',2);
lqrhLdk = plot3(XLd(1),YLd(1),ZLd(1),'rx','LineWidth',2,'MarkerSize',15);

% draw initial QR path
hQ   = plot3(lqrXQR(1),lqrYQR(1),lqrZQR(1),'--b','LineWidth',1);
hQd  = plot3(lqrXQd(1),lqrYQd(1),lqrZQd(1),':m','LineWidth',2);
hQdk = plot3(lqrXQd(1),lqrYQd(1),lqrZQd(1),'mx','LineWidth',2,'MarkerSize',15);

minax = min(min(min(lqrXQR,lqrYQR),lqrZQR));  
maxax = max(max(max(lqrXQR,lqrYQR),lqrZQR));

difax = (maxax-minax)/2;
axis([min(lqrXQR)-difax max(lqrXQR)+difax min(lqrYQR)-difax max(lqrYQR)+difax min(lqrZQR)-difax max(lqrZQR)+difax],'vis3d')

% axis([minax maxax minax maxax minax maxax],'vis3d')
% axis([-2 2 -2 2 -2 2])
% axis([XQR(1)-1.5 XQR(1)+1.5 YQR(1)-1.5 YQR(1)+1.5 ZQR(1)-1.5 ZQR(1)+1.5],'square')

view(0,90)
% view(40,40)
grid on
xlabel('x')
ylabel('y') 
zlabel('z')
% pause(10)
while waitforbuttonpress ~= 0 ; 
  pause(0.01) ; % allow for ctrl-c
end

for k=1:length(t)
%     axis([XQR(k)-1.5 XQR(k)+1.5 YQR(k)-1.5 YQR(k)+1.5 ZQR(k)-1.5
%     ZQR(k)+1.5],'square'); %Uncomment to zoom in into QR
    set(lqrhBx,'xdata',[lqrXQR(k) lqrBx(1,k)],'ydata',[lqrYQR(k) lqrBx(2,k)],'zdata',[lqrZQR(k) lqrBx(3,k)]);
    set(lqrhBy,'xdata',[lqrXQR(k) lqrBy(1,k)],'ydata',[lqrYQR(k) lqrBy(2,k)],'zdata',[lqrZQR(k) lqrBy(3,k)]);
    set(lqrhBz,'xdata',[lqrXQR(k) lqrBz(1,k)],'ydata',[lqrYQR(k) lqrBz(2,k)],'zdata',[lqrZQR(k) lqrBz(3,k)]);
   
    set(lqrhQRx,'xdata',[2*lqrXQR(k)-lqrBxQ(1,k) lqrBxQ(1,k)],'ydata',[2*lqrYQR(k)-lqrBxQ(2,k) lqrBxQ(2,k)],'zdata',[2*lqrZQR(k)-lqrBxQ(3,k) lqrBxQ(3,k)]);
    set(lqrhQRy,'xdata',[2*lqrXQR(k)-lqrByQ(1,k) lqrByQ(1,k)],'ydata',[2*lqrYQR(k)-lqrByQ(2,k) lqrByQ(2,k)],'zdata',[2*lqrZQR(k)-lqrByQ(3,k) lqrByQ(3,k)]);
%     [-Bx(1) Bx(1)],[2*YQR(1)-Bx(2) Bx(2)],[2*ZQR(1)-Bx(3) Bx(3)]

    set(hQ,'xdata',lqrXQR(1:k),'ydata',lqrYQR(1:k),'zdata',lqrZQR(1:k));
    set(lqrhL,'xdata',lqrXL(1:k),'ydata',lqrYL(1:k),'zdata',lqrZL(1:k));
    set(lqrhLk,'xdata',lqrXL(k),'ydata',lqrYL(k),'zdata',lqrZL(k));

    set(lqrhC,'xdata',[lqrXQR(k) lqrXL(k)],'ydata',[lqrYQR(k) lqrYL(k)],'zdata',[lqrZQR(k) lqrZL(k)]);

    set(lqrhLd,'xdata',XLd(1:k),'ydata',YLd(1:k),'zdata',ZLd(1:k));
    set(lqrhLdk,'xdata',XLd(k),'ydata',YLd(k),'zdata',ZLd(k));

    set(hQd,'xdata',lqrXQd(1:k),'ydata',lqrYQd(1:k),'zdata',lqrZQd(1:k));
    set(hQdk,'xdata',lqrXQd(k),'ydata',lqrYQd(k),'zdata',lqrZQd(k));
    
    pause(ts*pausefactor);
end

lfont = 18; %Legend Fontsize
hleg = legend([lqrhL lqrhLd],'$x_L$','$x_{L,des}$');
set(hleg,'Interpreter','latex','FontSize',lfont);