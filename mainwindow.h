#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "unsercenter.h"
#include "professormanagement.h"
#include "choiceprofessor.h"
#include "judges.h"
#include <memory>
#include "unsercenter.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onUserBtnClicked();
    void onJudgeBtnClicked();
    void onProfessorManageClicked();
    void onShowChoiceProfessor();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<unsercenter> unser;
    std::unique_ptr<Judges> judg;
    std::unique_ptr<ProfessorManagement> professor;
    std::unique_ptr<choiceProfessor> professorchoice ;
};
#endif // MAINWINDOW_H
