/*Assignment 3
------------------------------------ Q2 ------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee {
   int Id; 
   char name[20]; 
   double Salary; 
   char ChildrenNames[5][20]; 
   int count; 
};

void printChildren(struct Employee* array, int id, char c );
void addNewChild(struct Employee* array, int id, char* cName);

int main() {
   int size; 
   
   printf("Enter number of employees: "); 
   scanf("%d", &size); 
   
   struct Employee* list; 
   list = (struct Employee*)calloc(size, sizeof(struct Employee));
   
   int i; 
   for(i = 0; i < size; i++) {
      printf("\nEnter employee #%d id: ", (i+1));
      scanf("%d", &(list+i)->Id);
      
      printf("Enter employee name: ");
      getchar(); // clean garbage
      gets((list+i)->name);
      
      printf("Enter employee salary: ");
      scanf("%lf", &(list+i)->Salary); 
      
      do {
         printf("How many kids? ");
         scanf("%d", &(list+i)->count);
      } while((list+i)->count < 0 || (list+i)->count > 5 );
       
      int j; 
      for(j = 0; j < (list+i)->count ; ++j) {
         char s[20]; 
         printf("Enter child #%d name: ", (j+1));
         getchar(); 
         scanf("%s", s); 
         strcpy((list + i)->ChildrenNames[j], s ); 
      }// End for j child
   } // End for i 
   
//----------------------------------------------------------------
   int id2;
   char newName[20]; 
   
   printf("\nEnter the id of the employee you would like to add new child for him\n");
   scanf("%d", &id2); 
   
   printf("Enter the name of the new child\n"); 
   scanf("%s", newName);
   
   addNewChild( list , id2 , newName ) ; 
//----------------------------------------------------------------
   char c;
    
   printf("Enter the letter: "); 
   getchar(); 
   scanf("%c", &c); 
   
   printf("Enter the id of the employee you would like to view his child's name starting with letter %c:\n", c);
   int d; 
   scanf("%d", &d); 
   
   printChildren(list, d, c); 
   return 0; 
}//End main

//----------------------------------------------------------------
void printChildren(struct Employee* array, int id, char c) {
   int i; 
   for(i = 0; (array+i); ++i) {
   
      if((array+i)->name[0] == '\0') 
         break;
      if((array+i)->Id == id) {
         if((array+i)->count == 0) {
            printf("The employee has no kids.\n"); 
            return ; 
         }//End if((array+i)->count == 0)
         else{
            printf("Children names: \n");
            
            int j; 
            for(j = 0; j < (array+i)->count; ++j) {
               if((array+i)->ChildrenNames[j][0] == c || c == ' ') 
                  printf("%s %s \n", (array+i)->ChildrenNames[j], (array+i)->name);
            }//End for j
            return; 
         }// End else 
      }// End ((array+i)->Id == id)   
   }// End for i
   printf("No employee with the specified id\n");
}//End method printChildren

//----------------------------------------------------------------
void addNewChild(struct Employee *array, int id, char* cName) {
   int i; 
   for(i = 0; (array+i); ++i) {
      if((array+i)->name[0] == '\0') 
         break;
      if((array+i)->Id == id) {
         if((array+i)->count == 5) {
            printf("you can't add new kids for this employee.\n"); 
            return ; 
         }//End if((array+i)->count == 5)
         else {
          // Add new child
            int new = (array+i)->count; 
            strcpy((array+i)->ChildrenNames[new], cName); 
            (array+i)->count = (array+i)->count+1;
            return ; 
         }//End else
      }//End if((array+i)->Id == id) 
   }//End for i
   printf("No employee with the specified id\n");
}//End method addNewChild