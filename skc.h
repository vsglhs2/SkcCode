#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "etc.h"
#include "input.h"
#include "test.h"
#include "output.h"

class Skc : public QWidget
{
    Q_OBJECT

public:
    Skc(QWidget *parent = nullptr);
    ~Skc();
    QString setFirstName();
    QString setSecondName();
    cTime setTestTime();

private slots:
    void sdPage();
    void getFilename();
    void infoMessageBox();
    void doTest();
    void saveFile();
    void restartTest();
    void restartMenu();
    void testStop();
    void timerUpdate();
private:
    cTime testTime;

    bool isOpen = false; // Был ли открыт файл с тестом
    bool isNamed = false; // Были ли введены имя и фамилия пользователя
    bool isTimerEnd = false; // Закончилось ли время теста
    bool doneTest = false; // Закончился ли тест

    Input inputObj;
    Test testObj;
    Output outputObj;
    question cQuestion; // Текущее задание

    QTimer *testTimer;
    QString fileName;
    QString firstName;
    QString secondName;
    QFont testFont;
    QFont textFont;

    // Первая группа виджетов
    QTextBrowser *ftTextBrowser1;
    QPushButton *ftButton1;
    QPushButton *sdButton1;
    QPushButton *tdButton1;
    QPushButton *fhButton1;
    QLabel *ftLabel1;
    QLabel *sdLabel1;
    QLineEdit *ftLineEdit1;
    QLineEdit *sdLineEdit1;

    // Вторая группа виджетов
    QTextBrowser *ftTextBrowser2;
    QLabel *ftLabel2;
    QLabel *sdLabel2;
    QLabel *tdLabel2;
    QLabel *fhLabel2;
    QLabel *feLabel2;
    QLabel *sxLabel2;
    QLabel *snLabel2;
    QPushButton *ftButton2;
    QPushButton *sdButton2;
    QLineEdit *ftLineEdit2;

    // Третья группа виджетов
    QTextBrowser *ftTextBrowser3;
    QPushButton *ftButton3;
    QPushButton *sdButton3;
    QPushButton *tdButton3;
    QPushButton *fhButton3;

    // Методы, позволяющие либо скрывать, либо показывать группы виджетов
    void ftGroupHide();
    void ftGroupShow();
    void sdGroupHide();
    void sdGroupShow();
    void tdGroupHide();
    void tdGroupShow();
    void ftGroupInit();
    void sdGroupInit();
    void tdGroupInit();

    void testObjLoad(); // Метод, загружающий необходимые данные из класса Input в класс Test
    void outputObjLoad(); // Метод, загружающий необходимые данные из класса Test в класс Output
    void resultLoad(); // Отображение результатов теста
    void testFrameMovement(); // Отображение следующего задания в тесте
    void setTimeText();

    void messageBox(QString boxText, int boxType); // Выхов диалогового окна
};
#endif
