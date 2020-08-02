# Arduino as secret key
Tested on Arduino NANO

##### How to use

```
$ git clone https://github.com/Allespro/ArduinoSecretKey.git

### build Arduino_NANO_sketch/Arduino_NANO_sketch.ino ###

$ cd ArduinoSecretKey
$ bash compile.sh   #create binary file
$ ./lurk            #run binary
```
After ```./lurk``` you will see:
![key_wait.png](https://raw.githubusercontent.com/Allespro/ArduinoSecretKey/master/images/key_wait.png)
That means that app wait key on ```/dev/ttyUSB0```.
Connect Arduino to USB, if everything is cool you will see:
![key_found.png](https://raw.githubusercontent.com/Allespro/ArduinoSecretKey/master/images/key_found.png)
And a train (```sl``` command):
![Train](https://raw.githubusercontent.com/Allespro/ArduinoSecretKey/master/images/chu_chu.png)

##### How that work
Arduino have a password, and after connection they send password to ```/dev/ttyUSB0```
```./lurk``` reading ```/dev/ttyUSB0``` every second.
If sha256 hash of password from Arduino is same as hash stored in ```./lurk``` you will have acces to ```some_func()``` from ```lurk.cpp```.

Have fun!