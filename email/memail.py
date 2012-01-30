#send email with Gmail

import sys, smtplib
fromaddr = raw_input("From: ")
toaddrs  = raw_input("To: ")
print "Enter message, end with ^D:"
msg = ''
while 1:
    line = sys.stdin.readline()
    if not line:
        break
    msg = msg + line


#turn on TLS (transport layer security)
server = smtplib.SMTP('smtp.gmail.com', 587)
server.set_debuglevel(2)
server.ehlo()
server.starttls()
server.ehlo() 
server.login("gmail user name", "password")
server.sendmail(fromaddr, toaddrs, msg)
server.quit()
