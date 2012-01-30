#!/usr/bin/python

import wx
import sys
from ftplib import FTP
from time import strftime

class MyFrame(wx.Frame):
    def __init__(self, parent, id, title):
        wx.Frame.__init__(self, parent, id, title, wx.DefaultPosition, wx.Size(500, 300))
        panel = wx.Panel(self, -1)
        box = wx.BoxSizer(wx.HORIZONTAL)
        box.Add(wx.Button(panel, 1, "Download"),1)
        box.Add(wx.Button(panel, 2, "Upload"),1)
        box.Add(wx.Button(panel, 3, "ls"),1)
        box.Add(wx.Button(panel, 4, "up"),1)
        box.Add(wx.Button(panel, 5, "back"),1)
        self.input_field = wx.TextCtrl(panel,-1,'desktop.sh')
        box.Add(self.input_field,3,wx.EXPAND,1)

        vbox = wx.BoxSizer(wx.VERTICAL)
        vbox.Add(box)
        self.file_window = wx.TextCtrl(panel,-1,style=wx.TE_MULTILINE)
        vbox.Add(self.file_window,1,wx.EXPAND)
        panel.SetSizer(vbox)       

        self.Bind(wx.EVT_BUTTON, self.download_click, id=1)
        self.Bind(wx.EVT_BUTTON, self.upload_click, id=2)
        self.Bind(wx.EVT_BUTTON, self.ls_click, id=3)
        self.Bind(wx.EVT_BUTTON, self.up_click, id=4)
        self.Bind(wx.EVT_BUTTON, self.back_click, id=5)
   
        redir=RedirectText(self.file_window)
        sys.stdout=redir
        #print 'test'

        self.ftp = None
        self.connect()
        self.ls()
        self.back_directory = []

    def download_click(self, event):
        self.re_connect()
        self.clear()
        print "==="
        file_name = self.input_field.GetValue()
        
        download_status = self.ftp.retrbinary('RETR '+file_name, open(file_name, 'wb').write)
        #self.file_window.SetValue(download_status)
        print(download_status)
        
        if(download_status.startswith("226")):
            print "successfully downloaded "+file_name
            print "==="
            self.ftp = None
        else:
            print "failed downloaded "+file_name
            print "==="

        print strftime("%a, %d %b %Y %H:%M:%S")

                

    def upload_click(self,event):
        self.re_connect()
        self.clear()
        print "==="
        file_name = self.input_field.GetValue()
        
        upload_status = self.ftp.storbinary('STOR '+file_name, open(file_name,'rb'))
        print(upload_status)
        if(upload_status.startswith("226")):
            print "successfully uploaded " +file_name
            print "==="
            self.ftp = None
        else:
            print "failed uploaded "+file_name
            print "==="
        print strftime("%a, %d %b %Y %H:%M:%S")
 

    def ls_click(self, event):
        self.re_connect()
        self.ls()
        print(self.ftp.pwd())
    
    def up_click(self, event):
        self.re_connect()
        self.clear()
        self.back_directory.append(self.ftp.pwd())
        if(self.back_directory[-1] == "/"):
            print "Cannot go up anymore."
        else:
            self.ftp.cwd('..')
            self.ls()

    def back_click(self, event):
        self.re_connect()         
        self.clear()
        if(len(self.back_directory)!= 0 ):
            self.ftp.cwd(self.back_directory.pop())
            self.ls()
        else:
            print "Cannot go back anymore"
       
    def connect(self):
        self.ftp = FTP('host')
        print self.ftp.login('name', 'password')
        print self.ftp.cwd('default directory')

    def re_connect(self):
        if(self.ftp == None):
            self.connect()

    def ls(self):
        self.re_connect()
        self.clear()
        print self.ftp.retrlines('LIST')

    def clear(self):
        self.file_window.SetValue("")
                 
class MyApp(wx.App):
    def __init__(self, redirect=True, filename=None):
        wx.App.__init__(self, redirect, filename)

    def OnInit(self):
        frame = MyFrame(None, -1, 'FTP')
        frame.Show(True)
        frame.Center()
        return True

class RedirectText:
    '''redirect stdout'''
    def __init__(self, aWxTextCtrl):
        self.out=aWxTextCtrl

    def write(self, string):
        self.out.WriteText(string)

app = MyApp(redirect=False)
app.MainLoop()
