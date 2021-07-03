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

def find_url(page):
    # r = re.search(r"<meta[\w\b\s=:/.-]*>", page)
    r = re.search(r"<meta[\w\s/.=':-]*https[\w\s/.=':-]*>", page)
    url = re.search(r"'https.*'",r.group())

    return url.group()[1:-1]

def find_word(word, page):
    page = re.sub(r"[^a-zA-Z]","  ",page)
    matches = re.findall(f"\s{word}\s",page)
    return len(matches)


def find_outbound(word, page):
    result = []
    matches = re.findall(r"<a[\w\s/.=':-]*https[\w\s/.=':-]*>", page)
    for match in matches:
        url = re.search(r"'https.*'",match)
        result.append(url.group()[1:-1])

    return result

def solution(word, pages):
    word = word.lower()
    page_infos = dict()

    for i,page in enumerate(pages):
        # text 전처리
        page = page.replace('\n', ' ').replace('\"', "'").lower()

        # 페이지 url 파싱
        url = find_url(page)
        if url not in page_infos:
            page_infos[url] = {"index": i, "base_point": 0, "inbound": [], "outbound": 0}

    for i,page in enumerate(pages):
        # text 전처리
        page = page.replace('\n',' ').replace('\"',"'").lower()
        # print(page)

        # check base point
        page_infos[url]["base_point"] = find_word(word,page)

        # check outbound link
        outbound_links = find_outbound(word, page)
        # print("외부로 나가는 링크는",outbound_links)
        page_infos[url]["outbound"] = len(outbound_links)

        for link in outbound_links:
            if link in page_infos:
                page_infos[link]["inbound"].append(url)

    # return page_infos
    # 점수 계산
    max_idx = -987654321
    max_point = -987654321

    for k in page_infos:
        link_point = 0
        base_point = page_infos[k]["base_point"]
        for inbound in page_infos[k]["inbound"]:
            link_point += page_infos[inbound]["base_point"]/page_infos[inbound]["outbound"]
        final_point = base_point + link_point

        if final_point > max_point:
            max_idx = page_infos[k]["index"]
            max_point = final_point

    return max_idx


print(solution("blind",["<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"]))
print(solution("Muzi",["<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"]))
print(solution("blind",["<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blinde\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"]))


