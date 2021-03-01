def solution(s):
    # 짝수/홀수로 나눠서 푸는 경우
    # center = s[len(s)//2 - 1: len(s)//2+1] if len(s)%2 == 0 else s[len(s)//2]
    # 짝수/홀수 모두에 다 같이 쓸수 있는 풀이
    # 3이면 012 중 1 -> 1:2
    # 3//2 = 1이므로  3-1//2  = 1 , 3 + 1 // 2 = 2
    # 3//2 + 1 = 2, 3 // 2 - 1= 0
    # 4이면 0123 중 12 -> 1:3
    # 4//2 = 2이므로 4-1 // 2 = 1 , 4 + 1 // 2 = 2
    # 4//2 + 1 = 3, 4//2 - 1 = 0

    center = s[(len(s)-1 //2 ): len(s)//2 + 1]
    return center

s = "abcde"
s = "qwer"
print(solution(s))
