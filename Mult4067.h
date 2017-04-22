/* Mult4067 библиотека для работы
 16-канальными аналоговыми цифровыми мультиплексорами CD74HC4067  
 Автор - Захаров Леонид.
 Создана по материалам сайтов 
 http://arduino.ru/Hacking/LibraryTutorial
 http://mypractic.ru/urok-9-sozdanie-biblioteki-dlya-arduino.html 
 http://forum.amperka.ru/threads/Подключение-мультиплексора.1400/ */


#ifndef Mult4067_h // если библиотека не подключена
#define Mult4067_h // тогда подключаем ее

//#include "WProgram.h"  // Это нужно для Arduino IDE версий до 1.0

#include "Arduino.h"     /* содержащит стандартные константы и переменные языка Ардуино. 
В обычных программах он добавляется автоматически, а для библиотеки должен быть указан явно.*/

class Mult4067    // Класс обработки сигналов с мультиплексора
{
  public:
    Mult4067 (int dPin_S0, int dPin_S1, int dPin_S2, int dPin_S3, int AnSign);  // Конструктор
    int anData[16];    // Массив для данных с аналоговых входов мультиплексора     
    void anRead();     // Функция считывания данных с аналоговых входов мультиплексора 

    
  private:             // Локальные переменные
  int _dPin_S0;       
  int _dPin_S1;
  int _dPin_S2;
  int _dPin_S3;
  int _AnSign;
};

#endif


