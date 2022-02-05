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

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);

    std::random_device rd;
    std::mt19937 g(rd());
//    std::shuffle(dataList.begin(), dataList.end(), g); //shuffling tiles

    GameLogic* gameLogic = new GameLogic();
    view.rootContext()->setContextProperty("_gameLogic", gameLogic);
    view.rootContext()->setContextProperty("_model", QVariant::fromValue(dataList));
    view.setInitialProperties({{"model", QVariant::fromValue(dataList)}});

    view.setSource(QUrl("qrc:/game.qml"));
    view.show();

    return app.exec();
}
