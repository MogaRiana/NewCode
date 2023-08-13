def main():
    t = int(input())

    for i in range(t):
        a, b, c = input().split()
        a = int(a)
        b = int(b)
        c = int(c)


        if a + b >= 10 or a + c >= 10 or b + c >= 10:
            print("YES")
        else:
            print("NO")

main()