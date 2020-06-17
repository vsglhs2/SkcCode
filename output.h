#ifndef OUTPUT_H
#define OUTPUT_H

#include "etc.h"

class Output
{
private:
    QString testName; // Назавание теста
    QString firstName; // Имя тестируемого
    QString secondName; // Фамилия тестируемого
    QVector<wQuestion> wrongQuestions; // Вектор с неправильно отвеченными заданиями
    int testMark; // Оценка за тест
    float testPercents; // Количество процентов балов, полученных от общего их числа
    cTime testTime; // Время в минутах и секундах, за которые был пройден тест
public:
    Output();
    void getTestPercents(float testPercents);
    void getWrongQuestions(QVector<wQuestion>& wrongQuestions);
    void getTestTime(cTime testTime);
    void getTestName(QString testName);
    void getTestMark(int testMark);
    void getFirstName(QString firstName);
    void getSecondName(QString secondName);

    QString fileSave(); // Метод, сохраняющий результаты теста
    void zeroing(); // Метод, обнуляющий поля класса

    float setTestPercents();
    QVector <wQuestion> &setWrongQuestions();
    cTime setTestTime();
    QString setTestName();
    int setTestMark();
};

#endif
