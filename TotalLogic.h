#ifndef TOTALLOGIC_H
#define TOTALLOGIC_H



#include "FaceLogic.h"
#include "SitLogic.h"


enum  totalType{};
class TotalLogic
{
public:
    TotalLogic();


    static totalType judge()
    {
        FacePostureType t1 =FaceLogic::getRtType();
        SitLogic::readOne();
        eSitType t2 =SitLogic::getSitType();

        //�����ȣ���ʱֻ��������Ч
        if(t1>=1&&t1<=3)
        {
            return t2;
        }
        //����������ʱֻ������ʶ����Ч
        else if(t1==8||t1==9)
        {
            return t1;
        }
        //�����ģ��ۺ��ж�
        else
        {

        }

    }

private:
    float weight =0.7;

};

#endif // TOTALLOGIC_H
