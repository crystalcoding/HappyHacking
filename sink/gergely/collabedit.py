'''
Devise a function that takes an input 'n' (integer) and returns a string that is the
decimal representation of that number grouped by commas after every 3 digits. You can't
solve the task using a built-in formatting function that can accomplish the whole
task on its own.

Assume: 0 <= n < 1000000000

1 -> "1"
10 -> "10"
100 -> "100"
1000 -> "1,000"
10000 -> "10,000"
100000 -> "100,000"
1000000 -> "1,000,000"
35235235 -> "35,235,235"
'''

def add_comma(n):
#    rev_n = reversed(n)
#    ret = ''
#    for index, num in enumerate(rev_n):
#        ret += num 
#        if not index == 0 and index % 3 == 2:
#            if not index == len(n):
#                ret += ','
#
#    return reversed(ret)'''
    n_copy = list(n)
    ret = ''
    for index, num in enumerate(n):
        ret += n_copy.pop()
        if index % 3 == 2:
            if index != len(n)-1:
                ret += ','

    return ''.join(list(reversed(ret)))


if __name__ == '__main__':
    #n = raw_input()
    n = '12342313'
    n = '10'
    n = '100'
    n = '1000'
    n = '10000'
    n = '100000'
    n = '1000000'
    n = '35235235'
    #check is integer?
    #0 <= n < 1000000000
    MAX = 1000000000
    if int(n) >= 0 and int(n) < MAX:
        rev = add_comma(n)
        print rev
