# ParcelFlow

A desktop application built in C++ and Qt that models the process of parcel distribution by delivery agents. The project enforces a strict layered architecture and demonstrates advanced use of design patterns and custom GUI rendering.

## Features

* **Multi-Window Interface:** Automatically generates and launches an individual window for each registered delivery agent when the application starts.
* **Agent Capabilities:** Agent windows display assigned undelivered parcels (based on assigned streets or a geographic service area). Agents can filter parcels by street using a combo box and process them using a "Deliver" button.
* **Logistics Dashboard:** A master overview window displaying all parcels. It highlights delivered parcels with a green background and allows company employees to input data to add new parcels to the system.
* **Graphical Map Visualizer:** A dedicated map window plots all undelivered parcels as geometric shapes (circles, rectangles) at their specific coordinates using the `QWidget` and `QPainter` classes.
* **Real-Time Synchronization:** Utilizes the Observer design pattern to ensure that any modification made by an agent or employee automatically updates all open windows and the map simultaneously.
* **Data Persistence:** Reads agent information and parcel data from manually created text files at launch and automatically writes updates back to the parcels file when the application closes.

## Technologies & Architecture

* **Language:** C++
* **GUI Framework:** Qt 6 (Widgets, QPainter, Qt Designer)
* **Architecture:** Layered Architecture
* **Design Patterns:** Observer Pattern

### Prerequisites
* Visual Studio with C++ Desktop Development workload
* Qt 6 and Qt Visual Studio Tools extension

### Building and Running
1. Clone the repository: `git clone https://github.com/saratnv/ParcelFlow.git`
2. Open the solution file in Visual Studio.
3. Ensure the text files containing agent and parcel data are placed in the correct working directory.
4. Build and run the application.