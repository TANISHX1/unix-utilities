#include <stdio.h>
#include <stdlib.h>

int main(int argc , char * argv[]){
    if (argc<2){
        exit(0);
    }
    int files = 1;
    char buffer[200];
    while(files<argc)
    {
        FILE *fptr = fopen(argv[files], "r");
        
        if(fptr == NULL){
            printf("wcat: cannot open file\n");
            exit(1);
        }
        while(fgets(buffer ,sizeof(buffer),fptr) !=NULL ){
            printf("%s",buffer);
        }
        files ++;
        fclose(fptr);
    }
    
    return 0;
}