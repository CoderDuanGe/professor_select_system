#include "dbhelper.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "professor.h"

DBHelper *DBHelper::m_instance = NULL;

DBHelper::DBHelper()
{
    open();
}

DBHelper* DBHelper::getInstance()
{
    if (m_instance == NULL)
    {
        m_instance = new DBHelper;
    }
    return m_instance;
}

DBHelper::~DBHelper()
{
    close();
}

bool DBHelper::open()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    if( !db.open())
    {
        qDebug() <<"can not create sqlite connection";
    }
    else
    {
        m_db.reset(&db);
        return true;
    }
    return false;
}

void DBHelper::close()
{
    m_db->close();
}

QSqlDatabase DBHelper::getSqlDatabase() const
{
    //m_db.get() ==> QSqlDatabase* 类型的
    return *(m_db.get());
}

bool DBHelper::selectLogin(QString& user, QString& passwd)
{
    QSqlQuery query;
    query.exec(QString("SELECT passwd FROM login WHERE username='%1'").arg(user));
    if(query.seek(0))
    {
        QString password = query.value(0).toString();
        if(password==passwd) return true;
    }
    return false;
}

bool DBHelper::addProfessor(QString name, QString subProGroup, QString job, QString department, int code, int selected)
{
    QSqlQuery query;
    query.prepare("insert into pw(name,subprogroup,job,department,code,selectd)" "values(:BB,:CC,:DD,:EE,:FF,:GG)");//5个类型
    query.bindValue(":BB",name);
    query.bindValue(":CC",subProGroup);
    query.bindValue(":DD",job);
    query.bindValue(":EE",department);
    query.bindValue(":FF",code);
    query.bindValue(":GG",0);
    if(query.exec()) return true;
    return false;
}

bool DBHelper::deleteAllProfessor()
{
    QSqlQuery query;
    if(query.exec(QString("delete FROM pw"))) return true;
    else return false;
}

int DBHelper::selectAreaProfessor(QString s,QList<Professor>& strlist)
{
    QSqlQuery query;
    int sum=0;
    Professor professor;
    query.exec(QString("select * from pw where subprogroup='%1'").arg(s));
    while(1)
    {
        if(query.next())
        {
            sum++;
        }
    }
    return sum;
}

int DBHelper::countSelectedProfessor(QString s)
{
    QSqlQuery query;int sum=0;
    query.exec(QString("select count(*) from pw where='%1' and selectd=1 ").arg(s));
    {
        while(1)
        {
            if(query.next())
            {
                sum++;
            }
            return sum;
        }
    }
    return 0;
}

QList<Professor> &DBHelper::alreadyselectAreaProfessor(QString s, QList<Professor> &strlist)
{
    QSqlQuery query;
    Professor professor;
    query.exec(QString("select * from pw where subprogroup='%1' and selectd=1 ").arg(s));
    while(1)
    {
        if(query.next())
        {
            QString b=query.value(0).toString();
            QString c=query.value(1).toString();
            QString d=query.value(2).toString();
            QString e=query.value(3).toString();
            int f=query.value(4).toInt();
            int g=query.value(5).toInt();

            professor.setName(b);
            professor.setSubProGroup(c);
            professor.setJob(d);
            professor.setDepartment(e);
            professor.setCode(f);
            professor.setSelected(g);

            strlist.append(professor);
        }
    }
    return strlist;
}

QStringList& DBHelper::selectFilter(QStringList&  t)
{
    QSqlQuery query;
    query.exec("select distinct subprogroup from pw");
    while(1)
    {
        if(query.next())
        {
            QString s=query.value(0).toString();
            t.append(s);
        }
        else
        {
            return t;
        }
    }


}


