#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <appcenter.h>
#include "dbhelper.h"
#include <QDebug>
#include "professor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "prijectPw_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    QList<Professor>qlists;

    AppCenter::getInstance()->run();





    return a.exec();
}
