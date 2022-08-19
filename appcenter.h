#ifndef APPCENTER_H
#define APPCENTER_H

#include <QObject>
#include <memory>

class login;
class MainWindow;
class unsercenter;
class Judges;
class ProfessorManagement;
class choiceProfessor;
class unsercenter;


class AppCenter: public QObject
{
    Q_OBJECT
public:
    static AppCenter* getInstance();
    ~AppCenter();
    void run();
    void showLoginWindow();
    void hideLoginWindow();
    void showMainWindow();
    void hideMainWindow();



signals:
    void sigShowMainWindow();



private:
    AppCenter();
    std::unique_ptr<login>           log;
    std::unique_ptr<MainWindow> mainwindow;


};

#endif // APPCENTER_H
