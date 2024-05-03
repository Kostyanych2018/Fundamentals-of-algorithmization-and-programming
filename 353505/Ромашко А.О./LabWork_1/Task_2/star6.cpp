#include "star6.h"
#include <QPainter>

Star6::Star6(QPointF point, QObject *parent) :
    BasicFigure(point,parent)
{
    Q_UNUSED(point)
}

Star6::~Star6()
{

}

// Реализуем метод отрисовки
void Star6::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    qreal side = qMax(qAbs(endPoint().x() - startPoint().x()), qAbs(endPoint().y() - startPoint().y()));

    QPolygonF star;
    for (int i = 0; i < 12; ++i) {
        // Добавляем точки для внешних и внутренних вершин звезды
        qreal radius = (i % 2 == 0) ? side : side / 2.0;
        star << QPointF(startPoint().x() + radius * cos(2 * M_PI * i / 12 - M_PI/2),
                        startPoint().y() + radius * sin(2 * M_PI * i / 12 - M_PI/2));
    }
    painter->drawPolygon(star);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

double Star6::area() {
    double side = qMax(qAbs(endPoint().x() - startPoint().x()), qAbs(endPoint().y() - startPoint().y()));
    return abs(0.3125 * side * side * sqrt(6 * (6 + 2 * sqrt(6))));
}

double Star6::perimeter() {
    double side = qMax(qAbs(endPoint().x() - startPoint().x()), qAbs(endPoint().y() - startPoint().y()));
    return abs(6 * side);
}
