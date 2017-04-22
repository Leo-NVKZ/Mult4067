//#include "WProgram.h"
#include "Arduino.h"
#include <Mult4067.h>

void Mult4067::anRead()  // Функция считывания данных с аналоговых входов мультиплексора 
{
  // перебираем 16 каналов мультиплексора - с 0-го по 15-й включительно
  for(int i = 0; i < 16; i++)
  {
    // с помощью цифровых выходов Arduino выставляем на мультиплексоре адрес очередного канала:
    digitalWrite(_dPin_S0, (i >> 0) & 0x1);
    digitalWrite(_dPin_S1, (i >> 1) & 0x1);
    digitalWrite(_dPin_S2, (i >> 2) & 0x1);
    digitalWrite(_dPin_S3, (i >> 3) & 0x1);        
    anData[i] = analogRead(_AnSign);  // читаем аналоговый вход и сохраняем его в i-й элемент массива
  }
}

Mult4067::Mult4067(int dPin_S0, int dPin_S1, int dPin_S2, int dPin_S3, int AnSign) // Конструктор
{
  _dPin_S0=dPin_S0;
  _dPin_S1=dPin_S1;
  _dPin_S2=dPin_S2;
  _dPin_S3=dPin_S3;
  _AnSign=AnSign;
}

