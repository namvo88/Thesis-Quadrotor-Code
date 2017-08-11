

for nfile = 40:65
    foldername = 'C:\Users\Nam\Documents\Git\Thesis-Quadrotor-Code\NamMatlab\QRL\MatlabImages\';
    
    %     nameA = strcat('Gains',num2str(nfile),'.mat');
    nameB = strcat(foldername,'LPOSQRL',num2str(nfile),'.mat');
    savename = strcat(foldername,'Gains',num2str(nfile),'.mat');
    if exist(nameB,'file') == 2
        load(nameB);
        if exist('stept','var') == 0
            stept = 1.5;
            stepamp = 0.25;
            disp(strcat('added step var'));
        end
        if exist('fsat','var') == 0
            fsat = 1*[inf -inf];
            Msat = 1*[inf -inf];
            disp(strcat('added fsat var'));
        end
        save(savename,'comment','comment2','eps','facR','kR','kOmega','facq','kq','komega',...
            'facx','kpx','kdx','omega_n1_xL','omega_n2_xL','omega_n1_q',...
            'omega_n2_q','omega_n1_R','omega_n2_R','omega_n1_CFP','omega_n2_CFP','zeta_xL','zeta_q',...
            'zeta_R','LQRA','LQRB','LQRC','LQRD','K','LQRQ','LQRR','stept','stepamp','fsat','Msat');
        disp(strcat(num2str(nfile),'done'))
    end
    clear
end
