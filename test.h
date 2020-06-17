#ifndef TEST_H
#define TEST_H

#include "etc.h"

class Test
{
private:
    QVector<block> testBlocks; // Блоки с заданиями
    QString testName; // Название теста
    int blockAmount; // Количество блоков
    QString testDescription; // Описание теста
    int maxValue; // Максимальное количество балов
    int maxQuestions; // Максимальное количество заданий
    int curQuestions; // Текущий номер задания
    int cValue; // Текущий бал
    int testMark; // Оценка за тест
    int cBlockPos; // Текущий индекс блока
    int cBlockQuestion; // Текущий индекс задания
    cTime testTime; // Время теста
    float testPercents; // Количество процентов балов, полученных от общего их числа
    QVector<int> index; // Ранее выбранные индексы
    QVector<wQuestion> wrongQuestions; // Задания на которые были неправильно даны ответы

    int getRand(int i); // Получение случайного значения
    void setMaxValueAndQustionAmount(); // Получение максимального числа заданий и максимального бала

public:
    Test();
    void getTestName(QString testName);
    void getBlockAmount(int blockAmount);
    void getTestBlocks(QVector<block> &testBlocks);
    void getTestDescription(QString testDescription);
    void getTestTime(int testTime);
    bool getCurrentAnswer(QString answer);
    QVector<wQuestion>& setWrongQuestions();

    float setTestPercents();
    int setTestMark();
    cTime setTestTime();
    QString setTestName();
    question setCurrentQuestion();
    QString setCurrentBlockName();
    int setMaxQuestion();
    int setCurQuestion();
    int setCurBlockPos();
    int setCurBlockQuestion();

    void zeroing(); // Обнуление полей класса

};

#endif
