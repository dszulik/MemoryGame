#include "gamelogic.h"
#include <QDebug>
#include <iostream>
#include <ostream>
#include "dataobject.h"
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <vector>

using namespace std;

vector<QString> vectorToCompare;

GameLogic::GameLogic() : m_counter(0), m_points(0)
{
    // perform custom initialization steps here
}

void GameLogic::checkVisibility(QList<QObject *> model)
{
    setCounter(0);
    vectorToCompare.clear();
    vectorToCompare.push_back("tempOne");
    vectorToCompare.push_back("tempTwo");
    vectorToCompare.push_back("tempThree");

    for (int i = 0; i < model.size(); i++)
    {
        DataObject *obj = qobject_cast<DataObject *>(model[i]);

        if ((obj->flipped() == true) && (obj->isWin() != "win"))
        {
            setCounter(counter() + 1);
            vectorToCompare.at(counter() - 1) = obj->zrodlo();
        }
    }

    if (vectorToCompare.at(0) == vectorToCompare.at(1))
    {
        if (counter() == 2)
        {
            for (int j = 0; j < model.size(); j++)
            {
                DataObject *obj = qobject_cast<DataObject *>(model[j]);

                if (obj->zrodlo() == vectorToCompare.at(0))
                {
                    obj->setIsWin("win");
                    setPoints(points() + 1);
                    obj->setColBack("#C0CDD9");
                }
                else if (obj->isWin() != "win")
                {
                    obj->setFlippedToFalse(obj->flipped());
                }
            }
        }
    }
    else
    {
        if (counter() == 3)
        {
            for (int j = 0; j < model.size(); j++)
            {
                DataObject *obj = qobject_cast<DataObject *>(model[j]);

                if (obj->isWin() != "win")
                {
                    obj->setFlippedToFalse(obj->flipped());
                }
            }
        }
    }
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

int GameLogic::points() const
{
    return m_points;
}

void GameLogic::setPoints(int value)
{
    if (m_points != value)
    {
        m_points = value;
        emit pointsChanged(QString::number(m_points / 2));
    }
}
