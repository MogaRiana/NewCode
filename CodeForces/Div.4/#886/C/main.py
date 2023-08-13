def main():
    t = int(input())

    for i in range(t):
        for j in range(8):
            a = input()
            for k in a:
                if k >= 'a' and k <= 'z':
                    print(k,end = "")
        print()          
main()