#include "widget.h"
#include "ui_widget.h"
#include "style.h"
#include <QGraphicsDropShadowEffect>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    /// Настройка UI
    this->setWindowFlags(Qt::FramelessWindowHint);      // Отключаем оформление окна
    this->setAttribute(Qt::WA_TranslucentBackground);   // Делаем фон главного виджета прозрачным
    this->setStyleSheet(Style::getWindowStyleSheet());    // Устанавливаем стиль виджета
    // Создаём эффект тени
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(9); // Устанавливаем радиус размытия
    shadowEffect->setOffset(0);     // Устанавливаем смещение тени
    ui->widgetInterface->setGraphicsEffect(shadowEffect);   // Устанавливаем эффект тени на окно
    ui->label->setText("AIMP");
    ui->label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    // Установка стилей для всех элементов
    ui->label_2->setStyleSheet(Style::getLabelStyleSheet());
    ui->label->setStyleSheet(Style::getLabelStyleSheet());
    ui->close->setStyleSheet(Style::getCloseStyleSheet());
    ui->max->setStyleSheet(Style::getMaxStyleSheet());
    ui->min->setStyleSheet(Style::getMinStyleSheet());
    ui->add->setText(tr("Добавить"));
    ui->next->setStyleSheet(Style::getNextStyleSheet());
    ui->prev->setStyleSheet(Style::getPreviousStyleSheet());
    ui->stop->setStyleSheet(Style::getStopStyleSheet());
    ui->play->setStyleSheet(Style::getPlayStyleSheet());
    ui->pause->setStyleSheet(Style::getPauseStyleSheet());
    ui->add->setStyleSheet(Style::getMenuStyleSheet());
    ui->next->setCursor(Qt::PointingHandCursor);
    ui->prev->setCursor(Qt::PointingHandCursor);
    ui->stop->setCursor(Qt::PointingHandCursor);
    ui->play->setCursor(Qt::PointingHandCursor);
    ui->pause->setCursor(Qt::PointingHandCursor);
    ui->tableView->setStyleSheet(Style::getTableViewStyleSheet());


}

Widget::~Widget()
{
    delete ui;
}
