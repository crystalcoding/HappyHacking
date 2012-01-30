import gdata.youtube
import gdata.youtube.service
import sha

import wx
import wx.html

yt_service = gdata.youtube.service.YouTubeService()


uri = "http://gdata.youtube.com/feeds/api/videos?vq=%E6%96%B0%E5%8F%B0%E6%B9%BE%E6%98%9F%E5%85%89%E5%A4%A7%E9%81%93&orderby=published"
feed = yt_service.GetYouTubeVideoFeed(uri)
htmlstring = "<html><body>"
for entry in  feed.entry:
     #print entry.media.title.text
     #htmlstring += entry.media.title.text
     print entry.media.player.url
     playerurl = entry.media.player.url
     htmlstring = htmlstring +"<a href='"+playerurl+"'>"+"test"+"</a>" +"\n"
     #htmlstring = htmlstring + playerurl
     print entry.media.thumbnail[1].url
     htmlstring = htmlstring + "<img src='" + entry.media.thumbnail[1].url + "' />" + "\n"
     #for thumbnail in entry.media.thumbnail:
     #    print 'Thumbnail url: %s' % entry.media.thumbnail[1].url

htmlstring += "</body></html>"
print htmlstring

app = wx.App()
frame = wx.Frame(None, -1, 'youtube feed')

html = wx.html.HtmlWindow(frame)
html.LoadFile('y2.htm')

frame.Show()
app.MainLoop()
