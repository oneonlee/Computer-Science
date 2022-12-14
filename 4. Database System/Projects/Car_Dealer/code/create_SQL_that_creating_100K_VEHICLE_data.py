# -*- coding: utf-8 -*-
"""create_SQL_that_creating_100K_VEHICLE_data.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1uvtUki6ShoQv9-2YJmKFR2VGFXMUOpCO
"""

import random
import numpy as np
from tqdm import tqdm

sql = []

################################# make VEHICLE data #################################
Vid = 'NULL'

VIN_LENGTH = 17
digit_alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
Vin_list = []

vehicle_brand = ["현대", "기아", "르노삼성", "쌍용", "쉐보레", "토요타", "렉서스", "혼다", "닛산", "캐딜락", "링컨", "BMW", "메르세데스벤츠", "폭스바겐", "포르쉐", "아우디", "볼보", "부가티", "페라리", "람보르기니", "마세라티"]
vehicle_model = ["킹", "갓", "제네럴", "엠페러", "충무공", "마제스티", "하이퍼", "울트라", "판타스틱", "익스트림", "지니어스", "화룡정점", "마스터", "더엠비션", "리마스터", "성골", "엘라스틱", "레전더리", "허니버터", "지져스", "내셔널", "앱솔루트", "리미티드", "먼치킨", "군계일학", "다크호스", "프레지던트", "월드클래스", "엠페러", "올드스쿨", "카사노바", "카와이", "올타임레전드", "슈퍼루키", "크리티컬", "업그레이드", "엘리트", "최고급", "클래시컬", "스테디셀러", 
                 "어드벤스드", "유니버셜", "언프레딕터블", "VIP", "로얄", "풀차징", "유니버시티", "천상계", "베테랑", "슈프림", "뉴블러드", "일루미나틸", "누텔라", "비브라뉴", "슈퍼히어로", "아킬레스건", "트렌드세터", "하이테크", "오버클럭", "우주대스타", "사일런트", "맥가이버", "세레나데", "주상전하", "뉴제네레이션", "원탑", "알파고", "데스티네이션", "빈티지", "약방의감초", "해피버스데이", "마에스트로", "에픽", "인비저블", "유니크",
                 "올뉴", "모닝", "1.0", "럭셔리", "아반떼", "AD", "1.6", "터보", "스포츠", "M/T", "싼타페", "DM", "2.0", "디젤", "2WD", "익스클루시브", "스페셜", "카이엔", "3.0", "쿠페", "봉고3", "1톤", "4X2", "CRDI", "포터2", "4WD", "3시리즈", "골프", "S클래스", "DB", "말리부", "시빅", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]

Status_list = ["ONSALE", "RESERVED", "SOLDOUT"]

VEHICLE_table_base = "INSERT INTO VEHICLE (Vid, Vin, Model, Price, Status) VALUES"

for i in tqdm(range(100000)):
    Vin_tmp_value = ""
    for i in range(VIN_LENGTH):
        idx = random.randint(0, len(digit_alphabet)-1)
        Vin_tmp_value += digit_alphabet[idx]
    Vin_value = Vin_tmp_value
    while Vin_value in Vin_list:
        Vin_tmp_value = ""
        for i in range(VIN_LENGTH):
            idx = random.randint(0, len(digit_alphabet)-1)
            Vin_tmp_value += digit_alphabet[idx]
        Vin_value = Vin_tmp_value
    Vin_list.append(Vin_value)

    Model_value = vehicle_brand[random.randint(0, len(vehicle_brand)-1)] + "-" + vehicle_model[random.randint(0, len(vehicle_model)-1)] + "-" + vehicle_model[random.randint(0, len(vehicle_model)-1)]

    Price_value = random.randint(100, 429496) * 10000
    
    Status_value = Status_list[random.randint(0, len(Status_list)-1)]
    
    query = f"{VEHICLE_table_base} ({Vid}, '{Vin_value}', '{Model_value}', {Price_value}, '{Status_value}');\n"
    sql.append(query)
#####################################################################################


################################# make SALESPERSON_manages_VEHICLE data #################################
SALESPERSON_manages_VEHICLE_table_base = "INSERT INTO SALESPERSON_manages_VEHICLE (Salesperson_id, Vehicle_id) VALUES"
Salesperson_id_list = [str(i) for i in range(1, 12)]

for Vehicle_id in tqdm(range(1, 100000+1)):
    query = f"{SALESPERSON_manages_VEHICLE_table_base} ({Salesperson_id_list[random.randint(0, len(Salesperson_id_list)-1)]}, {Vehicle_id});\n"
    sql.append(query)
#########################################################################################################

f = open('create_100K_VEHICLE_data.sql', 'w')
for i, s in enumerate(sql):
    f.writelines(s)

f.close()

