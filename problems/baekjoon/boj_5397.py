"""
아이디어 : 
1. 커서를 두고 그냥 처음부터 끝까지 탐색하면서 그때그때 넣고 뺀다 -> O(N^2) -> 안풀림
2. 

아이디어 1 구현 : Class를 이용해서 구현할 수 있을 것 같다
1. 현재 커서를 멤버변수로 갖고
2. <,>,-에 대한 연산을 메서드로 가지면 되지 않나

정답여부 : N

주의점 :
1. 클래스 변수와 인스턴스 변수를 잘 구분할 것
2. list에는 insert가 있음을 배웠다.
3. 파이썬은 구현이 쉬운 대신 느리므로 데이터타입과 자료구조의 선택에 신중해야 한다
(C++은 무식하게 짜도 언어가 빨라서 풀릴 때가 있다)
4. 파이썬도 C++과 마찬가지로 입출력 속도개선을 위한 팁이 있다
"""

from sys import stdin

class PassWord :
    # 파이썬 클래스에서, 전역에서 self 없이 선언된 변수는 클래스 변수이다
    # 클래스 변수는 모든 인스턴스에 공통적으로 공유된다
    # 즉, 인스턴스A에서의 클래스변수의 변경이 인스턴스 B의 클래스변수에 영향을 미친다
    # 따라서 예상치 못한 결과를 일으킬 수 있다.
    #keyLog = ""
    #pointer = 0
    #passWord = []
    
    # 파이썬 클래스는, 메소드 선언부는 self를 인자로 받는다
    # 생성자 내에서 선언된 변수는 인스턴스 변수이다
    def __init__(self,keyLog) :
        self.keyLog = keyLog
        self.pointer = 0
        self.passWord = []

    # < 가 들어온 경우
    def left(self) :
        if self.pointer > 0 :
            self.pointer -= 1
    
    def right(self) :
        if self.pointer < len(self.passWord) :
            self.pointer += 1

    def back(self) :
        if self.pointer > 0 :
            # pop로하면 느린 듯
            # self.passWord.pop(self.pointer-1)
            self.passWord = self.passWord[:self.pointer-1] + self.passWord[self.pointer:]
            self.pointer -= 1

    def forward(self,key) :
        self.passWord = self.passWord[:self.pointer] + [key] + self.passWord[self.pointer:]
        self.pointer += 1

    def findPassWord(self) :
        for key in self.keyLog :
            if key == "<" :
                self.left()
            elif key == ">" :
                self.right() 
            elif key == "-" :
                self.back()
            else :
                # insert로 하면 시간초과 나는듯
                # 나만의 forward 연산을 만들자
                # self.passWord.insert(self.pointer,key)
                # self.pointer += 1
                self.forward(key)
        print(''.join(self.passWord))


if __name__ == "__main__" :
    tc = int(input()) 
    for t in range(tc) :
        # keyLog = input() # 그냥 input()으로 받으면 느리다
        keyLog = stdin.readline().strip() # realine은 빠르다. 대신 끝에 \n이 붙으니 주의

        # simple test code : 정상동작 확인용
        # keyLog = "-----"
        # keyLog = "A<-"
        # keyLog = "<A<B"
        
        # long test code : 실행시간 3초
        # import random
        # import time
        # test = ["A","-","<",">"]
        # testStr = ""
        # for i in range(1000000) :
        #     testKey = random.choice(test)
        #     testStr += testKey
        # start = time.time()
        # pw = PassWord(testStr)
        # pw.findPassWord()
        # print( time.time() - start) 

        pw = PassWord(keyLog)
        pw.findPassWord()
        