% Rotation matrices

% syms phi theta psi
% 

phi = 178;
theta = 0;
psi = 0;


Rx = [1 0 0; 
      0 cosd(phi) sind(phi); 
      0 -sind(phi) cosd(phi)];

Ry = [cosd(theta) 0 -sind(theta);
      0 1 0;
      sin(theta) 0 cosd(theta)];

Rz = [cosd(psi) sind(psi) 0; 
     -sind(psi) cosd(psi) 0; 
      0 0 1];
  
Rzxy = Rz*Rx*Ry
Rzyx = Rz*Ry*Rx
Rzyz = Rz*Ry*Rz

%%
phi = 178;
theta = 0;
psi = 0;

Rz1 = [cosd(psi) sind(psi) 0; 
     -sind(psi) cosd(psi) 0; 
      0 0 1];
Ry = [cosd(theta) 0 -sind(theta);
      0 1 0;
      sin(theta) 0 cosd(theta)];
Rz2 = [cosd(phi) sind(phi) 0; 
     -sind(phi) cosd(phi) 0; 
      0 0 1];
Rzyz = Rz1*Ry*Rz2

%%
phi = 10;
theta = 0;
psi = 0;

Rz = [cosd(psi) sind(psi) 0; 
     -sind(psi) cosd(psi) 0; 
      0 0 1];
Ry = [cosd(theta) 0 -sind(theta);
      0 1 0;
      sin(theta) 0 cosd(theta)];
Rx = [1 0 0; 
      0 cosd(phi) sind(phi); 
      0 -sind(phi) cosd(phi)];  
Rzyx = (Rx*Ry*Rz).'
  
  