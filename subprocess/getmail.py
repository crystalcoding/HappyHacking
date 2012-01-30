import subprocess
import os
import time

def refresh_mail():
    cmd = "getmail"
    my_pid = subprocess.Popen(cmd, shell = True)
    print "getmail pid", my_pid.pid

    print os.wait()

if __name__ == "__main__":
    while(True):
        refresh_mail()
        print "sleep 5 min"
        time.sleep(300)
