#ifndef PROFESSORMANAGEMENT_H
#define PROFESSORMANAGEMENT_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class ProfessorManagement;
}

class ProfessorManagement : public QDialog
{
    Q_OBJECT

public:
    explicit ProfessorManagement(QWidget *parent = nullptr);
    ~ProfessorManagement();
    void initcontrol();



public slots:
    void addSlot();
    void deleteSlot();

    void onFilter();

private:
    Ui::ProfessorManagement *ui;
    QSqlTableModel* _sqlModel;
};

#endif // PROFESSORMANAGEMENT_H
