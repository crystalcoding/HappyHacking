import time
import sys


print '''
      please set the -u option (unbuffering) 
      for example, 
      python -u program.py inputfile.txt
      '''

f = open(sys.argv[1])

while f:
    time.sleep(0.20)
    n = f.read(1)
    if not n:
        break
    sys.stdout.write(n)

print 'end of file'

    
