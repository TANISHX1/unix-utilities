## wzip
 **wzip** is a file compression tool. The compression method used here is known as run-length encoding (RLE). 
 It’s a straightforward approach where sequences of repeated characters are replaced with the count of those characters followed by the character itself.
 So, if a character appears multiple times in a row, the tool — in this case, wzip — compresses it by storing how many times it appeared and the character just once.
 if we had a file called input.txt with the following content:
```
aaaabbbbccccdddddeeeeeeeeee
```
wzip would turn it (logically) into:
```
4a5b4c5d10e
```
However, the exact format of the compressed file is quite important; here,
a 4-byte integer in binary format followed by the single character in ASCII is write out.
a compressed file will consist of some number of 5-byte entries, each of which is comprised of a 4-byte integer (the run
length) and the single character. 

* wzip supports `multiple files ` ,`no files (error)` ,`multi-line file with some longer lines` .

**Note** 

wzip use shell redirection in order to write the compressed output in a file (binary file).
For Example ,  to compress the file **input.txt** into a (hopefully smaller) **pinfo.bin**,
you would type:

`blazex@fedora:~/initial-utilities/wzip$ ./wzip input.txt > pinfo.bin`


**Details**
* Correct invocation should pass one or more files via the command line to the 
  program; if no files are specified, the program should exit with return `code
  1` and print `wzip: file1 [file2 ...]` (followed by a newline).
* Do note that if multiple files are passed to **wzip*, they are compressed
  into a single compressed output, and when unzipped, will turn into a single
  uncompressed stream of text (thus, the information that multiple files were
  originally input into **wzip** is lost). The same thing holds for
  **wunzip**.
* this compression method (RLE) may give negative compression.
