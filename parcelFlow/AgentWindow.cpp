#include "agentwindow.h"

AgentWindow::AgentWindow(Controller& c, Agent cour, QWidget* parent)
    : QWidget(parent), ctrl(c), courier(cour) {
    ui.setupUi(this);
    this->setWindowTitle(QString("Agent ")+QString::fromStdString(courier.getName()));

    ui.areaLabel->setText(QString("Service area:  center(%1,%2) | radius: %3")
        .arg(courier.getZoneX()).arg(courier.getZoneY()).arg(courier.getRadius()));

    connect(ui.deliverButton, &QPushButton::clicked, this, &AgentWindow::handleDeliver);
    connect(ui.streetCombo, &QComboBox::currentTextChanged, this, &AgentWindow::populatePackages);

    populateStreets();
    populatePackages();
}

AgentWindow::~AgentWindow() {}

void AgentWindow::populateStreets() {
    ui.streetCombo->blockSignals(true);
    ui.streetCombo->clear();
    ui.streetCombo->addItem("All assigned streets");

    for (const auto& street : courier.getStreets()) {
        ui.streetCombo->addItem(QString::fromStdString(street));
    }
    ui.streetCombo->blockSignals(false);
}

void AgentWindow::populatePackages() {
    ui.packagesList->clear();
    std::string selectedStreet = ui.streetCombo->currentText().toStdString();

    for (const auto& p : ctrl.getParcels()) {
        if (!p.isDelivered() && courier.canDeliver(p)) {

            if (selectedStreet == "All assigned streets" || p.getStreet() == selectedStreet) {
                QString text = QString::fromStdString(p.getRecipient() + " | " + p.getStreet());
                ui.packagesList->addItem(text);
            }
        }
    }
}

void AgentWindow::handleDeliver() {
    int row = ui.packagesList->currentRow();
    if (row < 0) return;

    QString selectedText = ui.packagesList->currentItem()->text();
    std::string recipient = selectedText.split(" | ")[0].toStdString();
    std::string street = selectedText.split(" | ")[1].toStdString();

    ctrl.deliverPackage(recipient, street);
}