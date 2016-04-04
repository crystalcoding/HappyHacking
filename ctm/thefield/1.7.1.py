def my_filter(L, num):
    return [x for x in L if x%num != 0]

if __name__ == '__main__':
    l = [1,2,4,5,7]
    print(my_filter(l, 2))
