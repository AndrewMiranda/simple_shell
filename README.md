# Simple Shell 👨🏻‍💻
### Authors

- Andrew Miranda / tiburonandrew@gmail.com 📧
- Sebastián Contreras / sebastiancontreras15897@gmail.com 📧

------------
### Unix shell
A Unix shell is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems. The shell is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts.
![](https://hipertextual.com/files/2015/03/terminal-linux.jpg)
###### for example 
       
    
    vagrant@vagrant-ubuntu-trusty-64:~$ time
	real    0m0.000s
    user    0m0.000s
    sys     0m0.000s
    vagrant@vagrant-ubuntu-trusty-64:~$ date
    Wed Nov 18 16:34:14 UTC 2020
    vagrant@vagrant-ubuntu-trusty-64:~$



------------
### FlowChart

```flow
st=>start: Login
op=>operation: enter a command
cond=>condition: Successful Yes or No?
e=>end: run command

st->op->cond
cond(yes)->e
cond(no)->op
```
------------


## 0x16. C - Simple shell
This project is made for the holbertonSchoolColombia school, the objective is to create a simple unix command interpreter.

------------
## functions shell
| Function name | Description                    |
| ------------- | ------------------------------ |
| `exit()`      | command to end the shell script.|
| `function_name()`|and that's what you will use to call it from elsewhere in your scripts.|
------------
## Means
Read or watch:
1. Unix shell
2. Thompson shell
3. Ken thompson
4. Everything you need to know to start coding your own shell concept page

------------
# Learning Objectives
the school gives us different learning objectives which are
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?


💻#end💻
