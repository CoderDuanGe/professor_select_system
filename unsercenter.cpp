#include "unsercenter.h"
#include "ui_unsercenter.h"
#include "appcenter.h"
#include <QSqlTableModel>
#include <QItemSelectionModel>
#include "dbhelper.h"
#include <QSqlDatabase>

extern QString strAccountInput;

unsercenter::unsercenter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::unsercenter),_sqlModel(new QSqlTableModel)
{
    ui->setupUi(this);

    this->setWindowTitle("用户管理");
    this->setWindowIcon(QIcon("://icon/loginicon.png"));
    initcontrol();

    ui->tableView->setModel(_sqlModel);

    ui->tableView->verticalHeader()->hide();

    if(strAccountInput != "admin")
    {
        ui->tableView->hideRow(0);
    }
    connect(ui->submitBtn, SIGNAL(clicked()), _sqlModel, SLOT(submitAll()));
    connect(ui->cancelBtn, SIGNAL(clicked()), _sqlModel, SLOT(revertAll()));

    _sqlModel->setHeaderData(0,Qt::Horizontal,("账号"));
    _sqlModel->setHeaderData(1,Qt::Horizontal,("密码"));


}

unsercenter::~unsercenter()
{
    delete ui;
}

void unsercenter::initcontrol()
{

    _sqlModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    _sqlModel->setTable("login");
    _sqlModel->select();
}

void unsercenter::addSlot()
{
    QSqlRecord record = _sqlModel->record();
    _sqlModel->insertRecord(-1,record);
}

void unsercenter::deleteSlot()
{
    QItemSelectionModel* selectModel = ui->tableView->selectionModel();
    QModelIndexList list = selectModel->selectedIndexes();
    foreach(QModelIndex index, list)
    {
        _sqlModel->removeRow(index.row());
    }
}


