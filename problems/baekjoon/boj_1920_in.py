"""
접근 : list에 집어넣고 in으로 풀자

정답여부 : N
틀린 이유 : 
1. in으로 찾는것이 python for문보다는 빠르다
2. 그럼에도 불구하고 in의 원리도 결국 순차탐색이므로 결국 복잡도는 O(N^2)
"""

if __name__ == "__main__" :
    n = int(input())
    target_list = list(map(int,input().split()))
    m = int(input())
    source_list = list(map(int,input().split()))

    for source in source_list :
        print(1 if source in target_list else 0)
  