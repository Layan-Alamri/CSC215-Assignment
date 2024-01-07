#include <stdio.h>
#include <stdlib.h>

struct Employee {
   int Id; 
   char name[20]; 
   double Salary; 
   char ChildrenNames[5][20]; 
   int count; 
};

int main(){
   
   FILE* fp = fopen("Employee.txt", "r");
   if(fp == NULL) {
      printf("cant open file to read\n"); 
      return 1; 
   }
   
   int num_lines = 0; 
   char temp[200]; 
   
   while (fgets (temp, 200, fp)){
      num_lines++; 
   } 
   fclose(fp); 
   
   struct Employee* list = (struct Employee*)calloc(num_lines, sizeof(struct Employee));
   fp = fopen("Employee.txt", "r");
   FILE* childFile = fopen("Chldren.txt", "r"); 
    
    if(childFile == NULL) {
      printf("cant open file to read\n"); 
      return 1; 
   }


   int i; 
   for(i = 0; i < num_lines; i++) {
      fscanf(fp, "%d" , &(list+i)->Id); 
      fscanf(fp, "%s" , (list+i)->name); 
      fscanf(fp, "%lf", &(list+i)->Salary); 
      
      char str[200]; 
      int IDFather, j; 
      fgets(str, 200, childFile ); 
         
      j = sscanf (str,"%d %s %s %s %s %s", &IDFather,(list + i)->ChildrenNames[0], 
         (list + i )->ChildrenNames[1], (list + i)->ChildrenNames[2], 
         (list + i )->ChildrenNames[3], (list + i)->ChildrenNames[4]); 
         
         (list+i)->count = j-1; 
   }//End for i
   
   fclose(fp); 
   fclose(childFile); 
   

   for(i = 0; i < num_lines; i++) {
      printf("Id: %d , name: %s , Salary: %.2f \n", (list+i)->Id, (list+i)->name, (list+i)->Salary);
      printf("Number of Childs:%d \n", (list+i)->count); 
      
      int l; 
      for(l = 0; l < (list+i)->count; l++)
         printf("%s\n", (list + i)->ChildrenNames[l]); 
      printf("------------------------------\n"); 
   }//End print all info
   
   return 0 ; 
}//End main 
