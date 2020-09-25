"""
필요 개념 : 
1. 정수 -> 이진수
2. 이진수 비트마스크 연산
3. 이진수 -> 문자열
"""

def bitmask(num1,num2) :
    return num1 | num2



def make_map(n,arr) :
    bomul_map = []
    for num in arr :
        # 한줄 마니아 등판ㅋㅋㅋ
        # 얌전히 여러줄로 짜겠습니다...
        bin_str = str(bin(num)[2:])
        if len(bin_str) < 6 :
            bin_str = "0"*(6-len(bin_str)) + bin_str
        bomul_map.append(''.join(list(map(lambda x : '#' if x == '1' else ' ',list(bin_str)))))
    return bomul_map

def solution(n, arr1, arr2):
    bitmask_arr = list(map(bitmask,arr1,arr2))
    return make_map(n,bitmask_arr)

if __name__ == "__main__" :
    n=5
    arr1=	[9, 20, 28, 18, 11]
    arr2=	[30, 1, 21, 17, 28]
    # print(bitmask(21,28))
    n=	6
    arr1=	[46, 33, 33 ,22, 31, 50]
    arr2=	[27 ,56, 19, 14, 14, 10]
    # print(make_bitstr(n,arr1,arr2))
    print(solution(n,arr1,arr2))