#include "gamelogic.h"
#include <QDebug>
#include <iostream>
#include <ostream>
#include <dataobject.h>

using namespace std;

GameLogic::GameLogic() : m_counter(0)
{
    // perform custom initialization steps here
}

void GameLogic::doSomething()
{
    //qDebug() << "GameLogic test";
}

void GameLogic::checkVisibility(QList<QObject *> model)
{
    for (int i = 0; i < model.size(); i++)
    {
        DataObject *obj = qobject_cast<DataObject *>(model[i]);
        //cout << obj -> flipped();
        cout << "Object fliped: " << obj -> flipped() << "\n";

    }
    //qDebug() << model;
}

int GameLogic::counter() const
{
    return m_counter;
}

void GameLogic::setCounter(int value)
{
    if (m_counter != value)
    {
        m_counter = value;
        emit counterChanged(); // trigger signal of counter change
    }
}
