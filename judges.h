#ifndef JUDGES_H
#define JUDGES_H

#include <QDialog>
#include <QStandardItemModel>
#include "ExcelBase.h"
#include "professormodel.h"

namespace Ui {
class Judges;
}

class Judges : public QDialog
{
    Q_OBJECT

public:
    explicit Judges(QWidget *parent = nullptr);
    ~Judges();

private slots:
    void onImportDataBtnClicked();
    void onAddSqLiteClicked();
    void onDeleteAllProfessorSqLiteClicked();

private:

    Ui::Judges *ui;
    ProfessorModel *m_proFessorMode;
};

#endif // JUDGES_H
