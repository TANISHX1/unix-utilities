#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void bin_read(FILE *fptr){
   char letter;
   int count;
 
   while(  fread(&count,sizeof(int),1,fptr) ==1)
   {
    
    fread(&letter,sizeof(char),1,fptr);
    for(int i=0;i<count;i++){
        printf("%c",letter);
       
    }
   }
}

int main(int argc ,char *argv[]){
    FILE *fptr;
    if(argc<2){
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }
    int files=1;
    while(files<argc)
    {
       fptr = fopen(argv[1],"rb");
       if(fptr == NULL){
        exit(1);
        }
       bin_read(fptr);
       files++;
    }
    return 0;
}