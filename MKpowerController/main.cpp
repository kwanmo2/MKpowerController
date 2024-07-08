#include "MKpowerCtrl.h"

int main()
{
    //��ü ���� �� COM PORT �Է�
    MKpowerCtrl mkCtrl("COM9");

    //�Ŀ� ��� ����
    mkCtrl.TurnOn(FALSE);
    Sleep(3000);

    //����� ���а� �Է�
    mkCtrl.SetVoltage(1, 23.5);
    Sleep(3000);
    //����� ���а� �Է�
    mkCtrl.SetVoltage(1, 24);
    Sleep(3000);
    //����� ������ �Է�
    mkCtrl.SetCurrent(1, 2);
    Sleep(3000);
    //����� ������ �Է�
    mkCtrl.SetCurrent(1, 1.2);
    Sleep(3000);
    //�Ŀ� ��� �ѱ�
    mkCtrl.TurnOn(TRUE);
    Sleep(3000);

    //���� ��µǴ� ������ �б�
    mkCtrl.GetCurrent(1);
    Sleep(3000);
    //���� ��µǴ� ���а� �б�
    mkCtrl.GetVoltage(1);

    //�Ŀ� ��� ����
    mkCtrl.TurnOn(FALSE);

    return 0;
}

