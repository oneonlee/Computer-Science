# 리눅스 원격 파일 전송 (업로드/다운로드)

원격접속을 하지 않은 로컬 PC 상태에서 아래 코드실행

## Remote(원격지) → Local(로컬)
```bash 
$ scp [옵션] [원격지 유저명]@[원격지 IP]:[원본 경로] [로컬 PC에 복사할 경로]
```

### 예시
```bash
$ scp -pr root@192.168.123.456:../../linuxer1/swvader03.wav  /Users/oneonlee/Desktop/
```
<!-- ```
scp -p -r 12181879@165.246.38.151:../../linuxer1/swvader03.wav /Users/oneonlee/Desktop/system_programming/lect7
``` -->

## Local(로컬) → Remote(원격지)
```bash
$ scp [옵션] [원본 경로] [원격지 유저명]@[원격지 IP]:[파일이 저장될 경로]
```

### 예시

```bash
$ scp -p /Users/oneonlee/Desktop/test.zip root@192.168.123.456:../../linuxer1/
```

## 옵션
- `-p` : 원본 파일의 변경 시간, 접근 시간, 퍼미션을 보존
- `-r` : 하위의 디렉터리 및 파일까지 복사
- `-v` : 상세 정보 출력
- `-F ssh_config` : 설정파일 지정
- `-P port` : 포트 지정
    - ssh 프로토콜 포트가 22번이 아닌 경우 사용



- 참고
    - [리눅스 scp - IT위키](https://itwiki.kr/w/%EB%A6%AC%EB%88%85%EC%8A%A4_scp)
    - [[리눅스] scp 명령어 사용법, 이 글 하나면 충분해 - ELOQUENCE 티스토리 블로그](https://lifegoesonme.tistory.com/459)
