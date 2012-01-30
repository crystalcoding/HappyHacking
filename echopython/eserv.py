import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#sock = socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
sock.bind(('',8881))
sock.listen(5)

try:
    while True:
        newSocket, address = sock.accept()
        print "Connected from", address
        while True:
            receivedData = newSocket.recv(8192)
            if not receivedData: break
            print 'server received:', receivedData
            myfile = open('data', mode='a')
            myfile.write(receivedData)
            myfile.write('\n')
            myfile.close()
            newSocket.sendall("server response "+receivedData)

            
        print "Disconnectd from" , address
finally:
    sock.close()
