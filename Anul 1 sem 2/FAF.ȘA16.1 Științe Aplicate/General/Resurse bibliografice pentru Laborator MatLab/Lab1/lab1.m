% Lucrare de laborator Nr.1
% Student ...Nume, prenume, grupa...
% Varianta ...

% Sarcina II.1. Calcularea expresiilor intr-un rind
x = -1.75*10^-3;
y = 3.1*pi;

F1 = ((exp(x)*sin(y)+exp(-x)*cos(y))/(exp(x)+sin(y)))^3.5...
+sqrt((exp(x)+sin(y))/(exp(x)*sin(y)+exp(-x)*cos(y)))...
+abs(x)*sin(y)

F2 = atan((2*x-sin(y))^(1/5)/sqrt(abs(x-log(y))))...
+abs(x)*sqrt(abs(x-log(y)))/(2*x-sin(y))^(1/5)

% II.2. Calcularea expresiilor cu variabile optimizate
a = exp(x)*sin(y)+exp(-x)*cos(y)
b = exp(x)+sin(y)
c = abs(x)*sin(y)
d = (2*x-sin(y))^(1/5)
e = sqrt(abs(x-log(y)))
disp('cu variabile intermediare:')
F11 = (a/b)^3.5 + sqrt(b/a) + abs(x)*sin(y)
F22 = atan(d/e) + abs(x)*e/d

% II.3. Diferite formate
disp('Prezentarea rezultatelor in diferite formate')
format long; F1, F2
format hex; F1, F2
format rat; F1, F2

% II.4. Studierea informatiei despre variabile
disp('Whos:')
whos
