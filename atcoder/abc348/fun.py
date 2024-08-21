d = [x * 100 for x in range(0, 12)]
print(d)

s = []
for i in range(0, 12):
    for j in range(0, 12):
        if i == j:
            continue
        s.append(abs(d[i] - d[j]))
        # print(i, j, d[i], d[j], d[i] + abs(d[i] - d[j]))

from collections import Counter
c = Counter(s)
print(c)
print(sum(s) / len(s))
print(sum(s), len(s))