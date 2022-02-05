#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QObject>
#include <dataobject.h>

class GameLogic : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int counter READ counter WRITE setCounter NOTIFY counterChanged) // this makes counter available as a QML property
    Q_PROPERTY(int points READ points WRITE setPoints NOTIFY pointsChanged)     // this makes points available as a QML property

public:
    GameLogic();
    int counter() const;        // getter
    void setCounter(int value); // setter
    int points() const;         // getter
    void setPoints(int value);  // setter

private:
    int m_counter; // initialize private variable (with default value) that can be only modified if getter is used
    int m_points;  // initialize private variable (with default value) that can be only modified if getter is used

signals: // signals are sent from C++ to QML
    void counterChanged();
    void pointsChanged(QString xd);
    void win();

public slots: // slots are public methods available in QML
    void checkVisibility(QList<QObject *> model);
    void restart(QList<QObject *> model);
};

#endif // GAMELOGIC_H
