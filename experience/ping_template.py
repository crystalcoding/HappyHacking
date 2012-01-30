import urllib2
import time
import random


def repeatReadPage(url):
    count = 0
    while True:
        html = urllib2.urlopen(url)
        count += 1
        print html.read()

        print "\nlink is:"
        print url
        print "Count",count

        sleepTime = random.randint(1,2)
        time.sleep(sleepTime)
        html.close()



if __name__ == "__main__":
    print "please input url:"
    url = raw_input();
    repeatReadPage(url)
    print "\nlink is:"
    print url
