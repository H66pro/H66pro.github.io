%%
str = num2str(3.1415926,4);
%4为有效数字；将数字（或者数组...）转换为字符串，"4"为有效数字
abs = abs('gb');
%字符转ASCII码
char = char(77);
%ASCII码转字符
fprintf(str)
%打印字符
length = length(str)
%输出字符长度，包括空格
doc num2str
%在一个窗口中打开对应函数的帮助文档
help num2str
%在命令行中显示帮助信息
lookfor num
%模糊查找含有"num"的函数
%%矩阵
A = [11 12 13; 21 22 23; 31 32 33]
%;换行，","或" "分隔
% B = A'
% %行列式转置
% C = A(:)
%将A竖向展开
D = inv(A)
%矩阵求逆
A * D

E = zeros(10,5,3)
E(:,:,1) = rand(10,5)
E(:,:,2) = rand(5,10,5)
E(:,:,3) = rand(10,5)
%%