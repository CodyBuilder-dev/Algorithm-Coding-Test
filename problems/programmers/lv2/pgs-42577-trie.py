"""
제목 : 전화번호 목록

아이디어 :
- 트라이의 원리를 알고 있다면, 트라이를 사용해서 풀면되는 문제
    - 공통되는 접두사를 key로 갖는다.
    - 그 다음 부분을 value로 갖는다. 단어가 여러 개라면 list에 담는다
    - value 내에서 또 공통되는 접두사가 있다면 이를 key로 하는 하위 dict을 만든다

구현 : 파이썬 dict를 이용한 tree로 구현 가능
(1) Trie의 구현
- 잘못된 접근 : 공통부를 찾고 -> 단어끼리 묶는다
    - 10^6개의 단어에 대해 공통부 찾기가 힘듬
    
- 올바른 접근 : 그냥 모든 단어에 대해 dict를 따라가게 만든다
- {
    "1" : {
        "1" : {
            "9": {  <------ 자식이 2개!
                None :{}
                "5" : { ... }
                }
            }
        }
    "9": {
        ...
        }
}

(2) 공통 개수 세기
- Trie에서, 자식 노드가 1개 이상인 노드가 있으면 접두사가 겹친다는 의미이므로 false
- 자식노드가 전부 1개 뿐이면 true
- 자식노드는, Trie 완전 탐색을 통해 찾는다
"""


def make_trie(trie:dict, word: str) -> dict:
    current_pointer = trie
    for char in word:
        if not current_pointer.get(char):
            current_pointer[char] = {}
        current_pointer = current_pointer[char]

    current_pointer.update({"end":"end"})
    return trie

def traverse_trie(trie:dict) -> bool:
    if trie.get("end"):
        if len(trie) > 1:
            return False
        else :
            return True

    # 이부분이 문제네
    # 앞의 key에서 먼저 return 해버리면 그 뒷부분의 key를 검사 안함
    result = True
    for k in trie:
        result = result & traverse_trie(trie[k])
    return result

def solution(phone_book):
    trie = {}
    for phone in phone_book:
        trie = make_trie(trie,phone)

    for k in trie:
        if not traverse_trie(trie[k]) : return False

    return True


phone_book = ["119", "97674223", "1195524421"]
phone_book = ["123", "456", "789"]
# phone_book = ["12", "123", "1235", "567", "88"] # False
# phone_book = ["1","2"] # True
# phone_book = ["987987","87"] # True
# phone_book = ["112","44","4544"] # True
phone_book = ["33", "11", "222", "21122", "211"] # False
# phone_book = ["12","13"]
print(solution(phone_book))
#
# a = {"end":{}}
# if a.get("end") :
#     print("True")
