def solution(A, B):
    A, B = sorted(A), sorted(B)

    answer = 0
    j = 0
    while i<len(A):
        if A[i] < B[j]:
            answer = answer + 1
            i,j = i+1, j+1
        else:
            j = j+1

    return answer