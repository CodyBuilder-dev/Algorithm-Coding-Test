if __name__ == "__main__" :
    n = int(input())
    scores = list(map(int,input().split()))

    # max-min인 경우 64ms
    # print(max(scores)-min(scores))

    # for문 돌면서 max,min 동시에 찾을 경우
    maxima = -123456789
    minima = 987654321
    for score in scores :
        if score > maxima : maxima = score
        if score < minima : minima = score

    print(maxima-minima)
