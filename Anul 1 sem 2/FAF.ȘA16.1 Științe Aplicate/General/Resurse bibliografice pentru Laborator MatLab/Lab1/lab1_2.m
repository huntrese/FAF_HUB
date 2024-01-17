% Lucrare de laborator Nr.1
% Student ...Nume, prenume, grupa...
% Varianta ...

% Sarcina III. De calculat valorile functiei pe segmentul dat
% in N puncte la intervale egale unul de altul.
% III.1 Limitele intervalului, numarul de puncte si pasul
a = -pi;
b = pi;
N = 8;
pas = (b-a)/(N-1);
% III.2. Intrevalul pentru x si calcularea y
x = [a:pas:b]
y = log(x.^2+1)+x.*cos(x).^2
