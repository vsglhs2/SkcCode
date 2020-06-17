#include "input.h"

void Input::zeroing() // Обнуление полей класса
{
    testName = "";
    testDescription = "";
    testBlocks.clear();
    blockAmount = 0;
    testTime = 0;
    isOpen = false;
}

Input::Input()
{
    zeroing();
}

bool Input::input(QString fileName)
{
    QFile c_file(fileName); // Создание объекта класса QFile
    QString buffer = ""; // Создание буффера, с помощью которого будет считываться тест из файла
    if (!c_file.open(QIODevice::ReadOnly) ) isOpen = false; else isOpen = true; // Открывается файл для чтения и делается проверка на то, открылся ли файл

    QTextStream textStream(&c_file); // Создается поток для чтения с файла
    buffer = textStream.readLine(); // Чтение ключа
    if (QString::compare(buffer, testKey) == 0) // Если полученная строка - ключ, тогда файл - тест, следовательно можно продолжать считывание
    {
    isOpen = true;

    testName = textStream.readLine(); // Считывание названия теста
    testDescription = textStream.readLine(); // Считывание опсания теста
    testTime = textStream.readLine().toInt(); // Считывание времни теста в секундах
    blockAmount  = textStream.readLine().toInt(); // Считывание количества блоков с заданиями
    testBlocks.resize(blockAmount); // Изменение размера вектора с блоками
    for (int i = 0; i < blockAmount; i++) // Считывание блоков в цикле в формате:
    {
        testBlocks[i].name = textStream.readLine(); // Считывание названия блока
        testBlocks[i].questionCount = textStream.readLine().toInt(); // Считывание общего количества заданий в блоке
        testBlocks[i].cQuestionCount = textStream.readLine().toInt(); // Считывание количества заданий в блоке, которые нужно использовать
        testBlocks[i].questionList.resize(testBlocks[i].questionCount); // Изменение размерности вектора с заданиями
        for (int j = 0; j < testBlocks[i].questionCount; j++) // Считывание самих заданий в цикле в формате:
        {
            testBlocks[i].questionList[j].questionDescription = textStream.readLine(); // Считывание описания задания
            testBlocks[i].questionList[j].questionAnswer = textStream.readLine(); // Считывание правильного ответа на задание
            testBlocks[i].questionList[j].questionValue = textStream.readLine().toInt(); // Считывание количества балов за правильный ответ на задание
        }
    }
    }
    else isOpen = false;
    c_file.close();
    return isOpen;
}

QString &Input::setTestName()
{
    return testName;
}

QString &Input::setTestDescription()
{
    return testDescription;
}

QVector<block> &Input::setTestBlocks()
{
    return testBlocks;
}

int Input::setBlockAmount()
{
    return blockAmount;
}

int Input::setTestTime()
{
    return testTime;
}
