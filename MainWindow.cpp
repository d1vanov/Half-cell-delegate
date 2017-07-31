#include "MainWindow.h"
#include "Model.h"
#include "Delegate.h"
#include <QTableView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Model * model = new Model(this);
    Delegate * delegate = new Delegate(this);
    QTableView * view = new QTableView(this);
    view->setModel(model);
    view->setItemDelegate(delegate);
    setCentralWidget(view);
}
