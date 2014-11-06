import sys
import urllib2
import subprocess

sentinel_start = 'http://www.youtube.com/watch?v=' 
sentinel_end = '&amp;'

def get_playlist_id(url):
    start = 'list='
    start = url.find(start) + len(start)
    return url[start:]

def get_playlist_feed(playlist_id):
    url = 'http://gdata.youtube.com/feeds/api/playlists/'
    return url + playlist_id

def get_video_ids(playlist_feed_url):
    ret = []
    f = urllib2.urlopen(playlist_feed_url)
    html = f.readlines()
    for line in html:
        begin = line.find(sentinel_start)
        if begin != -1:
            end = line.find(sentinel_end)
            video_id = line[begin+len(sentinel_start): end]
            #why there is duplicate?
            if video_id not in ret:
                ret.append(video_id)

    return ret

def write_play_list(video_ids):
    f = open("playlist.txt", 'w')
    for line in video_ids:
        f.write(sentinel_start+line)
        f.write('\n')

if __name__ == "__main__":
    #deadspace 3
    #python pl.py "http://www.youtube.com/watch?v=g2sbjIlnlN8&list=SP9MoLfABC7y5jTt6Yb8_GuuQVVwIKPjoV"

    #ff13-2
    #python pl.py "http://www.youtube.com/watch?v=klMlYOlAKlQ&list=SPF344954850DC4D95"
    
    url = sys.argv[1]
    playlist_id = get_playlist_id(url)
    playlist_feed_url = get_playlist_feed(playlist_id)
    video_ids = get_video_ids(playlist_feed_url)
    print 'total videos: ', len(video_ids)
    write_play_list(video_ids)

    #download
    #pass '-s' option to simulate
    subprocess.call(["youtube-dl", "--title", "-A", "-a", "playlist.txt"])
