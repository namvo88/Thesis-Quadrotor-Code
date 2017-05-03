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
xmin = XQR(1)-2;
ymin = YQR(1)-2;
zmin = ZQR(1)-2;
xmax = XQR(1)+2;
ymax = YQR(1)+2;
zmax = ZQR(1)+2;
% zmin = -10;
% zmax = 10;
% ymin = -20;
% ymax = 0;
% xmin = -2;
% xmax = 2;

% I Frame 
Ix = [0.1;0;0];
Iy = [0;0.1;0];
Iz = [0;0;0.1];
Iframe = [Ix Iy Iz];

% Bframe
Blength = 0.6;
Bframe = simoutR.signals.values(:,:,1);
for k=1:length(t)
Bx(:,k) = [XQR(k); YQR(k); ZQR(k)] + Blength*(simoutR.signals.values(:,1,k));
By(:,k) = [XQR(k); YQR(k); ZQR(k)] + Blength*(simoutR.signals.values(:,2,k));
Bz(:,k) = [XQR(k); YQR(k); ZQR(k)] + Blength*(simoutR.signals.values(:,3,k));
end

figure
hold on

% draw Iframe
hold on
hIx = line([0 Ix(1)],[0 Ix(2)],[0 Ix(3)],'Color','red','LineWidth',2);
hIy = line([0 Iy(1)],[0 Iy(2)],[0 Iy(3)],'Color','green','LineWidth',2);
hIz = line([0 Iz(1)],[0 Iz(2)],[0 Iz(3)],'Color','blue','LineWidth',2);

% draw initial Load, Ld and Ld-k
hL = plot3(XL(1),YL(1),ZL(1),'k-');
hLk  = plot3(XL(1),YL(1),ZL(1),'k*','LineWidth',5);
hLd = plot3(XLd(1),YLd(k),ZLd(k),'r-','LineWidth',2);
hLdk = plot3(XLd(1),YLd(1),ZLd(1),'r+','LineWidth',2);

% draw initial Bframe
% hB = plot3(XQR(1),YQR(1),ZQR(1)); %QR initial position
hBx = line([XQR(1) Bx(1)],[YQR(1) Bx(2)],[ZQR(1) Bx(3)],'Color','red','LineWidth',2);
hBy = line([XQR(1) By(1)],[YQR(1) By(2)],[ZQR(1) By(3)],'Color','green','LineWidth',2);
hBz = line([XQR(1) Bz(1)],[YQR(1) Bz(2)],[ZQR(1) Bz(3)],'Color','blue','LineWidth',2);

% draw initial QR
% hB = plot3(XQR(1),YQR(1),ZQR(1),'r+','MarkerSize',20); %QR initial position
% hQRx = line([-Bx(1) Bx(1)],[-Bx(2) Bx(2)],[-Bx(3) Bx(3)],'Color','black','LineWidth',2);
% hQRy = line([-By(1) By(1)],[-By(2) By(2)],[-By(3) By(3)],'Color','black','LineWidth',2);
% hQRz = line([-Bz(1) Bz(1)],[-Bz(2) Bz(2)],[-Bz(3) Bz(3)],'Color','black','LineWidth',2);

% draw initial cable
hC = line([XQR(1) XL(1)],[YQR(1) YL(1)],[ZQR(1) ZL(1)],'Color','black');
minax = min(min(min(XQR,YQR),ZQR))-1;  
maxax = max(max(max(XQR,YQR),ZQR))+1;  
% axis([min(min(XQR,YQR)) max(max(XQR,YQR)) min(min(XQR,YQR)) max(max(XQR,YQR)) ZQR(1)-1 ZQR(1)+1],'vis3d')
axis([minax maxax minax maxax minax maxax],'vis3d')

% axis([xmin xmax ymin ymax zmin zmax],'vis3d')
% axis([min(min(XQR,YQR)) max(max(XQR,YQR)) min(min(XQR,YQR)) max(max(XQR,YQR)) ZQR(1)-1 ZQR(1)+1],'equal')
view(100,10)
grid on
xlabel('x')
ylabel('y') 
zlabel('z')

while waitforbuttonpress ~= 0 ; 
  pause(0.01) ; % allow for ctrl-c
end
  tic
for k=1:length(t)

% set(hB,'xdata',XQR(k),'ydata',YQR(k),'zdata',ZQR(k));
set(hBx,'xdata',[XQR(k) Bx(1,k)],'ydata',[YQR(k) Bx(2,k)],'zdata',[ZQR(k) Bx(3,k)]);
set(hBy,'xdata',[XQR(k) By(1,k)],'ydata',[YQR(k) By(2,k)],'zdata',[ZQR(k) By(3,k)]);
set(hBz,'xdata',[XQR(k) Bz(1,k)],'ydata',[YQR(k) Bz(2,k)],'zdata',[ZQR(k) Bz(3,k)]);

set(hL,'xdata',XL(1:k),'ydata',YL(1:k),'zdata',ZL(1:k));
set(hLk,'xdata',XL(k),'ydata',YL(k),'zdata',ZL(k));

set(hC,'xdata',[XQR(k) XL(k)],'ydata',[YQR(k) YL(k)],'zdata',[ZQR(k) ZL(k)]);

set(hLd,'xdata',XLd(1:k),'ydata',YLd(1:k),'zdata',ZLd(1:k));
set(hLdk,'xdata',XLd(k),'ydata',YLd(k),'zdata',ZLd(k));

pause(ts*pausefactor);
end

toc