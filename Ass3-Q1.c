/*Assignment 3
------------------------------------ Q1 ------------------------------------*/
#include <stdio.h>
#include <string.h>

 void reserve2nPart (char* str, char ch);
 
int main() {

   char str[100]; 
   char ch;
   
   printf("Enter a string: ");
   scanf("%s", str);
   printf("Enter the character to substring the string: ");
   scanf(" %c", &ch); 
   
   reserve2nPart (str, ch);
   
   printf("The reversed string is: %s \n", str); 
   printf("The second character in new reserved is: %c \n", *(str+1)); 
   
   return 0;
}//End main

void reserve2nPart (char* s, char ch) {
   char* str = strchr(s, ch); 
   int length = strlen(str); 
   
   char temp; 

   int i, j; 
   for (i=0, j = length-1; i < j; i++, j--) {
      temp = *(str+i); 
      *(str+i) = *(str+j);
      *(str+j) = temp; 
   } 
   strcpy(s, str); 
}//End method reserve2nPart