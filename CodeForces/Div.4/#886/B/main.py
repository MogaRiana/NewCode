def main():
    t = int(input())

    for i in range(t):
        n = int(input())

        res = -1
        win = 0
        for i in range(n):
            a, b = map(int, input().split())

            if a <= 10 and b > res:
                win = i + 1
                res = b
        
        print(win)
main()
