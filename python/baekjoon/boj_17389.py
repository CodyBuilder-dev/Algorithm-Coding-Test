"""
제목 : 보너스 점수

"""


if __name__ == "__main__" :
    N = int(input())
    S = input()

    bonus = 0
    sum = 0
    for i in range(len(S)) :
        if S[i] == 'O' : 
            sum += bonus + i+1
            bonus += 1
        else : 
            bonus = 0
    
    print(sum)