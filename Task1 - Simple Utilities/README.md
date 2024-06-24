# Task1 - Simple Linux Shell Utilities

## In this task, some simple Linux Shell utilities are implemented in C.


### 1. pwd 

Like the Linux's pwd, it displays the current working directory.

Example of compiling & usage:
```
> gcc pwd.c -o pwd
> ./pwd
```

Output: ``` /home/shady ```


Note: if the current working directory length is larger than MAX_PATH_LEN (100), program will fail and an error message is displayed



### 2. echo

Like the Linux's echo, it displays the user's input message.

Example of compiling & usage:
```
> gcc echo.c -o echo
> ./echo Hello world
```

Output: ```Hello world```



### 3. cp

Like the Linux's cp, it makes a copy of a source file into the destination file. If destenation file doesn't exsist, it will be created only if the parent path exsists. The utility doesn't create any of the parent directories.  If destenation file exsists, it will be
overwritten.


Example of compiling & usage:
```
> gcc cp.c -o cp
> ./cp /home/shady/Desktop/sample1.txt /home/shady/sample2.txt
```

Output: On success, nothing is printed on screen, a new file with name sample2.txt  will be created within the directory /home/shady/ if it wasn't exsist, and it will hold the same content of sample1.txt (original file).
On failure, an appropriate message is displayed to stderr.



Another example of compiling & usage:
```
> gcc cp.c -o cp
> ./cp /home/shady/Desktop/sample1.txt /home/shady/
```

Output: On success, nothing is printed on screen, a new file with name sample1.txt (same as original file name) will be created within the directory /home/shady/ if it wasn't exsist, and it will hold the same content of sample1.txt (original file).
On failure, an appropriate message is displayed to stderr.



### 4. mv

Like the Linux's mv, it moves a source file into a new directory. If destenation file doesn't exsist, it will be created only if the parent path exsists. The utility doesn't create any of the parent directories. If destenation file exsists, it will be overwritten.


Example of compiling & usage:
```
> gcc mv.c -o mv
> ./mv /home/shady/Desktop/sample1.txt /home/shady/sample2.txt
```

Output: On success, nothing is printed on screen, a new file with name sample2.txt  will be created within the directory /home/shady/ if it wasn't exsist, and it will hold the same content of sample1.txt (original file). Then sample1.txt is removed.
On failure, an appropriate message is displayed to stderr.



Another example of compiling & usage:
```
> gcc mv.c -o mv
> ./mv /home/shady/Desktop/sample1.txt /home/shady/
```

Output: On success, nothing is printed on screen, a new file with name sample1.txt (same as original file name) will be created within the directory /home/shady/ if it wasn't exsist, and it will hold the same content of sample1.txt (original file). Then sample1.txt (original file) is removed.
On failure, an appropriate message is displayed to stderr.

