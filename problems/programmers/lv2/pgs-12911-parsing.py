"""
제목 : 다음 큰 숫자

아이디어 : 1로만 가득 찬 경우(111,11111 등)
- 그냥 앞에서 2번째 숫자의 왼쪽에 0을 집어넣는다


아이디어 : 그 외의 경우
(1) 한칸씩 오른쪽으로 rotation한다
- 반례 : 10101
    - 수행시 11010
    - 실제 답 10110
-> 잘못된 알고리즘

(2) 01뒤집기
- 문자열 맨 뒤에서부터 01을 찾는다
    - 01이 있는 경우 뒤집는다
    - 01이 없는 경우, 맨 앞에 0을 추가해서 뒤집는다
- 뒤집은 지점 뒤에 있는 1을 모두 뒤로 민다
"""

def solution(n):
    n_list= list(bin(n))[2:]
    if n_list.count('1') == len(n_list):
        return int('10'+'1'*(len(n_list)-1),2)
    n_list.insert(0,'0')
    for i in range(len(n_list)-1,-1,-1):
        if n_list[i-1:i+1] == ['0','1']:
            n_list[i-1],n_list[i] = '1','0'
            behind_one = n_list[i+1:].count('1')
            behind_all = len(n_list[i+1:])
            n_list[i+1:]= ['0']*(behind_all - behind_one) + ['1'] *behind_one
            return int(''.join(n_list),2)

# 테스트 케이스
print(solution(78),83)
print(solution(15),23)
print(solution(1),2)
print(solution(2),4)
print(solution(999999),1000031)
print(solution(1000000),1000064)
print(solution(10),12)
