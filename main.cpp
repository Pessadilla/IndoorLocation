#include "Functions/circleintersection.h"
#include "Functions/trianglecenter.h"
#include "Functions/pointcomparer.h"
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

    double xa1, ya1, xa2, ya2, xa3,ya3;


    CircleIntersection intersection(x1, y1, r1, x2, y2, r2);
    intersection.CalculateIntersection();

    PointComparer comparer;
    double greaterY = comparer.GetPointWithGreaterY(intersection.GetY1(), intersection.GetY2());
    if (greaterY==1)
        xa1=intersection.GetX1(),ya1=intersection.GetY1();
    else
        xa1=intersection.GetX2(),ya1=intersection.GetY2();

    CircleIntersection intersection2(x1, y1, r1, x3, y3, r3);
    intersection2.CalculateIntersection();

    PointComparer comparer2;
    greaterY = comparer2.GetPointWithSmallerY(intersection2.GetY1(), intersection2.GetY2());
    if (greaterY==1)
        xa2=intersection2.GetX1(),ya2=intersection2.GetY1();
    else
        xa2=intersection2.GetX2(),ya2=intersection2.GetY2();


    CircleIntersection intersection3(x2, y2, r2, x3, y3, r3);
    intersection3.CalculateIntersection();

    PointComparer comparer3;
    greaterY = comparer3.GetPointWithSmallerY(intersection3.GetY1(), intersection3.GetY2());
    if (greaterY==1)
        xa3=intersection3.GetX1(),ya3=intersection3.GetY1();
    else
        xa3=intersection3.GetX2(),ya3=intersection3.GetY2();

    if (intersection.HasIntersection()&intersection2.HasIntersection()&intersection3.HasIntersection())
    {
        TriangleCenter center(xa1, ya1, xa2, ya2, xa3, ya3);
        center.CalculateCenter();
        std::cout << "x1: "<<xa1<<"  y1: "<<ya1<<"  x2: "<<xa2<<"  y2: "<<ya2<<"  x3: "<<xa3<<"  y3: "<<ya3<<"\n";
        std::cout << "Üçgenin merkezi koordinatları: (" << center.GetCenterX() << ", " << center.GetCenterY() << ")\n";
    }







    return app.exec();
}
