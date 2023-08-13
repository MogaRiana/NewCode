def main():
    arr = [0, 1, 6, 11, 9, 7, 5, 20]
    n = len(arr)

    pref = arr
    for i in range(1, n):
        pref[i] = pref[i] + pref[i - 1]
    
    for i in range(n):
        print(pref[i], " ", end="")
main()