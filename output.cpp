#include "output.h"

void Output::zeroing() // Обнуление полей класса
{
    testName = "";
    firstName = "";
    secondName = "";
    wrongQuestions.clear();
    testMark = 0;
    testPercents = 0.0;
    testTime.min = 0;
    testTime.sec = 0;
}

void Output::getTestPercents(float testPercents)
{
    this->testPercents = testPercents;
}

void Output::getWrongQuestions(QVector<wQuestion>& wrongQuestions)
{
   this->wrongQuestions = wrongQuestions;
}

void Output::getTestTime(cTime testTime)
{
    this->testTime = testTime;
}

void Output::getTestName(QString testName)
{
    this->testName = testName;
}

void Output::getTestMark(int testMark)
{
    this->testMark = testMark;
}

void Output::getFirstName(QString firstName)
{
    this->firstName = firstName;
}

void Output::getSecondName(QString secondName)
{
    this->secondName = secondName;
}

Output::Output()
{
    zeroing();
}

QString Output::fileSave() // Сохранение результатов в файл
{
    QString fileName = QFileDialog::getSaveFileName(); // Получение пути файла, в который нужно сохранить результаты теста
    if (QString::compare(fileName, "") == 0) return ""; // Проверка на то, пустой ли путь, полученный предыдущи шагом
    else
    {
        if (fileName.lastIndexOf(".txt", fileName.size() - 1) == -1) fileName += ".txt"; // Проверка на то, есть ли в конце пути файла .txt. Если нет, то дабавляем.
        QFile fileSave(fileName);
        fileSave.open(QIODevice::WriteOnly); // Окрытие файла только для записи
        QTextStream outFile(&fileSave); // Создание потока для записи результатов теста

        // Формирование выходных рещультатов
        QString textString = "Имя тестируемого: " + firstName + " " + secondName +
                             "\nНазвание теста: " + testName +
                          "\nВ тесте было набрано " + QString::number(testPercents) + "% от общего количества балов и получена оценка " + QString::number(testMark) +
                          " за время " + QString::number(testTime.min) + " минут " + QString::number(testTime.sec) + " секунд.";
        if (!wrongQuestions.isEmpty())
        {
            textString +=    "\nНиже представлены задания, на которые были неправильно даны ответы:\n\n";
            for (auto &cQuestion : wrongQuestions)
            {
                textString += "Название блока с заданиями: " + cQuestion.name +
                              "\nОписание задания: " + cQuestion.questionDescription +
                              "\nПравильный ответ на задание: " + cQuestion.questionRightAnswer +
                              "\nОтвет, который был дан: " + cQuestion.questionWrongAnswer + "\n\n";
            }
        }
        outFile << textString;
        fileSave.close();
        return fileName;
    }
}

float Output::setTestPercents()
{
    return testPercents;
}

QVector<wQuestion> &Output::setWrongQuestions()
{
    return wrongQuestions;
}

cTime Output::setTestTime()
{
    return testTime;
}

QString Output::setTestName()
{
    return testName;
}

int Output::setTestMark()
{
    return testMark;
}







