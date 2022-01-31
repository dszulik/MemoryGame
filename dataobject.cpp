#include <QDebug>
#include "dataobject.h"
#include <iostream>
#include <QEvent>

DataObject::DataObject(QObject *parent)
    : QObject(parent)
{
}

DataObject::DataObject(const QString &name, const QString &zrodlo, const bool &flipped, QObject *parent)
    : QObject(parent), m_name(name), m_zrodlo(zrodlo), m_flipped(flipped)
{
}

QString DataObject::name()
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

QString DataObject::zrodlo()
{
    return m_zrodlo;
}

void DataObject::setZrodlo(const QString &zrodlo)
{
    if (zrodlo != m_zrodlo) {
        m_zrodlo = zrodlo;
        std::cout << "zrodlo works";
        emit zrodloChanged();
    }
}

bool DataObject::flipped()
{

    return m_flipped;
}

void DataObject::setFlipped(const bool &flipped)
{
    if (flipped != m_flipped) {
        m_flipped = flipped;
        std::cout << "flipped works";
        emit flippedChanged();
    }
}

