#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "circle_item.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    qmlRegisterType<CircleItem>("Shapes", 1, 0, "Ellipse");

//    app.setWindowIcon(QIcon(":/images/logo/openSESAME.ico"));

//    Authenticate authenticate;
//    engine.rootContext()->setContextProperty("_authenticate", &authenticate);

    engine.load(QUrl(QStringLiteral("qrc:/start.qml")));
    if (engine.rootObjects().isEmpty())
    {
        QCoreApplication::exit(-1);
    }

    return app.exec();

}
