# OS lecture 1: what do we study?

Reference book: “Understanding Linux Kernel” by Bovet & Cesati

## 1. Studying OS

- Studying the usage of OS
  - Studying the usage of utility programs (OS commands) : `ls`, `cat`, `cp`, ....
  - Studying the usage of system calls : `read`, `write`, `fork`, .....
- Studying the implementation of OS
  - Reading/Understanding/Modifying OS kernel code
    - Understanding the 5 concepts of OS: interrupt, process, file, memory, I/O
    - Confirming their implementation in OS kernel
  - Implementing my own OS

## 2. Linux commands

Following is a simple classification for some of the Linux commands. Read them and do the following lab problems. To access the lab server, you need to download putty.exe from the internet. For korean language support, get 한글 putty and set window>translation to UTF-8. Among the commands, use “man” to find out the meaning/usage of commands or system calls. For example,

```bash
      man  man    -- shows the usage of “man” command
      man  ls      -- shows the usage of “ls” command
      man  read   -- shows the usage of “read” system call
      man  kill     -- shows the usage of "kill" command
      man  2  kill   -- shows the usage of "kill" system call
      man  3  printf  -- shows the usage of "printf" c-library function
```

```bash
general: man
process:
         ps : listing processes
         gcc : c compiler
         kill  : stop a process
         ^c   : stop a process
file     :
         vi    : editor
         ls    : listing files and directories in the current directory
         cat   : show the contents of a file
         more : show the contents of a file screen by screen
         xxd    : show the contents of a file in binary
         cp, rm, mv : copy, remove, change the name
         echo  : echo
         grep  : search given string in a given file
         cd    : change directory
         rmdir, mkdir : remove a directory, create a directory
```

## 3. `vi` :editor

`vi x.c` : edit file `x.c`

- 1. mode: `vi` has three modes.
  - command mode: cursor moving, deleting, copying
  - input mode : insertion
  - status-line mode: other tasks
- 2. In the beginning we are at command mode.
  - command mode:
    - cusor moving: `j`(down), `k`(up), `h`(left), `l`(right)
    - deletion: `x`(delete one character), `dd`(delete a line)
    - copy and paste: - `3yy` : copy "3" lines starting from the current line - `p` : paste them after the current line
      recover - `u` : recover what you have just deleted
  - command mode -> insertion mode : `i`, `a`, `o`
    - `i`: start insertion from the current cursor
    - `a`: start insertion after the end of the current line
    - `o`: insert a new line
  - insertion mode: now you can type
  - insertion mode -> command mode: ESC key
  - command mode -> status-line mode: `/` or `:`
  - status-line mode:
    - `:q!` : quit without saving
    - `:w` : write
    - `:wq` : save and exit
    - `/pat` : search the pattern in "pat"
    - `:set number` : display line numbers

## 4. gcc : compiler

```bash
gcc -o myx x.c
```

will compile `x.`c and produce the executable file "myx". You can run "myx" by typing "myx" and hit the enter key. `x.c` will look like as follows.

```c
#include <stdio.h>
int main(){
    printf("hello\n");
    return 0;
}
```
