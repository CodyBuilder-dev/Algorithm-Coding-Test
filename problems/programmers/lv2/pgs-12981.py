"""
제목 : 영어 끝말잇기

아이디어 :
(1) 실제 끝말잇기 구현
- word를 순회하면서 이때까지 나온 단어를 쭉 기록한다
- 단어가 두번째 나온 경우 해당인덱스를 바탕으로 사람과 순번을 계산한다

(2) 정렬하는 경우
- (단어,인덱스) 튜플을 정렬한다
- 두번 나오는 단어는 이웃해서 나온다
- 인덱스를 이용해 사람과 순번을 계산한다
-> 생각해보니, 이렇게 풀면 맨 앞자리가 일치하는지 여부를 검사할 수 없다
-> 즉, 끝말잇기처럼 앞단어와 뒷단어의 순서관계를 반드시 검사해야하는 문제에서,
    정렬로 순서를 파괴하면 잘못된 풀이이다
"""
def solution(n, words):
    hash = {}
    for i in range(len(words)):
        if hash.get(words[i]):
            return [i%n+1,i//n+1]
        if i>0 and words[i-1][-1] != words[i][0]:
            return [i%n+1,i//n+1]
        hash[words[i]] = 1
    return [0,0]

print(solution(3,["tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"]))
print(solution(5,["hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"]))
print(solution(2,["hello", "one", "even", "never", "now", "world", "draw"]))