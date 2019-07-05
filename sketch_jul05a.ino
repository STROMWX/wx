#ifndef _MORSE_H
#define _MORSE_H
class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
  private:
    int _pin;
};
#endif /*_MORSE_H*/

#include "Arduino.h"
Morse::Morse(int pin)
{
  pinMode(pin,OUTPUT);
  _pin=pin;
}

void Morse::dot()
{
  digitalWrite(_pin,HIGH);
  delay(250);
  digitalWrite(_pin,LOW);
  delay(250);
}

void Morse::dash()
{
  digitalWrite(_pin,HIGH);
  delay(1000);
  digitalWrite(_pin,LOW);
  delay(250);
}

Morse morse(13);

void setup() {
  Serial.begin (9600);    //设置通信波特率    
}

void loop() {
char str[1000];               //定义数组，数组容量1000

 int temp=0;                 //表示接收状态
 int n=0;
if (Serial.available()>0)
{
  temp=1;
 Serial.readBytes(str,1000);  //读取字符串
 delay(2);  //延迟
 
}
                          
while (n<1000)                  //对字符串中的每一个字符进行选择
{
  switch(str[n])
  {
    
    case' ':morse.dash();morse.dash();morse.dash();morse.dash();break;    
    case'a':morse.dot();morse.dash();break;
    case'b':morse.dash();morse.dot();morse.dot();morse.dot();break;
    case'c':morse.dash();morse.dot();morse.dash();morse.dot();break;
    case'd':morse.dash();morse.dot();morse.dot();break;
    case'e':morse.dot();break;
    case'f':morse.dot();morse.dot();morse.dash();morse.dot();break;
    case'g':morse.dash();morse.dash();morse.dot();break;
    case'h':morse.dot();morse.dot();morse.dot();morse.dot();break;
    case'i':morse.dot();morse.dot();break;
    case'j':morse.dot();morse.dash();morse.dash();morse.dash();break;
    case'k':morse.dash();morse.dot();morse.dash();break;
    case'l':morse.dot();morse.dash();morse.dot();morse.dot();break;            
    case'm':morse.dash();morse.dash();break;
    case'n':morse.dash();morse.dot();break;
    case'o':morse.dash();morse.dash();morse.dash();break;
    case'p':morse.dot();morse.dash();morse.dash();morse.dot();break;          
    case'q':morse.dash();morse.dash();morse.dot();morse.dash();break;
    case'r':morse.dot();morse.dash();morse.dot();break;
    case's':morse.dot();morse.dot();morse.dot();break;
    case't':morse.dash();break;
    case'u':morse.dot();morse.dot();morse.dash();break;
    case'v':morse.dot();morse.dot();morse.dot();morse.dash();break;
    case'w':morse.dot();morse.dash();morse.dash();break;
    case'x':morse.dash();morse.dot();morse.dot();morse.dash();break;
    case'y':morse.dash();morse.dot();morse.dash();morse.dash();break;
  }
}
}
