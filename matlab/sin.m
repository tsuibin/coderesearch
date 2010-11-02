#! /usr/bin/env octave
t = linspace(0,3*pi,500);
y = sin(t);
z1 = ((t<pi) | (t > 2*pi)).*y; %<3>
w=(t>pi/3&t<2*pi/3)+(t>7*pi/3&t<8*pi/3);
w_n=~w;
z2=w*sin(pi/3)+w_n.*z1;
subplot(1,3,1),plot(t,y,':r'),ylabel('y');
subplot(1,3,2),plot(t,z1,':r'),axis([0 10 -1 1]);
subplot(1,3,3),plot(t,z2,'-b'),axis([0 10 -1 1]);

