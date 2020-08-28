#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QToolButton>
#include <QPushButton>
#include <QTranslator>
#include <QInputDialog>
#include <QComboBox>
#include <QSettings>
#include <QRect>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void currentClick();
private:

    void savelanguage();
    void loadcombobox();
    void fullmainwindow();
    void setenglishlang();
    void setkhmerlang();
    void loadcheckbox();
    void khmersystemlangtool();
    void englishsystemlangtool();
    void closeanywidget();

    QVBoxLayout *langlayout = new QVBoxLayout(this);
    QHBoxLayout* comboxlabellayout = new QHBoxLayout(this);
    QHBoxLayout* buttonlayout = new QHBoxLayout(this);
public:
    MainWindow(QWidget *parent = nullptr);
    QToolButton* Thumbnail(
            QToolButton* Button,
            const QString &Name,
            const QString &ImagePath);
    QPushButton* ConfirmButton(QPushButton* Button,
                               const QString &Name,
                               const QString &IconName);

    QWidget *LastWidget = new QWidget;
    QDialog *languagedialog = new QDialog(this);
    QMainWindow *englishmain = new QMainWindow(this);
    QMainWindow *khmermain = new QMainWindow(this);

    QTranslator translator;
    QComboBox* combo = new QComboBox(this);
    QCheckBox* checkbox = new QCheckBox(this);
    QLabel* label = new QLabel(this);
    QPushButton* applybutton = new QPushButton(this);
    QPushButton* cancelbutton = new QPushButton(this);

    int selected = 0;
    int index;
    ~MainWindow();
};
#endif // MAINWINDOW_H

