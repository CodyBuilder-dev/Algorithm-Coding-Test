"""
제목 : 스택으로 큐 만들기

아이디어 : 하노이의 탑
- instack, outstack을 2개 만든다
- 넣을때는 무조건 instack 넣는다
- 뽑을때는
    - outstack이 비어있으면, instack의 모든 원소를 outstack으로 옮긴후 맨 위에서 꺼낸다
    - outstack이 비어있지 않으면 outstack을 뽑는다
"""

class QueueFromStack:
    def __init__(self):
        self.in_stack = []
        self.out_stack = []

    def push(self,value):
        self.in_stack.append(value)

    def pop(self):
        if not self.out_stack:
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
        return self.out_stack.pop()

qfs = QueueFromStack()
for i in range(50):
    qfs.push(i)

for i in range(25):
    print(qfs.pop())

for i in range(50):
    qfs.push(i)

for i in range(75):
    print(qfs.pop())
