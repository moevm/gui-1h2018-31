#ifndef STYLE_H
#define STYLE_H

#include <QString>

class Style
{
public:
    static QString getWindowStyleSheet();
    static QString getLabelStyleSheet();
    static QString getCloseStyleSheet();
    static QString getMaxStyleSheet();
    static QString getRestoreStyleSheet();
    static QString getMinStyleSheet();
    static QString getNextStyleSheet();
    static QString getPreviousStyleSheet();
    static QString getStopStyleSheet();
    static QString getPlayStyleSheet();
    static QString getPauseStyleSheet();
    static QString getMenuStyleSheet();
    static QString getTableViewStyleSheet();
};

#endif // STYLE_H
