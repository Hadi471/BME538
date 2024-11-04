delete(instrfind({'Port'},{'COM1'}))
myCOM=serial('COM1','BaudRate',9600);
fopen(myCOM);
myCOM;

ECG = fread(myCOM);

ECG = ECG/max(ECG);

plot(ECG);

