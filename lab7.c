#include<stdio.h> 
#include<conio.h> 
#include<math.h> 
int main() { 
int i,n,Sum=0,numbers;
 float Average; 
printf("Welcome to company Financial System**");
printf("\nHow many employees do you have in your company?\n");
 scanf("%d",&n); 
printf("\nPlease Enter all the salaries of each employee one by one\n"); 
for(i=0;i<n;++i) 
{ scanf("%d",&numbers); Sum = Sum +numbers; }
 Average = Sum/n; 

printf("\nAverage salaries of employee is $ %.2f Numbers of employees are = %d", Average, n);
 return 0; 
getch();}