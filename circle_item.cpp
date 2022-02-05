#include <QPainter>
#include "circle_item.h"
#include <vector>
#include <iostream>

CircleItem::CircleItem(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
}

void CircleItem::paint(QPainter *painter)
{
    painter->save();
    QPen pen = painter->pen();
    pen.setBrush(m_color);
    pen.setWidth(3);
    painter->setPen(pen);
    painter->setBackground(m_color);
    painter->setBrush(QBrush(m_color));
    painter->drawEllipse(10, 10, 70, 70);
    painter->restore();
}

QColor CircleItem::color() const
{
    return m_color;
}

void CircleItem::setColor(const QColor &newColor)
{
    if (m_color != newColor)
    {
        m_color = newColor;
        update();
        emit colorChanged();
    }
}
