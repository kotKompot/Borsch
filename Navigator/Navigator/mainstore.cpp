#include <QtGui>
#include "MouseObserver.h"

int mains(int argc, char** argv)
{
QApplication app(argc, argv);
MouseObserver wgt;
wgt.resize(250,130);
        wgt.show();

        return app.exec();
}
