void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  
   digitalWrite(6,LOW);
  delay(100);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  delay(100);
  digitalWrite(6,HIGH);
  delay(100);//预设初始显示为0
  

}
int income=0;
void loop()
{
  if(Serial.available()>0)
    {
    income=Serial.read();
    
    income=income-'0';
    Serial.println(income,DEC);
    digitalWrite(6,HIGH);
    delay(100);
    
    digitalWrite(2,income&0x1?HIGH:LOW);
    digitalWrite(3,(income>>1)&0x1?HIGH:LOW);
    digitalWrite(4,(income>>2)&0x1?HIGH:LOW);
    digitalWrite(5,(income>>3)&0x1?HIGH:LOW);
    Serial.println(income&0x1);
    /*digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);*/
    delay(100);
  }
}
