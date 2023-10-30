#include "Functions/findcoordinate.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/IndoorLocation/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    double x1 = 0.0, y1 = 0.0, r1 = 6.26; // İlk çember
    double x2 = 5.0, y2 = 10.0, r2 = 6.56; // İkinci çember
    double x3 = 10.0, y3 = 5.0, r3 = 5.52; // Üçüncü çember



    FindCoordinate(x1,y1,r1,x2,y2,r2,x3,y3,r3);





    return app.exec();
}
