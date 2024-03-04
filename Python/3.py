import sys

eps = 1e-10  # Adjusted eps value
maxn = 10**5 + 10

p = [(0, 0)] * maxn

def check(x):
    global n, e, p
    total_sum = 0
    for i in range(1, n + 1):
        need = p[i][0] * x
        if p[i][1] < need:
            need -= p[i][1]
            total_sum += need / e
    return total_sum <= x

def main():
    global n, e, p
    n, e = map(int, input().split())
    total_sum = 0
    for i in range(1, n + 1):
        p[i] = tuple(map(int, input().split()))
        total_sum += p[i][0]

    if total_sum <= e:
        print("-1")
        return

    l, r = 0, 1e10
    while l + eps < r:
        mid = (l + r) / 2
        if check(mid):
            l = mid
        else:
            r = mid

    print("{:.10f}".format(l))

if __name__ == "__main__":
    main()
