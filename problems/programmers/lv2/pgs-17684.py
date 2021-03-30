"""
제목 : 압축

구현 :
- for문 중에 계속해서 문자열이 변하는 것이 편하다
-> 인덱스보다 deque를 쓰는 편이 더 편하다
"""
from collections import deque

def solution(msg):
    msg = deque(msg)

    word_index = {}
    base_word = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    for word,index in zip(base_word,range(1,27)) :
        word_index[word] = index

    answer = []
    while len(msg) > 0 :
        word = msg.popleft()
        while word_index.get(word) and len(msg) > 0 :
            word += msg.popleft()

        if word_index.get(word) :
            answer.append(word_index[word])
        else :
            msg.appendleft(word[-1])
            answer.append(word_index[word[:-1]])
            index += 1
            word_index[word] = index
    return answer

# 테스트 케이스
print(solution("KAKAO"))
print(solution("TOBEORNOTTOBEORTOBEORNOT"))
print(solution("ABABABABABABABAB"))
