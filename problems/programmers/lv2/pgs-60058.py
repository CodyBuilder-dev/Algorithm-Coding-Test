"""
제목 : 괄호 변환

아이디어 : deque 자료구조 + 요구사항 구현
- 앞에서부터 균형잡힌 문자열이 될때까지 넣는다
    - 균형잡힌 문자열이 되려면, 개수만 세면 된다
    - 찾으면, u,v로 분리한다
- u가 올바른 문자열인지 검사
    - '올바른 괄호' 문제처럼, 스택을 이용하거나 숫자를 세면 된다
- u가 올바른 문자열이면 v로 넘어감
- u가 올바른 문자열이 아니면,
    - '( v올바른 ) u뒤집기' 반환
- 뒤집기 연산은, for문으로 순회하면 될듯
    - )를 찾으면 (
    - (를 찾으면 )

구현 : 그냥 요구사항을 코드로 옮긴다
"""
def is_olbarun(pstr):
    count = 0
    for c in pstr:
        if c == ')': count -=1
        if c == '(': count +=1
        if count <0: return False

    if count >0: return False
    else: return True

def reverse_pstr(pstr):
    result = []
    for p in pstr:
        if p == '(': result.append(')')
        if p == ')': result.append('(')
    return ''.join(result)

def solution(pstr):
    if not pstr:
        return ""

    count_p = [0,0]
    for i,p in enumerate(pstr):
        if p == '(': count_p[0]+=1
        if p == ')': count_p[1]+=1
        if count_p[0] == count_p[1]:
            break

    u,v = pstr[:i+1],pstr[i+1:]
    if is_olbarun(u):
        return u + solution(v)
    else:
        return '('+solution(v) +')' + reverse_pstr(u[1:-1])

# 테스트 케이스
print(solution("(()())()"),"(()())()")
print(solution(")("),"()")
print(solution("()))((()"),"()(())()")
print(solution(")())(()("),"")