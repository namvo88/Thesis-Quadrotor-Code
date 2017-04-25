function [ hat ] = hat( vec )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

a = vec(1);
b = vec(2);
c = vec(3);

hat = [ 0 -c b;
        c 0 -a;
        -b a 0];

end

