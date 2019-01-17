#include "log.h"

#include <QLabel>
#include <QHBoxLayout>

Log::Log(Controller *controller)
    : QFrame()
{
    setFixedSize(600, 400);
    move(800, 100);
    setWindowTitle("Log");

    auto* layoutV = new QVBoxLayout();
    setLayout(layoutV);

    auto* layoutHTextBrowsers = new QHBoxLayout();
    auto* layoutHLabels = new QHBoxLayout();
    layoutV->addLayout(layoutHLabels);
    layoutV->addLayout(layoutHTextBrowsers);

    takeOff = new QLabel(this);
    land = new QLabel(this);

    takeOff->setText("Airplane routes:");
    land->setText("Airplane state:");

    layoutHLabels->addWidget(takeOff);
    layoutHLabels->addWidget(land);

    takeOffInfo = new QTextBrowser(this);
    landInfo = new QTextBrowser(this);

    layoutHTextBrowsers->addWidget(takeOffInfo);
    layoutHTextBrowsers->addWidget(landInfo);

    lblPlaneInfo = new QLabel(this);
    lblPlaneInfo->setText("Airplane info:");

    layoutV->addWidget(lblPlaneInfo);

    tbPlaneInfo = new QTextBrowser(this);
    tbPlaneInfo->setFixedHeight(50);

    layoutV->addWidget(tbPlaneInfo);

    connect(controller, SIGNAL(flightInfo(QString)),
            takeOffInfo, SLOT(append(QString)));

    connect(controller, SIGNAL(landingInfo(const QString&, bool)),
            this, SLOT(appendText(const QString&, bool)));

    connect(controller, SIGNAL(airplaneInfo(QString)),
            this, SLOT(info(QString)));
}

void Log::appendText(const QString &text, bool crashed)
{
    if(crashed) {
        landInfo->setTextColor(Qt::red);
    } else {
        landInfo->setTextColor(Qt::green);
    }
    landInfo->append(text);
}

void Log::info(const QString &text)
{
    tbPlaneInfo->setText(text);
}