/* Mult4067 библиотека для работы
 16-канальными аналоговыми цифровыми мультиплексорами CD74HC4067  
 Автор - Захаров Леонид.
 Создана по материалам сайтов 
 http://arduino.ru/Hacking/LibraryTutorial
 http://mypractic.ru/urok-9-sozdanie-biblioteki-dlya-arduino.html 
 http://forum.amperka.ru/threads/Подключение-мультиплексора.1400/
 
  Вызов метода считывания данных:
  [созданный объект].anRead();
  Пример: mult40671.anRead();
  
  Получение данных:
  [переменная]=[созданный объект].anData[номер канала на мультиплексоре];
  Пример: value = mult40671.anData[9];*/


#include <Mult4067.h> // Подключаем библиотеку

const int S0_1 = 2; // Определяем цифровые пины для поключения мультиплексора 1
const int S1_1 = 3;
const int S2_1 = 4;
const int S3_1 = 5;
const int S0_2 = 6; // Определяем цифровые пины для поключения мультиплексора 2
const int S1_2 = 7;
const int S2_2 = 8;
const int S3_2 = 9;

const int AnPin_1 = 3; // Определяем аналоговый пин для поключения мультиплексора 1
const int AnPin_2 = 4; // Определяем аналоговый пин для поключения мультиплексора 2


// Создаем объекты для мультиплексоров в соответствии с их количеством
Mult4067 mult40671(S0_1,S1_1,S2_1,S3_1,AnPin_1);   // Создаем объект для мультиплексора 1
Mult4067 mult40672(S0_2,S1_2,S2_2,S3_2,AnPin_2);   // Создаем объект для мультиплексора 2

void setup() {
  pinMode(S0_1, OUTPUT);   // Определяем цифровые пины на выход
  pinMode(S1_1, OUTPUT);
  pinMode(S2_1, OUTPUT);
  pinMode(S3_1, OUTPUT);
  pinMode(S0_2, OUTPUT);
  pinMode(S1_2, OUTPUT);
  pinMode(S2_2, OUTPUT);
  pinMode(S3_2, OUTPUT);
  
Serial.begin(9600);
}

void loop() {
mult40671.anRead();    // Вызов метода считывания параметров с аналоговых входов мультиплексора 1
  for(int i = 0; i < 16; i++)  // Выводим параметры
    PrintResult_1(i);
delay(2000);

mult40672.anRead();    // Вызов метода считывания параметров с аналоговых входов мультиплексора 2
  for(int i = 0; i < 16; i++)  // Выводим параметры
    PrintResult_2(i);
delay(5000);
}

void PrintResult_1(int anInMult_1)
{
  Serial.print(" anInMult_1 ");
  Serial.print(anInMult_1);
  Serial.print(" = ");
  Serial.println(mult40671.anData[anInMult_1]); // Получаем данные с аналогового входа мультиплексора № anInMult_1
}

void PrintResult_2(int anInMult_2)
{
  Serial.print(" anInMult_2 ");
  Serial.print(anInMult_2);
  Serial.print(" = ");
  Serial.println(mult40672.anData[anInMult_2]);  // Получаем данные с аналогового входа мультиплексора № anInMult_2
}
