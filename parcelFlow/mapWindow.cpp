#include "mapwindow.h"

MapWindow::MapWindow(Controller& c, QWidget* parent)
    : QWidget(parent), ctrl(c) {
    this->setWindowTitle("Parcel map");
}

void MapWindow::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    for (const auto& p : ctrl.getParcels()) {
        if (!p.isDelivered()) {
            painter.setBrush(Qt::red);
            painter.setPen(Qt::white);

            int radius = 15;
            painter.drawEllipse(p.getX(), p.getY(), radius * 2, radius * 2);

            painter.drawText(p.getX(), p.getY() - 3, QString::fromStdString(p.getRecipient()));
        }
    }
}