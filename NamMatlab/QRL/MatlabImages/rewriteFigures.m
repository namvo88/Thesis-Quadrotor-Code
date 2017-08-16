for nfile = [70:75]
    
    
    foldername = 'C:\Users\Nam\Documents\Git\Thesis-Quadrotor-Code\NamMatlab\QRL\MatlabImages\';
    loadname = strcat('LPOSQRL',num2str(nfile),'.mat');
    
    if exist(loadname,'file') == 2
        
        load(strcat(foldername,loadname));
        
    QRLplots;
    QRLplotsLQR;

clear;clc;close all
    end
    
end