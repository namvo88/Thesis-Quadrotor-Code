clear; clc; close all;

l1 = 0.3;
l2 = 0.2;

theta1 = linspace(0,pi/2,100);
theta2 = linspace(0,pi/2,100);

xe = cos(theta1)*l1+cos(theta2)*l2;
ye = sin(theta1)*l1+sin(theta2)*l2;

figure
subplot 121
plot(theta1,theta2)
xlabel('theta1')
ylabel('theta2')
subplot 122
plot(xe,ye)
xlabel('xe')
ylabel('ye')
% 
% A=[l1 l2 0 0; 0 0 l1 l2; 0 0 0 0; 0 0 0 0];
% B=[.4 .4 0 0];
% B*inv(A)
% 
% figure
% screenSize = get(0,'Screensize');
% set(gcf, 'Position', screenSize*.8);
% 
% hold on
% 
% % draw initial Load
% hL   = plot(theta1(1),theta2(1),'LineWidth',1);
% % hLk  = plot3(XL(1),YL(1),ZL(1),'ko','LineWidth',6,'MarkerSize',4);
% % plot3(XL(1),YL(1),ZL(1),'ko','LineWidth',1);
% 
% for k=1:length(theta1)
% 
%     set(hBx,'xdata',[XQR(k) Bx(1,k)],'ydata',[YQR(k) Bx(2,k)],'zdata',[ZQR(k) Bx(3,k)]);
%     set(hBy,'xdata',[XQR(k) By(1,k)],'ydata',[YQR(k) By(2,k)],'zdata',[ZQR(k) By(3,k)]);
%     set(hBz,'xdata',[XQR(k) Bz(1,k)],'ydata',[YQR(k) Bz(2,k)],'zdata',[ZQR(k) Bz(3,k)]);
%    
%     set(hQRx,'xdata',[2*XQR(k)-BxQ(1,k) BxQ(1,k)],'ydata',[2*YQR(k)-BxQ(2,k) BxQ(2,k)],'zdata',[2*ZQR(k)-BxQ(3,k) BxQ(3,k)]);
%     set(hQRy,'xdata',[2*XQR(k)-ByQ(1,k) ByQ(1,k)],'ydata',[2*YQR(k)-ByQ(2,k) ByQ(2,k)],'zdata',[2*ZQR(k)-ByQ(3,k) ByQ(3,k)]);
% %     [-Bx(1) Bx(1)],[2*YQR(1)-Bx(2) Bx(2)],[2*ZQR(1)-Bx(3) Bx(3)]
%        
%     set(hL,'xdata',XL(1:k),'ydata',YL(1:k),'zdata',ZL(1:k));
% 
%     set(hLk,'xdata',XL(k),'ydata',YL(k),'zdata',ZL(k));
%     
%     set(hC,'xdata',[XQR(k) XL(k)],'ydata',[YQR(k) YL(k)],'zdata',[ZQR(k) ZL(k)]);
% 
%     set(hLd,'xdata',XLd(1:k),'ydata',YLd(1:k),'zdata',ZLd(1:k));
%     set(hLdk,'xdata',XLd(k),'ydata',YLd(k),'zdata',ZLd(k));
%     
%     pause(ts*pausefactor);
% end