#include "Functions/circleintersection.h"
#include "Functions/trianglecenter.h"
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

    double x1 = 0.0, y1 = 0.0, r1 = 8.0; // İlk çember
    double x2 = 10.0, y2 = 5.0, r2 = 7.0; // İkinci çember

    CircleIntersection intersection(x1, y1, r1, x2, y2, r2);
    intersection.CalculateIntersection();

    if (intersection.HasIntersection()) {
        std::cout << "İki çember kesişiyor. Kesişen noktaların koordinatları:\n";
        std::cout << "Nokta 1: (" << intersection.GetX1() << ", " << intersection.GetY1() << ")\n";
        std::cout << "Nokta 2: (" << intersection.GetX2() << ", " << intersection.GetY2() << ")\n";
    } else {
        std::cout << "İki çember kesişmiyor veya biri diğerinin içinde.\n";
    }

    double a1 = 0, b1=0, a2=2, b2=2, a3= 1,b3=3;

    TriangleCenter center(a1, b1, a2, b2, a3, b3);
    center.CalculateCenter();

    std::cout << "Üçgenin merkezi koordinatları: (" << center.GetCenterX() << ", " << center.GetCenterY() << ")\n";


    return app.exec();
}
