#include"mainwindow.h"
#include"login.h"
#include "appcenter.h"
#include "unsercenter.h"
#include "judges.h"
#include "dbhelper.h"
#include "professormanagement.h"
#include "choiceprofessor.h"
AppCenter::AppCenter()
{
    log.reset(new login);
    mainwindow.reset(new MainWindow);


    connect(this, &AppCenter::sigShowMainWindow, this, &AppCenter::showMainWindow);
}

AppCenter *AppCenter::getInstance()
{
    static AppCenter appcenter;
    return &appcenter;
}

AppCenter::~AppCenter()
{

}

void AppCenter::run()
{
    showLoginWindow();
}

void AppCenter::showLoginWindow()
{
    log->show();
}

void AppCenter::hideLoginWindow()
{
    log->close();
}

void AppCenter::showMainWindow()
{
    mainwindow->show();
}

void AppCenter::hideMainWindow()
{
    mainwindow->hide();
}


