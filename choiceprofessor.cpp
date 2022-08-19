#include "choiceprofessor.h"
#include "ui_choiceprofessor.h"
#include <QStandardItemModel>
#include "dbhelper.h"
#include <QDebug>
#include <iostream>
#include <QList>
#include <QSqlRecord>
#include <QPdfWriter>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QPainter>


#include <QTime>


QList<Professor> professorData;
int g=0;
int ct=0;


choiceProfessor::choiceProfessor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choiceProfessor),_sqlModel(new QSqlTableModel(this)),modelView(new QStandardItemModel)
{
    ui->setupUi(this);
    ui->candidateTableView->hideColumn(5);
    initcontrol();
    ui->candidateTableView->hideColumn(5);
    ui->candidateTableView->setModel(_sqlModel);
    ui->selectedProfessorTableView->setModel(modelView);
    ui->candidateTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->selectedProfessorTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->candidateTableView->verticalHeader()->hide();

    ct=0;
    g=0;

    this->setWindowTitle("评委抽取");
    this->setWindowIcon(QIcon("://icon/loginicon.png"));
    ui->candidateTableView->setShowGrid(true); //设置显示格子线

    _sqlModel->setHeaderData(0,Qt::Horizontal,("姓名"));
    _sqlModel->setHeaderData(1,Qt::Horizontal,("领域"));
    _sqlModel->setHeaderData(2,Qt::Horizontal,("职称"));
    _sqlModel->setHeaderData(3,Qt::Horizontal,("单位"));
    _sqlModel->setHeaderData(4,Qt::Horizontal,("工号"));


    QStringList strings;
    strings<<"姓名"<<"领域"<<"职称"<<"单位"<<"工号";
    modelView->setHorizontalHeaderLabels(strings);

    QStringList strList;
    DBHelper *p=DBHelper::getInstance();
    p->selectFilter(strList);
    ui->FiltercomboBox->addItem("请选择领域");
    ui->FiltercomboBox->addItems(strList);

    auto gg=professorData.begin();
    for(;gg!=professorData.end();)
    {
        auto tt=gg;
        professorData.erase(tt);
        gg++;
    }

    ui->candidateTableView->hideColumn(5);
}


void choiceProfessor::onSubmitList()
{
    QString sPath = QFileDialog::getSaveFileName(this, tr("另存为"), "/", tr("Text Files (*.pdf)"));
    if(sPath.isEmpty())
    {
        return;
    }
    QFile pdfFile(sPath);
    pdfFile.open(QIODevice::WriteOnly);                 // 打开要写入的pdf文件
    QPdfWriter* pPdfWriter = new QPdfWriter(&pdfFile);  // 创建pdf写入器
    pPdfWriter->setPageSize(QPagedPaintDevice::A4);     // 设置纸张为A4
    pPdfWriter->setResolution(300);                     // 设置纸张的分辨率为300,因此其像素为3508X2479

    int iMargin = 60;                   // 页边距
    pPdfWriter->setPageMargins(QMarginsF(iMargin, iMargin, iMargin, iMargin));

    QPainter* pPdfPainter = new QPainter(pPdfWriter);   // qt绘制工具

    // 标题,居中
    QTextOption option(Qt::AlignHCenter | Qt::AlignVCenter);
    option.setWrapMode(QTextOption::WordWrap);

    // 标题上边留白
    int iTop = 100;

    // 文本宽度2100
    int iContentWidth = 2100;

    // 标题,22号字
    QFont font;
    font.setFamily("simhei.ttf");
    int fontSize = 20;
    font.setPointSize(fontSize);
    pPdfPainter->setFont(font);

    pPdfPainter->drawText(QRect(0, iTop, iContentWidth, 90),
                          QString("灵石县行政审批服务管理局"), option);
    iTop+=100;
    pPdfPainter->drawText(QRect(0, iTop, iContentWidth, 90),
                          QString("专家评审报备表"), option);

    fontSize = 16;
    font.setPointSize(fontSize);
    pPdfPainter->setFont(font);
    option.setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    iTop += 100;
    QString code=ui->projectCodeLineEdit->text();
    pPdfPainter->drawText(QRect(iContentWidth*0.65, iTop, iContentWidth, 60),
                          "编号:"+code);
    iTop+=120;
    pPdfPainter->setPen(2);
    //2750
    pPdfPainter->drawRect(0, iTop, 1980, 2700);//表格矩形方框
    pPdfPainter->drawLine(0,iTop+300,1980,iTop+300);
    pPdfPainter->drawLine(0,iTop+600,1980,iTop+600);
    pPdfPainter->drawLine(0,iTop+900,1980,iTop+900);
    pPdfPainter->drawLine(0,iTop+1500,1980,iTop+1500);
    pPdfPainter->drawLine(0,iTop+1800,1980,iTop+1800);
    pPdfPainter->drawLine(0,iTop+2100,1980,iTop+2100);
    pPdfPainter->drawLine(0,iTop+2400,1980,iTop+2400);
    pPdfPainter->drawLine(495,iTop,495,iTop+2700);

    pPdfPainter->drawLine(990,iTop,990,iTop+600);
    pPdfPainter->drawLine(1485,iTop,1485,iTop+600);

    pPdfPainter->drawText(100,iTop+180,"事项名称");
    pPdfPainter->drawText(1090,iTop+180,"受理时间");
    pPdfPainter->drawText(100,iTop+480,"申请单位");
    pPdfPainter->drawText(1145,iTop+480,"联系人");
    pPdfPainter->drawText(40,iTop+780,"专家评审内容");
    pPdfPainter->drawText(80,iTop+1150,"评审专家、");
    pPdfPainter->drawText(80,iTop+1300,"领域等事项");
    pPdfPainter->drawText(100,iTop+1680,"组织时间");
    pPdfPainter->drawText(80,iTop+1925,"股室负责人");
    pPdfPainter->drawText(180,iTop+2025,"签字");
    pPdfPainter->drawText(80,iTop+2225,"业务股分管");
    pPdfPainter->drawText(100,iTop+2325,"领导签字");


    pPdfPainter->drawText(180,iTop+2575,"备注");


    fontSize = 11;
    font.setPointSize(fontSize);
    pPdfPainter->setFont(font);
    option.setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    QString projectItems=ui->prijectLineEdit->text();
    pPdfPainter->drawText(530,iTop+180,projectItems);

    QString departments=ui->LineEditDepartment->text();
    pPdfPainter->drawText(550,iTop+480,departments);


    QString ftime=ui->LineEditYear_2->text()+"年"+ui->lineEditMonth_2->text()+"月"+ui->lineEditDay_2->text()+"日"+ui->lineEditHours_2->text()+"时";
    pPdfPainter->drawText(1510,iTop+180,ftime);


    QString person=ui->lineEditPerson->text();
    pPdfPainter->drawText(1510,iTop+480,person);

    QString professorTalk=ui->LineEditProfessorTalk->text();
    pPdfPainter->drawText(550,iTop+780,professorTalk);

    QString times=ui->LineEditYear->text()+" 年 "+ui->lineEditMonth->text()+" 月 "+ui->lineEditDay->text()+" 日 "+ui->lineEditHours->text()+" 时 "+" - ";

    QString dtimes=ui->lineEditDyear->text()+" 年 "+ui->lineEditDmonth->text()+" 月 "+ui->lineEditDday->text()+" 日 "+ui->lineEditDhours->text()+" 时 ";

    QString ttime=times+dtimes;
    pPdfPainter->drawText(550,iTop+1680,ttime);

    QString beizhu=ui->lineEditBeizhu->text();
    pPdfPainter->drawText(550,iTop+2575,beizhu);


    int sum=ui->lineEdit->text().toInt();
    int t=1370;int h=1;
    for(int i=1;i<=ct;i++)
    {
        QString name=professorData[i-1].getName();
        QString area=professorData[i-1].getSubProGroup();
        if(i<=8)
        {
            pPdfPainter->drawText(550,t+i*60,name);
            pPdfPainter->drawText(750,t+i*60,area);
        }
        else
        {
            pPdfPainter->drawText(1300,t+h*60,name);
            pPdfPainter->drawText(1500,t+h*60,area);
            h++;
        }

    }

    delete pPdfPainter;
    delete pPdfWriter;
    pdfFile.close();
}



choiceProfessor::~choiceProfessor()
{
    delete ui;
}

void choiceProfessor::initcontrol()
{
    //_sqlModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    _sqlModel->setTable("pw");
    _sqlModel->select();
}

void choiceProfessor::onFilterClicked()
{

    //modelView->clear();
    //    Listqrandom.clear();
    //    ListqtList.clear();


    auto ee=Listqrandom.begin();
    for(;ee!=Listqrandom.end();)
    {
        auto tt=ee;
        Listqrandom.erase(tt);
        ee++;
    }

    auto mm=Listq.begin();
    for(;mm!=Listq.end();)
    {
        auto tt=mm;
        Listq.erase(tt);
        mm++;
    }


    QString s=ui->FiltercomboBox->currentText();
    std::string s2=QString("subprogroup='%1'").arg(s).toStdString();
    //qDebug()<<s2;
    _sqlModel->setFilter(QObject::tr(s2.c_str()));
    //_sqlModel->select();
    Professor t;
    row=_sqlModel->rowCount();
    for(int i=0;i<row;i++)
    {

        t.setName(_sqlModel->record(i).value(0).toString());
        t.setSubProGroup(_sqlModel->record(i).value(1).toString());
        t.setJob(_sqlModel->record(i).value(2).toString());
        t.setDepartment(_sqlModel->record(i).value(3).toString());
        t.setCode(_sqlModel->record(i).value(4).toInt());
        t.setSelected(_sqlModel->record(i).value(5).toInt());
        if(_sqlModel->record(i).value(5).toInt()==1) Listq.append(t);
        else Listqrandom.append(t);
    }


    ui->candidateTableView->hideColumn(5);
    qDebug()<<"end";
}



QList<int> & choiceProfessor::getRandom(int number)
{
    QList<int> list;
    list.clear();

    result.clear();
    list.reserve(number);
    result.reserve(number);
    srand((int)time(0));
    for (int i = 0; i < number; i++)
    {
        list.push_back(i);
    }
    int length = list.size();
    for (int i = 0; i < length; i++)
    {
        int index = rand() % list.size();
        result.push_back(list[index]);
        list.erase(list.begin() + index);
    }
    return result;
}


void choiceProfessor::sumCandidateProfessor()
{

    //ui->selectedProfessorTableView->hideColumn(0);
    //产生多少个随机数
    int number=Listqrandom.size()>0?Listqrandom.size():0;
    qDebug()<<"number:"<<number;
    getRandom(number);
    int tt=ui->lineEdit->text().toInt();
    int f=tt-Listq.size();

    for(int i=0;i<f;i++)
    {
        int n=result[i];
        Listq.append(Listqrandom.at(n));
    }

    auto cc=ListqtList.begin();
    for(;cc!=ListqtList.end();)
    {
        auto tt=cc;
        ListqtList.erase(tt);
        cc++;
    }






    getRandom(Listq.size());
    for(int i=0;i<result.size();i++)
    {
        int n=result[i];
        ListqtList.append(Listq.at(n));
    }

    for(auto t:ListqtList)
    {
        qDebug()<<t.getName();
    }


    int sum=ui->lineEdit->text().toInt();
    int j=1;
    auto itr=ListqtList.begin();
    for(int i=0;i<sum;i++)
    {
        QString code=QString::number(itr->getCode());
        modelView->setItem(g,0,new QStandardItem(itr->getName()));
        modelView->setItem(g,1,new QStandardItem(itr->getSubProGroup()));
        modelView->setItem(g,2,new QStandardItem(itr->getJob()));
        modelView->setItem(g,3,new QStandardItem(itr->getDepartment()));
        modelView->setItem(g,4,new QStandardItem(code));
        professorData.append(*itr);
        itr++;
        g++;
        ct++;
    }

}
