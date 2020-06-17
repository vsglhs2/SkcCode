#ifndef ETC_H
#define ETC_H

#include <QFile>
#include <QFileInfo>
#include <QMainWindow>
#include <QPixmap>
#include <QTimer>
#include <QTextBrowser>
#include <QLineEdit>
#include <QVector>
#include <QPushButton>
#include <QWidget>
#include <QMessageBox>
#include <QLabel>
#include <QApplication>
#include <QIcon>
#include <QString>
#include <QTextStream>
#include <QFileDialog>
#include <QFont>

struct wQuestion
{
    QString name = ""; // Название блока, к которому относится задание
    QString questionDescription = ""; // Описание задание, на которое был неправильно дан ответ
    QString questionRightAnswer = ""; // Правильный ответ на задание
    QString questionWrongAnswer = ""; // Ответ, который был дан
};

struct question
{
    QString questionDescription = ""; // Описание задания
    QString questionAnswer = ""; // Ответ на задание
    int questionValue = 0; // Количество балов за правильный ответ на задание
};

struct block
{
    QString name = ""; // Название блока с заданиями
    int questionCount = 0; // Количество заданий в блоке
    int cQuestionCount = 0; // Количество заданий в блоке, которые нужно использовать
    QVector<question> questionList; // Список заданий
};

struct cTime
{
    int min = 0;
    int sec = 0;
};

#endif

