#include <stdio.h>
#include <string.h>
#define size 100

void countOddInteger (char* str, int* counter);
char* lastTwoWords (char* str);
void replace (char* str); 

int main() {
   char str[size]; 
   
   printf("Enter a sentence : "); 
   gets(str);
    
   int count = 0; 
   
   countOddInteger (str, &count);
   printf("The number of Odd integers in the string is : %d \n", count); 
   
   char *ss = lastTwoWords(str); 
   if (ss != NULL)
      printf("The last two words the in string is :%s \n", ss); 
   else
      printf("The is no 2 word in str \n") ; 
      
   replace( str ) ; 
   printf("The new string after replacement is : %s \n", str); 
   
   return 0 ; 
}//main


void countOddInteger (char* str, int* counter) {
   int len = strlen(str); 
   int i; 
   
   for(i = 0 ; i < len ; i++) {
      if( *(str+i) >= '0' && *(str+i) <= '9') {
       int num = (int) (*(str+i) - '0');
         if( num % 2 == 1 ) 
             ++*counter; 
     }//if
   }//for
}//count

char* lastTwoWords (char* str){
   int len = strlen( str ) -1; 
   int i; 
   int count = 0; 
   
   for( i = len ; i >= 0 ; i--) {
      if( *(str + i ) == ' ') 
         count++; 
      if(count == 2) 
         return (str + i ); 
   }//for
   
   if(count == 1) 
      return str; 
      
   return NULL;
}//last

void replace (char* str) {
   int i; 
   
   for(i = 0 ; i < strlen(str) ; i++)
      if( *(str+i) == ' ' ) 
         *(str+i) = '-'; 
}//replace