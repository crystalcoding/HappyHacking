import time
import subprocess

def getTotalMinutes():
    s = raw_input('input format: xxhxxm\n')
    hour  = s[0:s.find('h')]
    minute = s[s.find('h')+1:s.find('m')]
    return int(hour)*60+int(minute)

def run():
    command = ['vlc', 'county_load.flv']
    print "run command:",command
    subprocess.call(command)
    

if __name__ == '__main__':
    minutes = getTotalMinutes()
    print "Count Down Total Minutes:" + str(minutes)
    while minutes > 0:
        time.sleep(60)
        minutes = minutes - 1
        print str(minutes) + " minute(s) left"

    run()
        
        
        


