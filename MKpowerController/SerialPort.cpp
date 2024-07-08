// SerialPort.cpp

#include "SerialPort.h"
#include <iostream>

//SerialPort::SerialPort(const std::string& portName) : portName(portName), hSerial(INVALID_HANDLE_VALUE) {}
SerialPort::SerialPort(){}
SerialPort::~SerialPort() {
    close();
}

bool SerialPort::open(const std::string& portName) {
    hSerial = CreateFileA(portName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (hSerial == INVALID_HANDLE_VALUE) {
        std::cerr << "Error opening serial port " << portName << std::endl;
        return false;
    }

    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    if (!GetCommState(hSerial, &dcbSerialParams)) {
        std::cerr << "Error getting state" << std::endl;
        close();
        return false;
    }

    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    if (!SetCommState(hSerial, &dcbSerialParams)) {
        std::cerr << "Error setting state" << std::endl;
        close();
        return false;
    }

    COMMTIMEOUTS timeouts = { 0 };
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;

    if (!SetCommTimeouts(hSerial, &timeouts)) {
        std::cerr << "Error setting timeouts" << std::endl;
        close();
        return false;
    }

    return true;
}

void SerialPort::close() {
    if (hSerial != INVALID_HANDLE_VALUE) {
        CloseHandle(hSerial);
        hSerial = INVALID_HANDLE_VALUE;
    }
}

bool SerialPort::writeData(const std::string& data) {
    DWORD bytesWritten;
    if (!WriteFile(hSerial, data.c_str(), data.size(), &bytesWritten, NULL)) {
        std::cerr << "Error writing to serial port" << std::endl;
        return false;
    }
    return true;
}

std::string SerialPort::readData() {
    char buffer[256];
    DWORD bytesRead;
    if (!ReadFile(hSerial, buffer, sizeof(buffer) - 1, &bytesRead, NULL)) {
        std::cerr << "Error reading from serial port" << std::endl;
        return "";
    }
    buffer[bytesRead] = '\0';
    return std::string(buffer);
}
