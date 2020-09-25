from sys import stdin
from hashlib import sha256

S = stdin.readline().strip()
# S = input()
m = sha256()
m.update(S.encode("utf-8"))
print(m.hexdigest())