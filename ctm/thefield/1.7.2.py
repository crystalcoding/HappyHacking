def my_list(L):
    if L[0] == 0: return [[]]
    return [list(range(L[0], x+1)) for x in L ]

if __name__ == '__main__':
    l = [1,2,4]
    print(my_list(l))
