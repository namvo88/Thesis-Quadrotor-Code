pausefactor = 1;

t           = simoutL.time;
LQRposL        = lqrsimoutL.signals.values(:,:)';
LQRposQ        = lqrsimoutL3.signals.values(:,4:6)';

LQRxQd         = lqrsimoutL3.signals.values(:,1:3)';
LQRxLd          = simoutxLd.signals.values(:,1:3)';

LQRPOSL = LQRposL;
LQRXL = LQRPOSL(1,:);
LQRYL = LQRPOSL(2,:);
LQRZL = LQRPOSL(3,:);

LQRPOSLd = LQRxLd;
LQRXLd = LQRPOSLd(1,:);
LQRYLd = LQRPOSLd(2,:);
LQRZLd = LQRPOSLd(3,:);

LQRPOSQd = LQRxQd;
LQRXQd = LQRPOSQd(1,:);
LQRYQd = LQRPOSQd(2,:);
LQRZQd = LQRPOSQd(3,:);

LQRPOSQR = LQRposQ;
LQRXQR = LQRPOSQR(1,:);
LQRYQR = LQRPOSQR(2,:);
LQRZQR = LQRPOSQR(3,:);

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
LQRBx(:,k) = [LQRXQR(k); LQRYQR(k); LQRZQR(k)] + Blength*(LQRsimoutR.signals.values(:,1,k));
LQRBy(:,k) = [LQRXQR(k); LQRYQR(k); LQRZQR(k)] + Blength*(LQRsimoutR.signals.values(:,2,k));
LQRBz(:,k) = [LQRXQR(k); LQRYQR(k); LQRZQR(k)] + Blength*(LQRsimoutR.signals.values(:,3,k));

LQRBxQ(:,k) = [LQRXQR(k); LQRYQR(k); LQRZQR(k)] + l*(LQRsimoutR.signals.values(:,1,k));
LQRByQ(:,k) = [LQRXQR(k); LQRYQR(k); LQRZQR(k)] + l*(LQRsimoutR.signals.values(:,2,k));
LQRBzQ(:,k) = [LQRXQR(k); LQRYQR(k); LQRZQR(k)] + l*(LQRsimoutR.signals.values(:,3,k));
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
hBx  = line([LQRXQR(1) LQRBx(1)],[LQRYQR(1) LQRBx(2)],[LQRZQR(1) LQRBx(3)],'Color','red','LineWidth',2);
hBy  = line([LQRXQR(1) LQRBy(1)],[LQRYQR(1) LQRBy(2)],[LQRZQR(1) LQRBy(3)],'Color','green','LineWidth',2);
hBz  = line([LQRXQR(1) LQRBz(1)],[LQRYQR(1) LQRBz(2)],[LQRZQR(1) LQRBz(3)],'Color','blue','LineWidth',2);
line([LQRXQR(1) LQRBx(1)],[LQRYQR(1) LQRBx(2)],[LQRZQR(1) LQRBx(3)],'Color','red','LineWidth',1);
line([LQRXQR(1) LQRBy(1)],[LQRYQR(1) LQRBy(2)],[LQRZQR(1) LQRBy(3)],'Color','green','LineWidth',1);
line([LQRXQR(1) LQRBz(1)],[LQRYQR(1) LQRBz(2)],[LQRZQR(1) LQRBz(3)],'Color','blue','LineWidth',1);
hQRx = line([-LQRBxQ(1) LQRBxQ(1)],[2*LQRYQR(1)-LQRBxQ(2) LQRBxQ(2)],[2*LQRZQR(1)-LQRBxQ(3) LQRBxQ(3)],'Color','black','LineWidth',5);
hQRy = line([-LQRByQ(1) LQRByQ(1)],[2*LQRYQR(1)-LQRByQ(2) LQRByQ(2)],[2*LQRZQR(1)-LQRByQ(3) LQRByQ(3)],'Color','black','LineWidth',5);
hQ   = plot3(LQRXQR(1),LQRYQR(1),LQRZQR(1),'--b','LineWidth',1);
% hrot1 = plot3(BxQ(1),BxQ(2),BxQ(3),'ko','MarkerSize',15);

% draw initial cable
hC   = line([LQRXQR(1) LQRXL(1)],[LQRYQR(1) LQRYL(1)],[LQRZQR(1) LQRZL(1)],'Color','black');
line([LQRXQR(1) LQRXL(1)],[LQRYQR(1) LQRYL(1)],[LQRZQR(1) LQRZL(1)],'Color','black');

% draw initial Load
hL   = plot3(LQRXL(1),LQRYL(1),LQRZL(1),'--b','LineWidth',1);
hLk  = plot3(LQRXL(1),LQRYL(1),LQRZL(1),'ko','LineWidth',6,'MarkerSize',4);
plot3(LQRXL(1),LQRYL(1),LQRZL(1),'ko','LineWidth',1);

% draw initial QR path
hQd  = plot3(LQRXQd(1),LQRYQd(1),LQRZQd(1),':m','LineWidth',2);
hQdk = plot3(LQRXQd(1),LQRYQd(1),LQRZQd(1),'mx','LineWidth',2,'MarkerSize',15);

% draw initial Load path
hLd  = plot3(LQRXLd(1),LQRYLd(1),LQRZLd(1),':r','LineWidth',2);
hLdk = plot3(LQRXLd(1),LQRYLd(1),LQRZLd(1),'rx','LineWidth',2,'MarkerSize',15);


minax = min(min(min(LQRXQR,LQRYQR),LQRZQR))-1;  
maxax = max(max(max(LQRXQR,LQRYQR),LQRZQR))+1;  
% minx = min(min(XQR,YQR))-1;
% maxx = max(max(XQR,YQR))+1;
% miny = min(min(XQR,YQR))-1;
% maxy = max(max(XQR,YQR))+1;
% minz = min(ZQR)-1;
% maxz = max(ZQR)+1;

difax = (maxax-minax)/2;
axis([LQRXQR(1)-difax LQRXQR(1)+difax minax maxax LQRZQR(1)-difax LQRZQR(1)+difax],'vis3d')
% axis([minax maxax minax maxax minax maxax],'vis3d')
% axis([-(maxy-miny)/2-1 (maxy-miny)/2+1 miny maxy minz maxz],'vis3d')

% axis([-2 2 -2 2 -2 2])
% axis([XQR(1)-1.5 XQR(1)+1.5 YQR(1)-1.5 YQR(1)+1.5 ZQR(1)-1.5 ZQR(1)+1.5],'square')

% view(0,0)
view(80,25)
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
    set(hBx,'xdata',[LQRXQR(k) LQRBx(1,k)],'ydata',[LQRYQR(k) LQRBx(2,k)],'zdata',[LQRZQR(k) LQRBx(3,k)]);
    set(hBy,'xdata',[LQRXQR(k) LQRBy(1,k)],'ydata',[LQRYQR(k) LQRBy(2,k)],'zdata',[LQRZQR(k) LQRBy(3,k)]);
    set(hBz,'xdata',[LQRXQR(k) LQRBz(1,k)],'ydata',[LQRYQR(k) LQRBz(2,k)],'zdata',[LQRZQR(k) LQRBz(3,k)]);
   
    set(hQRx,'xdata',[2*LQRXQR(k)-LQRBxQ(1,k) LQRBxQ(1,k)],'ydata',[2*LQRYQR(k)-LQRBxQ(2,k) LQRBxQ(2,k)],'zdata',[2*LQRZQR(k)-LQRBxQ(3,k) LQRBxQ(3,k)]);
    set(hQRy,'xdata',[2*LQRXQR(k)-LQRByQ(1,k) LQRByQ(1,k)],'ydata',[2*LQRYQR(k)-LQRByQ(2,k) LQRByQ(2,k)],'zdata',[2*LQRZQR(k)-LQRByQ(3,k) LQRByQ(3,k)]);
%     [-Bx(1) Bx(1)],[2*YQR(1)-Bx(2) Bx(2)],[2*ZQR(1)-Bx(3) Bx(3)]
       
    set(hL,'xdata',LQRXL(1:k),'ydata',LQRYL(1:k),'zdata',LQRZL(1:k));
    set(hLd,'xdata',LQRXLd(1:k),'ydata',LQRYLd(1:k),'zdata',LQRZLd(1:k));
    set(hLdk,'xdata',LQRXLd(k),'ydata',LQRYLd(k),'zdata',LQRZLd(k));    
    set(hLk,'xdata',LQRXL(k),'ydata',LQRYL(k),'zdata',LQRZL(k));
    
    set(hC,'xdata',[LQRXQR(k) LQRXL(k)],'ydata',[LQRYQR(k) LQRYL(k)],'zdata',[LQRZQR(k) LQRZL(k)]);

    set(hQ,'xdata',LQRXQR(1:k),'ydata',LQRYQR(1:k),'zdata',LQRZQR(1:k));    
    set(hQd,'xdata',LQRXQd(1:k),'ydata',LQRYQd(1:k),'zdata',LQRZQd(1:k));
    set(hQdk,'xdata',LQRXQd(k),'ydata',LQRYQd(k),'zdata',LQRZQd(k));
    
    pause(ts*pausefactor);
end

lfont = 18; %Legend Fontsize
hleg = legend([hL hQd],'$x_L$','$x_{L,des}$');
set(hleg,'Interpreter','latex','FontSize',lfont);