#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <QObject>

//![0]
class DataObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString zrodlo READ zrodlo WRITE setZrodlo NOTIFY zrodloChanged)
//![0]

public:
    DataObject(QObject *parent=0);
    DataObject(const QString &name, const QString &zrodlo, QObject *parent=0);

    QString name() const;
    void setName(const QString &name);

    QString zrodlo() const;
    void setZrodlo(const QString &zrodlo);

signals:
    void nameChanged();
    void zrodloChanged();

private:
    QString m_name;
    QString m_zrodlo;
//![1]
};
//![1]

#endif // DATAOBJECT_H
