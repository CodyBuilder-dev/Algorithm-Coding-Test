"""
제목 : 압축

아이디어 :
(1) 사전을 만들어 둔다
(2) msg를 앞에서부터 한칸씩 뺀다
- 더이상 사전에서 찾을 수 없을 때 까지 뺀다
(3) 뺐는데 사전에서 찾을 수 없는 경우 추가 로직을 진행한다
- 사전의 마지막에 key와 value를 추가한다
- 마지막으로 뺐던 것 중에 한개를 집어 넣는다

구현 :
- 문자열을 순회하는 과정에서 앞에서 pop하는 식으로 구현할 수 있다
-> deque를 사용할 수 있따
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
