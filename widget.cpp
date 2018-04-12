#include "widget.h"
#include "ui_widget.h"
#include "style.h"
#include <QGraphicsDropShadowEffect>
#include <QFileDialog>
#include <QDir>


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

    // Настройка таблицы плейлиста
    m_playListModel = new QStandardItemModel(this);
    ui->tableView->setModel(m_playListModel);    // Устанавливаем модель данных в TableView
    // Устанавливаем заголовки таблицы
    m_playListModel->setHorizontalHeaderLabels(QStringList()  << tr("Audio Track")
                                                                << tr("File Path"));
    ui->tableView->hideColumn(1);    // Скрываем колонку, в которой хранится путь к файлу
    ui->tableView->verticalHeader()->setVisible(false);                  // Скрываем нумерацию строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);  // Включаем выделение строк
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); // Разрешаем выделять только одну строку
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);   // Отключаем редактирование
    // Включаем подгонку размера последней видимой колонки к ширине TableView
    ui->tableView->horizontalHeader()->setStretchLastSection(true);



    m_player = new QMediaPlayer(this);          // Инициализируем плеер
    m_playlist = new QMediaPlaylist(m_player);  // Инициализируем плейлист
    m_player->setPlaylist(m_playlist);          // Устанавливаем плейлист в плеер
    m_player->setVolume(70);                    // Устанавливаем громкость воспроизведения треков
    m_playlist->setPlaybackMode(QMediaPlaylist::Loop);  // Устанавливаем циклический режим проигрывания плейлиста

        // подключаем кнопки управления к слотам управления
        // Здесь отметим, что навигация по плейлисту осуществляется именно через плейлист
        // а запуск/пауза/остановка через сам плеер
    connect(ui->prev, &QToolButton::clicked, m_playlist, &QMediaPlaylist::previous);
    connect(ui->next, &QToolButton::clicked, m_playlist, &QMediaPlaylist::next);
    connect(ui->play, &QToolButton::clicked, m_player, &QMediaPlayer::play);
    connect(ui->pause, &QToolButton::clicked, m_player, &QMediaPlayer::pause);
    connect(ui->stop, &QToolButton::clicked, m_player, &QMediaPlayer::stop);

    // При даблклике по треку в таблице устанавливаем трек в плейлисте
    connect(ui->tableView, &QTableView::doubleClicked, [this](const QModelIndex &index){
        m_playlist->setCurrentIndex(index.row());
    });

    // при изменении индекса текущего трека в плейлисте, устанавливаем название файла в специальном лейбле
    connect(m_playlist, &QMediaPlaylist::currentIndexChanged, [this](int index){
        ui->label_2->setText(m_playListModel->data(m_playListModel->index(index, 0)).toString());
    });



}

Widget::~Widget()
{
    delete ui;
    delete m_playListModel;
    delete m_playlist;
    delete m_player;
}
void Widget::on_add_clicked()
{
    // С помощью диалога выбора файлов делаем множественный выбор mp3 файлов
    QStringList files = QFileDialog::getOpenFileNames(this,
                                                      tr("Open files"),
                                                      QString(),
                                                      tr("Audio Files (*.mp3)"));

    // Далее устанавливаем данные по именам и пути к файлам
    // в плейлист и таблицу отображающую плейлист
    foreach (QString filePath, files) {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(QDir(filePath).dirName()));
        items.append(new QStandardItem(filePath));
        m_playListModel->appendRow(items);
        m_playlist->addMedia(QUrl(filePath));
    }
}
