## Wcat
**wcat** is simple version of **cat**(a unix utility)
The program **wcat** is a simple program. Generally, it reads a file as specified by the user and prints its contents. 
A typical usage is as follows, in which the user wants to see the contents of main.c, and thus types:
```
blazex@fedora:~/initial-utilities/wcat$ ./wcat wcat.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc , char * argv[]){
.......
```
As shown, **wcat** reads the file **main.c** and prints out its contents.
wcat can read a `one-line file` ,`simple multi-file` ,`empty file` ,`no input file at all` ,`long file` ,`bad file on command line (does not exist)` ,`many files on command line, but one of them does not exist`    

**Details**
* it can be invoked with one or more files on the command
  line; it should just print out each file in turn. 
* In all non-error cases, **wcat** exit with status code 0.
* If *no files* are specified on the command line, **wcat** should just exit
  and return 0. 
* If the program tries to **fopen()** a file and fails(fopen return's NULL ), it should print a
  message "wcat: cannot open file" (followed by a newline) and exit
  with status code 1.  If multiple files are specified on the command line,
  the files should be printed out in order until the end of the file list is
  reached or an error opening a file is reached (at which point the error
  message is printed and **wcat** exits). 
