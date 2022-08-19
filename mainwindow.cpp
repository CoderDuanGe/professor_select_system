#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "appcenter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("评委抽取系统");
    this->setWindowIcon(QIcon("://icon/loginicon.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onUserBtnClicked()
{
    unser.reset(new unsercenter);
    unser->show();

}

void MainWindow::onJudgeBtnClicked()
{
    judg.reset(new Judges);
    judg->show();
}

void MainWindow::onProfessorManageClicked()
{
    professor.reset(new ProfessorManagement);
    professor->show();
}

void MainWindow::onShowChoiceProfessor()
{
    professorchoice.reset(new choiceProfessor);
    professorchoice->show();
}

