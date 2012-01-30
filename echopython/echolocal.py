import socket 
sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
#sock = socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) 
sock.connect('/tmp/s')
print "Connected to server"

try:
    while True:
        data = raw_input()
        sock.sendall(data)



finally:
    sock.close()

'''
for line in data.splitlines():
    sock.sendall(line)
    print "Send:", line
    response = sock.recv(8192)
    print "Received:", response
'''
