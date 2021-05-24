#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    dc = new DataContext(Data::Samples::Scenes["prologue"]);
    initialize();
}

void MainWindow::initialize() {
    dbWindow();

    cm = *(new CommandManager(dc));

    // ui->setupUi(this);

    setWindowTitle("NEET Adventures");
    setGeometry(100, 200, 500, 400);
    setMinimumSize(200, 200);

    outputField = new QTextEdit(this);
    outputField->setGeometry(10, 10, 280, 350);
    outputField->setText(dc->scene->desk);
    outputField->setReadOnly(true);

    inputField = new QLineEdit(this);
    inputField->setGeometry(10, 370, 140, 20);

    okButton = new QPushButton(this);
    okButton->setGeometry(155, 370, 35, 20);
    okButton->setText("OK");
    connect(okButton, SIGNAL( released() ), this, SLOT( ok() ));

    saveButton = new QPushButton(this);
    saveButton->setGeometry(200, 370, 40, 20);
    saveButton->setText("Save");
    connect(saveButton, SIGNAL( released() ), this, SLOT( saveDB() ));

    exitButton = new QPushButton(this);
    exitButton->setGeometry(200, 370, 40, 20);
    exitButton->setText("Exit");
    exitButton->setHidden(true);
    connect(exitButton, SIGNAL( released() ), this, SLOT( exitApp() ));

    loadButton = new QPushButton(this);
    loadButton->setGeometry(250, 370, 40, 20);
    loadButton->setText("Load");
    connect(loadButton, SIGNAL( released() ), this, SLOT( loadDB() ));

    QString heroPath = "/home/user/Documents/first_cond.jpeg";
    QImage* heroImage = new QImage(heroPath);
    QString heartPath = "/home/user/Documents/heart.jpg";
    QImage* hrtImage = new QImage(heartPath);
    QString energyPath = "/home/user/Documents/energy.jpg";
    QImage* engImage = new QImage(energyPath);
    QString moodPath = "/home/user/Documents/smile.png";
    QImage* mdImage = new QImage(moodPath);

    heroImg = new QLabel(this);
    heroImg->setGeometry(300, 10, 100, 100);
    QPixmap* heroItem = new QPixmap(QPixmap::fromImage(*heroImage));
    heroImg->setPixmap(heroItem->scaled(100, 100));

    hpImg = new QLabel(this);
    hpImg->setGeometry(300, 120, 30, 30);
    QPixmap* heartItem = new QPixmap(QPixmap::fromImage(*hrtImage));
    hpImg->setPixmap(heartItem->scaled(30, 30));

    energyImg = new QLabel(this);
    energyImg->setGeometry(300, 150, 30, 30);
    QPixmap* energyItem = new QPixmap(QPixmap::fromImage(*engImage));
    energyImg->setPixmap(energyItem->scaled(30, 30));

    moodImg = new QLabel(this);
    moodImg->setGeometry(300, 180, 30, 30);
    QPixmap* moodItem = new QPixmap(QPixmap::fromImage(*mdImage));
    moodImg->setPixmap(moodItem->scaled(30, 30));


    hp = new QLabel(this);
    hp->setGeometry(340, 120, 40, 30);
    hp->setFont(*new QFont("Times New Roman", 14));
    hp->setText(QString::number((*dc->hero)[Hero::HP]));

    energy = new QLabel(this);
    energy->setFont(*new QFont("Times New Roman", 14));
    energy->setGeometry(340, 150, 40, 30);
    energy->setText(QString::number((*dc->hero)[Hero::ENERGY]));

    mood = new QLabel(this);
    mood->setFont(*new QFont("Times New Roman", 14));
    mood->setGeometry(340, 180, 40, 30);
    mood->setText(QString::number((*dc->hero)[Hero::MOOD]));

    days = new QLabel(this);
    days->setFont(*new QFont("Times New Roman", 20));
    days->setGeometry(400, 20, 120, 40);
    days->setText("Дни: " + QString::number(dc->updates % 4));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ok() {
    cm.readCommand(dc, this, inputField->text());
    updateFields();
}

void MainWindow::updateFields() {
    outputField->setText(dc->scene->desk);
    inputField->clear();

    days->setText("Дни: " + QString::number(dc->updates / 3));

    if (++(dc->updates) > 10) {
        QString heroPath = "/home/user/Documents/second_cond.jpeg";
        QImage* heroImage = new QImage(heroPath);
        QPixmap* heroItem = new QPixmap(QPixmap::fromImage(*heroImage));

        heroImg->setPixmap(heroItem->scaled(100, 100));
    }

    hp->setText(QString::number((*dc->hero)[Hero::HP]));
    energy->setText(QString::number((*dc->hero)[Hero::ENERGY]));
    mood->setText(QString::number((*dc->hero)[Hero::MOOD]));

    if (!dc->hero->isAlive()) {
        outputField->setText("Вы не смогли стать полноценным человеком.\n\n\n\nИгра окончена.");
        inputField->setReadOnly(true);
        okButton->setHidden(true);
        saveButton->setHidden(true);
        exitButton->setHidden(false);
    }
}

void MainWindow::save() {
    QString savePath = QFileDialog::getSaveFileName(this, "Choose path to save", "/home/user/Documents/", "Text files (*.txt);;All files (*.*)");
    QFile file(savePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << (*dc->hero)[Hero::HP] << "\n";
    out << (*dc->hero)[Hero::ENERGY] << "\n";
    out << (*dc->hero)[Hero::MOOD] << "\n";
    out << dc->updates << "\n";

    file.close();
}

void MainWindow::load() {
    QString savePath = QFileDialog::getOpenFileName(this, "Choose file to load", "/home/user/Documents/", "Text files (*.txt);;All files (*.*)");
    QFile file(savePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString line = in.readLine();
    (*dc->hero)[Hero::HP]       = line.toInt();
    line = in.readLine();
    (*dc->hero)[Hero::ENERGY]   = line.toInt();
    line = in.readLine();
    (*dc->hero)[Hero::MOOD]     = line.toInt();
    line = in.readLine();
    dc->updates                 = line.toInt();

    file.close();

    inputField->setReadOnly(false);

    updateFields();
}

void MainWindow::saveDB() {
    dbw->rep->create(dc);
}

void MainWindow::loadDB() {
    dbWindow();
    inputField->setReadOnly(false);
    okButton->setHidden(false);
    saveButton->setHidden(false);
    exitButton->setHidden(true);
}

void MainWindow::dbWindow() {
    dbw = new DbWindow();
    connect(dbw, SIGNAL(selected()), this, SLOT(dbSelected()));
}

void MainWindow::dbSelected() {
    dc = dbw->getDataContext();
    updateFields();
    show();
}

void MainWindow::exitApp() {
    QApplication::exit();
}
