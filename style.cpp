#include "style.h"


QString Style::getWindowStyleSheet()
{
    return "QWidget { "
           "background-color: #454545; "
           "border: 1px solid black; "
           "}";
}
QString Style::getLabelStyleSheet()
{
    return "QLabel { "
           "color: #8f8f8f; "
           "border: none; "
           "margin: 6px; "
           "}";
}

QString Style::getCloseStyleSheet()
{
    return "QToolButton { "
           "image: url(:/buttons/close-orange.png);"
           "background-color: #292929; "
           "icon-size: 12px;"
           "padding-left: 10px;"
           "padding-right: 10px;"
           "padding-top: 5px;"
           "padding-bottom: 5px;"
           "border: 1px solid #292929; "
           "}"
           "QToolButton:hover {"
           "image: url(:/buttons/close.png); "
           "}"
           "QToolButton:pressed { "
           "image: url(:/buttons/close.png);"
           "background-color: #de8e37; "
           "}";
}

QString Style::getMaxStyleSheet()
{
    return "QToolButton { "
           "image: url(:/buttons/window-maximize-gray.png);"
           "background-color: #292929;"
           "icon-size: 12px;"
           "padding-left: 10px;"
           "padding-right: 10px;"
           "padding-top: 5px;"
           "padding-bottom: 5px;"
           "border: 1px solid #292929; "
           "}"
           "QToolButton:hover {"
           "image: url(:/buttons/window-maximize.png); "
           "}"
           "QToolButton:pressed { "
           "image: url(:/buttons/window-maximize.png);"
           "background-color: #de8e37; "
           "}";
}

QString Style::getRestoreStyleSheet()
{
    return "QToolButton { "
           "image: url(:/buttons/window-restore-gray.png);"
           "background-color: #292929;"
           "icon-size: 12px;"
           "padding-left: 10px;"
           "padding-right: 10px;"
           "padding-top: 5px;"
           "padding-bottom: 5px;"
           "border: 1px solid #292929; "
           "}"
           "QToolButton:hover {"
           "image: url(:/buttons/window-restore.png); "
           "}"
           "QToolButton:pressed { "
           "image: url(:/buttons/window-restore.png);"
           "background-color: #de8e37; "
           "}";
}

QString Style::getMinStyleSheet()
{
    return "QToolButton { "
           "image: url(:/buttons/window-minimize-gray.png);"
           "background-color: #292929;"
           "icon-size: 12px;"
           "padding-left: 10px;"
           "padding-right: 10px;"
           "padding-top: 5px;"
           "padding-bottom: 5px;"
           "border: 1px solid #292929; "
           "}"
           "QToolButton:hover { "
           "image: url(:/buttons/window-minimize.png); "
           "}"
           "QToolButton:pressed { "
           "image: url(:/buttons/window-minimize.png);"
           "background-color: #de8e37; "
           "}";
}

QString Style::getNextStyleSheet()
{
    return "QToolButton { "
           "image: url(:/buttons/skip-next.png);"
           "icon-size: 24px;"
           "padding: 6px;"
           "margin: 6px;"
           "border: none;"
           "}"
           "QToolButton:pressed { "
           "image: url(:/buttons/skip-next-orange.png)"
           "}";
}

QString Style::getPreviousStyleSheet()
{
    return "QToolButton { "
           "image: url(:/buttons/skip-previous.png);"
           "icon-size: 24px;"
           "padding: 6px;"
           "margin: 6px;"
           "border: none;"
           "}"
           "QToolButton:pressed { "
           "image: url(:/buttons/skip-previous-orange.png)"
           "}";
}

QString Style::getStopStyleSheet()
{
    return "QToolButton { "
           "image: url(:/buttons/stop.png);"
           "icon-size: 24px;"
           "padding: 6px;"
           "margin: 6px;"
           "border: none;"
           "}"
           "QToolButton:pressed { "
           "image: url(:/buttons/stop-orange.png)"
           "}";
}

QString Style::getPlayStyleSheet()
{
    return "QToolButton { "
           "image: url(:/buttons/play.png);"
           "icon-size: 48px;"
           "padding: 6px;"
           "margin: 6px;"
           "border: none;"
           "}"
           "QToolButton:pressed { "
           "image: url(:/buttons/play-orange.png)"
           "}";
}

QString Style::getPauseStyleSheet()
{
    return "QToolButton { "
           "image: url(:/buttons/pause.png);"
           "icon-size: 24px;"
           "padding: 6px;"
           "margin: 6px;"
           "border: none;"
           "}"
           "QToolButton:pressed { "
           "image: url(:/buttons/pause-orange.png)"
           "}";
}

QString Style::getMenuStyleSheet()
{
    return "QToolButton { "
           "color: #8f8f8f;"
           "background-color: #292929;"
           "icon-size: 12px;"
           "padding-left: 10px;"
           "padding-right: 10px;"
           "padding-top: 5px;"
           "padding-bottom: 5px;"
           "border: 1px solid #292929; "
           "}"
           "QToolButton:hover {"
           "color: white;"
           "}"
           "QToolButton:pressed { "
           "color: white; "
           "background-color: #de8e37; "
           "}";
}

QString Style::getTableViewStyleSheet()
{
    return "QTableView { "
           "background-color: white; "
           "color: black; "
           "border: 1px solid #e2e2de;"


           "}";
}
