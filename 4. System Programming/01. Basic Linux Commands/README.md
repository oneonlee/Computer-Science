# Basic Linux Commands

- [`chmod`](#chmod)
- [`clear`](#clear)
- [`cp`](#cp)
- [`date`](#date)
- [`dd`](#dd)
- [`df`](#df)
- [`diff`](#diff)
- [`dmesg`](#dmesg)
- [`du`](#du)
- [`env`](#env)
- [`exit`](#exit)
- [`file`](#file)
- [`find`](#find)
- [`gunzip`](#gunzip)
- [`gzip`](#gzip)
- [`head`](#head)
- [`ifconfig`](#ifconfig)
- [`ln`](#ln)
- [`mount`](#mount)
- [`mkdir`](#mkdir)
- [`netstat`](#netstat)
- [`pwd`](#pwd)
- [`stat`](#stat)
- [`tail`](#tail)
- [`time`](#time)
- [`touch`](#touch)
- [`tty`](#tty)
- [`whereis`](#whereis)
- [`which`](#which)
- [`whoami`](#whoami)

## `chmod`

`chmod`는 change mode의 줄임말로, 리눅스 퍼미션 변경 명령어이다. 파일 또는 폴더의 사용권한을 지정할 수 있다.

<img width="479" alt="image" src="https://user-images.githubusercontent.com/73745836/158049191-a2de5d13-c625-4aac-8681-ef23807d29d4.png">

## `clear`

터미널 화면 비우기 명령어이다.

<img width="361" alt="image" src="https://user-images.githubusercontent.com/73745836/158049195-e47b0b25-b22c-4d9a-a343-814fec7d3199.png">

## `cp`

`cp` 명령어는 copy의 줄임말로서, 파일과 디렉토리를 복사하는 기능을 수행한다.<br>

`$ cp f1 f1` 명령어를 사용하면, f1의 복사본을 f2라는 이름으로 생성한다.<br>
만약, d1이 이미 존재하는 디렉토리일 경우, `$ cp f1 d1` 명령어를 사용하면, f1의 복사본을 d1 폴더 안에 같은 이름으로 생성한다.<br>
`$ cp f1 d1/f2` 명령어를 사용하면, f1의 복사본을 d1 폴더 안에 f2라는 이름으로 생성한다.<br>

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158050320-1dbe7296-167c-4fd3-9d27-168b1a25afd9.png">

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

## `env` 

`env` 명령어는 리눅스의 환경변수를 조회할 수 있는 명령어이다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049246-8c567cda-faca-453d-a76d-efe7797eaef0.png">

## `exit` 

`exit` 명령어는 현재 세션 종료 및 명령어 스크립트 종료를 수행하는 명령어이다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049249-5f0f1d8b-d166-4034-bb3e-04ef5bc72ae6.png">

## `file`

`file` 명령어는 파일형식 확인하고, 파일의 종류를 판단하는 리눅스 명령어이다. 판단 시, 확장자를 보고 판단하는 것이 아니라 내용을 보고 판단한다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049253-548f32d2-1211-4510-9c99-befeddff7790.png">

## `find`

`find` 명령어는 파일, 디렉토리의 검색을 수행하는 리눅스 명령어이다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049256-95cb968a-85ba-4a54-b641-7eba733cb378.png">

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

## `ln`

`ln` 명령어는 링크 생성을 수행하는 리눅스 명령어이다. 기본 옵션은 하드 링크를 생성하는 것이며, `-s` 옵션을 사용하면 심볼릭 링크를 생성한다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049278-a1bea65a-1496-4b09-bc56-e3d0c5eed4ef.png">

## `mkdir`

`mkdir`은 make directory의 줄임말로서, 디렉토리(폴더)를 생성할 수 있다.

## `mount`

`mount` 명령어는 파일시스템 마운트 명령어로서, 현재 시스템에 마운트된 정보 확인할 수 있다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049283-6ceeef8c-ff26-4fb8-b92f-a1c799c99d97.png">

## `netstat` 

`netstat` 명령어는 network statistics (네트워크 통계)의 줄임말로, 네트워크 접속, 라우팅 테이블, 네트워크 인터페이스의 통계 정보를 보여주는 도구이다.

<img width="348" alt="image" src="https://user-images.githubusercontent.com/73745836/158049286-f1f9f8fb-1144-4618-8322-27fcebeb49cd.png">

## `pwd`

`pwd` 명령어를 통해 login directory를 확인할 수 있다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158050105-33be5b98-1c5b-4f65-a9c7-f880d84b2f9c.png">

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

## `whereis` 

`whereis` 명령어는 명령어에 대한 바이너리, 소스, 매뉴얼 페이지의 위치를 알려주는 리눅스 명령어이다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049307-65b510a4-b844-4a20-adc6-b9ba73c8d2f7.png">

## `which`

`which` 명령어는 실행파일의 위치를 찾는 리눅스 명령어이다. alias가 있으면 먼저 보여준다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049311-4810bb64-a3e9-4619-9b7f-45db2535d64b.png">

## `whoami`

`whoami` 명령어는 사용자명을 조회하는 리눅스 명령어이다.

<img width="452" alt="image" src="https://user-images.githubusercontent.com/73745836/158049316-057cdc08-16d0-4800-bc5c-32b5bf76d2c6.png">
