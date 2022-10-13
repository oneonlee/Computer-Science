des-Code에는 여러 개의 `.cpp` 파일과 `.h` 파일이 있다.

`g++`을 사용해 컴파일 할 경우, 아래 명령어로 컴파일을 하고, 결과파일을 실행할 수 있다.

```bash
$ g++ table.cpp util.cpp enc.cpp f-func.cpp keysched.cpp main.cpp -o DES
$ ./DES
```
