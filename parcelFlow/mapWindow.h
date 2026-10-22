#pragma once
#include <QWidget>
#include <QPainter>
#include "controller.h"
#include "observer.h"

class MapWindow : public QWidget, public Observer {
	Q_OBJECT
private:
	Controller& ctrl;
public:
	MapWindow(Controller& c, QWidget* parent = nullptr);

	void update() override { this->repaint(); }
protected:
	void paintEvent(QPaintEvent* event) override;
};