import http.client

def chunk_data(data, chunk_size):
    dl = len(data)
    ret = ""
    for i in range(dl // chunk_size):
        ret += "%s\r\n" % (hex(chunk_size)[2:])
        ret += "%s\r\n\r\n" % (data[i * chunk_size : (i + 1) * chunk_size])

    if len(data) % chunk_size != 0:
        ret += "%s\r\n" % (hex(len(data) % chunk_size)[2:])
        ret += "%s\r\n" % (data[-(len(data) % chunk_size):])

    ret += "0\r\n\r\n"
    return ret


conn = http.client.HTTPConnection(host)
url = "/some_path"
conn.putrequest('POST', url)
conn.putheader('Transfer-Encoding', 'chunked')
conn.endheaders()
conn.send(chunk_data(body, size_per_chunk).encode('utf-8'))

resp = conn.getresponse()
print(resp.status, resp.reason)
conn.close()
