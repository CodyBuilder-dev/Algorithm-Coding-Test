"""
제목 : 매칭 점수

아이디어 :
- HTML을 파싱한다
    - 외부 링크의 주소를 찾아낸다
    - 내 페이지로 링크가 걸린 것을 찾아낸다
    - 내부 기본 점수를 찾아낸다


구현 : 클래스를 이용한 연결관계를 구현해야 하는 듯
- 결국 가장 높은 점수를 갖는 페이지의 index를 반환
-
"""
import re

class Webpage:
    def __init__(self,html):
        self.html = html
        self.basic_point = len(re.findall(f"\\b{word}\\b",self.html,re.I))
        self.outward_link = []
        self.inward_link = []

    def add_outward_link(self,outward_link):
        self.outward_link.append(outward_link)

    def add_inward_link(self,inward_link):
        self.outward_link.append(inward_link)

    def get_basic_point(self,word):
        return self.basic_point

    def get_link_point(self):
        pass


def solution(word, pages):
    page_classes = []
    for page in pages :
        page_classes.append(Webpage(page))

    return page_classes

# print(re.findall("\\bblind\\b","blind bilnd blinde Blind",re.I))
print(solution("blind",["<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"]))