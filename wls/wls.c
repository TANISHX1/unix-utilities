#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#define PATH_MAX 1024

int inode ( DIR *fdir , const char *path){
    struct dirent *entry;
    struct stat status;
    char path_buffer[PATH_MAX];
    printf("inode\t | \tType\t | \tname\n");
    printf("-----\t   \t----\t   \t----\n");
    while((entry = readdir(fdir)) != NULL){
    printf("%-5llu\t |",entry->d_ino);
    snprintf(&path_buffer,sizeof(path_buffer),"%s/%s",path,entry->d_name);
    if(stat(&path_buffer,&status) == -1){
        fprintf(stderr, "[Error] stat\n");
        continue;
    }
    if(S_ISDIR(status.st_mode)){
        printf("\tDIR\t |\t");
    }
    else if(S_ISREG(status.st_mode)){
        printf("\tFILE\t |\t");
    }
    else{
        printf("\tother\t |\t");
    }
    printf("%-5s",entry->d_name);
    printf("\n");
}
}

int main(int argc ,char * argv[]){
   struct dirent *entry;   
   DIR *fdir;
   const char *path = (argc>1)?argv[1]:".";
   fdir = opendir(path);
   if(fdir == NULL){
    fprintf(stdout, "[Error]__Failed_to_open\n");
    exit(1);
   }
   if(argc ==1){
    while((entry = readdir(fdir)) != NULL){
        if(entry->d_name[0] == '.'){
            continue;
        }
        printf("%s\t",entry->d_name);
    }
    printf("\n");
   }
  else
  {
    inode(fdir,path);
   }
   closedir(fdir);
   return 0;
}
