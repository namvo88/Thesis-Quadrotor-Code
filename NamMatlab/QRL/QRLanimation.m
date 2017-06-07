pausefactor = 1;

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
end

figure
screenSize = get(0,'Screensize');
set(gcf, 'Position', screenSize*.8);

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
hL   = plot3(XL(1),YL(1),ZL(1),'--b','LineWidth',1);
hLk  = plot3(XL(1),YL(1),ZL(1),'ko','LineWidth',6,'MarkerSize',4);
plot3(XL(1),YL(1),ZL(1),'ko','LineWidth',1);

% draw initial Load path
hLd  = plot3(XLd(1),YLd(1),ZLd(1),':r','LineWidth',2);
hLdk = plot3(XLd(1),YLd(1),ZLd(1),'rx','LineWidth',2,'MarkerSize',15);

minax = min(min(min(XQR,YQR),ZQR))-1;  
maxax = max(max(max(XQR,YQR),ZQR))+1;  
axis([minax maxax minax maxax minax maxax],'vis3d')
% axis([-2 2 -2 2 -2 2])
% axis([XQR(1)-1.5 XQR(1)+1.5 YQR(1)-1.5 YQR(1)+1.5 ZQR(1)-1.5 ZQR(1)+1.5],'square')

% view(0,0)
view(3)
grid on
xlabel('x')
ylabel('y') 
zlabel('z')
% pause(10)
while waitforbuttonpress ~= 0 ; 
  pause(0.01) ; % allow for ctrl-c
end

for k=1:length(t)
%     axis([XQR(k)-1.5 XQR(k)+1.5 YQR(k)-1.5 YQR(k)+1.5 ZQR(k)-1.5 ZQR(k)+1.5],'square')
    set(hBx,'xdata',[XQR(k) Bx(1,k)],'ydata',[YQR(k) Bx(2,k)],'zdata',[ZQR(k) Bx(3,k)]);
    set(hBy,'xdata',[XQR(k) By(1,k)],'ydata',[YQR(k) By(2,k)],'zdata',[ZQR(k) By(3,k)]);
    set(hBz,'xdata',[XQR(k) Bz(1,k)],'ydata',[YQR(k) Bz(2,k)],'zdata',[ZQR(k) Bz(3,k)]);
   
    set(hQRx,'xdata',[2*XQR(k)-BxQ(1,k) BxQ(1,k)],'ydata',[2*YQR(k)-BxQ(2,k) BxQ(2,k)],'zdata',[2*ZQR(k)-BxQ(3,k) BxQ(3,k)]);
    set(hQRy,'xdata',[2*XQR(k)-ByQ(1,k) ByQ(1,k)],'ydata',[2*YQR(k)-ByQ(2,k) ByQ(2,k)],'zdata',[2*ZQR(k)-ByQ(3,k) ByQ(3,k)]);
%     [-Bx(1) Bx(1)],[2*YQR(1)-Bx(2) Bx(2)],[2*ZQR(1)-Bx(3) Bx(3)]
       
    set(hL,'xdata',XL(1:k),'ydata',YL(1:k),'zdata',ZL(1:k));

    set(hLk,'xdata',XL(k),'ydata',YL(k),'zdata',ZL(k));
    
    set(hC,'xdata',[XQR(k) XL(k)],'ydata',[YQR(k) YL(k)],'zdata',[ZQR(k) ZL(k)]);

    set(hLd,'xdata',XLd(1:k),'ydata',YLd(1:k),'zdata',ZLd(1:k));
    set(hLdk,'xdata',XLd(k),'ydata',YLd(k),'zdata',ZLd(k));
    
    pause(ts*pausefactor);
end

lfont = 18; %Legend Fontsize
hleg = legend([hL hLd],'$x_L$','$x_{L,des}$');
set(hleg,'Interpreter','latex','FontSize',lfont);