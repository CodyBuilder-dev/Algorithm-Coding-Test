"""
제목 : [3차]파일명 정렬

아이디어 :
- 우선 머리 가슴 배를 분리한다
- 각 부분을 list에 tuple로 저장한다
- tuple의 정렬함수를 정의해 해당 함수를 바탕으로 정렬한다
- 동일한 경우, 원래 들어온 순서를 기억했다가 그거를 바탕으로 정렬한다
"""
import re

def solution(files):
    answer = []
    for i,file in enumerate(files):
        hn = re.match(r'^\D+\d{1,5}',file).group()

        answer.append([ file,
                        re.match(r'^\D+',hn).group().lower(),
                        re.search(r'\d{1,5}',hn).group(),
                        i])

    return list(map(lambda x: x[0],sorted(answer,key= lambda x: (x[1],int(x[2]),x[3]))))

# 테스트 케이스
print(solution(["img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"]))
print(["img1.png", "IMG01.GIF", "img02.png", "img2.JPG", "img10.png", "img12.png"])

print(solution(["F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"]))
print(["A-10 Thunderbolt II", "B-50 Superfortress", "F-5 Freedom Fighter", "F-14 Tomcat"])