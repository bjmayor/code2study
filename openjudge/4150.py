n = int(input())
a = tuple(int(v) for v in input().split())
b = tuple(int(v) for v in input().split())
c = tuple(int(v) for v in input().split())

f = [[0]*4 for _ in range(n)]

f[0][0] = a[0]
f[0][2] = b[0]

for i in range(1, n):
    f[i][0] = max(f[i-1][2], f[i-1][3])+a[i]
    f[i][1] = max(f[i-1][0], f[i-1][1])+b[i]
    f[i][2] = max(f[i-1][2], f[i-1][3])+b[i]
    f[i][3] = max(f[i-1][0], f[i-1][1])+c[i]

print(max(f[n-1][0], f[n-1][1]))
