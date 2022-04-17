# Basic Linux Commands (http://linux.die.net/Linux-CLI/)

- [`cat`](#cat)
- [`cd`](#cd)
- [`chmod`](#chmod)
- [`clear`](#clear)
- [`cp`](#cp)
- [`date`](#date)
- [`dd`](#dd)
- [`df`](#df)
- [`diff`](#diff)
- [`dmesg`](#dmesg)
- [`du`](#du)
- [`echo`](#echo)
- [`env`](#env)
- [`exit`](#exit)
- [`file`](#file)
- [`find`](#find)
- [`grep`](#grep)
- [`gunzip`](#gunzip)
- [`gzip`](#gzip)
- [`head`](#head)
- [`ifconfig`](#ifconfig)
- [`less`](#less)
- [`locate`](#locate)
- [`ln`](#ln)
- [`ls`](#ls)
- [`man`](#man)
- [`mkdir`](#mkdir)
- [`more`](#more)
- [`mount`](#mount)
- [`mv`](#mv)
- [`netstat`](#netstat)
- [`ps`](#ps)
- [`pwd`](#pwd)
- [`rm`](#rm)
- [`stat`](#stat)
- [`tail`](#tail)
- [`time`](#time)
- [`touch`](#touch)
- [`tty`](#tty)
- [`uname`](#uname)
- [`whereis`](#whereis)
- [`which`](#which)
- [`whoami`](#whoami)
- [`xxd`](#xxd)

---

## Linux command classification

### display information

- general: `man`
- process: `ps`, `who`, `finger`, `top`, `last`, `history`
- file:
  - location: `find`, `which`, `whereis`, `locate`
  - general: `ls`, `file`
  - content: `cat`, `more`, `od`, `xxd`, `cmp`, `diff`, `wc`, `head`, `tail`, `objdump`
  - search: `grep`
  - others: `echo`
- other: `tty`, `pwd`, `date`, `cal`, `df`, `du`, `uname`, `mount`, `hostname`, `whoami`, `env`

### manipulate information

- process: `kill`, `gcc`, `make`, `ctrl-c`, `ctrl-z`, `&`, `time`, `gdb`
- file:
  - editor: `vi`, `ed`, `sed`
  - file system: `fsck`
  - directory: `cd`, `mkdir`, `rmdir`
  - general: `ln`, `mv`, `cp`, `rm`, `gzip`, `gunzip`, `tar`, `touch`
  - permission: `chmod`, `umask`, `chown`
- terminal/login: `login`, `exit`, `su`, `passwd`, `stty`, `clear`
- communication: `write`, `mail`, `ftp`, `telnet`, `ifconfig`
- shell: `sh`, `csh`, `ksh`

## file tree

- `/` : root directory
- `bin` : executable files
  - `ls`, `zip`, `cat`, `chown`, `df`, `du`, `env`, `ftp`, `grep`, ...
- `etc` : system configuration files
  - `password` (password file), `hostname` (the name of this server), …
- `home` : user home directories
  - `linuxer2` (home for user linuxer2), `park`(home for user park), …
- `usr` : library files, header files
  - `lib` (library files are here), `include` (header files are here), …

## relative path, absolute path

If the path starts with `/`, it is an absolute path; otherwise it is a relative path.

```bash
   cd  /home/linuxer1/12345   -- go to /home/linuxer1/12345
   cd  12345                  -- go to directory 12345 in the current directory
                                 if the current location is /home/linuxer1,
                                     go to /home/linuxer1/12345
                                 if the current location is /bin
                                     go to /bin/12345
```

If the destination directory does not exist, the system issues an error.

## special symbols

- `.` : current directory
  - `cp f1 ./f2` -- copy f1 to f2 in the current directory
- `..` : parent directory
  - `cp f1 ../f2` -- copy f1 to f2 in the parent directory
- `>` : standard output redirection
  - `cat f1 > f3` -- display the content of f1 in f3 (same effect as “cp f1 f3”)
- `|` : pipe. redirect the standard output of the first program into the standard input of the second program
  - `cat f1 | more`
- `*` : match any file name
  - `ls b*` -- diplay all file/directory names that start with ‘b’

---

## `cat`

`cat` 명령어는 concatenate 또는 catenate에서 따온 이름으로, file의 contents를 보여준다.

- `cat f1` : show the contents of `f1`
- `cat f1 > f2` : redirect the standard output file of `cat` to `f2`.
  - As a result, the data in `f1` will be copied to `f2`.
- `cat > f3` : Read data from keyboard and send them to `f3`.
  - `^D` will end the input.

```bash
$ cat f1
hello
$ cat f1 >f2
$ cat f2
hello
$ cat > f3
hihihi
$ cat f3
hihihi
```

## `cd`

`cd` 명령어는 "Change Directory"의 줄임말로서, 현재 디렉토리의 위치를 변경한다.

- `cd /` : go to the `/` directory (the root directory)
- `cd /dev` : go to `/dev`
- `cd ..` : go to the parent directory
- `cd .` : go to the current directory (no moving)
- `cd` : go to the home directory (the directory you enter when logging)

## `chmod`

`chmod`는 change mode의 줄임말로, 리눅스 퍼미션 변경 명령어이다. 파일 또는 폴더의 사용권한을 지정할 수 있다.

<img width="479" alt="image" src="https://user-images.githubusercontent.com/73745836/158049191-a2de5d13-c625-4aac-8681-ef23807d29d4.png">

## `clear`

터미널 화면 비우기 명령어이다.

<img width="361" alt="image" src="https://user-images.githubusercontent.com/73745836/158049195-e47b0b25-b22c-4d9a-a343-814fec7d3199.png">

## `cp`

`cp` 명령어는 copy의 줄임말로서, 파일과 디렉토리를 복사하는 기능을 수행한다.

- `cp f1 f2` 명령어를 사용하면, `f1`의 복사본을 `f2`라는 이름으로 생성한다.
- 만약, `d1`이 이미 존재하는 디렉토리일 경우, `cp f1 d1` 명령어를 사용하면, `f1`의 복사본을 `d1` 폴더 안에 같은 이름으로 생성한다.<br>
  `cp f1 d1/f2` 명령어를 사용하면, `f1`의 복사본을 `d1` 폴더 안에 라는 이름으로 생성한다.<br>

```bash
$ mkdir d1
$
$ cp f1 f2
$ ls
d1 f1 f2
$
$ cp f1 d1
$ cd d1
$ ls
$ f1
$
$ cd ..
$ cp f1 d1/f2
$ cd d2
$ ls
f1 f2
```

## `date`

`date` 명령어는 현재 날짜와 시간을 표시하는 명령어이다.

<img width="363" alt="image" src="https://user-images.githubusercontent.com/73745836/158049222-3dcdbdc2-3bb9-46bf-83b8-0d4308595732.png">

## `dd`

`dd` 명령어는 Disk Dump의 약자로, 파일을 생성하거나, 디스크를 복사할 때 사용할 수 있다.
<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049223-cfbd8e5b-4543-4ded-abde-9c34e41dafb1.png">

## `df`

`df` 명령어는 파일시스템 사용량을 알려주는 명령어이다. `-h` 옵션(human-readable)을 사용하면 메가바이트(M) 기가바이트(G) 등 용량단위를 적절히 맞추어 읽기 쉬운 단위로 표현된다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049229-f7930cdd-8eef-46ca-a6d3-45e125f5125b.png">

## `diff`

`diff` 명령어는 differences의 약자로 두 파일 사이의 내용을 비교하는 명령어이다. ` diff [옵션][비교파일1][비교파일2]`으로 사용할 수 있으며, 옵션은 아래와 같다.

```
-c	두 파일간의 차이점 출력
-d	두 파일간의 차이점을 상세하게 출력
-r	두 디렉토리간의 차이점 출력, 서브디렉토리 까지 비교
-i	대소문자의 차이 무시
-w	모든 공백 차이무시
-s	두 파일이 같을 때 알림
-u	두 파일의 변경되는 부분과 변경되는 부분의 근처의 내용도 출력
```

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049236-d1b8aa5a-22fb-4446-a61f-3eee532954c6.png">

## `dmesg` 

`dmesg`는 display message의 줄임말로 리눅스 부팅 메시지, 리눅스 부팅 로그를 표시하는 명령어이다. `dmesg | less` 명령어를 사용하면, 메시지를 스크롤 할 수 있다.

<img width="435" alt="image" src="https://user-images.githubusercontent.com/73745836/158049239-66af7cb4-2626-49e0-b8b3-30a5e54c76d6.png">

## `du`

`du` disk usage의 줄임말로서, 리눅스 디렉토리 용량 확인 및 리눅스 폴더 용량 확인할 수 있는 명령어이다.

<img width="436" alt="image" src="https://user-images.githubusercontent.com/73745836/158049245-485d6f11-41d6-4344-8695-7728751d19d6.png">

## `echo`

`echo` 명령어는 argument로 전달되는 텍스트 / 문자열을 화면에 표시하는 데 사용된다.

- `echo korea > f1` : redirect the standard output file of “echo” to `f1`. As a result “korea” will be written to file `f1`.

```bash
$ echo korea
korea
$ echo korea > f1
$ cat f1
korea
```

## `env` 

`env` 명령어는 리눅스의 환경변수를 조회할 수 있는 명령어이다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049246-8c567cda-faca-453d-a76d-efe7797eaef0.png">

## `exit` 

`exit` 명령어는 현재 세션 종료 및 명령어 스크립트 종료를 수행하는 명령어이다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049249-5f0f1d8b-d166-4034-bb3e-04ef5bc72ae6.png">

## `file`

`file` 명령어는 파일형식 확인하고, 파일의 종류를 판단하는 리눅스 명령어이다. <br>
판단 시, 확장자를 보고 판단하는 것이 아니라 내용을 보고 판단한다.

```bash
$ file README.md
README.md: ASCII text
```

## `find`

`find` 명령어는 파일, 디렉토리의 검색을 수행하는 리눅스 명령어이다.

`find / -name "stdio.h" -print` : find the location of `stdio.h` starting from /

```bash
$ find
.
./version-groups.conf
./pluginconf.d
./pluginconf.d/security.conf
./pluginconf.d/fastestmirror.conf
./vars
./protected.d
```

```bash
$ find / -name "stdio.h" -print
/Library/Developer/CommandLineTools/usr/include/c++/v1/stdio.h
/Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/sys/stdio.h
/Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/stdio.h
/Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/sys/stdio.h
/Library/Developer/CommandLineTools/SDKs/MacOSX11.3.sdk/usr/include/c++/v1/stdio.h
```

## `grep`

grep –nr “ko” _ : find all files that contain string “ko”. –n means show the
line number that contains “ko”. –r means “do this recursively
searching down all sub-directories”. _ menas “all files” in
the current directory.

`grep` 명령어는 입력으로 전달된 파일에서 특정 문자열을 찾을 때 사용하는 명령어다. 쉽게 말해서 원하는 문자나 문자열을 찾을 때 사용한다.<br>
<br>

- 기본 문법

```bash
$ grep [-옵션] 패턴 파일명
```

- `-nr` 옵션을 사용하면 특정 단어가 포함된 모든 파일들을 확인할 수 있다.<br>

<img width="697" alt="스크린샷 2022-03-13 오후 5 12 29" src="https://user-images.githubusercontent.com/73745836/158051078-0cc33408-239e-428a-89f5-a2a1b1292f67.png">

- 출력 명령과 함께 사용할 때 문법

```bash
출력명령어 | grep 패턴
```

```bash
$ ll /etc/ssh/
total 96
-rw-r--r--  1 root  wheel   564K  1  1  2020 moduli
-rw-r--r--  1 root  wheel   1.5K  1  1  2020 ssh_config
-rw-r--r--  1 root  wheel   3.1K  1  1  2020 sshd_config
$ ll /etc/ssh/ | grep config
-rw-r--r--  1 root  wheel   1.5K  1  1  2020 ssh_config
-rw-r--r--  1 root  wheel   3.1K  1  1  2020 sshd_config
```

## `gunzip`

`gunzip` 명령어는 압축된 파일 압축해제에 쓰이는 명령어이다. `gunzip [압축해체할 파일명.gz]`으로 [압축해체할 파일명.gz]을 압축해제 할 수 있다. <br>
`gzip -d` 는 `gunzip`과 동일하며, `gzip` 에서 `-d` 옵션을 사용하는 것으로 압축해제를 하는 옵션이다. <br>
하지만, `gunzip` 으로 압축해제를 하면 `gzip`으로 압축하기 전의 원본파일의 소유주와 소유그룹, 파일액세스 시간, 파일변경시간, 퍼미션은 그대로 유지한채로 압축해제가 된다.<br>

참고로, `gzip [압축할 파일명]`으로 [압축할 파일]을 압축 할 수 있다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049303-c998eb06-5577-4362-ad56-2778120c4708.png">

## `gzip`

`gzip` 명령어는 `GNU zip`의 약자로, `gzip` 명령을 통해 압축이 성공하면 기존의 모든 원본 파일이 사라지고 확장자가 `.gz`인 새 파일이 만들어진다.

<img width="392" alt="image" src="https://user-images.githubusercontent.com/73745836/158049198-6b8d13dc-d632-40d6-ae14-b0260f484822.png">

## `head`

`head` 명령어는 파일의 첫 부분만 출력하는 명렁어이다. 아무 옵션 없이 사용하면, 처음 10개행을 확인할 수 있다. 아래의 명어를 통해 원하는 n개의 행을 확인할 수 있다.

```
head -행수 파일명
head -n행수 파일명
head 파일명 -n행수
cat 파일명 | head -행수
cat 파일명 | head -n행수
```

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049269-5d514d90-53db-4437-8920-dc962b25c0df.png">

## `ifconfig`

`ifconfig` 명령어는 interface configuration의 줄임말로서, 리눅스 네트워크의 IP 주소, 맥주소, 넷마스크, MTU 설정 등을 확인할 수 있는 명령어이다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049271-b4dc8dad-8ce5-4b2a-ae88-92eb0ab63276.png">

## `less`

[`more`](#more) 명령어와 비슷하다.

## `locate`

find the location of a file in the file database

## `ln`

`ln` 명령어는 링크 생성을 수행하는 리눅스 명령어이다. 기본 옵션은 하드 링크를 생성하는 것이며, `-s` 옵션을 사용하면 심볼릭 링크를 생성한다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049278-a1bea65a-1496-4b09-bc56-e3d0c5eed4ef.png">

## `ls`

`ls` 명령어는 "listing"의 줄임말로서, 현재 디렉토리에 있는 파일들과 디렉토리를 보여주는 명령어이다.

- `ls` : list all files
- `ls –l` : list all files in detail
- `ls –al` : list all files including hidden files
- `ls ex*` : list all files whose name start with “ex”

```bash
$ ls -l
-rwxr-xr-x 1 linuxer1 linuxer1 14 Feb 26 2013 f1
```

## `man`

`man` 명령어는 "mannual"의 줄임말로서, commands/system calls/c-lib functions 등의 사용법(매뉴얼)을 확인할 수 있다. <br>
다음 화면으로 이동하려면 '스페이스바'를 누르면 이동할 수 있고, ‘q’를 누르면 종료할 수 있다.

- `man ls` : shows the usage of `ls` command
- `man 1 kill` : shows the usage of `kill` command (manual section 1)
- `man 2 kill` : shows the usage of `kill` system call (manual section 2)
- `man kill` : same as `man 1 kill`
- `man 3 printf` : shows the usage of `printf` c library functions (manual section 3)
- `man printf` : same as `man 3 printf` (`printf` appears at section 3)

## `mkdir`

`mkdir`은 'make directory'의 줄임말로서, 디렉토리(폴더)를 생성할 수 있다.

```bash
$ mkdir d1
```

## `more`

`more`은 file의 contents를 화면에 화면 단위로 끊어서 출력하는 명령어이다. <br>
이 명령어는 위에서 아래 방향으로만 출력 되기 때문에, 지나간 내용을 다시 볼 수 없는 단점이 있다.<br>
다음 화면으로 이동하려면 '스페이스바'를 누르면 이동할 수 있고, ‘q’를 누르면 종료할 수 있다.

- `more f1`
- `ls –al | more` : send the output of `ls –al` as an input to `more`.
  - As a result we can see the output of `ls –al` one screen at a time.
- `ps –ef | more` : send the output of “ps –ef”to `more`
- `grep -nr "ko" \* | more` : display the result of `grep ...` screen by screen

## `mount`

`mount` 명령어는 파일시스템 마운트 명령어로서, 현재 시스템에 마운트된 정보 확인할 수 있다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049283-6ceeef8c-ff26-4fb8-b92f-a1c799c99d97.png">

## `mv`

`mv`는 move의 약자로서 파일이나 디렉토리를 다른 위치로 이동시키거나 파일명을 변경하고자 할때 사용한다.<br>
파일이름뿐만 아니라 디렉토리명도 변경할 수 있다.<br>
<br>

`mv 파일명1 파일명2`을 사용하면, 파일명1을 파일명2로 파일명을 변경한다. 이는 `cp` 명령어와 `rm` 명령어가 연속으로 사용된 것과 같다.

```bash
$ mv f2 f3 # change the name of file f2 to f3
```

## `netstat` 

`netstat` 명령어는 network statistics (네트워크 통계)의 줄임말로, 네트워크 접속, 라우팅 테이블, 네트워크 인터페이스의 통계 정보를 보여주는 도구이다.

<img width="348" alt="image" src="https://user-images.githubusercontent.com/73745836/158049286-f1f9f8fb-1144-4618-8322-27fcebeb49cd.png">

## `ps`

`ps`는 Process Status의 약자로 현재 돌아가고 있는 프로세스를 확인할 수 있는 명령어이다.

```bash
$ ps
  PID TTY           TIME CMD
43259 ttys000    0:02.57 -zsh
43304 ttys000    0:00.01 -zsh
43311 ttys000    0:01.86 /Users/oneonlee/.cache/gitstatus/gitstatusd-darwin-x86
60796 ttys000    0:00.00 grep --color=auto --exclude-dir=.bzr --exclude-dir=CVS
60812 ttys000    0:00.00 grep --color=auto --exclude-dir=.bzr --exclude-dir=CVS
```

- PID: process ID
- TTY: terminal id for this process
- TIME: time spent on this process
- CMD: executable file name for this process
  <br>

- `ps -ef` 명령어를 사용하면 커널 프로세스를 제외한 모든 프로세스를 풀 포맷으로 출력해준다.<br>

<img width="697" alt="스크린샷 2022-03-13 오후 5 15 18" src="https://user-images.githubusercontent.com/73745836/158051143-e67fd7f0-9982-45aa-98fd-2960443e16ac.png">

- `ps –ef | more` : pipeline the output of `ps –ef` to `more`
  - [`more`](#more) will show the result of “ps –ef” screen by screen

## `pwd`

`pwd`는 Present Working Directory의 줄임말로서, 현재 directory를 확인할 수 있다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158050105-33be5b98-1c5b-4f65-a9c7-f880d84b2f9c.png">

## `rm`

`rm` 명령어는 "remove"의 줄임말로서, 파일을 삭제하는 명령어이다.

- `rm f4` : remove file `f4`

## `stat`

`stat` 명령어는 파일 또는 파일시스템 상태를 조회할 수 있는 명령어로, 파일크기, Inode 번호, 링크 수, 퍼미션, UID, GID, 접근/수정/변경 일시 등을 확인 할 수 있다.

<img width="429" alt="image" src="https://user-images.githubusercontent.com/73745836/158049291-1809d805-a8bf-4481-892d-959920c53e34.png">

## `tail`

`tail` 명령어는 문서 파일이나 지정된 데이터의 마지막 몇 줄을 보여주는 리눅스 명령어이다.<br>

`tail 파일명`을 사용하면 파일의 끝부분 10개행을 보여준다.<br>
`tail 파일명 -n숫자`를 사용하면 숫자만큼 파일의 끝부분 행을 보여준다.<br>

<img width="423" alt="image" src="https://user-images.githubusercontent.com/73745836/158049295-1354ef5c-fa5b-4cb4-bfda-6e0e12eab4ac.png">

## `time`

`time` 명령어는 명령어 수행 시간 측정할 수 있는 리눅스 명령어이다.

<img width="416" alt="image" src="https://user-images.githubusercontent.com/73745836/158049297-6e97d0ef-778c-4aee-a55f-2a4b26629985.png">

## `touch` 

`touch` 명령어는 파일의 타임스탬프를 변경하는 리눅스 명령어이다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049299-e194ed58-c70c-4f1d-9ecb-4084a1c2668f.png">

## `tty`

`tty` 명령어는 TeleTYpewriter (텔레타이프라이터; 원격타자기)의 줄임말로서, 터미널 이름을 출력하는 리눅스이다.

<img width="243" alt="image" src="https://user-images.githubusercontent.com/73745836/158049300-3308a8fe-f720-43a3-b399-58bf1cc254d3.png">

## `uname`

'UNIX Name'의 줄임말로, 운영체제 (operating system)의 정보를 보여준다.

사용가능한 옵션 : `uname [-amnprsv]`

```bash
$ uname -s
Darwin
```

## `whereis` 

`whereis` 명령어는 명령어에 대한 바이너리, 소스, 매뉴얼 페이지의 위치를 알려주는 리눅스 명령어이다.

```bash
$ whereis head
/usr/bin/head
$ whereis whereis
/usr/bin/whereis
$ whereis kill
/bin/kill
```

## `which`

`which` 명령어는 실행파일의 정확한 위치를 찾는 리눅스 명령어이다. 'alias'가 있으면 먼저 보여준다.<br>
('alias'는 별칭이라는 뜻으로 리눅스에서 'alias'는 사용자가 명령어를 다른 이름으로 바꿔서 사용할 수 있는 쉘 내부 명령어를 말한다.)

```bash
$ which kill
kill: shell built-in command
$ which cat
/bin/cat
$ which ls
ls: aliased to ls -G
$ which which
which: shell built-in command
$ which whereis
/usr/bin/whereis
```

## `whoami`

`whoami` 명령어는 사용자명을 조회하는 리눅스 명령어이다.

```bash
$ whoami
oneonlee
```

## `xxd`

파일의 내용을 16진수(hexadecimal numbers)로 보여준다.

```bash
$ xxd f1
00000000: 6865 6c6c 6f0a                           hello.
```
