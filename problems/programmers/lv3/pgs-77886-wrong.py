"""
제목 : 110옮기기

아이디어 : 모든원소의 합이 10^6이므로 스위핑이 되긴 해
(1) 왼쪽에서부터 110을 찾는다
(2) 찾은 110을 오른쪽에서부터 한번씩 끼워넣으며, 그 수의 최소값을 찾는다
->문제점 : 중첩이 가능하다... 거기에 엄청난 시간복잡도

아이디어 : 규칙 기반 접근
- 잘라낸 곳을 기준으로 앞에 0이 없거나 맨 앞이다 -> 무조건 맨 앞으로
- 잘라낸 곳을 기준으로 뒤에 0이 있다 -> 무조건 맨 마지막 0 뒤로
- 잘라낸 곳을 기준으로 뒤에 0이 없다 -> 맨 마지막 0 뒤로
-> 규칙기반 접근은 좋지 않다

아이디어 : SHIFT하며 비교
- 십진수 32435442의 3을 빼서 옮기며 가장 작은 수를 만든다고 생각해보자
- 당연히 앞에서부터 비교하면서, 3보다 작은놈은 3앞으로 보내고 3보다 큰놈은 3뒤로 보내려고 할 것이다
- 이 아이디어를 2진수에도 동일하게 적용해보자
- 110을 찾은 후 왼쪽부터 오른쪽으로 1비트씩 shift하며 3칸씩 비교한다
- 110보다 작으면 다음칸으로 넘어가고 같거나 크면 그 앞에 끼워넣으면 된다

틀린 이유 : 투 포인터를 이용해 너무 복잡하게 풀려고 했다
"""
def find_110(x,start):
    for i in range(start,len(x)-2):
        if x[i:i+3] == "110": return i
    return -1

def make_minimum(x):
    temp = x
    pointer = 0
    while pointer < len(x):
        first_110 = find_110(temp,pointer)
        if (first_110 == -1): break

        temp = temp[:first_110]+temp[first_110+3:]
        second_pointer = pointer
        while temp[second_pointer:second_pointer+3] <= "110"\
                and second_pointer < len(temp)-2:
            second_pointer += 1
        if (second_pointer == len(temp) - 2):
            temp += "110"
        else:
            temp = temp[:second_pointer] + "110" + temp[second_pointer:]
        pointer = second_pointer+3

    return temp

def solution(s):
    answer = []
    for x in s:
        answer.append(make_minimum(x))

    return answer

# print([1][2:])
print(solution(["1110","100111100","0111111010"]),["1101","100110110","0110110111"])
print(solution(["100111100"]))