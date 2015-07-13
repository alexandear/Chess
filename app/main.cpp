#include <QApplication>
#include <QQuickView>
#include <QWidget>
#include <QQmlContext>

#include "gamecontroller.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQuickView view;
    view.rootContext()->setContextProperty("game", new GameController);
    view.setSource(QUrl(QStringLiteral("qrc:/qml/MainWindow.qml")));

    auto container = QWidget::createWindowContainer(&view);
    container->setMinimumSize(640, 480);
    container->setFocusPolicy(Qt::TabFocus);
    container->setWindowTitle(QObject::tr("Chess"));
    container->show();

    return app.exec();
}
