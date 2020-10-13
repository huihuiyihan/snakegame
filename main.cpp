#include <QtCore/QStandardPaths>
#include <QtCore/QStringList>
#include <QtQml/QQmlContext>
#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickItem>
#include <QtQuick/QQuickView>
#include <QQmlApplicationEngine>
#include "MessageMgr.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    MessageMgr msg;
    engine.rootContext()->setContextProperty("msg", &msg);

    const QUrl url(QStringLiteral("qrc:///qml/GamePanel.qml"));
    //const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

//    QQuickView viewer;
//    viewer.setSource(QUrl(QLatin1String("qrc:/GamePanel.qml")));
//    viewer.setTitle("c");
//    viewer.setFlags(Qt::Window | Qt::WindowSystemMenuHint | Qt::WindowTitleHint |
//                    Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
//    viewer.setMaximumSize(QSize(1280,720));
//    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
//    viewer.show();

//    QMetaObject::invokeMethod(viewer.rootObject(), "init", Qt::QueuedConnection);

    return app.exec();
}
