import urllib2
import time

def rank_speed(speed):
    if speed < 56000: print 'Dial-up'
    elif speed > 5600 and speed < 8000000: print 'DSL/Satellite'
    elif speed > 8000000 and speed < 20000000: print 'Cable'
    else: print 'T3'

url = 'ftp://ftp1.optonline.net/test64'
#url = 'http://www.podtrac.com/pts/redirect.mov/zdpub.vo.llnwd.net/o2/dltv/episode257/dl.tv.257.mov'
#url = 'http://google.com'
req = urllib2.urlopen(url)
chunk = 500*1024
total = 0
#t0 = time.clock(), this will count cpu time in *nix, but we want 'wall' time
t0 = time.time()
print 'Fetching the file at:', url
while True:
    stuff =  req.read(chunk)
    if stuff:
        total += len(stuff)
        print 'downloading',total, "bytes..."
    else:
        now = time.time()
        #print 't0: ', t0
        #print 'now:', now
        time_used = now - t0
        print "time_used:", time_used, "seconds"
        if time_used == 0: break
        else:
            byte_per_sec = total / time_used
            k_byte_per_sec = byte_per_sec / 1000
            bit_per_sec = byte_per_sec * 8
            k_bit_per_sec = bit_per_sec / 1000
            m_bit_per_sec = k_bit_per_sec / 1000
            print "speed K-byte-per-sec(KBs):", k_byte_per_sec, 'KBs'
            print "speed M-bit-per-sec(Mbs):", m_bit_per_sec, 'Mbs'
            print "Internet Speed Result:"
            rank_speed(bit_per_sec)
        break




