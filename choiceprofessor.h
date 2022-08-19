#ifndef CHOICEPROFESSOR_H
#define CHOICEPROFESSOR_H

#include <QDialog>
#include <QSqlTableModel>
#include "professor.h"
#include <QSet>
#include <memory>


class printProfessor;
class QStandardItemModel;



namespace Ui {
class choiceProfessor;
}

class choiceProfessor : public QDialog
{
    Q_OBJECT

public:
    explicit choiceProfessor(QWidget *parent = nullptr);
    ~choiceProfessor();
     void initcontrol();

     int row;
     QList<Professor> sumProfessorSelected;
     printProfessor *printPro;


public slots:
     void onFilterClicked();

     void onSubmitList();

     QList<int>& getRandom(int number);
     void sumCandidateProfessor();


private:
    Ui::choiceProfessor *ui;
    QSqlTableModel* _sqlModel;
    QStandardItemModel *modelView;

    QList<Professor> Listqrandom;
    QList<int> result;

    QList<Professor> Listq;
    QString projectItem;
    int sumItem;
    QString projectCode;


    QList<Professor> ListqtList;



};

#endif // CHOICEPROFESSOR_H
