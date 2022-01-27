#include <QDebug>
#include "dataobject.h"

DataObject::DataObject(QObject *parent)
    : QObject(parent)
{
}

DataObject::DataObject(const QString &name, const QString &zrodlo, QObject *parent)
    : QObject(parent), m_name(name), m_zrodlo(zrodlo)
{
}

QString DataObject::name() const
{
    return m_name;
}

void DataObject::setName(const QString &name)
{
    if (name != m_name) {
        m_name = name;
        emit nameChanged();
    }
}



QString DataObject::zrodlo() const
{
    return m_zrodlo;
}

void DataObject::setZrodlo(const QString &zrodlo)
{
    if (zrodlo != m_zrodlo) {
        m_zrodlo = zrodlo;
        emit zrodloChanged();
    }
}
