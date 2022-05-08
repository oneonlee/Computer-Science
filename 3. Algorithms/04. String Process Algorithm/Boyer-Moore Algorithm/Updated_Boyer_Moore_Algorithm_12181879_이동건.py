# 개선된 보이어-무어 알고리즘
# 작성자 : 12181879 이동건

print("Updated Boyer Moore Algorithm")
print("Written by 12181879 Lee Dong-geon")
print("===================================================\n")


def initSkip(p):
    num = 94    # 알파벳, 특수문자, 숫자의 종류의 개수
                # ASCII 코드에서 33번부터 126번까지의 개수와 같음 (126-33+1 = 94)

    M = len(p)  # pattern의 길이
    skip = [M for _ in range(num)]  # skip 배열을 모두 M값으로 해줌
    for i in range(M):
        # ord 함수는 하나의 문자를 인자로 받고, 그 문자에 해당하는 유니코드 정수를 반환함
        skip[ord(p[i]) - ord('!')] = M - i - 1
    return skip


def MisChar(p, t):
    M = len(p)  # M은 pattern의 길이
    N = len(t)  # N은 text의 길이
    skip = initSkip(p)  # initSkip 함수를 통해 skip 배열을 생성

    i = M - 1  # text의 index로 사용
    j = M - 1  # pattern의 index로 사용

    while j >= 0: # 뒤에서부터 검사하고 인덱스가 줄어들기 때문에 0 이상인 경우만 작동
        while t[i] != p[j]: # 마지막 글자부터 비교하면서 일치한다면 하나씩 감소하면서 계속 비교
            k = skip[ord(t[i]) - ord('!')]
            if M - j > k:
                i = i + M - j
            else:
                i = i + k
            if i >= N:      # 패턴이 일치하는 것이 없을 경우
                return N    # 텍스트의 마지막 인덱스를 반환
            j = M - 1       # 뒤에서부터 접근하므로 pattern의 길이에 -1을 해줌
        i = i - 1 # i와 j 모두 하나씩 감소
        j = j - 1
    return i + 1


FILE_PATH = "RFC2616_modified.txt"  # 주어진 파일의 상대경로
                                    # .py파일과 같은 폴더 안에 넣어줌
with open(FILE_PATH) as f:
    lines = f.read().splitlines()  # 주어진 "RFC2616_modified.txt" 파일을 행 단위로 lines 리스트에 저장

patterns_list = ["similar", "UA -----v", "HTTP/1.1,", "letter \"A\"..\"Z\"", "[50]"]  # 주어진 pattern들을 담은 리스트

for pattern in patterns_list:  # pattern이 담긴 patterns_list를 for문으로 순회
    print(f"=========== Finding \"{pattern}\" ===========")
    M = len(pattern)

    line_num = 0  # 줄 번호를 세기 위한 변수, line은 1번부터 시작한다고 가정
    found_cnt = 0  # 찾은 pattern의 총 개수를 세기 위한 변수

    for text in lines:  # lines 리스트에 있는 줄 단위 데이터(text)를 한 줄 씩 분석
        N = len(text)
        line_num += 1  # line은 1번 줄부터 시작한다고 가정

        if N == 0:  # text의 길이가 0이면, 즉 text가 비어있으면 검사를 skip
            continue
        elif N < M:  # text가 pattern보다 짧으면 검사를 skip
            continue

        tmp_text = text  # pattern을 찾은 다음 곳부터 text의 끝까지 슬라이싱한 문자열을 담는 변수
        found_idx = 0  # temp_text에서 pattern을 찾은 위치(index)를 담는 변수
        found_idx_list = []  # 하나의 text에서 찾은 found_idx를 담는 리스트

        found_idx = MisChar(pattern, tmp_text)

        if found_idx < N:   # tmp_text에서 pattern을 찾았을 경우
                            # 만약 pattern을 찾지 못하였다면 found_idx가 문자열의 가장 끝인 N을 반환받을 것임
            print(f"Found the \"{pattern}\" on line {line_num} : index {found_idx}", end="")
            
            found_idx_list.append(found_idx) # 찾은 pattern의 위치(index)를 found_idx_list에 보관(append)
            tmp_text = text[found_idx+M:] # pattern을 찾은 다음 곳부터 text의 끝까지 문자열을 슬라이싱

            # 하나의 text 라인에서 여러 개의 패턴을 찾을 때
            while len(tmp_text) >= M:   # 분석할 남은 text의 길이가 pattern보다 길거나 같을 때만 실행
                                        # MisChar에서 return된 found_idx는 슬라이싱된 tmp_text에서의 pattern의 위치임
                found_idx = MisChar(pattern, tmp_text)

                if found_idx == len(tmp_text):  # 만약 남은 tmp_text에서 pattern을 찾지 못한 경우, found_idx는 tmp_text의 맨 끝 인덱스일 것임
                    break
                else:  # 남은 tmp_text에서 pattern을 찾은 경우
                    found_idx = found_idx_list[-1] + found_idx + M  # found_idx에 그 전의 인덱스만큼을 더해주어 원래 text의 위치(index)로 복원
                    print(f", {found_idx}", end="") # pattern을 찾은 줄번호, 위치를 알려주는 출력문
                    found_idx_list.append(found_idx) # 찾은 pattern의 위치(index)를 found_idx_list에 보관(append)
                    tmp_text = text[found_idx+M:] # pattern을 찾은 다음 곳부터 text의 끝까지 문자열을 슬라이싱
            print()

        found_cnt += len(found_idx_list) # 하나의 text 라인에서 찾은 패턴의 개수를 found_cnt에 더해줌으로써, 전체 문서에서 pattern이 나타난 횟수를 집계

    print(f"Finally, found {found_cnt} \"{pattern}\" in total!!\n") # 전체 문서에서 pattern을 찾은 결과 출력


