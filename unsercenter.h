#ifndef UNSERCENTER_H
#define UNSERCENTER_H

#include <QDialog>
#include <QSqlQuery>


#include <QSqlError>
#include <QSqlRecord>

class QTableView;
class QSqlTableModel;

namespace Ui {
class unsercenter;
}

class unsercenter : public QDialog
{
    Q_OBJECT

public:
    explicit unsercenter(QWidget *parent = nullptr);
    ~unsercenter();

    void initcontrol();
private slots:
    void addSlot();
    void deleteSlot();


private:
    Ui::unsercenter *ui;
    QSqlTableModel* _sqlModel;

};

#endif // UNSERCENTER_H
