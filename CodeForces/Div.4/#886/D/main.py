def main():
    t = int(input())

    for i in  range(t):
        n, k = input().split()
        n = int(n)
        k = int(k)
        l = list(map(int, input().split()))
        l.sort()

        crt, res = 1, -1
        for ii in range(1, n):
            if l[ii] - l[ii - 1] <= k:
                crt += 1
            else:
                if crt > res:
                    res = crt
                crt = 1

        if crt > res:
            res = crt

        if res == -1:
            print(0)
        else:
            print(n - res)

main()
             