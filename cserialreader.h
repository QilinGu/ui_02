#ifndef CSERIALREADER_H
#define CSERIALREADER_H
#include <QSerialPort>
#include <cv.h>
#include <QString>
#include <QList>

/**
    单例模式： 串口通信类（只读）
    使用方法： 先获取单例，open（）--> connectDevice() --> readSerial -->closeSerial().
    唯一有用的接口： readSerial（）
    所有错误都以异常抛出


*/

class CSerialReader
{
public:
    static CSerialReader* getReader();
    void OpenSerial();
    void CloseSerial();
    const QList<QList<int> > ReadSerial();
    void ConnectDevice(const QString & cDevAddr = "0x00158300428D");
    bool isConnected();

private:
    QSerialPort m_iPort;
    static CSerialReader* m_pReader;

private:
    CSerialReader();
    const QList<QList<int> > __ParseData(const QStringList & iStringList);

};

#endif // CSERIALREADER_H
