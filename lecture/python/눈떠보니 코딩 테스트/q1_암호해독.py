data = ['   + -- + - + -   ',
'   + --- + - +   ',
'   + -- + - + -   ',
'   + - + - + - +   ']

for value in data :
    value = value.replace(' ','').replace('+','1').replace('-','0')

    # int(value,2)
    # 2진수 문자열을 정수로 바꾸기
    print(chr(int(value,2)),end='')

#한줄 중독자
print(''.join([chr(int(value.replace(' ','').replace('+','1').replace('-','0'),2)) for value in data]))

