import socket, struct
def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(('localhost', 10001))
    while True:
        entrada = input()
        if entrada is 'q':
            break
        s.send(struct.pack(">H", int(entrada)))
    s.close()

main()