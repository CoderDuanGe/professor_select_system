#include "professor.h"

Professor::Professor()
{

}


void Professor::setName(QString name)
{
    this->name=name;
}

QString Professor::getName()
{
    return this->name;
}

void Professor::setSubProGroup(QString subProGroup)
{
    this->subprogroup=subProGroup;
}

QString Professor::getSubProGroup()
{
    return this->subprogroup;
}

void Professor::setJob(QString job)
{
    this->job=job;
}

QString Professor::getJob()
{
    return this->job;
}

void Professor::setDepartment(QString department)
{
    this->department=department;
}

QString Professor::getDepartment()
{
    return this->department;
}

void Professor::setCode(int code)
{
    this->code=code;
}

int Professor::getCode()
{
    return this->code;
}

void Professor::setSelected(int select)
{
    this->selected=select;
}

int Professor::getSelected()
{
    return selected;
}
