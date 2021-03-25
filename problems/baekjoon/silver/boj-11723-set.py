"""
제목 : 집합

아이디어 :
- 집합을 실제로 구현하면, 연산을 300만번 수행하므로 시간복잡도가 매우 커지지 않을까?
    - 테스트용 & 심심해서 한번 구현해 보자



결과 :
- 입출력 최적화 + if-else 최적화를 수행했음에도, 채점중(71%)에서 시간 초과
"""

from sys import stdin,stdout

class Set :
    def __init__(self):
        self.s = set()

    def add(self,x) :
        self.s.add(x)

    def remove(self,x):
        if x in self.s :
            self.s.remove(x)

    def check(self,x):
        if x in self.s :
            # 출력 최적화
            # print(1)
            stdout.write("1\n")
        else :
            # print(0)
            stdout.write("0\n")

    def toggle(self,x):
        if x in self.s : self.remove(x)
        else : self.add(x)

    def all(self):
        self.s = set([str(i) for i in range(1,21)])

    def empty(self):
        self.s = set()

def solution(M):
    s = Set()
    for i in range(M):

        # 입출력 최적화
        # input_string = input().split()
        input_string = stdin.readline().split()

        operation = input_string[0]
        if len(input_string) > 1 :
            value = input_string[1]

        if operation == "add":
            s.add(value)
            continue # continue로 넘어가 줘야 함
        if operation == "remove":
            s.remove(value)
            continue
        if operation == "check":
            s.check(value)
            continue
        if operation == "toggle":
            s.toggle(value)
            continue
        if operation == "all":
            s.all()
            continue
        if operation == "empty":
            s.empty()
            continue


M = int(input())
solution(M)

