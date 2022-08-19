#include "judges.h"
#include "ui_judges.h"
#include <QMainWindow>
#include <QScopedPointer>
#include <QList>
#include <QVariant>
#include "ExcelBase.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QTableView>
#include "filehelper.h"
#include "professormodel.h"
#include "appcenter.h"

Judges::Judges(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Judges),
    m_proFessorMode(new ProfessorModel)
{
    ui->setupUi(this);
    this->setWindowTitle("评委信息导入");
    this->setWindowIcon(QIcon("://icon/loginicon.png"));
    //setWindowState(this->windowState() ^ Qt::WindowFullScreen);
    ui->tableView->setModel(m_proFessorMode->model);
    //ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);



    m_proFessorMode->model->setHeaderData(0,Qt::Horizontal,("姓名"));
    m_proFessorMode->model->setHeaderData(1,Qt::Horizontal,("领域"));
    m_proFessorMode->model->setHeaderData(2,Qt::Horizontal,("职称"));
    m_proFessorMode->model->setHeaderData(3,Qt::Horizontal,("单位"));
    m_proFessorMode->model->setHeaderData(4,Qt::Horizontal,("工号"));

}

Judges::~Judges()
{
    delete ui;
    delete m_proFessorMode;
}

void Judges::onImportDataBtnClicked()
{
    QString path= QFileDialog::getOpenFileName(this,QString(),QString(),"excel(*.xls *.xlsx)");
    if(path.isEmpty())
        return;
    m_proFessorMode->controlPfofessonMode(path);
}

void Judges::onAddSqLiteClicked()
{
    m_proFessorMode->addProfessor();
    QMessageBox::information(this, tr("数据导入"),
                             tr("数据导入成功"),
                             QMessageBox::Ok);

}

void Judges::onDeleteAllProfessorSqLiteClicked()
{
    m_proFessorMode->deleteAllProfessor();
    QMessageBox::information(this, tr("清空数据"),
                             tr("数据清空成功！"),
                             QMessageBox::Ok);
}

