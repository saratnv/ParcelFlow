#pragma once

#include <QtWidgets/QWidget>
#include "ui_AgentWindow.h"
#include "controller.h"
#include "observer.h"

class AgentWindow : public QWidget, public Observer {
    Q_OBJECT

private:
    Controller& ctrl;
    Agent courier;
    Ui::AgentWindowClass ui;

    void populateStreets();
    void populatePackages();

public:
    AgentWindow(Controller& c, Agent cour, QWidget* parent = nullptr);
    ~AgentWindow();

    void update() override {
        populatePackages();
    }

private slots:
    void handleDeliver();
};