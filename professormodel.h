#ifndef PROFESSORMODEL_H
#define PROFESSORMODEL_H

#include "professor.h"
#include <QList>
#include <QStandardItemModel>

class ProfessorModel
{
public:
    ProfessorModel();
    QStandardItemModel *model;
    QList<Professor>& controlPfofessonMode(QString path);

    void addProfessor();
    void deleteAllProfessor();

private:
    QList<Professor> m_list;

};

#endif // PROFESSORMODEL_H
