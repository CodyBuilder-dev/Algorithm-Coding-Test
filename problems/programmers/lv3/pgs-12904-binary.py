"""
제목 : 가장 긴 팰린드롬

아이디어 : 힌트에서 'x를 중심으로' 라는 말이 있었다. 중심에서부터 뻗어나가는 식으로 해보자
- c를 하나씩 넘어가며 중심에서 뻗어나간다
    - 팰린드롬이 성립할 때 까지 뻗어나간다
    - 성립하지 않는 순간을 포착해 길이를 기록한다
- 끝까지 반복한다
- 최대 길이를 반환한다

구현 :
(1)중심에서 좌우로 -1,+1로 뻗어나간다
-> 주의할 점 : 자칫 잘못하면 회문의 길이가 홀수인 경우만 고려할 수 있음
- 1개에서 뻗어나가는 경우
    -> 좌우로 +1 -1로 뻗어나간다
- 2개에서 뻗어나가는 경우
    -> 좌우로 +1 -1로 뻗어나간다

"""
def solution(s):
    maxima =1

    for i,c in enumerate(s):
        # 회문 길이가 홀수인 경우
        j = 0
        while True:
            j+=1
            if i-j < 0 or i+j >= len(s):
                j-=1
                break
            if not s[i-j] == s[i+j]:
                j-=1
                break

        maxima = 2*j+1 if 2*j+1 >= maxima else maxima

        # 회문 길이가 짝수인 경우를 찾기
        for i in range(len(s)-1):
            if s[i:i+2] == ''.join(reversed(s[i:i+2])):
                j = 0
                while True:
                    j += 1
                    if i - j < 0 or i+j+1 >= len(s):
                        j-=1
                        break
                    if not s[i-j] == s[i+1+j]:
                        j-=1
                        break
                maxima = 2*(j+1) if 2*(j+1) >= maxima else maxima
    return maxima


#테스트 케이스
print(solution("abcdcba"))
print(solution("a"))
print(solution("abacde"))
print(solution("ecdabbeadc"))
print(solution("abcde"))