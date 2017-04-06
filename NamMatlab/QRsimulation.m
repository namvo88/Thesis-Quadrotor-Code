POS = simout.signals.values(1:3,:);
X = POS(1,:);
Y = POS(2,:);
Z = POS(3,:);

%%
tend = t(end);
ts = tend/length(t);
xmin = min(X)-1;
ymin = min(Y)-1;
zmin = min(Z)-1;
xmax = max(X)+1;
ymax = max(Y)+1;
zmax = max(Z)+1;

% I Frame 
Ix = [1;0;0];
Iy = [0;1;0];
Iz = [0;0;-1];
Iframe = [Ix Iy Iz];


% Bframe initial
Bframe = R.signals.values(:,:,1);
Bx = [X(1); Y(1); Z(1)]+Bframe(:,1);
By = [X(1); Y(1); Z(1)]+Bframe(:,2);
Bz = [X(1); Y(1); Z(1)]-Bframe(:,3);

figure
hold on
% draw Iframe
line([0 Ix(1)],[0 Ix(2)],[0 Ix(3)],'Color','red')
line([0 Iy(1)],[0 Iy(2)],[0 Iy(3)],'Color','green')
line([0 Iz(1)],[0 Iz(2)],[0 Iz(3)],'Color','blue')

% draw init and xdes
plot3(0,0,0,'g+','LineWidth',2)
plot3(xdes(1),xdes(2),xdes(3),'r+','LineWidth',2)

% draw initial Bframe
hplot = plot3(X(1),Y(1),Z(1),'ro'); %QR initial position
hx = line([X(1) Bx(1)],[Y(1) Bx(2)],[Z(1) Bx(3)],'Color','red');
hy = line([X(1) By(1)],[Y(1) By(2)],[Z(1) By(3)],'Color','green');
hz = line([X(1) Bz(1)],[Y(1) Bz(2)],[Z(1) Bz(3)],'Color','blue');

axis([xmin xmax ymin ymax zmin zmax],'vis3d')
% view(120,30)
view(90,0)

grid on
xlabel('x')
ylabel('y') 
zlabel('z')
% 
% for k=1:length(t)
%     hold on
%     plot3(X(k),Y(k),Z(k),'c+')
% end
Bcog = ones(3,length(t));

for k=1:length(t)
set(hplot,'xdata',X(k),'ydata',Y(k),'zdata',Z(k));
Bcog(:,k) = [X(k); Y(k); Z(k)];
Bx(:,k) = Bcog(:,k)+(R.signals.values(:,1,k));
By(:,k) = Bcog(:,k)+(R.signals.values(:,2,k));
Bz(:,k) = Bcog(:,k)-(R.signals.values(:,3,k));
end

while waitforbuttonpress ~= 0 ; 
  pause(0.01) ; % allow for ctrl-c
end

for k=1:length(t)
set(hplot,'xdata',X(k),'ydata',Y(k),'zdata',Z(k));
% Bcog = [X(k); Y(k); Z(k)];
% Bx = Bcog+(R.signals.values(:,1,k));
% By = Bcog+(R.signals.values(:,2,k));
% Bz = Bcog-(R.signals.values(:,3,k));

set(hx,'xdata',[X(k) Bx(1,k)],'ydata',[Y(k) Bx(2,k)],'zdata',[Z(k) Bx(3,k)]);
set(hy,'xdata',[X(k) By(1,k)],'ydata',[Y(k) By(2,k)],'zdata',[Z(k) By(3,k)]);
set(hz,'xdata',[X(k) Bz(1,k)],'ydata',[Y(k) Bz(2,k)],'zdata',[Z(k) Bz(3,k)]);

pause(ts);

% drawnow
end

