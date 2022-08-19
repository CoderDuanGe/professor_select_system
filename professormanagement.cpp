#include "professormanagement.h"
#include "ui_professormanagement.h"
#include "dbhelper.h"
#include <QItemSelectionModel>
#include <QSqlRecord>
#include <QStandardItemModel>
#include <QCloseEvent>
#include "appcenter.h"


extern QString strAccountInput;

ProfessorManagement::ProfessorManagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfessorManagement), _sqlModel(new QSqlTableModel(this) )
{
    ui->setupUi(this);
    this->setWindowTitle("评委管理");
    this->setWindowIcon(QIcon("://icon/loginicon.png"));
    ui->tableView->setModel(_sqlModel);
    initcontrol();
    if(strAccountInput!="admin")  ui->tableView->hideColumn(5);


    _sqlModel->setHeaderData(0,Qt::Horizontal,"姓名");
    _sqlModel->setHeaderData(1,Qt::Horizontal,"领域");
    _sqlModel->setHeaderData(2,Qt::Horizontal,"职称");
    _sqlModel->setHeaderData(3,Qt::Horizontal,"单位");
    _sqlModel->setHeaderData(4,Qt::Horizontal,"工号");
    _sqlModel->setHeaderData(5,Qt::Horizontal,"是否选定");

}

ProfessorManagement::~ProfessorManagement()
{
    delete ui;
}



void ProfessorManagement::initcontrol()
{
    //DBHelper *p=DBHelper::getInstance();
    _sqlModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    _sqlModel->setTable("pw");
    _sqlModel->select();

    connect(ui->submitBtn, SIGNAL(clicked()), _sqlModel, SLOT(submitAll()));
    connect(ui->cancleBtn, SIGNAL(clicked()), _sqlModel, SLOT(revertAll()));
}


void ProfessorManagement::addSlot()
{
    QSqlRecord record = _sqlModel->record();
    _sqlModel->insertRecord(-1,record);
}

void ProfessorManagement::deleteSlot()
{
    QItemSelectionModel* selectModel = ui->tableView->selectionModel();
    QModelIndexList list = selectModel->selectedIndexes();
    foreach(QModelIndex index, list)
    {
        _sqlModel->removeRow(index.row());
    }
}

void ProfessorManagement::onFilter()
{


    QString s=ui->lineEdit->text();
    const char * select=QString("name='%1'").arg(s).toStdString().c_str();
    _sqlModel->setFilter(QObject::tr(select));
    if(s=="")
    {
        _sqlModel->setTable("pw");
        _sqlModel->select();
    }

    _sqlModel->setHeaderData(0,Qt::Horizontal,"姓名");
    _sqlModel->setHeaderData(1,Qt::Horizontal,"领域");
    _sqlModel->setHeaderData(2,Qt::Horizontal,"职称");
    _sqlModel->setHeaderData(3,Qt::Horizontal,"单位");
    _sqlModel->setHeaderData(4,Qt::Horizontal,"工号");
    _sqlModel->setHeaderData(5,Qt::Horizontal,"是否选定");
    if(strAccountInput!="admin")  ui->tableView->hideColumn(5);
}
