# Git
~~햣햣햣~~

## 목차
1. 버전관리의 첫 시작
2. 버전을 되돌리고, 나누어 관리하자.
3. 원격저장소(GitHub)를 이용하여 협업하기
* 참고

---

## 1. 버전관리의 첫 시작
* Git : 버전관리 시스템
* 버전 : 유의미한 변화가 결과물로 나온 것
* 버전관리가 필요한 이유
  1. 협업하기
  2. 되돌리기
  3. 효율적으로 백업하기

### 버전이 되기까지 거쳐가는 세 개의 공간
  1. Working directory (작업 공간)
  2. Staging Area
  3. Repository (저장소)

### 명령어 살펴보기
* 들어가기 전에 ...
  * 지금부터 각 섹션마다 나오는 터미널 명령어 맨 앞의 ```$``` 기호는 command line 임을 알려주는 표시이다. 
  * 터미널 명령어를 입력할 때는 ```$``` 기호는 무시하면 된다.
  * 모든 git의 명령어는 ```$ git``` 으로 시작한다.

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
  * 현재 Working directory에 있는 모든 변경사항들을 Staging Area로 전부 다 옮기고 싶다면
    * ``$ git add .``
    * 주의) ``add.``이 아니라 ``add .``이다.
  * 만약, Staging Area에 있는 파일을 다시 Working directory로 내리고 싶다면
    * ``$ git rm --cached name.file`` 

* Staging Area에서 Repository로 이동시키기
  * ```$ git commit -m "commit message"```
  * 만약 commit message를 길고 자세하게 작성하고 싶다면,
    * ``$ git commit``으로 commit message 작성 창으로 넘어간 후 자세히 작성할 수 있다.

* 커밋한 내역(log)을 확인하기
  * ``$ git log``
  * ``^Z (Ctrl+Z)``로 빠져나올 수 있다.

* Tip) add와 commit을 동시에 하기
  * ``$ git commit -am "commit message"``
  * 단, 한 번 이라도 commit을 한 대상에 대해서만 가능하다.

### GitHub에 내 코드 push하기
1. ```$ git remote add origin https://github.com/oneonlee/git_test.git```
   * 원격 저장소와 로컬 저장소를 연결해주는 명령어이다. (로컬 저장소에 원격 저장소를 등록)

2. ```$ git branch -M main```
   * main branch를 생성하는 명령어이다.

3. ```$ git push -u origin main```
   * 말그대로 push하는 명령어이다.

#### 기존에 있던 레포지토리에 내 코드를 push하고 싶을 때
```
error: origin 리모트가 이미 있습니다.
```
- 해결방법 
  - `$ git remote rm origin`을 통해 remote origin을 삭제해주고, ```$ git remote add origin https://github.com/oneonlee/git_test.git```를 입력한다.

  - 참고 : [깃허브 remote origin 삭제](https://azurealstn.tistory.com/47)


```
error: 레퍼런스를 'https://github.com/oneonlee/git_test.git'에 푸시하는데 실패했습니다
힌트: 현재 브랜치의 끝이 리모트 브랜치보다 뒤에 있으므로 업데이트가
힌트: 거부되었습니다. 푸시하기 전에 ('git pull ...' 등 명령으로) 리모트
힌트: 변경 사항을 포함하십시오.
힌트: 자세한 정보는 'git push --help'의 "Note about fast-forwards' 부분을
힌트: 참고하십시오.
``` 
- 해결방법
  - Git Repository에서 과거 Commit내역 삭제하기
    - 어차피 과거의 commit들을 다 날려버려도 상관 없다면, 내 repository에 들어가서 main 브랜치로 올렸던 과거 commit 내역을 삭제하는 것이 가장 맘편한 방법일 것이다.
  - `$git push origin main -— force`
    - `push` 뒤에 `—- force`를 붙여주면, 과거 commit 내역과 상관없이 지금 현재 commit 내용으로 덮어씌워 버리는 명령어이다.
    - `--force` 옵션을 실행하게 되면 기존 repository의 commit 모두 삭제되고, 현재 내가 작업한 commit 내역들만 남기 때문에 유의해야 한다.
    - 기존의 commit 내역들을 포함하여 push 할 수 있는 방법은 잘 모르겠다.
    
  - 참고 : [[Git 문제] 현재 브랜치의 끝이 리모트 브랜치보다 뒤에 있으므로 업데이트가 거부되었습니다 ???!!!](https://medium.com/@yms0214/git-%EB%AC%B8%EC%A0%9C-%ED%98%84%EC%9E%AC-%EB%B8%8C%EB%9E%9C%EC%B9%98%EC%9D%98-%EB%81%9D%EC%9D%B4-%EB%A6%AC%EB%AA%A8%ED%8A%B8-%EB%B8%8C%EB%9E%9C%EC%B9%98%EB%B3%B4%EB%8B%A4-%EB%92%A4%EC%97%90-%EC%9E%88%EC%9C%BC%EB%AF%80%EB%A1%9C-%EC%97%85%EB%8D%B0%EC%9D%B4%ED%8A%B8%EA%B0%80-%EA%B1%B0%EB%B6%80%EB%90%98%EC%97%88%EC%8A%B5%EB%8B%88%EB%8B%A4-1b4cdf80c2f)

---

## 2. 버전을 되돌리고, 나누어 관리하자.

### git으로 되돌리자
- Working directory, Staging area, Repository에 올린 내용은 어떻게 취소할 수 있을까?

#### 1) 되돌리는 명령어 `$ git reset`
- `$ git reset --hard HEAD^` : 수정한 것까지 통째로 "쎄게 되돌리자"
  - <img width="443" alt="$ git reset --hard HEAD^" src="https://user-images.githubusercontent.com/73745836/122880394-ec5b3700-d374-11eb-935f-ccfd7f4bfbbd.png">
- `$ git reset --mixed HEAD^` == `$ git reset` (옵션 생략할 경우) : add한 것 까지 "적당히 되돌리자"
  - <img width="431" alt="$ git reset --mixed HEAD^" src="https://user-images.githubusercontent.com/73745836/122880256-c9c91e00-d374-11eb-8997-461e7ef32a29.png">
- `$ git reset --soft HEAD^` : commit한 것만 "살짝만 되돌리자"
  - <img width="422" alt="스크린샷 2021-06-22 오후 4 15 19" src="https://user-images.githubusercontent.com/73745836/122880527-0c8af600-d375-11eb-85e2-13f7774ee385.png">

- `HEAD`의 의미 : 가장 최근 버전에서 (현재 작업 중인 브랜치/커밋 중 가장 최근 커밋을 가리킨다.)
- `^`의 의미 : 하나 되돌리자
  - `^^` : 두 개 전으로  

- `$ git reset` 명령어는 한 번 이상의 commit 내역이 있어야 작동한다.

#### 2) `$ git revert`
- `$ git revert`도 `reset`과 동일하게 commit을 되돌리는 명령어이다.
- `$ git revert <되돌아가고 싶은 commit>` 으로 작성할 수 있다.
- [아래 예제](https://github.com/oneonlee/CS101/blob/main/0.%20Git/README.md#1-%EB%91%90-%EC%BB%A4%EB%B0%8B-%EA%B0%84%EC%9D%98-%EB%B9%84%EA%B5%90)에서 3번 commit으로 `revert`하고 싶다면
  - `$ git revert de6d5c1148981e15617999c7ecaa6ec2ea21ff29`

- `reset`과의 차이점
  - `$ git reset`과 `$ git revert`는 commit을 과거 시점으로 되돌려준다는 점에서 결과적으로 같은 결과를 내지만, 차이점은 **되돌리는 commit까지의 이력이 사라지느냐**의 여부에 있다.
  - `$ git reset`은 되돌린 버전 이후의 버전들이 모두 사라지게 되지만, `$ git revert`는 되돌린 버전 이후의 버전들은 모두 유지되고, revert되었다는 사실을 담은 commit만 새로 추가된다.

  - [아래 예제](https://github.com/oneonlee/CS101/blob/main/0.%20Git/README.md#1-%EB%91%90-%EC%BB%A4%EB%B0%8B-%EA%B0%84%EC%9D%98-%EB%B9%84%EA%B5%90)에서 3번 commit으로 reset을 하면 4, 5번 commit은 삭제되지만, 3번 commit으로 revert를 하면 4,5번 commit은 그대로 유지됩니다.

  - 즉, `reset`은 과거 자체를 바꾸는 명령어이고, `revert`는 과거를 변경시켰다는 새로운 commit으로써 새로운 commit을 만드는 명령어다.

  - 실용적인 면으로 따져 보았을 때, `revert`는 `reset`보다 더 안전하게 commit을 되돌리는 방법이고,
  - `reset`은 `revert`보다 commit log를 깔끔하게 유지해주며 commit을 되돌리는 방법이라고 할 수 있다.

> 이 글에서는 일반적인 관점에서 reset과 비교했을 때의 이야기이긴 하지만, -n 옵션을 이용하면 revert를 써도 commit을 남기지 않을 수는 있다.

### 나누어 관리하자
- Branch로 알아보는 git의 협업 원리
  1. 작업 단위로 나눈다. (작업 단위 : Branch)
  2. 각자 작업한다.
  3. 합친다.

- 현재 branch 목록 확인하기
  - `$ git branch`
 
- 새 branch 만들기
  - `$ git branch <브랜치 이름>`

- 다른 branch로 들어가기
  - `$ git checkout <브랜치 이름>`

- 새 branch를 만들고 동시에 그 branch로 들어가기
  - `$ git checkout -b <브랜치 이름>`

- 어떤 branch를 어디로 합칠 것인가? (만약에 'my_branch'라는 branch를 'main'에 합치려고 한다면,)
 - 병합의 결과가 되는 대상에 `checkout`
    - `$ git checkout main`
 - 합치는 명령어
   - `$ git merge <합치려는 branch>`
   - `$ git merge my_branch`

### 변경내역들을 비교하고 싶을 때
`$ git diff`는 변경내역들끼리의 비교 결과를 보여준다.

버전을 관리하는 도중에 다음과 같은 상황이 있을 수 있을 것이다.

> 10번 commit 중 1번 commit과 2번 commit을 비교하고 싶어!
 
> 지금 push한 commit과 이전 commit을 비교하고 싶어!
 
> 현재 staging area에 있는 변경 내역과 직전의 commit을 비교하고 싶어!

> branch1 브랜치에 있는 commit과 master(=main) 브랜치에 있는 commit을 비교하고 싶어!

이럴 때 사용할 수 있는게 `$ git diff`이다. 말그대로 패치간의 차이점을 알 수 있게 해주는 것이다.

#### 1) 두 커밋 간의 비교
- 예를 들어 현재 저장소에 test.txt 달랑 하나 있고, 1번부터 5번 commit이 있으며, 각각의 commit은 다음과 같이 작성되어 있다고 가정해보자.

```
1번 commit : test.txt에 A 라는 문자열 하나 저장
2번 commit : test.txt에 B문자 추가
3번 commit : test.txt에 C문자 추가
4번 commit : test.txt에 D문자 추가
5번 commit : test.txt에 E문자 추가
```

- `$ git log`를 통해 commit 내역들을 확인한다.

```
$ git log
commit f7fe32715c4bd705110196134271d8f873384316 (HEAD -> master)
Author: Lee Dong-geon <peter8739@gmail.com>
Date:   Tue Dec 1 23:06:03 2020 +0900

    5

commit 2845ce53054627b3381c9f2515dc7545cff2347b
Author: Lee Dong-geon <peter8739@gmail.com>
Date:   Tue Dec 1 23:05:49 2020 +0900

    4

commit de6d5c1148981e15617999c7ecaa6ec2ea21ff29
Author: Lee Dong-geon <peter8739@gmail.com>
Date:   Tue Dec 1 23:05:38 2020 +0900

    3

commit 1d7fce052aafb388ddf092ea315835f5154683f7
Author: Lee Dong-geon <peter8739@gmail.com>
Date:   Tue Dec 1 23:04:52 2020 +0900

    2

commit 6958b6b21e15aa0be36736016c5bc955b57a61be
Author: Lee Dong-geon <peter8739@gmail.com>
Date:   Tue Dec 1 23:04:38 2020 +0900

    1

```

commit 옆에 마구잡이로 생긴 문자열 (f7fe32715c4bd705110196134271d8f873384316 등등…) 은 각각의 commit을 나타내는 commit hash이다.
이 commit을 가리키는 말이라고 생각하면 된다.

- 5번 commit이 4번 commit을 기준으로 무엇이 바뀌었는지 알고 싶을 때,
  - `$ git diff 비교대상commit 기준commit`
  - 쉽게 말해, `$ git diff <이 commit에 비해> <이 commit은 무엇이 달라졌니?>`
  - 여기서는, `$ $ git diff f7fe32715c4bd705110196134271d8f873384316 2845ce53054627b3381c9f2515dc7545cff2347b`

```
$ git diff 2845ce53054627b3381c9f2515dc7545cff2347b f7fe32715c4bd705110196134271d8f873384316
diff --git a/test.txt b/test.txt
index 8422d40..8fda00d 100644
--- a/test.txt
+++ b/test.txt
@@ -2,3 +2,4 @@ A
 B
 C
 D
+E          # 4번 Commit에 비해 E라는 문자열이 추가되었다(+ 표시)
```

#### 2) 이전 commit과 전전 commit의 비교
매번 이렇게 commit hash를 쓰는게 귀찮으므로, `HEAD`를 이용해 아래와 같이 사용해도 된다.<br/>
HEAD는 현재 branch의 가장 최근 commit, `HEAD^`는 현재 branch의 가장 최근 commit에서 하나 이전 commit을 가리키므로,<br/>
`$ git diff HEAD HEAD^`는 <br/>
이전 commit (5번)과 전전 commit (4번)을 비교하라는 명령이다.<br/>

```
$ git diff HEAD^ HEAD
diff --git a/test.txt b/test.txt
index 8422d40..8fda00d 100644
--- a/test.txt
+++ b/test.txt
@@ -2,3 +2,4 @@ A
 B
 C
 D
+E
```

#### 3) 이전 commit과 현재 수정된 내용 비교
아직 commit하지 않은, 수정된 내용과 이전 commit (이 예제에서는 5번 commit)과 비교하기 위해 `$ git diff HEAD`를 사용할 수 있다.<br/>
예를 들어 test.txt에 F라는 문자를 추가하고, `$ git diff HEAD`를 친다면 아래와 같은 결과를 확인할 수 있다.

```
$ git diff HEAD
diff --git a/test.txt b/test.txt
index 8fda00d..cead32e 100644
--- a/test.txt
+++ b/test.txt
@@ -3,3 +3,4 @@ B
 C
 D
 E
+F
```

즉, 아직 commit하지 않은 현재 작업 중인 내용을 가장 최근 commit한 내용과 비교한 결과라고 볼 수 있다.

#### 4) 원격 저장소와 로컬 저장소 간의 비교
- `$ git diff <비교대상 branch이름> origin/<branch 이름>`

#### 5) branch 간의 비교
- `$ git diff <비교대상 branch 이름> <기준 branch 이름>`

---

## 3. 원격저장소(GitHub)를 이용하여 협업하기
### 로컬과 원격의 상호작용
Branch 개념을 원격저장소 (GitHub)에 접목시켜 실질적인 협업을 이루기

#### 1) `$ git remote` : 원격저장소에 조회(추가) 하기
- 내 로컬 repository와 상호작용하고 있는 (혹은 할 수 있는) 원격 저장소들의 목록을 조회

- `$ git remote -v`
  - 단축이름과 URL 같이 보기 
- `$ git remote add <단축이름> <url>`
  - 기존 워킹 디렉토리에 새 원격저장소를 추가하는 명령어
- `$ git remote add origin <url>`
  - <url>에 있는 원격저장소를 `origin`이라는 이름으로 추가하기
- `$ git remote rm <단축이름>`
  - 등록한 원격저장소를 지우는 명령어 (remove의 약자)
  
#### 2) `$ git push` : 원격저장소에 밀어넣기
- `$ git push -u origin main`
  - 내 repository의 main 브랜치를 origin의 main 브랜치로 push 
  - `-u` : 디폴트 설정 (main 브랜치를 기본값으로 설정해줌)
    - 그 이후엔 `$ git push`만 써도 push가 된다.

#### 3) `$ git pull` : 원격저장소 갖고 와서 합치기
- `$ git pull origin main`
  - origin을 내 repository의 main 브랜치로 갖고와라 (merge)
  
#### 4) `$ git fetch` : 원격저장소 일단 갖고만 오기
- `$ git fetch origin`
  - 동기화시키지는 말고 (merge하지는 말고), `origin`을 내 repository의 main 브랜치로 일단 갖고와라
  - 다시 한 번 말하자면, `origin`은 명령어가 아니라 임의의 이름이다.
  - (당연하게도) 로컬 저장소의 파일이 실제로 변하지는 않는다.
  - 물론 fetch한 내용을 담은 branch를 로컬의 main branch로 merge 할 수는 있다.
  
- fetch한 파일을 확인하는 방법
  - 특정 branch에 들어가서 확인
    - `rb92303..73b393f  master     ->  origin/main`이라고 뜨면 `origin/main`에서 확인 가능
    - 그 특정 branch는 `$ git branch`로는 확인할 수 없다.
  - `$ git checkout origin/main`의 명령어를 입력 후, 로컬 저장소를 보면 바뀐 파일을 확인할 수 있다.
    - `$ git checkout FETCH_HEAD`도 가능
  - `$ git checkout main`으로 다시 원래 있던 main으로 돌아올 수 있다.
  
#### 5) `$ git clone` : 원격저장소 복사하기
- `$ git clone <url>`
  - <url>에 있는 원격 저장소 내용을 현재 디렉토리에 복사해오기
  - remote를 추가해주지 않아도 `origin`이라는 이름으로 프로젝트를 자동 생성
  
### 협업의 세가지 시나리오
#### 1) 내 로컬 저장소는 **변했는데** 원격 저장소는 **변함 없는** 경우
- 그냥 push하면 그만
  
#### 2) 내 로컬 저장소는 **변함** 없는데 원격 저장소는 **변한** 경우
- `$ git pull origin main`으로 동기화를 시킨 다음에 코드를 작성한 후, push하기
  
#### 3) 내 로컬 저장소는 **변했는데** 원격 저장소는 **변한** 경우
가장 골치 아픈 상황인 동시에 가장 일반적인 경우
  
##### Solution 1. rebase
: 현재 내가 작업하고 있는 branch의 base를 옮긴다.
* base : 현재 내가 작업하고 있는 branch와 합치려는 branch의 공통 조상
  
##### Solution 2. pull request
1. 협업 대상 repository를 fork 한다.
2. fork한 나의 repository를 clone 한다.
3. 로컬에서 새 branch를 만들어준다.
4. 이 branch에서 쓰고 싶은 코드를 맘껏 작성한다.
5. 이 branch에서 commit을 한다.
6. 코드작업을 수행한 fork 해온 repository의 그 branch에 push
  - `$ git push origin newbranch`
7. 원격저장소에 pull request를 보낸다.
  - 로컬 관점에선 push지만, 원격저장소 관점에서는 pull이기 때문에 이름이 **pull** request이다.
  - GitHub에서 `Compare & pull request` 버튼을 누름으로서 가능
8. 원격 저장소의 관리자가 승인을 해주면, merge 됨으로서 코드가 반영된다.
9. 승인된 후에는 branch를 GitHub 웹페이지에서 직접 지우거나, `$ git branch -d newbranch`의 명령어로 지워주는 것이 좋다.
  - branch가 많아봤자 좋을 것이 없기 때문. 
  
---

## 참고 

* [git 공식 문서](https://git-scm.com/doc)
* [인프런 강의 : 빠르게 git - 핵심만 골라 배우는 Git/Github](https://www.inflearn.com/course/%EB%B9%A0%EB%A5%B4%EA%B2%8C-git)
* [amamov gits](https://github.com/amamov/gits)
* [유용한 터미널 명령어 모음 - Mac Training : Let's focus on Software](https://mactraining.tistory.com/148)
* [learn git branching](https://learngitbranching.js.org/?locale=ko) - branch의 변화를 시각적으로 확인할 수 있는 사이트 1
* [visualizing git](http://git-school.github.io/visualizing-git/) - branch의 변화를 시각적으로 확인할 수 있는 사이트 2
