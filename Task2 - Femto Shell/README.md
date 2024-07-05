# Task1 - Simple Linux Shell (Femto Shell)

## In this task, a simple shell is implemented in C to be like Linux Shell.

## Compilation steps

To compile & run the code: 
```
> gcc *.c -o femtoShell
> ./femtoShell
```

Output: ``` Your command: ``` and the program waits for user to input the command


## Available commands:

The shell supports two types of commands:

### 1. Built-in commands

commands that are executed within the shell without running any new processes. This includes:

#### 1. assignment command 

It's used to create a new local variable or update it if it exists.

Syntax:

```
<name>=<value>
```

Output: None

Note: Any leading or trailing spaces in variable names or values are truncated. ``` x=12 ``` is equivalent to ```      x  =      12```

#### 2. set

It's used to display all local variables.

Example pf usage:

```
> gcc *.c -o femtoShell
> ./femtoShell
Your command: x=14
Your command: y =   15
Your command: z  =   hello
Your command: x =   1
Your command: set
```

Output:
```
localVar[0]: x=1
localVar[0]: y=15
localVar[0]: z=hello
```

#### 3. export

It's used to export local variables (separated by spaces) to the environment variables.

Syntax:

```
export <variable 1 name> <variable 2 name> ... <variable n name>
```


#### 4. env

It's used to list all environment variables.


Example pf usage:

```
> gcc *.c -o femtoShell
> ./femtoShell
Your command: x=14
Your command: y =   15
Your command: z  =   hello
Your command: x =   1
Your command: export x z
Your command: env
```

Output:
```
...
x=1
z=hello
```



### 2. External commands

Any other command is treated as an external command, it will be executed in another process.

Example of usage:

```
> gcc *.c -o femtoShell
> ./femtoShell
Your command: ls
```

Output:
```
arrayList.c  arrayList.h  femtoShell  femtoShell.c  README.md  stringUtil.c  stringUtil.h  var.c  var.h
```


Another example:

Example pf usage:

```
> gcc *.c -o femtoShell
> ./femtoShell
Your command: ls -l /home/shady/Desktop
```

Output:
lists all files and directories on the desktop using then long format.
