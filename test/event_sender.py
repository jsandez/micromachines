import socket, struct
def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(('localhost', 10001))
    while True:
        entrada = input()
        if entrada is 'q':
            break
        s.send(struct.pack(">H", int(entrada)))
    
    while True:
        entrada = input()
        if entrada is 'q':
            break
        uuidEventoRed = s.recv(2)
        #uuidEvento = struct.unpack("!i", uuidEventoRed)[0]
        print(uuidEventoRed)

    s.close()

main()