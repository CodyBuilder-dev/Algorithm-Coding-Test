"""
아이디어 : 
1. 커서를 두고 그냥 처음부터 끝까지 탐색하면서 그때그때 넣고 뺀다 -> O(N^2) -> 안풀림
2. 리스트를 2개 두고, 큐처럼 구현한다

아이디어 2 구현 : 리스트를 2개 잡고 구현할 수 있을 것 같다
1. list 변수를 2개 만들고
2. <,>,-에 대해 각 list를 넘나드는 메소드를 만들면 됨

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
        self.temp = []
        self.passWord = []

    # < 가 들어온 경우
    def left(self) :
        if len(self.passWord) > 0 :
            self.temp.append(self.passWord.pop())
        
    
    def right(self) :
        if len(self.temp) > 0 :
            self.passWord.append(self.temp.pop())
        

    def back(self) :
        if len(self.passWord) > 0 :
            self.passWord.pop()    

    def forward(self,key) :
        self.passWord.append(key)
        
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
                self.forward(key)
        
        print(''.join(self.passWord + list(reversed(self.temp))))


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
        