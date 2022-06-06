# Signal

signal: a notification of an event to the target process

## 1. Example of signal

### 1) No signal handling

ex1.c:

```c
void main(){
   for(;;);
}
```

`^c` will kill this process. When the user presses `^c`, the system sends a signal (SIGINT: signal number 2) to the current running process. If the process didn't prepare for this signal, it dies.

### 2) Prepared for the signal number 2

ex2.c:

```c
#include <stdio.h>
#include <signal.h>
void foo(int signum){
  printf("I am ok\n");
}
void main(){
   signal(2, foo);   // prepare for signal number 2. same as signal(SIGINT, foo)
   for(;;);
}
```

`signal(SIGINT, foo)` means "don't kill me when `SIGINT` arrives, run `foo()` instead".

## 2. signal number, signal name, signal event, target process, default action

Refer "/usr/include/bits/signum.h" for signal numbers and signal names.
| signal number | signal name | when this signal is raised | whom this signal is sent to | default action |
| ------------- | ----------- | ------------------------------------------------------------------ | --------------------------------------------- | ---------------------- |
| 1 | SIGHUP | a session leader with a controlling terminal(e.g. shell) is killed | all foreground child processes of this leader | kill |
| 2 | SIGINT | ^c | foreground process | kill |
| ..... | | | | |
| 9 | SIGKILL | kill -9 1234 | pid 1234 | kill with no exception |
| ....... | | | | |
| 11 | SIGSEGV | illegal access of memory | the process who accessed illegal memory area | kill |
| ..... | | | | |
| 15 | SIGTERM | kill 1234 | pid 1234 | kill |
| ... | | | | |
| 17 | SIGCHLD | child process is killed | the parent process | ignore |
| ......... | | | | |
| 20 | SIGTSTP | ^z | the currrent process | suspend |
| 31 | SIGSYS | bad system call | the process who called the system call | kill |

## 3. `kill` command, `kill()` system call

`kill` is a command to send a signal (it is not a command to "kill" a program!)

```bash
kill  -12  1234
```

will send "signal 12" to "process 1234". If the signal number is not specified signal 15 is sent. Thus

```bash
kill  1234
```

is same as

```bash
kill  -15  1234
```

And if process 1234 didn't prepare for signal number 15, it will "kill" the process. If process 1234 did prepare for signal 15, it cannot "kill" the process.

A program can call `kill()` to send a signal.

```c
kill(1234, 15);
```

will send signal 15 to process 1234.

## 4. How the signal is processed

signal `x` is raised ==><br>
signal `x` is sent to the target process ==><br>
if the target process has prepared for this signal<br>
the prepared function is executed<br>
and go back to the location where the signal is happened<br>
otherwise<br>
do the default action

### ex)

ex1 is running ==><br>
`^c` is pressed ==><br>
signal 2 (SIGINT) is raised ==><br>
signal 2 is sent to ex1 ==><br>
ex1 is killed

ex2 is running ==><br>
`^c` is pressed ==><br>
signal 2 (SIGINT) is raised ==><br>
signal 2 is sent to ex2 ==><br>
`foo()` is executed ==><br>
go back to `for(;;);`

## 5. Exit

All program should call `exit()` to terminate the program. (In fact, the compiler adds `exit()` at the end of all programs in case the programmer forgets).

```c
int main(){
    ..........
    exit(0);  // terminate this process and send exit status(0) to the parent
}
```

Algorithm for `exit`:

```
1. remove the body
2. make the process status "zombie"
3. send SIGCHLD to the parent
4. adopt the children of this process to the init process (pid=1)
```

(\* "init" process (pid=1) is one that runs an infinite loop calling `wait()`. It removes a zombie process whoever becomes a child of it.)

## 6. Wait

The parent should call `wait()` for each child it has created.

Algorithm for `wait`:

```
if the child is already dead (a zombie)
    remove the process descriptor
else
    wait until the child is dead
```

```c
int x, y;
x = wait(&y);
printf("child %d is removed. the exit status was %d\n", x, y);
```

## 7. daemon process

- A process which satisfies
  - the only process in a new process group in a new session
  - it is not a process group leader, nor a session leader

```c
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>

int main(){
   int x,y,z;

   x=fork();
   if (x != 0) exit(0); // kill the parent

   setsid(); // become a session leader of a new session and
             // lose the controlling terminal. "ps -ejf|grep pid" (pid is the process id of
             // this process) will show the PID of this process is same as its SID,
             // and it has no terminal. Since it no longer belongs to the original terminal
             // it will not get SIGHUP when the original terminal is closed

   if (fork() !=0) exit(0); // kill the parent again, so that the child becomes the only
                            // non-session-leader member in the new session
   // prepare for various signals
   signal(SIGCHLD,SIG_IGN); /* ignore child */
   signal(SIGTSTP,SIG_IGN); /* ignore tty signals */
   signal(SIGTTOU,SIG_IGN);
   signal(SIGTTIN,SIG_IGN);
   signal(SIGHUP,signal_handler); /* catch hangup signal */
   signal(SIGTERM,signal_handler); /* catch kill signal */

   for(;;){
     // daemon's code here
     ...........
   }
}
```

## 8. Homework

(Do not use `^z` when experimenting with signals. `^z` will stop the process, and the process cannot receive further signals.)

### 1) Try to kill ex1 and ex2 in Section 1 with ^c. What happens? You cannot kill ex2 with ^c, just leave it and go to homework 1-1).

#### 1-1) Open another putty window and find the pid of ex2 by `$ ps -ef | grep 12345` where 12345 is your student ID. Suppose ex2's pid is 334455. Send SIGINT (signal number 2) to ex2 with `$ kill -2 334455` What happens? Explain the result.

### 2. You can kill ex2 as follows:

```
open another terminal
find the pid of ex2, e.g. 1234
kill 1234 (or “kill -15 1234”)
```

Why SIGINT (signal 2) cannot kill ex2 while SIGTERM (signal 15) can?

#### 2-1) Change ex2.c as follows.

```c
#include <stdio.h>
#include <signal.h>

void foo(int signum){
    printf("I am ok\n");
}

void main(){
    signal(2, foo); // prepare for signal number 2. same as signal(SIGINT, foo)
    signal(15, foo);
    for(;;);
}
```

Now compile and run ex2 and try to kill it with SIGINT and SIGTERM in another window. Assume ex2 has pid 334455.

```bash
$ kill -2 334455
$ kill -15 334455
```

Explain the result.

### 3. You can also kill ex2 by closing the terminal where ex2 is running. Confirm this by first finding out the pid of ex2 with `ps –ef | grep 1234` (assuming your student id is 1234) in another terminal, close the terminal where ex2 is currently running, and find this pid again with `ps –ef | grep 1234` in the second window. Explain why ex2 dies in this case.

### 4. How can you prevent ex2 from being killed even when you close the terminal?

### 5. If you were successful in problem 4 in preventing ex2 from being killed, how can you still kill ex2?

### 6. Write a program (ex3.c) that forks two children as below. All three processes (the parent and the two children) run infinite loops. Run this program and find the pids of the three processes in another window. Kill the parent (`kill -15 parent-pid`) and observe what happens to the children.

```c
   ..................
   x = fork();
   if (x==0) for(;;); // first child
   else{
   y=fork();
   if (y==0) for(;;); // second child
   }
   for(;;); // parent
   ...........
```

### 7. Same as 6), but this time kill the shell of the terminal where ex3 is running with `kill -9 114455`, where 114455 is the pid of the shell. What happens to the three processes (the parent and the two children)? Why the three children die and how can you prevent the three processes from being killed?

### 8. Same as 6), but this time kill one of the children instead of the parent. What happens to the dead child? Can you remove this dead child (zombie) with signal 9? How can you remove this dead child?

### 9. In problem 8), how can you prevent the generation of a zombie child? Modify your code in 6) to prevent the generation of zombie child. Remember the parent cannot wait in `wait()` since the parent should run its infinite loop too. The parent should prepare a handler for `SIGCHLD` signal and call `wait()` inside this handler.

### 10. Modify your FTP server program such that it doesn’t generate zombie children.

### 11. Write a program that uses `kill()` to send a signal to a process.

```c
    enter pid and signal number
    1234 15
    enter pid and signal number
    1122 2
    ............
    Use above program to kill ex2.
```

### 12. Modify your shell such that it can handle `&` symbol. In a normal shell, the `&` symbol means "give me prompt without waiting".

ex) Suppose "inf.c" is as follows:

```c
int main(){
    for(;;){
        .............
    }
}
```

If you run "inf" without `&`, the shell will wait until "inf" finishes.

```bash
$ ./inf
-               --- shell wait here
```

But if you run it with `&`, the shell runs "inf" but is ready for next command.

```bash
$ ./inf&
$               --- "inf" is running, but you can issue next command
```

### 13. Make a daemon which wakes up every 5 seconds and prints hello in a pre-specified file.

### 14. Make a program which re-runs automatically when it is killed.
