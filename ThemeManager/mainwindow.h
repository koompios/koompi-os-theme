#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QToolButton>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QToolButton* Thumbnail(
            QToolButton* Button,
            const QString &Name,
            const QString &ImagePath);
    QPushButton* ConfirmButton(QPushButton* Button,
                               const QString &Name,
                               const QString &IconName);

    int selected = 0;
    ~MainWindow();
};
#endif // MAINWINDOW_H



