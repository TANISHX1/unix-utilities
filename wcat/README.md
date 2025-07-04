## Wcat
The program wcat is a simple program. Generally, it reads a file as specified by the user and prints its contents. 
A typical usage is as follows, in which the user wants to see the contents of main.c, and thus types:
```
blazex@fedora:~/Documents/OS/ostep-projects/initial-utilities/wcat$ ./wcat wcat.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc , char * argv[]){
    if (argc<2){
        exit(0);
    }

```
