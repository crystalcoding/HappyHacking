import subprocess
import os
import time

hours = 12
minutes = 60
seconds = 60
time.sleep(hours*minutes*60) #in 12 hours
pid = subprocess.Popen('svn update', shell= True , cwd='/cygdrive/c/source/')
sts = os.waitpid(pid.pid, 0)