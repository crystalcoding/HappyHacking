import subprocess
import os
import time

def run_process():
    os.chdir("/etc/init.d/")
    print "parent process id", os.getpid()

    cmd = "/etc/init.d/ntp-client restart"
    my_sub_p = subprocess.Popen(cmd, shell = True)
    print "child process id(ntp-client)", my_sub_p.pid

    print os.wait()#parent waits for the child, get rid of zombine

if __name__ == "__main__":
    while(True):
        run_process() 
        time.sleep(1)
