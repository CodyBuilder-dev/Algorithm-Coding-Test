"""
제목 : 가장 긴 팰린드롬

아이디어 : 어차피 팰린드롬을 찾는 기존 알고리즘따윈 모른다->완전탐색
- 부분문자열을 찾는다 O(n^2)
- 뒤집어서 같으면 팰린드롬이다

결과 : 정확성 테스트는 통과하지만, 효율성을 못 뚤는다
"""

def solution(s):
    maxima =0
    for i in range(len(s)):
        for j in range(i+1,len(s)+1):
            if s[i:j] == ''.join(reversed(s[i:j])):
                maxima = len(s[i:j]) if len(s[i:j]) > maxima else maxima

    return maxima

print(solution("abcdcba"))