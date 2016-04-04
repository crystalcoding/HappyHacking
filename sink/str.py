cities = ['Chicago', 'Detroit', 'Atlanta']
airports = ['ORD', 'DTW', 'ATL']

z = zip(cities, airports)
for c,a in z:
    print c

ret = [ (c,a) for c, a in z]
print ret

l = [1,2,3,4,5]
ret = [ i*10 for i in l ]
print ret

d = {'a':1, 'b':2, 'c':3}
ret = [ key for key, val in d.iteritems()]
print ret
