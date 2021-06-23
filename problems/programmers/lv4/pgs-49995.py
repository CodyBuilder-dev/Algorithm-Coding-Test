"""
제목 : 쿠키 구입

아이디어 : 구간을 나눈다
-> 시작점 3개를 추출하는 경우의 수 -> 너무 많음
-> 기각

아이디어 : 시작점을 정한다
-> 시작점을 기준으로 왼쪽 오른쪽 합 구함
-> 큰쪽에서 하나 뺀다
-> 같아질떄까지 반복

"""
def solution(cookie):
    max_cookie = -987654321

    for i in range(1,len(cookie)):
        left_pointer = 0
        left_sum = sum(cookie[:i])
        right_pointer = len(cookie)-1
        right_sum = sum(cookie[i:])
        while left_pointer < i and right_pointer >= i:
            if left_sum > right_sum:
                # sum을 매번 구하지 말고, pointer를 이용
                # left_pointer += 1
                # left_sum = sum(cookie[left_pointer:i])
                # 이거 하나 최적화했는데 되네?
                left_sum -= cookie[left_pointer]
                left_pointer += 1
            elif left_sum < right_sum:
                right_sum -= cookie[right_pointer]
                right_pointer -= 1

            else:
                max_cookie = max(max_cookie,left_sum)
                break

    return max(max_cookie,0)

print(solution([1,1,2,3]))
print(solution([1,2,4,5]))