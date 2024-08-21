arr = list(map(int, input().split()))

s = set()
for k in range(31):
    for x in arr:
        s.add(int(x / (2 ** k)))

print(len(s))