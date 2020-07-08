#include "mainwindow.h"

#include <QLabel>
#include <QPushButton>
#include <QProcess>
#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>
#include <QDialog>
#include <QGridLayout>
#include <QImageReader>
#include <QToolButton>
#include <QIcon>
#include <QApplication>
#include <QWidget>
#include <QScrollArea>

QWidget* wrap(QLayout* l) {
    auto widget = new QWidget();
    widget->setLayout(l);
    return widget;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //All Widget And Mainwindow
    QWidget *widgetscroll = new QWidget;
    QMainWindow *Mainwindowscoll = new QMainWindow;
    QScrollArea *scroll = new QScrollArea;
    QWidget *LastWidget = new QWidget;

    // All layout variables
    QGridLayout * ThumbnailLayout = new QGridLayout;
    QVBoxLayout * Mainlayout = new QVBoxLayout;
    QHBoxLayout * FooterLayout = new QHBoxLayout;
    QVBoxLayout *layoutscroll = new QVBoxLayout(widgetscroll);
    QVBoxLayout * MainLastLayout = new QVBoxLayout(LastWidget);

    // Header
    QLabel * AppTitle = new QLabel;
    AppTitle->setText(" Choose a theme you like and click apply.");
    AppTitle->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    AppTitle->setMinimumHeight(35);
    AppTitle->setMaximumHeight(35);

    // Footer
    QPushButton * Default = new QPushButton;
    QPushButton * Apply = new QPushButton;
    QPushButton * Cancel = new QPushButton;

    if(selected == 0) {
        Apply->setDisabled(true);
    }
    ConfirmButton(Default, "Restore Default", "preferences-desktop-default-applications");
    ConfirmButton(Apply, "Apply", "dialog-ok-apply");
    ConfirmButton(Cancel, "Cancel", "dialog-cancel");

    // All thumbnail
    QToolButton* KoompiDark = new QToolButton;
    QToolButton* KoompiLight = new QToolButton;
    QToolButton* KoompiMosxDark = new QToolButton;
    QToolButton* KoompiMosxLight = new QToolButton;
    QToolButton* KoompiWinxDark = new QToolButton;
    QToolButton* KoompiWinxLight = new QToolButton;


    FooterLayout->addWidget(Default);
    FooterLayout->addStretch();
    FooterLayout->addWidget(Apply);
    FooterLayout->addWidget(Cancel);

    Thumbnail(KoompiDark, "KOOMPI Dark", "://resources/images/koompi-dark.png");
    Thumbnail(KoompiLight, "KOOMPI Light", "://resources/images/koompi-light.png");
    Thumbnail(KoompiMosxDark, "KOOMPI MOSX Dark", "://resources/images/mosx-dark.png");
    Thumbnail(KoompiMosxLight, "KOOMPI MOSX Light", "://resources/images/mosx-light.png");
    Thumbnail(KoompiWinxDark, "KOOMPI WinX Dark", "://resources/images/winx-dark.png");
    Thumbnail(KoompiWinxLight, "KOOMPI WinX Light", "://resources/images/winx-light.png");


    ThumbnailLayout->setSpacing(20);
    ThumbnailLayout->addWidget(KoompiDark, 1, 1, 1, 1, Qt::AlignCenter);
    ThumbnailLayout->addWidget(KoompiLight, 1, 2, 1, 1, Qt::AlignCenter);
    ThumbnailLayout->addWidget(KoompiMosxDark, 2, 1, 1, 1, Qt::AlignCenter);
    ThumbnailLayout->addWidget(KoompiMosxLight, 2, 2, 1, 1, Qt::AlignCenter);
    ThumbnailLayout->addWidget(KoompiWinxDark, 3, 1, 1, 1, Qt::AlignCenter);
    ThumbnailLayout->addWidget(KoompiWinxLight, 3, 2, 1, 1, Qt::AlignCenter);

    Mainlayout->addLayout(ThumbnailLayout);
    

    // Mainwindow And Widget Scoll

    // +WidgetScroll
    scroll->setWidget(widgetscroll);
    scroll->setWidgetResizable(true);
    scroll->setFocusPolicy(Qt::NoFocus);
    layoutscroll->addLayout(Mainlayout);

    //+MainwindowScroll
    Mainwindowscoll->setGeometry(0,0,880,525);
    Mainwindowscoll->setCentralWidget(scroll);

    //Last Widget
    LastWidget->setGeometry(0,0,900,645);

    MainLastLayout->addWidget(AppTitle);
    MainLastLayout->addWidget(Mainwindowscoll);
    MainLastLayout->addLayout(FooterLayout);

    LastWidget->show();

    connect(Default, &QPushButton::clicked, this, [=](){
        qDebug() << "KoompiLight clicked";
        QProcess* change_plasma_theme = new QProcess;
        QProcess* change_layout_theme = new QProcess;

        change_plasma_theme->execute("lookandfeeltool -a org.koompi.theme.koompi-light");
        change_layout_theme->execute("/usr/bin/bash /usr/share/org.koompi.theme.manager/koompi-layout-light.sh");
    });

    connect(Cancel, &QPushButton::clicked, this, [=](){
        QApplication::quit();
    });

    connect(Apply, &QPushButton::clicked, this, [=](){
        QProcess* change_plasma_theme = new QProcess;
        QProcess* change_layout_theme = new QProcess;
        QProcess* change_kvantum_theme = new QProcess;

        qDebug() << selected;
        switch(selected) {
        case 1:
            change_plasma_theme->execute("lookandfeeltool -a org.koompi.theme.koompi-dark");
            change_layout_theme->execute("/usr/bin/bash /usr/share/org.koompi.theme.manager/koompi-layout-dark.sh");
            break;
        case 2:
            change_plasma_theme->execute("lookandfeeltool -a org.koompi.theme.koompi-light");
            change_layout_theme->execute("/usr/bin/bash /usr/share/org.koompi.theme.manager/koompi-layout-light.sh");
            break;
        case 3:
            change_plasma_theme->execute("lookandfeeltool -a org.koompi.theme.koompi-mosx-dark");
            change_layout_theme->execute("/usr/bin/bash /usr/share/org.koompi.theme.manager/koompi-mosx-layout-dark.sh");
            break;
        case 4:
            change_plasma_theme->execute("lookandfeeltool -a org.koompi.theme.koompi-mosx-light");
            change_layout_theme->execute("/usr/bin/bash /usr/share/org.koompi.theme.manager/koompi-mosx-layout-light.sh");
            break;
        case 5:
            change_plasma_theme->execute("lookandfeeltool -a org.koompi.theme.koompi-winx-dark");
            change_kvantum_theme->execute("kvantummanager --set Fluent-Dark");
            change_layout_theme->execute("/usr/bin/bash /usr/share/org.koompi.theme.manager/koompi-winx-layout-dark.sh");
            break;
        case 6:
            change_plasma_theme->execute("lookandfeeltool -a org.koompi.theme.koompi-winx-light");
            change_kvantum_theme->execute("kvantummanager --set Fluent-Light");
            change_layout_theme->execute("/usr/bin/bash /usr/share/org.koompi.theme.manager/koompi-winx-layout-light.sh");
            break;
        }
    });

    connect(KoompiDark, &QToolButton::clicked, this, [=](){
        selected = 1;
        Apply->setDisabled(false);
    });

    connect(KoompiLight, &QToolButton::clicked, this, [=](){
        selected = 2;
        Apply->setDisabled(false);
    });

    connect(KoompiMosxDark, &QToolButton::clicked, this, [=](){
        selected = 3;
        Apply->setDisabled(false);
    });

    connect(KoompiMosxLight, &QToolButton::clicked, this, [=](){
        selected = 4;
        Apply->setDisabled(false);
    });

    connect(KoompiWinxDark, &QToolButton::clicked, this, [=](){
        selected = 5;
        Apply->setDisabled(false);
    });

    connect(KoompiWinxLight, &QToolButton::clicked, this, [=](){
        selected = 6;
        Apply->setDisabled(false);
    });

    LastWidget->setWindowIcon(QIcon::fromTheme("preferences-desktop-theme-global"));
    LastWidget->setWindowTitle("Theme Manager");
    //this->setCentralWidget(wrap(MainLastLayout));

}

QToolButton *MainWindow::Thumbnail(QToolButton *Button, const QString &Name, const QString &ImagePath)
{
    Button->setText(Name);
    Button->setIcon(QIcon(ImagePath));
    Button->setIconSize(QSize(400,220));
    Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    Button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    Button->setMaximumSize(390,275);
    Button->setFocusPolicy(Qt::ClickFocus);
    return Button;
}

QPushButton *MainWindow::ConfirmButton(QPushButton *Button, const QString &Name, const QString &IconName)
{
    Button->setText(Name);
    Button->setIcon(QIcon::fromTheme(IconName));
    Button->setIconSize(QSize(26,26));
    Button->setMinimumHeight(30);
    Button->setMaximumHeight(30);
    return Button;
}

MainWindow::~MainWindow()
{
}


