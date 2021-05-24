#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dbwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void updateFields();
    ~MainWindow();
    void dbWindow();

private:
    void initialize();
    DataContext* dc;
    CommandManager cm;

    Ui::MainWindow *ui;
    QTextEdit* outputField;
    QLineEdit* inputField;
    QPushButton* okButton;
    QPushButton* saveButton;
    QPushButton* loadButton;
    QPushButton* exitButton;
    QLabel* heroImg;
    QLabel* hpImg;
    QLabel* energyImg;
    QLabel* moodImg;
    QLabel* hp;
    QLabel* energy;
    QLabel* mood;
    QLabel* days;
    DbWindow* dbw;

private slots:
    void ok();
    void save();
    void load();
    void saveDB();
    void loadDB();
    void dbSelected();
    void exitApp();
};

#endif // MAINWINDOW_H
