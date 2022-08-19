#include "filehelper.h"
#include <QtXlsx>
#include "professor.h"
class Professor;

FileHelper::FileHelper()
{

}

FileHelper::~FileHelper()
{

}

QList<Professor> FileHelper::getProfessorListFromLocalFile(const QString file)
{
    QXlsx::Document xlsx(file);
    QXlsx::CellRange range = xlsx.dimension();
    int rowCounts = range.lastRow ();
    int colCounts = range.lastColumn ();
    qDebug()<<rowCounts;
    qDebug()<<colCounts;
    QList<Professor> lists;
    Professor professor;
    for(int i=1;i<=rowCounts-2;i++)
    {
        QVariant a = xlsx.read (i+2,1);//读取文件相应的行列（注意xlsx读取的文件的起始行列从1开始）
        QVariant b = xlsx.read (i+2,2);
        QVariant c = xlsx.read (i+2,3);
        QVariant d = xlsx.read (i+2,4);
        QVariant e = xlsx.read (i+2,5);
        professor.setName(a.toString());
        professor.setSubProGroup(b.toString());
        professor.setJob(c.toString());
        professor.setDepartment(d.toString());
        professor.setCode(e.toInt());
        professor.setSelected(0);
        lists.append(professor);
    }
    return lists;
}
