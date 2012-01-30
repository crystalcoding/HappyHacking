'''                                                                                                   
Miku's fan you are?                                                                                   
Download Miku's concert from YouTube.                                              
You will need to install BeautifulSoup(for xml parsing),                                              
and youtube-dl to download youtube's videos.                                                          
Author: Glenn Y. Chen                                                                                 
'''

import urllib2
from subprocess import call
from BeautifulSoup import BeautifulSoup


doc = urllib2.urlopen('http://gdata.youtube.com/feeds/api/videos?author=SeyrenLK')
html = doc.read()
soup = BeautifulSoup(html)

for media_group in soup.findAll('media:group'):
    link =  media_group.findChild('media:content').attrs[0][1]
    #let youtube-dl handle title or you can get it yourself                                           
    #title = media_group.findChild('media:title').text                                                
    if link.find('http') != -1:
        call(["youtube-dl", "--title", link])

