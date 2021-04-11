"""
제목 : 큰 수 만들기

아이디어 : 그리디
- 앞에 잘못 푼 문제와 동일

구현 : 인덱스를 지정하는 포인터를이용
- left, right, max_idx를 정한다
- max_idx와 앞에 남은 수 k를 비교한
    - max_idx > k이면 못지운다
    - max_idx <= k 이면 지운다
        - 지운 경우, 별도 제출용 리스트에 해당 제일 큰 수를 append
- left,right,max_idx를 재조정한다
    - 지운 경우, 해당 수의 뒤에서 다음으로 큰 수를 찾는다
        - 즉, left = max_idx+1
        - max_idx = max(number[left:])
    - 지우지 못한 경우, 해당수 없에서 다음으로 큰 수를 찾는다
        - 즉, right = max_idx
        - max_idx = max(number[:right])
- left > right와 까지 반복한다
    - 이때 마지막에 한칸이 남으면, 그거 넣을지말지 예외처리한다
- 이후 left뒤에있는걸 다 합친다
"""
def solution(number,k):
    n = len(number)
    number = list(number)
    answer = []

    left,right = 0,len(number)
    max_idx = number.index(max(number))

    while k > 0 and left < right:
        if max_idx - left > k: #너무 많아 못 지움
            right = max_idx
            max_idx = number[left:right].index(max(number[left:right])) + left

        else: #지울 수 있음
            k -= (max_idx-left)
            if not (right-left) == 1: # 마지막 한칸 남은 경우, 거의 최소값이므로 버린다
                answer.append(number[max_idx])
            left = max_idx+1
            if left < right:
                max_idx = number[left:right].index(max(number[left:right])) + left

    return ''.join((answer + number[left:]))[:n-k]




# 테스트케이스
# print(solution("1924",2),"94")
# print(solution("1231234", 3),"3234")
# print(solution("4177252841",4),"775841")
print(solution("321",2))
print(solution("21",1))
print(solution('77777', 1))