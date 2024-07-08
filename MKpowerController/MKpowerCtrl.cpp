// MKpowerController.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "MKpowerCtrl.h"
#include <iostream>
#include <cmath>

#define DEBUG

MKpowerCtrl::MKpowerCtrl(const std::string& portName) {

    if (!serial.open(portName)) {
#ifdef DEBUG
        std::cerr << "Failed to open serial port" << std::endl;
#endif
    }
#ifdef DEBUG
    std::cout << "Serial port opened successfully" << std::endl;
#endif
}

MKpowerCtrl::~MKpowerCtrl() {

    serial.close();
#ifdef DEBUG
    std::cout << "Serial port closed" << std::endl;
#endif
}

bool MKpowerCtrl::TurnOn(bool nVal) {
    dataToSend = "OUT" + std::to_string(nVal);
    if (serial.writeData(dataToSend)) {
#ifdef DEBUG
        std::cout << "Data sent: " << dataToSend << std::endl;
#endif
        Sleep(50);
        return true;
    }
    else {
#ifdef DEBUG
        std::cerr << "Failed to send data" << std::endl;
#endif
        return false;
    }
}

bool MKpowerCtrl::SetBeep(bool nVal) {
    dataToSend = "BEEP" + std::to_string(nVal);
    if (serial.writeData(dataToSend)) {
#ifdef DEBUG
        std::cout << "Data sent: " << dataToSend << std::endl;
#endif
        Sleep(50);
        return true;
    }
    else {
#ifdef DEBUG
        std::cerr << "Failed to send data" << std::endl;
#endif
        return false;
    }
}

bool MKpowerCtrl::SetCurrent(int nChannel, float nVal) {
    char buf[20];
    sprintf_s(buf, "%.2f", nVal);
    dataToSend = "ISET" + std::to_string(nChannel) + ":" + std::string(buf);
    if (serial.writeData(dataToSend)) {
#ifdef DEBUG
        std::cout << "Data sent: " << dataToSend << std::endl;
#endif
        Sleep(50);
        return true;
    }
    else {
#ifdef DEBUG
        std::cerr << "Failed to send data" << std::endl;
#endif
        return false;
    }

}
bool MKpowerCtrl::SetVoltage(int nChannel, float nVal) {
    char buf[20];
    sprintf_s(buf, "%.2f", nVal);
    dataToSend = "VSET" + std::to_string(nChannel) + ":" + std::string(buf);

    if (serial.writeData(dataToSend)) {
#ifdef DEBUG
        std::cout << "Data sent: " << dataToSend << std::endl;
#endif
        Sleep(50);
        return true;
    }
    else {
#ifdef DEBUG
        std::cerr << "Failed to send data" << std::endl;
#endif
        return false;
    }
}

bool MKpowerCtrl::LoadSet(int nVal) {
    dataToSend = "RCL" + std::to_string(nVal);
    if (serial.writeData(dataToSend)) {
#ifdef DEBUG
        std::cout << "Data sent: " << dataToSend << std::endl;
#endif
        Sleep(50);
        return true;
    }
    else {
#ifdef DEBUG
        std::cerr << "Failed to send data" << std::endl;
#endif
        return false;
    }
}

bool MKpowerCtrl::SaveSet(int nVal) {
    dataToSend = "SAV" + std::to_string(nVal);
    if (serial.writeData(dataToSend)) {
#ifdef DEBUG
        std::cout << "Data sent: " << dataToSend << std::endl;
#endif
        Sleep(50);
        return true;
    }
    else {
#ifdef DEBUG
        std::cerr << "Failed to send data" << std::endl;
#endif
        return false;
    }
}

bool MKpowerCtrl::SetOCP(bool nVal) {
    dataToSend = "OCP" + std::to_string(nVal);
    if (serial.writeData(dataToSend)) {
#ifdef DEBUG
        std::cout << "Data sent: " << dataToSend << std::endl;
#endif
        Sleep(50);
        return true;
    }
    else {
#ifdef DEBUG
        std::cerr << "Failed to send data" << std::endl;
#endif
        return false;
    }
}

bool MKpowerCtrl::SetOVP(bool nVal) {
    dataToSend = "OVP" + std::to_string(nVal);
    if (serial.writeData(dataToSend)) {
#ifdef DEBUG
        std::cout << "Data sent: " << dataToSend << std::endl;
#endif
        Sleep(50);
        return true;
    }
    else {
#ifdef DEBUG
        std::cerr << "Failed to send data" << std::endl;
#endif
        return false;
    }
}


float MKpowerCtrl::GetCurrent(int nChannel) {
    dataToSend = "IOUT" + std::to_string(nChannel)+"?";
    if (serial.writeData(dataToSend)) {
#ifdef DEBUG
        std::cout << "Data sent: " << dataToSend << std::endl;
#endif
        Sleep(50);
    }
    else {
#ifdef DEBUG
        std::cerr << "Failed to send data" << std::endl;
#endif
    }
    receivedData = serial.readData();
    if (!receivedData.empty()) {
#ifdef DEBUG
        std::cout << "Data received: " << receivedData << std::endl;
#endif
        return std::stof(receivedData);
    }
    else {
#ifdef DEBUG
        std::cerr << "No data received or failed to read data" << std::endl;
#endif
        return 0.0;
    }
}

float MKpowerCtrl::GetVoltage(int nChannel) {
    dataToSend = "VOUT" + std::to_string(nChannel) + "?";
    if (serial.writeData(dataToSend)) {
#ifdef DEBUG
        std::cout << "Data sent: " << dataToSend << std::endl;
#endif
        Sleep(50);
    }
    else {
#ifdef DEBUG
        std::cerr << "Failed to send data" << std::endl;
#endif
    }
    receivedData = serial.readData();
    if (!receivedData.empty()) {
#ifdef DEBUG
        std::cout << "Data received: " << receivedData << std::endl;
#endif
        return std::stof(receivedData);
    }
    else {
#ifdef DEBUG
        std::cerr << "No data received or failed to read data" << std::endl;
#endif
        return 0.0;
    }
}

/*
std::string MKpowerCtrl::GetStatus() {
    dataToSend = "STATUS?";
    if (serial.writeData(dataToSend)) {
#ifdef DEBUG
        std::cout << "Data sent: " << dataToSend << std::endl;
#endif
        Sleep(50);
    }
    else {
#ifdef DEBUG
        std::cerr << "Failed to send data" << std::endl;
#endif
    }
    receivedData = serial.readData();
    if (!receivedData.empty()) {
#ifdef DEBUG
        std::cout << "Data received: " << receivedData << std::endl;
#endif
        return receivedData;
    }
    else {
#ifdef DEBUG
        std::cerr << "No data received or failed to read data" << std::endl;
#endif
        return "";
    }
}

std::string MKpowerCtrl::GetIDN() {
    dataToSend = "IDN?";
    if (serial.writeData(dataToSend)) {
#ifdef DEBUG
        std::cout << "Data sent: " << dataToSend << std::endl;
#endif
        Sleep(50);
    }
    else {
#ifdef DEBUG
        std::cerr << "Failed to send data" << std::endl;
#endif
    }
    receivedData = serial.readData();
    if (!receivedData.empty()) {
#ifdef DEBUG
        std::cout << "Data received: " << receivedData << std::endl;
#endif
        return receivedData;
    }
    else {
#ifdef DEBUG
        std::cerr << "No data received or failed to read data" << std::endl;
#endif
        return "";
    }
}
*/