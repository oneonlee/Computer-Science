# Git

빠르게 git - 핵심만 골라 배우는 Git/GitHub



## 목차

1. 버전관리의 첫 시작

* 참고



## 1. 버전관리의 첫 시작

* Git : 버전관리 시스템
* 버전 : 유의미한 변화가 결과물로 나온 것
* 버전관리가 필요한 이유
  1. 협업하기
  2. 되돌리기
  3. 효율적으로 백업하기



* 버전이 되기까지 거쳐가는 세 개의 공간
  1. Working directory (작업 공간)
  2. Staging Area
  3. Repository (저장소)



* 명령어 살펴보기
  * 들어가기 전에 ...
    * 지금부터 각 섹션마다 나오는 터미널 명령어 맨 앞의 ```$``` 기호는 command line 임을 알려주는 표시이다. 
    * 해당 터미널 명령어를 입력할 때는 ```$``` 기호는 무시하면 된다.
    * 모든 git의 명령어는 ```$ git``` 으로 시작한다.
    * 모든 git의 명령어는 ```git```으로 시작한다.
  * git 초기화하기 (버전관리 시작) 
    * ```$ git init```
      * 명령어를 실행하면 ```.git``` 이라는 숨김 폴더가 생긴다.
  * (숨김 파일 / 폴더까지 포함한) 모든 파일 / 폴더 목록 보기
    * ```$ ls -al```
  * 버전관리가 되고 있는 폴더의 상태를 알려주는 명령어
    * ```$ git status ```
  * Working directory에서 Staging Area로 이동시키기
    * 특정 파일 (ex> ```name.file```)을 이동시키고 싶다면
      * ```$ git add name.file```
    * 현재 Working directory에 있는 모든 변경사항들을 전부 다 옮기고 싶다면
      * ``$ git add .``
  * Staging Area에서 Repository로 이동시키기
    * ```$ git commit -m "commit message"```
    * 만약 commit message를 길고 자세하게 작성하고 싶다면,
      * ``$ git commit``으로 commit message 작성 창으로 넘어간 후 자세히 작성할 수 있다.
  * 커밋한 내역(log)을 확인하기
    * ``$ git log``
  * Tip) add와 commit을 동시에 하기
    * ``$ git commit -am "commit message"``
    * 단, 한 번 이라도 commit을 한 대상에 대해서만 가능하다.



* GitHub에 내 코드 push하기

  1. ```$ git remote add origin https://github.com/oneonlee/git_test.git```
     * 원격 저장소와 로컬 저장소를 연결해주는 명령어이다. (로컬 저장소에 원격 저장소를 등록)
  2. ```$ git branch -M main```
     * main branch를 생성하는 명령어이다.

  3. ```$ git push -u origin main```
     * 말그대로 push하는 명령어이다.



## 참고

* [인프런 강의 : 빠르게 git - 핵심만 골라 배우는 Git/Github](https://www.inflearn.com/course/%EB%B9%A0%EB%A5%B4%EA%B2%8C-git)
* [amamov GitHub / Computer-Science / GIT](https://github.com/amamov/Computer-Science/tree/main/7%20GIT#-git-)
* [Mac Training : Let's focus on Software](https://mactraining.tistory.com/148)

