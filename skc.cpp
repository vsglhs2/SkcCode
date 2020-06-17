#include "skc.h"

void Skc::ftGroupHide()           // Выключение отображения первой группы виджетов
{
    ftTextBrowser1->hide();
    ftButton1->hide();
    sdButton1->hide();
    tdButton1->hide();
    fhButton1->hide();
    ftLabel1->hide();
    sdLabel1->hide();
    ftLineEdit1->hide();
    sdLineEdit1->hide();
}

void Skc::ftGroupShow()           // Включение отображения первой группы виджетов
{
    ftTextBrowser1->show();
    ftButton1->show();
    sdButton1->show();
    tdButton1->show();
    fhButton1->show();
    ftLabel1->show();
    sdLabel1->show();
    ftLineEdit1->show();
    sdLineEdit1->show();
}

void Skc::sdGroupHide()           // Выключение отображения второй группы виджетов
{
    ftTextBrowser2->hide();
    ftButton2->hide();
    sdButton2->hide();
    ftLineEdit2->hide();
    ftLabel2->hide();
    sdLabel2->hide();
    tdLabel2->hide();
    fhLabel2->hide();
    feLabel2->hide();
    sxLabel2->hide();
    snLabel2->hide();
}

void Skc::sdGroupShow()           // Включение отображения второй группы виджетов
{
    ftTextBrowser2->show();
    ftButton2->show();
    sdButton2->show();
    ftLineEdit2->show();
    ftLabel2->show();
    sdLabel2->show();
    tdLabel2->show();
    fhLabel2->show();
    feLabel2->show();
    sxLabel2->show();
    snLabel2->show();
}

void Skc::tdGroupHide()          // Выключение отображения третьей группы виджетов
{
    ftTextBrowser3->hide();
    ftButton3->hide();
    sdButton3->hide();
    tdButton3->hide();
    fhButton3->hide();
}

void Skc::tdGroupShow()          // Включение отображения третьей группы виджетов
{
    ftTextBrowser3->show();
    ftButton3->show();
    sdButton3->show();
    tdButton3->show();
    fhButton3->show();
}

void Skc::ftGroupInit()          // Инициализация первой группы виджетов
{
    ftTextBrowser1 = new QTextBrowser(this);
    ftTextBrowser1->setGeometry(10, 10, 462, 242);
    ftTextBrowser1->setFont(textFont);
    ftTextBrowser1->setText("Добро пожаловать в \"Систему контроля знаний\". Пожалуйста, выберите файл с тестом и нажмите кнопку \"начать тест\", чтобы продолжить.");

    ftButton1 = new QPushButton("Открыть тест", this);
    ftButton1->setGeometry(10, 258, 88, 24);
    ftButton1->setFont(testFont);
    sdButton1 = new QPushButton("Начать тест", this);
    sdButton1->setGeometry(10, 288, 88, 24);
    sdButton1->setFont(testFont);
    tdButton1 = new QPushButton("Выход", this);
    tdButton1->setGeometry(397, 258, 75, 24);
    tdButton1->setFont(testFont);
    fhButton1 = new QPushButton("Информация", this);
    fhButton1->setGeometry(397, 288, 75, 24);
    fhButton1->setFont(testFont);

    ftLabel1 = new QLabel("Имя", this);
    ftLabel1->setGeometry(123, 258, 47, 24);
    ftLabel1->setFont(testFont);
    sdLabel1 = new QLabel("Фамилия", this);
    sdLabel1->setGeometry(123, 288, 47, 24);
    sdLabel1->setFont(testFont);

    ftLineEdit1 = new QLineEdit(this);
    ftLineEdit1->setGeometry(195, 259, 177, 24);
    ftLineEdit1->setFont(testFont);
    ftLineEdit1->setText("");
    sdLineEdit1 = new QLineEdit(this);
    sdLineEdit1->setGeometry(195, 289, 177, 24);
    sdLineEdit1->setFont(testFont);
    sdLineEdit1->setText("");

}

void Skc::sdGroupInit()                      // Инициализация второй группы виджетов
{
    testTimer = new QTimer(this);
    ftTextBrowser2 = new QTextBrowser(this);
    ftTextBrowser2->setGeometry(10, 32, 463, 183);
    ftTextBrowser2->setFont(textFont);

    ftButton2 = new QPushButton("Ввод", this);
    ftButton2->setGeometry(354, 221, 119, 23);
    ftButton2->setFont(testFont);
    sdButton2 = new QPushButton("Досрочное завершение", this);
    sdButton2->setGeometry(175, 221, 169, 23);
    sdButton2->setFont(testFont);
    ftLabel2 = new QLabel("", this);        // Название блока с заданиями
    ftLabel2->setGeometry(10, 10, 109, 16);
    ftLabel2->setFont(testFont);
    sdLabel2 = new QLabel("", this);        // Имя Фамилия
    sdLabel2->setGeometry(125, 10, 223, 16);
    sdLabel2->setFont(testFont);
    tdLabel2 = new QLabel("", this);        // Осталось времени
    tdLabel2->setGeometry(440, 10, 32, 16);
    tdLabel2->setFont(testFont);
    fhLabel2 = new QLabel("Введите ответ:", this);
    fhLabel2->setGeometry(10, 221, 155, 23);
    fhLabel2->setFont(testFont);
    feLabel2 = new QLabel("", this);        // Название теста
    feLabel2->setGeometry(10, 295, 223, 16);
    feLabel2->setFont(testFont);
    sxLabel2 = new QLabel("", this);        // Выполненных заданий из общего количества заданий
    sxLabel2->setGeometry(239, 295, 109, 16);
    sxLabel2->setFont(testFont);
    snLabel2 = new QLabel("", this);        // Балов за задание
    snLabel2->setGeometry(354, 295, 119, 16);
    snLabel2->setFont(testFont);

    ftLineEdit2 = new QLineEdit(this);
    ftLineEdit2->setGeometry(10, 250, 463, 20);
    ftLineEdit2->setFont(testFont);
}

void Skc::tdGroupInit() // Инициализация третьей группы виджетов
{
    ftTextBrowser3 = new QTextBrowser(this);
    ftTextBrowser3->setGeometry(9, 9, 464, 246);
    ftTextBrowser3->setFont(textFont);

    ftButton3 = new QPushButton("Перейти в главное меню", this);
    ftButton3->setGeometry(9, 261, 229, 23);
    ftButton3->setFont(testFont);
    sdButton3 = new QPushButton("Сохранить результаты теста", this);
    sdButton3->setGeometry(9, 290,229, 23);
    sdButton3->setFont(testFont);
    tdButton3 = new QPushButton("Пройти тест ещё раз", this);
    tdButton3->setGeometry(244, 261, 229, 23);
    tdButton3->setFont(testFont);
    fhButton3 = new QPushButton("Выход", this);
    fhButton3->setGeometry(244, 290, 229, 23);
    fhButton3->setFont(testFont);
}

void Skc::saveFile() // Сохранение результатов теста в файл
{
    QString cFileName = outputObj.fileSave();
    if (QString::compare(cFileName, "") == 0) messageBox("Файл для сохранения не выбран. Пожалуйста, попробуйте снова.", 2); // Если файл не был выбран, то извещаем об этом,
    else messageBox("Файл с результатами теста сохранён по пути: " + cFileName, 1);                                          // Иначе информируем о пути сохраненного файла
}

void Skc::restartTest()               // Перезапуск теста без ввода имени и фамилии и открытия файла с тестом
{
    testObj.zeroing();                // Обнуление полей класса
    outputObj.zeroing();              // Обнуление полей класса
    testObjLoad();                    // Загрузка данных из класса Input в класс Test
    testTime = testObj.setTestTime(); // Получение количества времени, выделенног она тест
    setTimeText();                    // Обновление оставшегося времени теста
    testTimer->start(1000);           // Старт таймера, посылающего сигналы каждую секунду
    ftGroupHide();                    // Выключение отображения первой группы виджетов
    tdGroupHide();                    // Выключение отображения третьей группы виджетов
    sdGroupShow();                    // Включение отображения второй группы виджетов
    testFrameMovement();              // Отображение первого задания в тесте

    isTimerEnd = false;               // Таймер не остановлен
    doneTest = false;                 // Тест не закончен
}

void Skc::restartMenu()               // Вход в главное меню
{
    inputObj.zeroing();               // Обнуление полей класса
    testObj.zeroing();                // Обнуление полей класса
    outputObj.zeroing();              // Обнуление полей класса
    sdGroupHide();                    // Выключение отображения первой группы виджетов
    tdGroupHide();                    // Выключение отображения первой группы виджетов
    ftGroupShow();                    // Включение отображения первой группы виджетов
    ftTextBrowser1->setText("Добро пожаловать в \"Систему контроля знаний\". Пожалуйста, выберите файл с тестом и нажмите кнопку \"начать тест\", чтобы продолжить.");

    ftLineEdit1->clear();             // Очищение поля для ввода имени
    sdLineEdit1->clear();             // Очищение поля для ввода фамилии
    testTime.min = 0;                 // Обнуление количества минут, данных на тест
    testTime.sec = 0;                 // Обнуление количества секунд, данных на тест
    isOpen = false;
    isNamed = false;
    isTimerEnd = false;
    doneTest = false;
    fileName = "";
    firstName = "";
    secondName = "";
}

void Skc::testObjLoad()               // Загрузка данных из класса Input в класс Test
{
    testObj.getTestName(inputObj.setTestName());
    testObj.getTestDescription(inputObj.setTestDescription());
    testObj.getTestTime(inputObj.setTestTime());
    testObj.getBlockAmount(inputObj.setBlockAmount());
    testObj.getTestBlocks(inputObj.setTestBlocks());
}

void Skc::outputObjLoad()             // Загрузка данных из класса Test в класс Output
{
    cTime bufferTestTime;
    int bufferSec;
    bufferSec = (testObj.setTestTime().min - setTestTime().min) * 60 + testObj.setTestTime().sec - setTestTime().sec;
    bufferTestTime.min = bufferSec / 60;
    bufferTestTime.sec = bufferSec - bufferTestTime.min * 60;
    outputObj.getTestName(testObj.setTestName());
    outputObj.getTestPercents(testObj.setTestPercents());
    outputObj.getTestMark(testObj.setTestMark());
    outputObj.getTestTime(bufferTestTime);
    outputObj.getWrongQuestions(testObj.setWrongQuestions());
}

void Skc::testFrameMovement()         // Отображение следующего задания в тесте
{
    ftLineEdit2->clear();
    feLabel2->setText(testObj.setTestName());
    ftLabel2->setText(testObj.setCurrentBlockName());
    sdLabel2->setText(firstName + " " + secondName);
    sxLabel2->setText(QString::number(testObj.setCurQuestion()) + "/" + QString::number(testObj.setMaxQuestion()));
    cQuestion = testObj.setCurrentQuestion();
    snLabel2->setText("Балов за задание: " + QString::number(cQuestion.questionValue));
    ftTextBrowser2->setText(cQuestion.questionDescription);
}

void Skc::infoMessageBox() // Обображение информации о программе
{
    messageBox("Эта программа предназначена для выполнения пользователями тестов. Для того, чтобы пройти один из них, выберите нужный файл, введите свои имя и фамилию, и нажмите на кнопку \"начать тест\". Далее выполняйте задания, после завершения которых вы получите информацию о результатах пройденного вами теста.", 1);
}

void Skc::messageBox(QString boxText, int boxType) // Вызов диалогового окна
{
    QMessageBox mBox;
    mBox.setText("Внимание!");
    switch(boxType)
    {
        case 1: mBox.setWindowTitle("Информирование"); break;
        case 2: mBox.setWindowTitle("Предупреждение"); break;
    }
    QPixmap pixmap(":/icons/iconMini.png");
    mBox.setWindowIcon(pixmap);
    mBox.setInformativeText(boxText);
    mBox.setDefaultButton(QMessageBox::Ok);
    switch(boxType)
    {
    case 1: mBox.setIcon(QMessageBox::Information); break;
    case 2: mBox.setIcon(QMessageBox::Warning); break;
    }
    mBox.exec();
}

Skc::Skc(QWidget *parent)
    : QWidget(parent)

{
    testFont.setPixelSize(11); // Установка размера шрифта
    textFont.setPixelSize(14); // Установка размера шрифта

    ftGroupInit(); // Инициализация первой группы виджетов
    sdGroupInit(); // Инициализация второй группы виджетов
    tdGroupInit(); // Инициализация третьей группы виджетов
    sdGroupHide(); // Выключение отображения второй группы виждетов
    tdGroupHide(); // Выключение отображения третьей группы виждетов

    // Подключение кнопок
    connect(sdButton1, &QPushButton::clicked, this, &Skc::sdPage);
    connect(tdButton1, &QPushButton::clicked, qApp, &QApplication::exit);
    connect(ftButton1, &QPushButton::clicked, this, &Skc::getFilename);
    connect(fhButton1, &QPushButton::clicked, this, &Skc::infoMessageBox);
    connect(ftButton2, &QPushButton::clicked, this, &Skc::doTest);
    connect(fhButton3, &QPushButton::clicked, qApp, &QApplication::exit);
    connect(ftButton3, &QPushButton::clicked, this, &Skc::restartMenu);
    connect(tdButton3, &QPushButton::clicked, this, &Skc::restartTest);
    connect(sdButton3, &QPushButton::clicked, this, &Skc::saveFile);
    connect(testTimer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    connect(sdButton2, &QPushButton::clicked, this, &Skc::testStop);
}

void Skc::resultLoad() // Отображение результатов теста
{
    outputObjLoad(); // Загрузка данных из класса Test в класс Output
    sdGroupHide(); // Выключение отображения второй группы виждетов
    tdGroupShow(); // Выключение отображения третьей группы виждетов

    testTimer->stop(); // Остановка таймера

    // Формирование результатов теста
    QString textString = "Имя тестируемого: " + firstName + " " + secondName +
                         "\nНазвание теста: " + outputObj.setTestName() +
                         "\nВ тесте было набрано " + QString::number(outputObj.setTestPercents()) + "% от общего количества балов и получена оценка " + QString::number(outputObj.setTestMark()) +
                         ".\nТест был завершён за время " + QString::number(outputObj.setTestTime().min) + " минут " + QString::number(outputObj.setTestTime().sec) + " секунд.";
    if (!outputObj.setWrongQuestions().isEmpty())
    {
        textString +=    "\nНиже представлены задания, на которые были неправильно даны ответы:\n\n";
        for (auto &cQuestion : outputObj.setWrongQuestions())
        {
            textString += "Название блока с заданиями: " + cQuestion.name +
                          "\nОписание задания: " + cQuestion.questionDescription +
                          "\nПравильный ответ на задание: " + cQuestion.questionRightAnswer +
                          "\nОтвет, который был дан: " + cQuestion.questionWrongAnswer + "\n\n";
         }
    }
    ftTextBrowser3->setText(textString);
    outputObj.getFirstName(firstName);
    outputObj.getSecondName(secondName);
}

void Skc::doTest() // Обновление текущего задания теста
{
    if (QString::compare(ftLineEdit2->text(), "") != 0 && !isTimerEnd) // Если строка, куда нужно вписать ответ, не пуста, и таймер не кончился, то
    {
        doneTest = testObj.getCurrentAnswer(ftLineEdit2->text()); // Проверка ответа
        if (!doneTest) testFrameMovement(); // Если тест не окончен, то отображаем следующее задание,
        else resultLoad(); // Иначе загружаем результаты

    }
}

void Skc::testStop()
{
    while (!doneTest) // Пока не кончатся вопросы, устанавлимаем ответ
    {
        doneTest = testObj.getCurrentAnswer("Ответ не был дан.");
    }
    resultLoad(); // Загружаем результаты
}

void Skc::setTimeText() // Отображение времени до завершения теста
{
    tdLabel2->setText(((testTime.min < 10) ? "0" + QString::number(testTime.min) : QString::number(testTime.min))  + ":" + ((testTime.sec < 10) ? "0" + QString::number(testTime.sec) : QString::number(testTime.sec)));
}

void Skc::timerUpdate() // Обновление таймера
{

    if (testTime.sec - 1 >= 0) --testTime.sec;
    else
    if (testTime.min - 1 >= 0)
    {
        testTime.sec = 59;
        --testTime.min;
    }
    else
    {
        isTimerEnd = true;
    }

    if (!isTimerEnd) setTimeText(); // Если таймер еще идет, то отображаем оставшееся время, иначе
    else
    {
        while (!doneTest) // Пока не кончатся вопросы, устанавлимаем ответ
        {
            doneTest = testObj.getCurrentAnswer("Ответ не был дан.");
        }
        resultLoad(); // И загружаем результаты
    }
}


void Skc::sdPage() // "Открытие" страницы с тестом
{
    firstName = ftLineEdit1->text();
    secondName = sdLineEdit1->text();
    if (ftLineEdit1->text() == "" || sdLineEdit1->text() == "") isNamed = false; else isNamed = true;
    if (isOpen && isNamed)
    {
        testObjLoad(); // Загрузка данных из класса Input в класс Test
        ftGroupHide(); // Выключение отображения первой группы виджетов
        sdGroupShow(); // Включение отображения первой группы виджетов
        testTime = testObj.setTestTime(); // Установка времени
        setTimeText(); // Отображение времени, данного на тест
        testTimer->start(1000); // Запуск таймера, который каждую секунды отправляет сигнал
        testFrameMovement(); // Отображение первого задания теста
    }
    else
    {
        if (!isOpen) messageBox("Выбранный вами файл не соответствует требованиям программы! Пожалуйста, попробуйте ещё раз.", 2);
        else if (!isNamed) messageBox("Имя и(или) фамилия не были введены. Пожалуйста, введите их для успешного запуска теста.", 2);
    }
}

void Skc::getFilename() // Получение пути к файлу
{

    fileName = QFileDialog::getOpenFileName(); // Получение пути к файлу
    isOpen = inputObj.input(fileName); // Проверка на то, является ли выбранный файл тестом, и если является, то загрузка его данных в программу
    if(!isOpen) ftTextBrowser1->setText("Выбранный вами файл не содержит теста. Пожалуйста, выберите новый файл."); // Если файл не открыт, то выводим сообщение об этом
    else
    {
        QString textString = "Название теста: ";
        textString += inputObj.setTestName();
        textString += "\nОписание теста: ";
        textString += inputObj.setTestDescription();
        textString += "\nНа тест отведено: " + QString::number(inputObj.setTestTime() / 60) + " минут " + QString::number(inputObj.setTestTime() - (inputObj.setTestTime() / 60) * 60) + " секунд.";
        textString += "\n\nДля получения оценки \"5\" необходимо набрать 85%, для оценки \"4\" - 70%, для оценки \"3\" - 50%.";
        ftTextBrowser1->setText(textString);
    }
}

QString Skc::setFirstName()
{
    return firstName;
}

QString Skc::setSecondName()
{
    return secondName;
}

cTime Skc::setTestTime()
{
    return testTime;
}

Skc::~Skc()
{

}
