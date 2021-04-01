"""
제목 : 찾기

아이디어 : 그냥 빠른 문자열 탐색 알고리즘 쓰면 된다

구현 : 오토마타로 짜자
- 누군가가 만들어놓은 동적 전이표 생성 코드 사용
- 생각해보니, 전이표의 공간복잡도는 O(text길이*pattern의 unique문자 수) = 10^6 * 53 =
"""
NO_OF_CHARS = 123

def getNextState(pat, M, state, x):
    '''
    calculate the next state
    '''

    # If the character c is same as next character
      # in pattern, then simply increment state

    if state < M and x == ord(pat[state]):
        return state+1

    i=0
    # ns stores the result which is next state

    # ns finally contains the longest prefix
     # which is also suffix in "pat[0..state-1]c"

     # Start from the largest possible value and
      # stop when you find a prefix which is also suffix
    for ns in range(state,0,-1):
        if ord(pat[ns-1]) == x:
            while(i<ns-1):
                if pat[i] != pat[state-ns+1+i]:
                    break
                i+=1
            if i == ns-1:
                return ns
    return 0

def computeTF(pat, M):
    '''
    This function builds the TF table which
    represents Finite Automata for a given pattern
    '''
    global NO_OF_CHARS

    TF = [[0 for i in range(NO_OF_CHARS)]\
          for _ in range(M+1)]

    for state in range(M+1):
        for x in range(NO_OF_CHARS):
            z = getNextState(pat, M, state, x)
            TF[state][x] = z

    return TF

def search(pat, txt):
    '''
    Prints all occurrences of pat in txt
    '''
    global NO_OF_CHARS
    M = len(pat)
    N = len(txt)
    TF = computeTF(pat, M)

    # Process txt over FA.
    state=0
    answer = []
    for i in range(N):
        state = TF[state][ord(txt[i])]
        if state == M:
            answer.append(i-M+2)
            # print("Pattern found at index: {}".format(i-M+1))

    print(len(answer))
    for idx in answer :
        print(idx,end = ' ')

# Driver program to test above function
def main():
    txt = input()
    pat = input()
    search(pat, txt)

if __name__ == '__main__':
    main()

# This code is contributed by Atul Kumar