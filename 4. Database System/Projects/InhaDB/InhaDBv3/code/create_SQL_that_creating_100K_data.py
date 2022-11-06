import random
import numpy as np
from tqdm import tqdm

id = 'null'

first_char = '이김박정윤최장한오우배변곽공류홍표조주도신은혜선명진수국종경'
second_char = '동김이박정윤최장한오우배변곽공류홍표조주도신은혜선명진수국종경'
third_char = '건김이박정윤최장한오우배변곽공류홍표조주도신은혜선명진수국종경'

alphabet = "abcdefghijklmnopqrstuvwxyz"
digit_alphabet = "0123456789-abcdefghijklmnopqrstuvwxyz"
emailList = ['time@inha.edu']

phoneNumberList = ['01000000000', '01011111111',
                   '01022222222', '01033333333', '01044444444']

majorList = ['기계공학과', '전자공학과', '정보통신공학과', '수학과', '경제학과']

studentIdList = ['12181879', '12201111', '12192222', '12213333', '12194444']

student_table_base = "INSERT INTO STUDENT (Id, Name, Email, Phone_number, Major, Student_Id) VALUES"


classIdList = ['1', '2', '3', '4', '5']

student_takes_class_table_base = "INSERT INTO STUDENT_TAKES_CLASS (Student_Id, Class_Id) VALUES"

sql = []
for i in tqdm(range(100000)):
    f_idx = random.randint(0, 29)
    s_idx = random.randint(0, 30)
    t_idx = random.randint(0, 30)
    name = first_char[f_idx] + second_char[s_idx] + third_char[t_idx]

    idx_1 = random.randint(0, 25)
    idx_2 = random.randint(0, 36)
    idx_3 = random.randint(0, 36)
    idx_4 = random.randint(0, 36)
    email = alphabet[idx_1] + digit_alphabet[idx_2] + \
        digit_alphabet[idx_3] + digit_alphabet[idx_4] + "@inha.edu"
    while email in emailList:
        idx_1 = random.randint(0, 25)
        idx_2 = random.randint(0, 36)
        idx_3 = random.randint(0, 36)
        idx_4 = random.randint(0, 36)
        email = alphabet[idx_1] + digit_alphabet[idx_2] + \
            digit_alphabet[idx_3] + digit_alphabet[idx_4] + "@inha.edu"
    emailList.append(email)

    phone_number = '0'+str(random.randint(1000000001, 1099999999))
    while phone_number in phoneNumberList:
        phone_number = '0'+str(random.randint(1000000001, 1099999999))
    phoneNumberList.append(phone_number)

    major_idx = random.randint(0, 4)

    student_Id = random.randint(12000000, 12999999)
    while student_Id in studentIdList:
        student_Id = random.randint(12000000, 12999999)
    studentIdList.append(student_Id)

    query = f"{student_table_base} ({id}, '{name}', '{email}', '{phone_number}', '{majorList[major_idx]}', {student_Id});\n"
    sql.append(query)
    
    class_idx = random.randint(0, 4)
    class_Id = classIdList[class_idx]
    query = f"{student_takes_class_table_base} ({student_Id}, {class_Id});\n"
    sql.append(query)


f = open('create_100K_data.sql', 'w')
for i, s in enumerate(sql):
    f.writelines(s)

f.close()
