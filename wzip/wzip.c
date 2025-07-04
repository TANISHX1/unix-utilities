#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc , char*argv[]){

    int files=1;
    FILE *fptr;
    
    if (argc<2){
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
    char current , prev='\0';
    int count=0;
    while(files<argc)
    {
        fptr = fopen(argv[files],"r");
         if(fptr == NULL){
            exit(1);
        }
        
       while((current = fgetc(fptr))!=EOF)
        {
            if(current == prev){count++;}
             else{
                if(count>0)
                {
                    fwrite(&count,sizeof(int),1,stdout);
                    fwrite(&prev,sizeof(char),1,stdout);
                }
                    prev=current;
                    count=1;
             }
            }
            fclose(fptr);
            files++;
    
    } 
      
            if(count>0)
            {
                fwrite(&count,sizeof(int),1,stdout);
                fwrite(&prev,sizeof(char),1,stdout);
            }
            
    
    return 0;
}
