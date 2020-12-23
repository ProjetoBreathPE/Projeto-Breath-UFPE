#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDateTime"
#include "qglobal.h"
#include "QRandomGenerator64"

QTime hora(00,00,00);
QRandomGenerator64 gerador;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tempo = new QTimer(this);
    connect(tempo, SIGNAL(timeout()), this, SLOT(atualizaTimer()));
    connect(tempo, SIGNAL(timeout()), this, SLOT(atualizaRelogio()));
    connect(tempo, SIGNAL(timeout()), this, SLOT(generateRandom()));
    tempo->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//função do timer
void MainWindow::atualizaTimer(){
    QTime tempoAtual=hora;
    QString tempoTexto=tempoAtual.toString("hh:mm:ss");
    ui->timer->setText(tempoTexto);
    hora = hora.addSecs(1);
}
//função que mostra a hora atual
void MainWindow::atualizaRelogio(){
    QTime tempoAtual=QTime::currentTime();
    QString tempoTexto=tempoAtual.toString("hh:mm:ss");
    ui->relogio->setText(tempoTexto);
}
//função que gera números aleatórios e os mostra em tempo real
void MainWindow::generateRandom(){
    int num = gerador.generate() & std::numeric_limits<int>::max();
    QString numberTexto = QString::number(num);
    ui->generator->setText(numberTexto);
}

