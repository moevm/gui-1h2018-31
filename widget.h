#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QMediaPlaylist>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_add_clicked();              // Слот для обработки добавления треков через диалоговое окно

private:
    Ui::Widget *ui;
    QStandardItemModel  *m_playListModel;   // Модель данных плейлиста для отображения

};

#endif // WIDGET_H
