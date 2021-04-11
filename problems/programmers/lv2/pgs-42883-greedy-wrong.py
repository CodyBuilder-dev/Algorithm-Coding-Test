"""
제목 : 큰 수 만들기

접근법 1: 브루트 포스
1. 2개를 임의로 뽑는다( 100만C2 = 시간 초과!)
2. 리스트에 보관한다
3. 최종적으로 보관된 리스트를 정렬 
-> number의 자리수가 10^6이므로, 완전탐색을 쓰지 말라는 소리다

접근법 2 : 그리디
- 길이가 n인데 k개를 제거한다 = n-k개를 뽑는다와 같은 의미
- 아래의 순서대로 숫자를 뽑는다
    - 제일 큰 수를 찾아 뽑는다
    - 해당 수의 앞 자리수와 뒤 자리수를 계산한다
        - 만약 앞 자리수 > 지울수 있는 수이면 지우지 않는다
        - 만약 앞 자리수 <= 지울 수 있는 수 이면 지운다
    - 지운 경우, 해당 수의 뒤에서 다음으로 큰 수를 찾는다
    - 지우지 못한 경우, 해당수 없에서 다음으로 큰 수를 찾는다
        - 위의 과정을 반복한다

- 지우는 방법 대신 포함하는 방법으로도 짤 수 있다
    - 제일 큰 수를 찾는다
    - 뒤에 충분한 수가 있는 경우, 해당 수 뒷부분에서 다음 큰수를 찾는다
    - 뒤에 충분한 수가 없는 경우 해당 뒤의 수를 모두 포함시킨 후 앞부분에서 다음으로 큰 수를 찾는다



"""
def solution(number,k):
    lst = [1]*len(number)
    i = 0
    while i < len(number):
        for j in range(i,len(number)):
            if number[j] > number[i]:
                if j-i <= k :
                    k -= (j-i)
                    lst[i:j] =[0]*(j-i)
                    i = j
                    break
            if j == len(number)-1:
                i+=1
    answer = []
    for i,v in enumerate(lst):
        if v ==1:
              answer.append(number[i])

    return ''.join(answer)

# 테스트케이스
print(solution("1924",2),"94")
print(solution("1231234", 3),"3234")
print(solution("4177252841",4),"775841")