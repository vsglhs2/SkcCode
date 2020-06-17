#include "test.h"

void Test::zeroing() // Обнуление полей класса
{
    testBlocks.clear();
    testName = "";
    blockAmount = 0;
    testDescription = "";
    maxValue = 0;
    maxQuestions = 0;
    curQuestions = 0;
    cValue = 0;
    testMark = 0;
    cBlockPos = 0;
    cBlockQuestion = 0;
    testTime.min = 0;
    testTime.sec = 0;
    testPercents = 0.0;
    index.clear();
    wrongQuestions.clear();
}

void Test::getTestName(QString testName)
{
    this->testName = testName;
}

void Test::getBlockAmount(int blockAmount)
{
    this->blockAmount = blockAmount;
}

void Test::getTestBlocks(QVector<block>& testBlocks) // Выбор нескольких заданий среди общего количества
{
    unsigned int deltaIndex = 0; // Переменная, обозначающая количество блоков, в которых количество заданий, которое нужно использовать равно нулю
    this->testBlocks.resize(blockAmount);
    for (int i = 0; i < blockAmount; i++)
    {
         this->testBlocks[i - deltaIndex].cQuestionCount = testBlocks[i].cQuestionCount;
         this->testBlocks[i - deltaIndex].questionCount = testBlocks[i].questionCount;
        if (testBlocks[i].cQuestionCount == 0)
        {
            deltaIndex++;
            continue;
        }
         this->testBlocks[i - deltaIndex].questionList.resize( this->testBlocks[i - deltaIndex].cQuestionCount);
         this->testBlocks[i - deltaIndex].name = testBlocks[i].name;

        for (int j = 0; j <  this->testBlocks[i - deltaIndex].cQuestionCount; j++)
        {
            index.push_back(getRand(i - deltaIndex));
             this->testBlocks[i - deltaIndex].questionList[j] = testBlocks[i].questionList[index[j]];
        }

        index.clear();
    }

    blockAmount -= deltaIndex;
    this->testBlocks.resize(blockAmount);
    setMaxValueAndQustionAmount();
}

void Test::getTestDescription(QString testDescription)
{
    this->testDescription = testDescription;
}



void Test::getTestTime(int testTime)
{
    this->testTime.min = testTime / 60;
    this->testTime.sec = testTime - this->testTime.min * 60;
}

void Test::setMaxValueAndQustionAmount()
{
    for (int i = 0; i < blockAmount; i++)
    {
        for (int j = 0; j <  this->testBlocks[i].cQuestionCount; j++)
        {
            maxValue +=  this->testBlocks[i].questionList[j].questionValue;
            maxQuestions++;
        }
    }
}

int Test::getRand(int i)
{
    bool enter = false;
    int r_num = 0;
    while (true)
    {
        enter = false;
        r_num = 0 + rand() %  this->testBlocks[i].questionCount;
        for (int c_index : index)
        {
            if (r_num == c_index)
            {
                enter = true;
                break;
            }
        }

        if (enter == false) return r_num;
    }
}

Test::Test()
{
    srand((unsigned)time(NULL));
    zeroing();
}

QVector<wQuestion>& Test::setWrongQuestions()
{
    return wrongQuestions;
}

float Test::setTestPercents()
{
    return testPercents;
}

int Test::setTestMark()
{
    return testMark;
}

cTime Test::setTestTime()
{
    return testTime;
}

QString Test::setTestName()
{
    return testName;
}

question Test::setCurrentQuestion()
{
    question currentQuestion = testBlocks[cBlockPos].questionList[cBlockQuestion];
    return currentQuestion;
}

QString Test::setCurrentBlockName()
{
    return testBlocks[cBlockPos].name;
}

int Test::setCurQuestion()
{
    return curQuestions + 1;
}

int Test::setMaxQuestion()
{
    return maxQuestions;
}

bool Test::getCurrentAnswer(QString answer) // Проверка ответа
{
    if (QString::compare(answer, testBlocks[cBlockPos].questionList[cBlockQuestion].questionAnswer) == 0) // Если данный ответ правильный,
    {
        cValue += testBlocks[cBlockPos].questionList[cBlockQuestion].questionValue; // То увеличиваем текущий бал,

    }
    else
    {
        wQuestion wQ; // Иначе формируем задание, на которое был неправильно дан ответ
        wQ.name = testBlocks[cBlockPos].name;
        wQ.questionDescription = testBlocks[cBlockPos].questionList[cBlockQuestion].questionDescription;
        wQ.questionRightAnswer = testBlocks[cBlockPos].questionList[cBlockQuestion].questionAnswer;
        wQ.questionWrongAnswer = answer;
        wrongQuestions.push_back(wQ);
    }
    if (curQuestions + 1 >= maxQuestions) // Если текущее количество заданий + 1 >= максимальному количеству заданий, то
    {
        testPercents = float(cValue) / float(maxValue) * 100; // Вычисляем процент полученных балов и оценку за тест
        testPercents = int(testPercents) + (int(100 * (testPercents - int(testPercents))) / 100);
        if (testPercents >= 85) testMark = 5; else
            if (testPercents >= 70) testMark = 4; else
                if (testPercents >= 50) testMark = 3; else
                    testMark = 2;
        return true; // Возвращаем true, что означает, что тест окончен,
    }
    else
    {
    curQuestions++; // Иначе к номеру текущего вопроса прибавляем единицу
    if (cBlockQuestion + 1 >= testBlocks[cBlockPos].cQuestionCount) // Если текущий индекс заданя в блоке + 1 >= количества заданий, используемых в текущем блоке,
    {
        cBlockQuestion = 0; // То текущий индекс задания равен нулю
        cBlockPos++; // И индекс текущего блока увеличивается на один,
    }
    else cBlockQuestion++; // Иначе индекс текущего вопроса увеличивается на единицу
    return false;
    }
}

int Test::setCurBlockPos()
{
    return cBlockPos;
}

int Test::setCurBlockQuestion()
{
    return cBlockQuestion;
}








