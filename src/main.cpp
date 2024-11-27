// COMP2811 Coursework 2: application entry point

#include <QtWidgets>
#include "window.hpp"
#include "utils/database_utils.hpp"

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  setupDatabase();

  MainWindow window;
  window.show();

  return app.exec();
}
