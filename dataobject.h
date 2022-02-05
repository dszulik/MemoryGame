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
    Q_PROPERTY(QString isWin READ isWin WRITE setIsWin NOTIFY isWinChanged)
    Q_PROPERTY(QString colFront READ colFront WRITE setColFront NOTIFY colFrontChanged)
    Q_PROPERTY(QString colBack READ colBack WRITE setColBack NOTIFY colBackChanged)

public:
    DataObject(QObject *parent = 0);
    DataObject(const QString &name, const QString &zrodlo, const bool &flipped, const QString &isWin, const QString &colFront, const QString &colBack, QObject *parent = 0);

    QString name();
    void setName(const QString &name);

    QString zrodlo();
    void setZrodlo(const QString &zrodlo);

    Q_INVOKABLE bool flipped();
    Q_INVOKABLE void setFlipped(const bool &flipped);
    Q_INVOKABLE void setFlippedToFalse(const bool &flipped);

    QString isWin();
    void setIsWin(const QString &isWin);

    QString colFront();
    void setColFront(const QString &colFront);

    QString colBack();
    void setColBack(const QString &colBack);

signals:
    void nameChanged();
    void zrodloChanged();
    void flippedChanged(bool flip);
    void isWinChanged();
    void colFrontChanged(QString colF);
    void colBackChanged(QString colB);

private:
    QString m_name;
    QString m_zrodlo;
    bool m_flipped;
    QString m_isWin;
    QString m_colFront;
    QString m_colBack;
};

#endif
