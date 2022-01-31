#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <QObject>
#include <QEvent>

class DataObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString zrodlo READ zrodlo WRITE setZrodlo NOTIFY zrodloChanged)
    Q_PROPERTY(bool flipped READ flipped WRITE setFlipped NOTIFY flippedChanged)

public:
    Q_INVOKABLE
    DataObject(QObject *parent=0);
    DataObject(const QString &name, const QString &zrodlo, const bool &flipped, QObject *parent=0);

    QString name();
    void setName(const QString &name);

    QString zrodlo();
    void setZrodlo(const QString &zrodlo);

    bool flipped();
    void setFlipped(const bool &flipped);

signals:
    void nameChanged();
    void zrodloChanged();
    void flippedChanged();

private:
    QString m_name;
    QString m_zrodlo;
    bool m_flipped;
};
#endif
