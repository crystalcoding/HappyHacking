import socket 
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#sock = socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) 
sock.connect(('localhost', 8881))
print "Connected to server"
data = "data sent from the client"
for line in data.splitlines():
    sock.sendall(line)
    print "Send:", line
    response = sock.recv(8192)
    print "Received:", response
sock.close()
