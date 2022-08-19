#ifndef DBHELPER_H
#define DBHELPER_H

class QSqlDatabase;
class Professor;
#include <memory>
#include <QString>

class QSqlDatabase;
class DBHelper
{
public:
    static DBHelper* getInstance();

    ~DBHelper();
    bool open();
    void close();
    QSqlDatabase getSqlDatabase() const;
    // 对表的增删改查接口
    bool selectLogin(QString& user,QString& passwd);
    bool addProfessor(QString name,QString subProGroup,QString job,QString department,int code,int selected);
    bool deleteAllProfessor();

    int selectAreaProfessor(QString s,QList<Professor>& strlist);

    int countSelectedProfessor(QString s);

    QList<Professor>& alreadyselectAreaProfessor(QString s,QList<Professor>& strlist);



    QStringList& selectFilter(QStringList& t);



private:
    DBHelper();
    static DBHelper *m_instance;
    std::shared_ptr<QSqlDatabase> m_db;

};

#endif // DBHELPER_H
