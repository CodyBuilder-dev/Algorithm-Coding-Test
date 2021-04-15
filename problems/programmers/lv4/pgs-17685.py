
"""
제목 : [3차] 자동완성

아이디어 : 누가봐도 트라이
- 트라이의 정의대로 충실하게 구현하면 된다
- 시간복잡도 : 모든 단어의 문자를 순차적으로 검색하므로, 
최악의 경우 O(L) = 10^7

구현 : dict로 구현한다
- trie 생성시에, 현재 문자 이후에 단어가 몇개 들어가는지 정보를 "밑"에 함께 저장한다
- 끝은 "뚱"으로 구분한다
-{"g":
    {   "밑":2
        "o":{"밑":2,
            "뚱":1
            "n": {"밑":1
            }}
    }
}
"""
def solution(words):
    # 트라이 생성
    trie = {}
    for word in words:
        pointer = trie
        for c in word:
            if c not in pointer:
                pointer[c] = {"밑":0}
            pointer = pointer[c]
            pointer["밑"] +=1
        pointer["뚱"]=1

    # print(trie)
    # 트라이 조회
    # trie[-1]:1일때 까지 조회후 덧셈 및 탈출
    # 끝까지 조회해도 탈출을 못한 경우(단어 전체를 검색하는 경우) 별도 덧셈처리
    count = 0
    for word in words:
        pointer = trie
        is_break_middle = False
        for i,c in enumerate(word,start=1):
            if pointer[c]["밑"] == 1:
                count += i
                is_break_middle = True
                break
            else:
                pointer = pointer[c]
        if not is_break_middle:
            count += len(word)

    return count

print(solution(["go","gone","guild"]))