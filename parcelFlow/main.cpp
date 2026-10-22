#include "AgentWindow.h"
#include <QMessageBox>
#include <stdexcept>
#include <QtWidgets/QApplication>
#include "repository.h"
#include "controller.h"
#include "LogisticsWindow.h"
#include "mapWindow.h"
int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    try {
        Repository repo("agents.txt", "parcels.txt");
        Controller ctrl(repo);

        std::vector<QWidget*> allWindows;

        //agent w
        for (const auto& c : ctrl.getAgents()) {
            AgentWindow* w = new AgentWindow(ctrl, c);
            ctrl.addObserver(w);
            w->show();
            allWindows.push_back(w);
        }

        //logistic w
        LogisticsWindow* logisticsW = new LogisticsWindow(ctrl);
        ctrl.addObserver(logisticsW);
        logisticsW->show();
        allWindows.push_back(logisticsW);

        //map
        MapWindow* mapW = new MapWindow(ctrl);
        ctrl.addObserver(mapW);
        mapW->show();
        allWindows.push_back(mapW);

        int result = a.exec();

        for (auto w : allWindows) delete w;
        return result;

    }
    catch (const std::exception& e) {
        QMessageBox::critical(nullptr, "Startup failed", e.what());
        return 1;
    }
}