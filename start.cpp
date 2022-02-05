#include <QGuiApplication>
#include <iostream>
#include <random>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "circle_item.h"
#include "dataobject.h"
#include "gamelogic.h"

int main(int argc, char ** argv)
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<CircleItem>("Shapes", 1, 0, "Ellipse");
    QQmlApplicationEngine engine;

    QList<QObject *> dataList = {
        new DataObject("0", "qrc:/images/1.png", false, "unmatched", "#374759", "#F0A53E"),
        new DataObject("1", "qrc:/images/2.png", false, "unmatched", "#374759", "#F0A53E"),
        new DataObject("2", "qrc:/images/3.png", false, "unmatched", "#374759", "#F0A53E"),
        new DataObject("3", "qrc:/images/4.png", false, "unmatched", "#374759", "#F0A53E"),
        new DataObject("4", "qrc:/images/5.png", false, "unmatched", "#374759", "#F0A53E"),
        new DataObject("5", "qrc:/images/6.png", false, "unmatched", "#374759", "#F0A53E"),
        new DataObject("6", "qrc:/images/7.png", false, "unmatched", "#374759", "#F0A53E"),
        new DataObject("7", "qrc:/images/8.png", false, "unmatched", "#374759", "#F0A53E"),
        new DataObject("8", "qrc:/images/1.png", false, "unmatched", "#374759", "#F0A53E"),
        new DataObject("9", "qrc:/images/2.png", false, "unmatched", "#374759", "#F0A53E"),
        new DataObject("10", "qrc:/images/3.png", false, "unmatched", "#374759", "#F0A53E"),
        new DataObject("11", "qrc:/images/4.png", false, "unmatched", "#374759", "#F0A53E"),
        new DataObject("12", "qrc:/images/5.png", false, "unmatched", "#374759", "#F0A53E"),
        new DataObject("13", "qrc:/images/6.png", false, "unmatched", "#374759", "#F0A53E"),
        new DataObject("14", "qrc:/images/7.png", false, "unmatched", "#374759", "#F0A53E"),
        new DataObject("15", "qrc:/images/8.png", false, "unmatched", "#374759", "#F0A53E")
    };

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(dataList.begin(), dataList.end(), g); //shuffling tiles

    for (int i = 0; i < 16; i++)
    {
        DataObject *obj = qobject_cast<DataObject *>(dataList[i]);
        obj->setName(QString::number(i));
    }

    GameLogic* gameLogic = new GameLogic();
    engine.rootContext()->setContextProperty("_gameLogic", gameLogic);
    engine.rootContext()->setContextProperty("_model", QVariant::fromValue(dataList));
    engine.setInitialProperties({{"model", QVariant::fromValue(dataList)}});

    engine.load(QUrl(QStringLiteral("qrc:/game.qml")));
    if (engine.rootObjects().isEmpty())
    {
        QCoreApplication::exit(-1);
    }

    return app.exec();
}
