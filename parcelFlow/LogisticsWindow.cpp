#include "LogisticsWindow.h"
#include <QMessageBox>
LogisticsWindow::LogisticsWindow(Controller& c, QWidget* parent)
    : QWidget(parent), ctrl(c) {
    ui.setupUi(this);
    this->setWindowTitle("Logistics dashboard");

    connect(ui.addButton, &QPushButton::clicked, this, &LogisticsWindow::handleAddPackage);

    populateList();
}
LogisticsWindow::~LogisticsWindow() {}


void LogisticsWindow::populateList() {
    ui.packagesList->clear();

    for (const auto& p : ctrl.getParcels()) {
        QString text = QString::fromStdString(p.getRecipient() + " | " + p.getStreet() + " " +
            std::to_string(p.getNumber()) + " | Status: " +
            (p.isDelivered() ? "Delivered" : "Undelivered"));

        QListWidgetItem* item = new QListWidgetItem(text);

        if (p.isDelivered()) {
            item->setBackground(Qt::green);
        }

        ui.packagesList->addItem(item);
    }
}

void LogisticsWindow::handleAddPackage() {
    std::string rec = ui.recipientEdit->text().toStdString();
    std::string street = ui.streetEdit->text().toStdString();

    int num = ui.numberEdit->text().toInt();
    int x = ui.xEdit->text().toInt();
    int y = ui.yEdit->text().toInt();

    try {
        ctrl.addPackage(rec, street, num, x, y);
        ui.recipientEdit->clear();
        ui.streetEdit->clear();
        ui.numberEdit->clear();
        ui.xEdit->clear();
        ui.yEdit->clear();
    }
    catch (const DeliveryException& e) {
        QMessageBox::critical(this, "Error: ", e.what());
    }
}

