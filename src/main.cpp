#include <QtQml>
#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "checker.h"

int main(int argc, char *argv[])
{
    Checker checker;
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("checker", &checker);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
