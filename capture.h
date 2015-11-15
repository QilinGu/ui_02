#ifndef CAPTURE
#define CAPTURE

#include <iostream>
#include <vector>
#include <QImage>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <fstream>
using namespace std;


//������ͷ
string openCamera();

//������ͷץȡ��Ƭ
string capture();

//�ر�����ͷ
void closeCamera();

//ץȡͼƬ������qt��ʽ��ͼƬ
QImage detect();

//��β�������رմ򿪵�opencv����
void exitApp();

//���߷�����������ת���ַ���
string int2str(int n);

//���߷�������Դ�ַ����и���ַ���vector
vector<string> split(const string& src, string delimit, string null_subst="");

//�Ƿ���������ͷ��
bool isAllowCameraOpen();

//��������ͷ��
void allowCameraOpen();

QImage cvMat2QImage(const cv::Mat& mat);

cv::Mat QImage2cvMat(QImage image);
#endif // CAPTURE

