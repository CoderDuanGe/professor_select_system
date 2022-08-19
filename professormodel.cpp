#include "professormodel.h"
#include "filehelper.h"
#include "dbhelper.h"
ProfessorModel::ProfessorModel()
{
    model=new QStandardItemModel;


    model->setColumnCount(5);

    model->setHeaderData(0,Qt::Horizontal,"姓名");
    model->setHeaderData(1,Qt::Horizontal,"领域");
    model->setHeaderData(2,Qt::Horizontal,"职称");
    model->setHeaderData(3,Qt::Horizontal,"单位");
    model->setHeaderData(3,Qt::Horizontal,"工号");

}

QList<Professor>& ProfessorModel::controlPfofessonMode(QString path)
{
    m_list=FileHelper::getProfessorListFromLocalFile(path);
    int m=0,n=0;
    for(auto i:m_list)
    {
        QString ID=QString::number(m+1);
        QString CODE=QString::number(i.getCode());
        model->setItem(m,n,new QStandardItem(i.getName()));
        model->setItem(m,++n,new QStandardItem(i.getSubProGroup()));
        model->setItem(m,++n,new QStandardItem(i.getJob()));
        model->setItem(m,++n,new QStandardItem(i.getDepartment()));
        model->setItem(m,++n,new QStandardItem(CODE));
        m++;
        n=0;
    }
    return m_list;
}

void ProfessorModel::addProfessor()
{
    int m=0,n=0;
    for(auto i:m_list)
    {
        DBHelper *p=DBHelper::getInstance();
        //int id,QString name,QString subProGroup,QString job,QString department,int code,int selected
        p->addProfessor(i.getName(),i.getSubProGroup(),i.getJob(),i.getDepartment(),i.getCode(),0);
    }
}

void ProfessorModel::deleteAllProfessor()
{
    DBHelper *t=DBHelper::getInstance();
    t->deleteAllProfessor();
}
