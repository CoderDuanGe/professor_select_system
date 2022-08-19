#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <QString>

// 专家类
class Professor
{
public:
    Professor();


    void setName(QString name);
    QString getName();

    void setSubProGroup(QString subProGroup);
    QString getSubProGroup();

    void setJob(QString job);
    QString getJob();

    void setDepartment(QString department);
    QString getDepartment();

    void setCode(int code );
    int getCode();

    void setSelected(int select);
    int getSelected();






private:
    // 表的各个字段
    QString name;
    QString subprogroup;
    QString job;
    QString department;
    int code;
    int selected;



};

#endif // PROFESSOR_H
