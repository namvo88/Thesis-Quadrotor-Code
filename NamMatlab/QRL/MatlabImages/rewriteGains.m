
foldername = 'C:\Users\Nam\Documents\Git\Thesis-Quadrotor-Code\NamMatlab\QRL\MatlabImages\';
    
for nfile = 40:65

    nameA = strcat('Gains',num2str(nfile),'.mat');
    nameB = strcat(foldername,'LPOSQRL',num2str(nfile),'.mat');
    savename = strcat(foldername,'Gains',num2str(nfile),'.mat');
        if exist(nameB,'file') == 1
            load(nameB);
            save(savename,'comment','comment2','eps','facR','kR','kOmega','facq','kq','komega',...
            'facx','kpx','kdx','omega_n1_xL','omega_n2_xL','omega_n1_q',...
            'omega_n2_q','omega_n1_R','omega_n2_R','omega_n1_CFP','omega_n2_CFP','zeta_xL','zeta_q',...
            'zeta_R','LQRA','LQRB','LQRC','LQRD','K','LQRQ','LQRR','stept','stepamp');
        end
end
