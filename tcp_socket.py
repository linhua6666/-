#coding: utf-8
import socket

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
#绑定端口
s.bind(('192.168.153.1',9999))
s.listen(1)
print('Wait for connecting...')
(conn,addr) = s.accept()
print('conn=',conn)
print('addr=',addr)
while True:
    str1 = conn.recv(1024)
    str2 = str(str1,encoding='uft-8')
    print('I received a string is :,str2')
    str3 = str2.upper()
    conn.send(str3.encode('utf-8'))
    if str2 == '.':
        break
conn.close()
s.close()