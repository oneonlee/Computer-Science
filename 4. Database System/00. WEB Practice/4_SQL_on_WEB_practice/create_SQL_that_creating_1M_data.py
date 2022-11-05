import random
import numpy as np


first = '김이박정윤최장한오우배변곽공류홍표조주도신은혜선명진수국종경'
second = '김이박정윤최장한오우배변곽공류홍표조주도신은혜선명진수국종경'
third = '김이박정윤최장한오우배변곽공류홍표조주도신은혜선명진수국종경'
Dnumber = [1, 4, 5]
ssnList = []
sex = 'MF'
base = "INSERT INTO EMPLOYEE (Fname, Minit, Lname, Ssn, Sex, Salary, Dno) VALUES "

sql = []
for i in range(1000000):
    if i % 100000 == 0:
        print(i)
    f_idx = random.randint(0, len(first)-1)
    s_idx = random.randint(0, len(first)-1)
    t_idx = random.randint(0, len(first)-1)
    d_idx = random.randint(0, 2)
    sex_idx = random.randint(0, 1)
    ssn = random.randint(111111111, 999999999)
    while ssn in ssnList:
        ssn = random.randint(111111111, 999999999)
    ssnList.append(ssn)

    Fname = second[s_idx] + third[t_idx]
    Minit = " "
    Lname = first[f_idx]
    Sex = sex[sex_idx]
    Ssn = ssn
    Salary = random.randint(10000, 99999)
    Dno = Dnumber[d_idx]

    query = base + '("' + Fname + '", "' + Minit + '", "' + Lname + '", ' + \
        str(Ssn) + ', "' + Sex + '", ' + str(Salary) + ', ' + str(Dno) + ');\n'

    sql.append(query)

f = open('create_1M_data.sql', 'w')
for i, s in enumerate(sql):
    f.writelines(s)

f.close()
