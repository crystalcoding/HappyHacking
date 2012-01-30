import subprocess
import os
import time

print 'running /root/script/getportsnap.py'

cmd = "portsnap fetch update"

while True:
    my_sub_p = subprocess.Popen(cmd, shell = True)
    print "child process id(portsnap)", my_sub_p.pid
    print os.wait()
    print 'portsnap using pythin has ended'
    time.sleep(3600)
