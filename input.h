#ifndef INPUT_H
#define INPUT_H

#include "etc.h"

class Input
{
private:
    QString testName; // Название теста
    QString testDescription; // Описание теста
    QVector<block> testBlocks; // Блоки с заданиями
    int blockAmount; // Количество блоков с заданиями
    int testTime; // Время в секундах
    bool isOpen = false; // Был ли открыт файл с тестом
    QString testKey = "58979478"; // Ключ, по которому программа определяет, является ли выбранный файл тестом
public:
    Input();
    void zeroing();
    bool input(QString fileName);
    QString &setTestName();
    QString &setTestDescription();
    QVector<block> &setTestBlocks();
    int setBlockAmount();
    int setTestTime();
};

#endif
