#ifndef CIRCLE_ITEM_H
#define CIRCLE_ITEM_H

#include <QQuickPaintedItem>

class CircleItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

public:
    explicit CircleItem(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;
    //<-- slide
    QColor color() const;
    void setColor(const QColor &newColor);
    // bool event(QEvent *event) override;

signals:
    void colorChanged();

private:
    QColor m_color;
};

#endif // CIRCLE_ITEM_H
