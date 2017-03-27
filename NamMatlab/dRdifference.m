figure
hold on
t = dRdiff.time;
dRdiffval = zeros(size(t));
dRdudtval = zeros(size(t));
dRBlockval = zeros(size(t));

for n=1:3
    for m=1:3
        for k=1:length(t)
            dRdiffval(k) = dRdiff.signals.values(n,m,k);
        end
        subplot(9,1,(n-1)*3+m)
        plot(t,dRdiffval)
    end
end
hold off
suptitle('Difference')
%%
figure
hold on
t = dRdudt.time;

for n=1:3
    for m=1:3
        for k=1:length(t)
            dRdudtval(k) = dRdudt.signals.values(n,m,k);
            dRBlockval(k) = dRBlock.signals.values(n,m,k);
        end
        dRdiff2 = dRBlockval-dRdudtval;
        subplot(9,2,2*((n-1)*3+m)-1)
        plot(t,dRdiff2)        
        subplot(9,2,2*((n-1)*3+m))
        plot(t,dRdudtval,t,dRBlockval);
        legend('dudt','Block')
    end
end
hold off

%%
% figure
% hold on
% t = dRBlock.time;
% 
% for n=1:3
%     for m=1:3
%         for k=1:length(t)
%             dRBlockval(k) = dRBlock.signals.values(n,m,k);
%         end
%         subplot(9,1,(n-1)*3+m)
%         plot(t,dRBlockval)
%     end
% end
% hold off
% suptitle('dRBlock')