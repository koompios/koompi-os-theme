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
#include <QComboBox>
#include <QLibraryInfo>
#include <QDir>


QWidget* wrap(QLayout* l) {
    auto widget = new QWidget();
    widget->setLayout(l);
    return widget;
}

void MainWindow::englishsystemlangtool(){

    savelanguage();
    QTranslator translator;
    qApp->removeTranslator(&translator);
    khmermain = new MainWindow;
    khmermain->installEventFilter(this);
}
void MainWindow::khmersystemlangtool(){

    savelanguage();
    QTranslator translator;
    translator.load(":/i18n/km.qm");
    qApp->installTranslator(&translator);
    khmermain = new MainWindow;
    khmermain->installEventFilter(this);
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    //Load Data Language And Show Language
    QString savedata = QDir::homePath().append("/.config/Theme Manager/thememanager.ini");
    QLocale lsystem = QLocale::system();
    QSettings settings(savedata, QSettings::IniFormat);
    settings.beginGroup("mainwindow");

    if (settings.value("combo").toString() == "Khmer"){
        setkhmerlang();
    }
    if (settings.value("combo").toString() == "English"){
        setenglishlang();
    }
    if (settings.value("combo").toString() != "English" && settings.value("combo").toString() != "Khmer"){

        if (lsystem.languageToString(lsystem.language()) != "Khmer"){
            setenglishlang();
        }
        if (lsystem.languageToString(lsystem.language()) == "Khmer"){
            setkhmerlang();
        }
    }
    settings.endGroup();
}

void MainWindow::fullmainwindow(){
    QLocale lsystem = QLocale::system();

    //Create New Language Tool Dialog
    QVBoxLayout*langlayout = new QVBoxLayout;
    QHBoxLayout* comboxlabellayout = new QHBoxLayout;
    QHBoxLayout* buttonlayout = new QHBoxLayout;

    //ComboBox Language Label Button ...
    combo = new QComboBox;
    applybutton = new QPushButton;
    cancelbutton = new QPushButton;
    checkbox = new QCheckBox;
    label = new QLabel;

    checkbox->setText(tr("System Language"));
    label->setText(tr("Languages"));

    if (lsystem.languageToString(lsystem.language()) == "Khmer"){
        combo->addItem(tr("Khmer"));
        combo->addItem(tr("English"));
    }
    if (lsystem.languageToString(lsystem.language()) != "Khmer"){
        combo->addItem(tr("English"));
        combo->addItem(tr("Khmer"));
    }
    //combo->setFocusPolicy(Qt::NoFocus);
    combo->setFocusPolicy(Qt::ClickFocus);

    applybutton->setText(tr("Apply"));
    cancelbutton->setText(tr("Cancel"));

    loadcombobox();     //call load combobox savedata
    loadcheckbox();     //call load checkbox savedata

    comboxlabellayout->addWidget(label, 5);
    comboxlabellayout->addWidget(combo, 1);

    buttonlayout->addWidget(applybutton);
    buttonlayout->addWidget(cancelbutton);

    langlayout->addLayout(comboxlabellayout);
    langlayout->addStretch();
    langlayout->addWidget(checkbox);
    langlayout->addLayout(buttonlayout);

    //All Widget And Mainwindow
    QWidget *widgetscroll = new QWidget;
    QMainWindow *Mainwindowscoll = new QMainWindow;
    QScrollArea *scroll = new QScrollArea;
    QWidget *LastWidget = new QWidget;

    // All layout variables
    QGridLayout * ThumbnailLayout = new QGridLayout;
    QVBoxLayout * Mainlayout = new QVBoxLayout;
    QHBoxLayout * FooterLayout = new QHBoxLayout;
    QHBoxLayout * AppTitleLayout = new QHBoxLayout;
    QVBoxLayout * layoutscroll = new QVBoxLayout(widgetscroll);
    QVBoxLayout * MainLastLayout = new QVBoxLayout(LastWidget);

    // Header
    QLabel * AppTitle = new QLabel;
    QPushButton * LanguageTitle = new QPushButton;

    AppTitle->setText(tr("Choose a theme you like and click apply."));
    AppTitle->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    AppTitle->setMinimumHeight(35);
    AppTitle->setMaximumHeight(35);

    LanguageTitle->setText(tr("Languages"));
    LanguageTitle->setMinimumHeight(35);
    LanguageTitle->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    LanguageTitle->setMaximumHeight(35);

    // Footer
    QPushButton * Default = new QPushButton;
    QPushButton * Apply = new QPushButton;
    QPushButton * Cancel = new QPushButton;
    QPushButton * Lang = new QPushButton;

    if(selected == 0) {
        Apply->setDisabled(true);
    }
    ConfirmButton(Default, tr("Restore Default"), tr("preferences-desktop-default-applications"));
    ConfirmButton(Apply, tr("Apply"), tr("dialog-ok-apply"));
    ConfirmButton(Cancel, tr("Cancel"), tr("dialog-cancel"));

    Lang->setText(tr("Languages"));

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

    AppTitleLayout->addWidget(AppTitle);
    AppTitleLayout->addStretch();
    AppTitleLayout->addWidget(Lang);

    Thumbnail(KoompiDark, tr("KOOMPI Dark"), "://resources/images/koompi-dark.png");
    Thumbnail(KoompiLight, tr("KOOMPI Light"), "://resources/images/koompi-light.png");
    Thumbnail(KoompiMosxDark, tr("KOOMPI MOSX Dark"), "://resources/images/mosx-dark.png");
    Thumbnail(KoompiMosxLight, tr("KOOMPI MOSX Light"), "://resources/images/mosx-light.png");
    Thumbnail(KoompiWinxDark, tr("KOOMPI WinX Dark"), "://resources/images/winx-dark.png");
    Thumbnail(KoompiWinxLight, tr("KOOMPI WinX Light"), "://resources/images/winx-light.png");


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
    LastWidget->setGeometry(0,0,900,655);

    MainLastLayout->addLayout(AppTitleLayout);
    MainLastLayout->addWidget(Mainwindowscoll);
    MainLastLayout->addLayout(FooterLayout);
    connect(Lang, &QPushButton::clicked, this, [=](){

        connect(checkbox, &QCheckBox::stateChanged, languagedialog, [&](bool isChecked){
            if (!isChecked){
                combo->setDisabled(false);
                savelanguage();
            }
            if (isChecked){
                combo->setDisabled(true);
                savelanguage();
            }
        });

        languagedialog->setLayout(langlayout);
        languagedialog->show();

        connect(applybutton, &QPushButton::clicked, this, [=](){
            if( checkbox->isChecked()){

                if (lsystem.languageToString(lsystem.language()) == "Khmer"){
                    khmersystemlangtool();
                    LastWidget->close();
                    closeanywidget();

                    qDebug()<<"khmer combobox set1";
                }
                if(lsystem.languageToString(lsystem.language()) != "Khmer"){
                    LastWidget->close();
                    englishsystemlangtool();
                    closeanywidget();

                    qDebug()<<"english combobox set1";
                }
            }
            if(!checkbox->isChecked()){
                if (combo->currentText() == "English"){

                    LastWidget->close();        //close any widget or mainwindow
                    closeanywidget();
                    englishsystemlangtool();    //set english language

                }
                if (combo->currentText() == "Khmer"){

                    LastWidget->close();      //close any widget or mainwindow
                    closeanywidget();
                    khmersystemlangtool();     //set khmer language

                }
                if (combo->currentText() == "ខ្មែរ"){

                    LastWidget->close();       //close any widget or mainwindow
                    closeanywidget();
                    khmersystemlangtool();      //set khmer language

                }
                if (combo->currentText() == "អង់គ្លេស"){

                    LastWidget->close();        //close any widget or mainwindow
                    closeanywidget();
                    englishsystemlangtool();     //set khmer language

                }

            }
        });
    });

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

    LastWidget->setWindowIcon(QIcon::fromTheme(tr("preferences-desktop-theme-global")));
    LastWidget->setWindowTitle(tr("Theme Manager"));
    //this->setCentralWidget(wrap(MainLastLayout));

    LastWidget->show();

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
    Button->setMinimumHeight(35);
    Button->setMaximumHeight(35);
    return Button;
}
void MainWindow::savelanguage()
{
    QLocale lsystem = QLocale::system();
    QString savedata = QDir::homePath().append("/.config/Theme Manager/thememanager.ini");
    QSettings settings(savedata, QSettings::IniFormat);
    settings.beginGroup("mainwindow");

    settings.setValue("checkbox", checkbox->isChecked());
    if (!checkbox->isChecked()){
        if (combo->currentText() == "ខ្មែរ"){
            settings.setValue("combo", "Khmer");
        }
        if (combo->currentText() == "អង់គ្លេស"){
            settings.setValue("combo", "English");
        }
    }
    if(checkbox->isChecked()){
        if(lsystem.languageToString(lsystem.language()) == "Khmer"){
            settings.setValue("combo", "Khmer");
        }
        if(lsystem.languageToString(lsystem.language()) != "Khmer"){
            settings.setValue("combo", "English");
        }
    }
    settings.endGroup();
    qDebug()<<"Save Language";
}

void MainWindow::loadcombobox()
{
    QString savedata = QDir::homePath().append("/.config/Theme Manager/thememanager.ini");
    QSettings settings(savedata, QSettings::IniFormat);
    settings.beginGroup("mainwindow");
    combo->setCurrentText(settings.value("combo").toString());
    checkbox->setTristate(settings.value("checkbox").toBool());
    qDebug()<<"check bool"<<settings.value("checkbox").toBool();
    settings.endGroup();
}
void MainWindow::setenglishlang(){
    QTranslator t;
    t.load(":/i18n/ph.qm");
    qApp->removeTranslator(&t);
    fullmainwindow();
    khmermain->close();
}
void MainWindow::setkhmerlang(){
    QTranslator t;
    t.load(":/i18n/km.qm");
    qApp->installTranslator(&t);
    fullmainwindow();
    englishmain->close();
}
void MainWindow::loadcheckbox(){
    QString savedata = QDir::homePath().append("/.config/Theme Manager/thememanager.ini");
    QSettings settings(savedata, QSettings::IniFormat);
    settings.beginGroup("mainwindow");
    checkbox->setChecked(settings.value("checkbox").toBool());
    combo->setDisabled(settings.value("checkbox").toBool());
    settings.endGroup();
}
void MainWindow::closeanywidget(){
    this->close();
    languagedialog->close();
    khmermain->close();
    englishmain->close();
}

MainWindow::~MainWindow()
{
}

