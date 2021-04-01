"""
제목 : 신규 아이디 추천

아이디어 : 문자열을 스텝에 맞게 적절히 처리한다

구현 : re와 string 내장 함수를 적절히 사용한다

"""
import re

def solution(new_id):
    new_id = new_id.lower() # step 1
    new_id = re.sub('[^a-z0-9-_.]','',new_id) # step 2
    new_id = re.sub("\.{2,1000}",".",new_id) # step 3
    new_id = new_id.strip('.') # step 4
    if len(new_id) == 0 : new_id = 'a' # step 5
    if len(new_id) >= 16 : new_id = new_id[:15] # step 6
    new_id = new_id.strip('.')
    if len(new_id) <= 2 : new_id += new_id[-1]*(3-len(new_id)) # step 7

    return new_id
print(solution(".ABD!-_/..$#$@!!@$,"))
print(solution("...!@BaT#*..y.abcdefghijklm"))
print(solution(	"z-+.^."), "z--")
print(solution("=.="),	"aaa")
print(solution("123_.def"),	"123_.def")
print(solution("abcdefghijklmn.p"),	"abcdefghijklmn")

print(solution(".b..................c."))
print(''.strip('.'))
print(solution('!@#$%^&*()=+[{]}:?,<>/123$#%@#_'))