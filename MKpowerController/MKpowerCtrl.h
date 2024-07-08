
#include "SerialPort.h"

class MKpowerCtrl {
public:
    SerialPort serial;
    MKpowerCtrl(const std::string& portName);
    ~MKpowerCtrl();

    bool SetCurrent(int nChannel, float nVal);
    bool SetVoltage(int nChannel, float nVal);
    bool SetBeep(bool nVal);
    
    bool TurnOn(bool nVal);

    bool LoadSet(int nVal);
    bool SaveSet(int nVal);

    bool SetOCP(bool nVal);
    bool SetOVP(bool nVal);

    float GetCurrent(int nChannel);
    float GetVoltage(int nChannel);

    //std::string GetStatus();
    //std::string GetIDN();



private:
    
    std::string portName;
    std::string dataToSend;
    std::string receivedData;
};