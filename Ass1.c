#include <stdio.h>

int isDig (char ch);
double halfNum (int num);
void printOddEven (double number1, double number2); 

int main () {
   char ch; 
   int num1, num2; 
   
   printf("Enter a character: "); 
   scanf("%c", &ch); 
   
   printf("Enter the first number: "); 
   scanf("%d", &num1); 
   
   printf("Enter the second number: "); 
   scanf("%d", &num2); 
   
   if (isDig( ch ))
      printf("The character is numerical \n"); 
   else
      printf("The character is Not numerical \n"); 
      
      
   printf("The half of %d is %.2lf \n",num1 ,halfNum(num1));
   
   printOddEven(num1, num2); 
   
   return 0 ; 
}//m

int isDig (char ch){
   if(ch >= '0' && ch <= '9')
      return 1 ; 
   else
      return 0 ; 
}

double halfNum (int num){
   return num / 2.0 ; 
}

void printOddEven (double number1, double number2){
   double sum = number1 + number2 ; 
   
   if( (int)sum % 2 == 0) 
      printf("The summation of %.0lf and %.0lf is Even number \n" , number1 ,number2); 
   else
      printf("The summation of %.0lf and %.0lf is Odd number \n" , number1 ,number2); 
}