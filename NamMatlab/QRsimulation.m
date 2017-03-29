POS(:,:) = pos(:,:);
X = pos(1,:);
Y = pos(2,:);
Z = -pos(3,:);

% figure
% hold on
% plot3(POS(1,:),POS(2,:),POS(3,:))
% plot3(POS(1,1),POS(2,1),POS(3,1),'gx')
% plot3(POS(1,150),POS(2,150),POS(3,150),'bd')
% plot3(POS(1,end),POS(2,end),POS(3,end),'ro')
% xlabel('x')
% ylabel('y')
% zlabel('z')
% view(90,0)
% grid on
% hold off

%%
tend = t(end);
ts = tend/length(t);
xmin = min(X)-1;
ymin = min(Y)-1;
zmin = min(Z)-1;
xmax = max(X)+1;
ymax = max(Y)+1;
zmax = max(Z)+1;


Ix = [1;0;0];
Iy = [0;1;0];
Iz = [0;0;-1];
Iframe = [Ix Iy Iz];
p0 = [0;0;0];

% k = 50;

Bframe = R.signals.values(:,:,1);
By = Bframe(:,2)+[X(1); Y(1); Z(1)];
Bz = Bframe(:,3)+[X(1); Y(1); Z(1)];

figure
h = plot3(X(1),Y(1),Z(1),'rd'); %QR position
hy = line([X(1) Bz(1)],[Y(1) Bz(2)],[Z(1) Bz(3)],'Color','green');
hz = line([X(1) Bz(1)],[Y(1) Bz(2)],[Z(1) Bz(3)],'Color','blue');

% h2 = plot3()
% pause(0.5);

% plot(Y(1),Z(1),'gx')
% hold on
% plot3(X(1),Y(1),Z(1),'gx')
% axis([ymin ymax zmin zmax],'square')
axis([xmin xmax ymin ymax zmin zmax],'square')
% view(120,30)
view(90,0)
grid on
% xlabel('x')
% ylabel('y') 
% zlabel('z')

line([0 Ix(1)],[0 Ix(2)],[0 Ix(3)],'Color','red')
line([0 Iy(1)],[0 Iy(2)],[0 Iy(3)],'Color','green')
line([0 Iz(1)],[0 Iz(2)],[0 Iz(3)],'Color','blue')
% hold off



for m=1:length(t)
set(h,'xdata',X(m),'ydata',Y(m),'zdata',Z(m));
By = (R.signals.values(:,2,m))+[X(m); Y(m); Z(m)];
Bz = (R.signals.values(:,3,m))+[X(m); Y(m); Z(m)];

set(hy,'xdata',[X(m) By(1)],'ydata',[Y(m) By(2)],'zdata',[Z(m) By(3)]);
set(hz,'xdata',[X(m) Bz(1)],'ydata',[Y(m) Bz(2)],'zdata',[Z(m) Bz(3)]);

pause(ts);

drawnow
end
% plot3(POS(1,end),POS(2,end),POS(3,end),'ro')
% hold off
