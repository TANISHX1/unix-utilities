// simple version of grep unix-utility

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool search (char *substring , char *string){
     int string_size    = strlen(string);
     int substring_size = strlen(substring);
     for(int i=0,j ;i<string_size - substring_size ;i++){
        
         for(j=0;j<substring_size;j++){
            if(string[i+j] != substring[j]){break;}
         }
         if(j==substring_size)
         return true;
        }
     return false;
}

int main(int argc , char * argv[]){
    FILE *fptr;
    int files = 1;
    char *substring = argv[files++];
    char buffer[256];
   
    //if No Command Line argument is passed
    if(argc<2){
       printf("wgrep: searchterm [file ...]\n");
       exit(1); 
    }
   
    //if only word is passed (when gets input through piping)
    if(argc == 2){
        while(fgets(buffer , sizeof(buffer),stdin) != NULL)
        {   if(search(argv[1],buffer))
           { printf("%s",buffer);}
        }
    }
    
    //if more than one file is passed
    else
    {
        while(files<argc)
       { 
            fptr = fopen(argv[files],"r");
            if(fptr == NULL){printf("wgrep: cannot open file\n") ;exit(1);}
            while(fgets(buffer,sizeof(buffer),fptr) != NULL)
            {
                if(search(substring,buffer))
                {
                    printf("%s",buffer);
                }
            } 
            files++;
            fclose(fptr);}
        }
    return 0;
}