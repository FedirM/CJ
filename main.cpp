#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQml>

#include <cj.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));

//    engine.rootContext()->setContextProperty("CJ", obj);
    qmlRegisterSingletonType<CJ>("CJ", 1, 0, "CJ", CJ::initSingleton);

    engine.load(url);

    return app.exec();
}
