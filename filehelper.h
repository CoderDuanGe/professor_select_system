#ifndef FILEHELPER_H
#define FILEHELPER_H
#include <QList>
#include <QString>
#include "professor.h"

class FileHelper
{
public:
    FileHelper();
    ~FileHelper();
    static QList<Professor> getProfessorListFromLocalFile(const QString file);
};

#endif // FILEHELPER_H
