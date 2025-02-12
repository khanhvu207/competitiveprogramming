import matplotlib.pyplot as plt
import sys

f = open(sys.argv[1], 'r') #read file
t = int(sys.argv[2]) # x-axis range
step = int(sys.argv[3]) # sample step-size

N = int(f.readline())
print(f"Number of points in this test is: {N}")

X = [0] * N
Y = [0] * N
D = [0] * N

for i in range(N):
    line = f.readline().split()
    X[i] = int(line[0])
    Y[i] = int(line[1])
    D[i] = line[2]

x_axis = []
y_axis = []
INF = 1E18
T = 0

while T < t: 
    x_min = INF
    x_max = -INF
    y_min = INF
    y_max = -INF
    for i in range(N):
        dx = 0
        dy = 0
        if D[i] == 'L':
            dx = -1
        elif D[i] == 'R':
            dx = 1
        elif D[i] == 'U':
            dy = 1
        else:
            dy = -1
        newx = X[i] + T * dx
        newy = Y[i] + T * dy
        x_min = min(x_min, newx)
        x_max = max(x_max, newx)
        y_min = min(y_min, newy)
        y_max = max(y_max, newy)    
    y_axis.append((x_max - x_min) * (y_max - y_min))
    x_axis.append(T)
    T += step

plt.plot(x_axis, y_axis)
plt.xlabel('time')
plt.ylabel('area of bbox')
plt.show()



