#include "MKpowerCtrl.h"

int main()
{
    //객체 생성 시 COM PORT 입력
    MKpowerCtrl mkCtrl("COM9");

    //파워 출력 끄기
    mkCtrl.TurnOn(FALSE);
    Sleep(3000);

    //출력할 전압값 입력
    mkCtrl.SetVoltage(1, 23.5);
    Sleep(3000);
    //출력할 전압값 입력
    mkCtrl.SetVoltage(1, 24);
    Sleep(3000);
    //출력할 전류값 입력
    mkCtrl.SetCurrent(1, 2);
    Sleep(3000);
    //출력할 전류값 입력
    mkCtrl.SetCurrent(1, 1.2);
    Sleep(3000);
    //파워 출력 켜기
    mkCtrl.TurnOn(TRUE);
    Sleep(3000);

    //실제 출력되는 전류값 읽기
    mkCtrl.GetCurrent(1);
    Sleep(3000);
    //실제 출력되는 전압값 읽기
    mkCtrl.GetVoltage(1);

    //파워 출력 끄기
    mkCtrl.TurnOn(FALSE);

    return 0;
}

