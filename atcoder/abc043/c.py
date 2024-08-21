n = int(input())
arr = list(map(int, input().split()))

avg = sum(arr) / len(arr)
rounded_avg = round(avg)

total_cost = sum([(x - rounded_avg) ** 2 for x in arr])
print(total_cost)