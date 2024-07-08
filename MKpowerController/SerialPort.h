// SerialPort.h

#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <windows.h>
#include <string>

class SerialPort {
public:
    //SerialPort(const std::string& portName);
    SerialPort();
    ~SerialPort();

    bool open(const std::string& portName);
    void close();
    bool writeData(const std::string& data);
    std::string readData();

private:
    HANDLE hSerial;
    std::string portName;
};

#endif // SERIALPORT_H