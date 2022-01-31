#include <QGuiApplication>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include "circle_item.h"
#include "dataobject.h"
#include "gamelogic.h"

int main(int argc, char ** argv)
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<CircleItem>("Shapes", 1, 0, "Ellipse");

    QList<QObject *> dataList = {
        new DataObject("Item 1", "qrc:/images/1.svg",false),
        new DataObject("Item 2","qrc:/images/2.svg",false),
        new DataObject("Item 3","qrc:/images/3.svg",false),
        new DataObject("Item 4", "qrc:/images/4.svg",false),
        new DataObject("Item 5", "qrc:/images/5.svg",false),
        new DataObject("Item 6","qrc:/images/6.svg",false),
        new DataObject("Item 7","qrc:/images/7.svg",false),
        new DataObject("Item 8", "qrc:/images/8.svg",false),
        new DataObject("Item 9", "qrc:/images/1.svg",false),
        new DataObject("Item 10","qrc:/images/2.svg",false),
        new DataObject("Item 11","qrc:/images/3.svg",false),
        new DataObject("Item 12", "qrc:/images/4.svg",false),
        new DataObject("Item 13", "qrc:/images/5.svg",false),
        new DataObject("Item 14","qrc:/images/6.svg",false),
        new DataObject("Item 15","qrc:/images/7.svg",false),
        new DataObject("Item 16", "qrc:/images/8.svg",false)
    };

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(dataList.begin(), dataList.end(), g); //shuffling tiles

    QList<QObject *> myList;
    myList.reserve(dataList.size());
    std::copy(dataList.begin(), dataList.end(), std::back_inserter(myList));

    GameLogic* gameLogic = new GameLogic();
    gameLogic->doSomething();
    view.rootContext()->setContextProperty("_gameLogic", gameLogic);
    view.rootContext()->setContextProperty("_dataObject", new DataObject());
    view.setInitialProperties({{"model", QVariant::fromValue(myList)}});

    view.setSource(QUrl("qrc:/game.qml"));
    view.show();

    return app.exec();
}
