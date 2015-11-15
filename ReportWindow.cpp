#include "ReportWindow.h"
#include "ui_ReportWindow.h"
#include <QStandardItemModel>
#include "capture.h"
ReportWindow::ReportWindow(QWidget *parent, vector<Report> reportSet) :
    QMainWindow(parent),
    ui(new Ui::ReportWindow)
{
    ui->setupUi(this);

    setTable(reportSet);

}

ReportWindow::~ReportWindow()
{
    delete ui;
}

void ReportWindow::setTable(vector<Report> reportSet)
{
    QStandardItemModel  *model = new QStandardItemModel();

    model->setColumnCount(4);

    model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("��������"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("��ʼʱ��"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("����ʱ��"));
    model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("����ʱ��(sec)"));



    ui->tableView->setModel(model);

    //��ͷ��Ϣ��ʾ����

    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

    //�����п��ɱ�

    ui->tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Fixed);

    ui->tableView->setColumnWidth(0,101);
    ui->tableView->setColumnWidth(1,102);
    ui->tableView->setColumnWidth(2,102);
    ui->tableView->setColumnWidth(3,102);

    //ע���ڽ��б������ʱ�����ǡ�ui->tableView->setModel(model);����ǰ�����Ծ��������ں�

    // ��֮�����ò�����Ч��������������ʾ��

    // ��������У��������һ������Ϣ����
     for(int i = 0; i < reportSet.size(); i++)
     {
         Report report =reportSet[i];

         model->setItem(i,0,new QStandardItem(report.type.c_str()));
            //�����ַ���ɫ
         model->item(i,0)->setForeground(QBrush(QColor(255, 0, 0)));
            //�����ַ�λ��
         model->item(i,0)->setTextAlignment(Qt::AlignCenter);
         model->setItem(i,1,new QStandardItem(report.start.c_str()));
         model->setItem(i,2,new QStandardItem(report.end.c_str()));
         model->setItem(i,3,new QStandardItem(int2str(report.duration).c_str()));
     }
    //�ġ�ɾ���У�
    //x��ָ��ɾ����һ��
    //model->removeRow(x);
    //ɾ��������
    //model->removeRows(0,model->rowCount());

}
