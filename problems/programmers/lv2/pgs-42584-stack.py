"""
제목 : 주식가격

문제 조건 :
- 아마 현재 시점부터 리스트의 끝까지의 시간을 요구하는 듯
    - 리스트의 끝에 도달하면 0으로 처리함
- 예외적으로 다음에 바로 떨어지는건 1초로 봄

아이디어 : price를 한칸씩 탐색하면서 그 이전까지의 모든 시간 갱신
- 시간복잡도는 O(N^2)이므로 당연히 불가능

아이디어 : 스택을 쓰면 된다
- 순차적으로 돈다
    - 현재 값을 스택의 마지막 값과 비교한다
        - 스택의 맨 마지막 값보다 크면, 그냥 스택에 값과 인덱스를 집어넣는다
        - 스택의 맨 마지막 값보다 작으면, 스택에서 더 작은값이 안 나올때까지 뺀다
            - 빼는 과정에서, 현재 값까지의 거리를 answer에 저장한다
- 시간복잡도
    - 근데 결국 for문 내부에서 while을 돌리니까 최악의 경우는 O(N^2)이다
    - 그러나 실제로는, while의 횟수가 for 전체의 길에에 비해 매우 짧아지므로 거의 O(N)에 가깝다
"""
def solution(prices):
    answer = [0]*len(prices)
    stack = []

    for i,p in enumerate(prices):
        while stack and stack[-1][0] > p:
            previous_idx = stack.pop()[1]
            answer[previous_idx] = i - previous_idx

        else:
            stack.append((p,i))

    # 끝까지 떨어지지 않은것만 별도 처리
    answer = [len(answer) - 1 - i if not a else a for i,a in enumerate(answer)]

    return answer

print(solution([1, 2, 3, 2, 3]),[4,3,1,1,0])
print(solution([1,3,2,4,3,5,4]))