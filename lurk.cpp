#include <iostream>

#include <fcntl.h>

#include <termios.h>

#include <unistd.h>

#include <cstring>

#include "sha256.h"

#include <string>

#include <cstdlib>

using namespace std;

string cod(string mystr) {
    string crypted = "";
    for (int i = 0; i < strlen(mystr.c_str()); i++)
        crypted += mystr[i] ^ 3;
    return crypted;
}

string decod(string mystr) {
    string decrypted = "";
    for (int i = 0; i < strlen(mystr.c_str()); i++)
        decrypted += mystr[i] ^ 3;
    return decrypted;
}

int some_func() {
    cout << decod("Hfz#jp#ubojg\"") << endl;
    sleep(3);
    system("sl");
    return 0;
}

int main() {
    int fd;
    char buf[512];
    char bw[15];
    int iIn;
    string message;
    cout << "/!\\ I need a key /!\\" << endl;
    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);
    if (fd == -1) {
        cout << "Wait for a key ";
    }
    while (true) {
        if (fd == -1) {
            cout << ".";
            fflush(stdout);
            sleep(1);
            fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);
        } else {
            cout << endl << "Key is here!" << endl;
            fflush(stdout);
            break;
        }
    }
    struct termios options; /*структура для установки порта*/
    tcgetattr(fd, & options); /*читает пораметры порта*/
    options.c_cflag |= (CLOCAL | CREAD); // Ignore modem controls
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8; // 8 bit chars
    options.c_cflag &= ~(PARENB | PARODD); // shut off parody
    options.c_cflag &= ~CSTOPB; //no scts stop
    options.c_iflag &= ~IGNBRK; //disable break processing
    options.c_iflag = 0; // no echo
    options.c_iflag &= ~(IXON | IXOFF | IXANY); // no software flow control
    options.c_oflag = 0; // no remapping
    options.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    options.c_cc[VMIN] = 0; // read doesn't block
    options.c_cc[VTIME] = 5; // 0.5s read timeout
    tcsetattr(fd, TCSANOW, & options);
    while (true) {
        fflush(stdout);
        iIn = read(fd, buf, 512);
        message = buf;
        if (message != "") {
            if (sha256(message) == "5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8") {
                some_func();
                break;
            } else {
                cout << endl << "Key is invalid!" << endl;
                close(fd);
                return 0;
            }
        } else {
            sleep(1);
        }
    }
    close(fd);
    return (1);
}

//c88kDnu4zv3ProW0tUQQWbb1hCDq9TP3EdEZTnnRnP2tc4A0oxgvL8IB1dhk9D7Y