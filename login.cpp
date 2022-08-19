#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <QMessageBox>
#include "appcenter.h"
#include "dbhelper.h"
#include <QSqlQuery>

QString strAccountInput;

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setFixedSize(600, 400);
    this->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
    this->setWindowTitle("评委抽取系统");
    this->setWindowIcon(QIcon("://icon/loginicon.png"));
}

login::~login()
{
    delete ui;
}



void login::onLoginBtnClicked()
{
    strAccountInput=ui->lineEdit_name->text();
    QString strCodeInput =ui->lineEdit_password->text();

    DBHelper *p=DBHelper::getInstance();
    if(p->selectLogin(strAccountInput,strCodeInput ))
    {
        emit AppCenter::getInstance()->sigShowMainWindow();
        this->close();
    }
    else
    {
        QMessageBox dialog_login;
        dialog_login.setText(QStringLiteral("登录密码错误，请检查是否输入错误或点击忘记密码"));
        dialog_login.setWindowTitle(QStringLiteral("登录错误")) ;
        dialog_login.setFixedSize(300,100);
        dialog_login.exec();
    }
}

void login::forgetClicked()
{
    QMessageBox dialog_forget_password;

    dialog_forget_password.setText(QStringLiteral("请联系管理员找回密码"));
    dialog_forget_password.setWindowTitle(QStringLiteral("忘记密码")) ;
    dialog_forget_password.setFixedSize(300,100);
    dialog_forget_password.exec();
}
