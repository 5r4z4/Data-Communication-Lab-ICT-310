clc;
clear all;
%Distribution of different values in Workspace
x = 1:5;
y = [6 7 8 9 10];
z = [10 20
      30 40];
  
%Use of If/else in Matlab
%input a number
 num = input('Enter a num: ');
 if num > 0
     disp('The number is positve');
     
 elseif num < 0
         disp ('The num is negative');
 else 
     disp('The num is zero');
 end;
 
 