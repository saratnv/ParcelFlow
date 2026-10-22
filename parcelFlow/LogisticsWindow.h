#pragma once

#include <QWidget>
#include "ui_LogisticsWindow.h"
#include "controller.h"
#include "repository.h"

class LogisticsWindow : public QWidget, public Observer
{
	Q_OBJECT

private:
	Controller& ctrl;
	Ui::LogisticsWindowClass ui;

	void populateList();

public:
	LogisticsWindow(Controller& c, QWidget* parent = nullptr);
	~LogisticsWindow();
	void update()override {
		populateList();
	}

private slots:
	void handleAddPackage();

};

