## wgrep
A variant of the UNIX tool **grep**. This tool looks through a file, line by line, trying to find a
user-specified search term in the line. If a line has the word within it, the line is printed out, otherwise it is not. 

Here is how a user would look for the term **printf** in the file **wgrep.c**:
```
blazex@fedora:~/initial-utilities/wgrep$ ./wgrep printf wgrep.c
       printf("wgrep: searchterm [file ...]\n");
           { printf("%s",buffer);}
            if(fptr == NULL){printf("wgrep: cannot open file\n") ;exit(1);}
                    printf("%s",buffer);
```
**wgrep** can do `standard input test`(cat wgrep.c | ./wgrep words) using piping in the terminal / shell/ unix command line. also supports `long search term` and 
`long lines of text` (has a buffer size of `256` characters per line).

**Details**
* Always passed a search term and zero or more files to grep through (thus, more than one is possible). It should go
  through each line and see if the search term is in it; if so, the line
  should be printed, and if not, the line should be skipped.
* The matching is case sensitive. Thus, if searching for **printf**, lines
  with **Printf** will *not* match. 
* If passed no command-line arguments, it print's
  "wgrep: searchterm [file ...]" (followed by a newline) and exit with status 1.  
* If **wgrep** encounters a file that it cannot open, it should print
  "wgrep: cannot open file" (followed by a newline) and exit with status 1. 
* In all other cases, **wgrep** should exit with return code 0.
* If a search term, but no file, is specified, **wgrep** should work,
  but instead of reading from a file, **wgrep** should read from *standard input*.
* For simplicity, if passed the empty string as a search string, **wgrep** print's NO lines. 
