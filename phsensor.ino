#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define SensorPin A1            //pH meter Analog output to Arduino Analog Input 0
#define Offset 0.00            //deviation compensate
#define LED 13
#define samplingInterval 20
#define printInterval 800
#define ArrayLenth  40    //times of collection
int pHArray[ArrayLenth];   //Store the average value of the sensor feedback
int pHArrayIndex=0;  
int temp;  
int buttonState = 0;
int temp1;
String number="8187816916";
int message=0;  
int gas=7;
int soil=6;  
void regnumber()
{
/*String number="9014475682";
int message=0;*/  
lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);
Serial.end();delay(10000);Serial.begin(9600);delay(1000);
lcd.clear();lcd.print("Ready To Receive");
back:
while(Serial.available()>0)
{

  
String siva=Serial.readString();
int len=siva.length();
int ourdata = siva.indexOf("NUMBER:");
lcd.clear();lcd.print("message received");delay(1000);
lcd.clear();lcd.print("Ph.No:");
for(int i=7;i<=17;i++)
{
number[i-7]=siva[ourdata+i];
}
message=1;
lcd.print(number);delay(1000);
Serial.end();delay(10000);Serial.begin(9600);delay(1000);
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print(number);
Serial.print('"');
Serial.print("\r\n");delay(1000);
Serial.print("welcome message");delay(100);
Serial.write(0x1A);delay(10000); 
Serial.end();delay(10000);Serial.begin(9600);delay(1000);
}

if(message==0)
goto back;
}
void setup(void)
{
  Serial.begin(9600);delay(100);
  pinMode(soil,INPUT);pinMode(gas,INPUT);delay(1000);
  lcd.begin(16, 2);
  lcd.print("hello, world!");
//regnumber();
lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);
lcd.clear();lcd.print("sending message");delay(1000);
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print(number);
Serial.print('"');
Serial.print("\r\n");delay(1000);
Serial.print("FOOD FRESHNESS DETECTION");delay(100);
Serial.write(0x1A);delay(10000);
lcd.clear();lcd.print("sms sent...."); 

}
void loop(void)
{
  
  static unsigned long samplingTime = millis();
  static unsigned long printTime = millis();
  static float pHValue,voltage;

  if(millis()-samplingTime > samplingInterval)
  {
      pHArray[pHArrayIndex++]=analogRead(SensorPin);
      if(pHArrayIndex==ArrayLenth)pHArrayIndex=0;
      voltage = avergearray(pHArray, ArrayLenth)*5.0/1024;
      pHValue = 3.5*voltage+Offset;
      samplingTime=millis();
  }
  if(millis() - printTime > printInterval)   //Every 800 milliseconds, print a numerical, convert the state of the LED indicator
  {
    lcd.clear();
        lcd.print("Voltage:");
        lcd.print(voltage,2);
    lcd.setCursor(0,1);   
        lcd.print("pH value: ");
        lcd.print(pHValue,2);
        digitalWrite(LED,digitalRead(LED)^1);
        printTime=millis();     
  }
 
  delay(1000);
  

 int gasval=digitalRead(gas);delay(100);
 if(gasval==LOW)
 {
  lcd.clear();lcd.print("GAS FOUND");delay(1000); 
  lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);
lcd.clear();lcd.print("sending message");delay(1000);
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print(number);
Serial.print('"');
Serial.print("\r\n");delay(1000);
Serial.print("GAS FOUND ");delay(100);
Serial.print(" Voltage:");
Serial.print(voltage);
Serial.print(" pH value: ");
Serial.print(pHValue);delay(100);
Serial.write(0x1A);delay(10000);
lcd.clear();lcd.print("sms sent...."); 
 }
 if(gasval==HIGH)
 {
  lcd.clear();lcd.print("NO GAS FOUND");delay(1000);
 }

 int soilval=digitalRead(soil);delay(100);
 if(soilval==LOW)
 {
  lcd.clear();lcd.print("WET SOIL");delay(1000); 
  lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);
lcd.clear();lcd.print("sending message");delay(1000);
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print(number);
Serial.print('"');
Serial.print("\r\n");delay(1000);
Serial.print(" WET SOIL");delay(100);
Serial.print(" Voltage:");
Serial.print(voltage);
Serial.print(" pH value: ");
Serial.print(pHValue);delay(100);
Serial.write(0x1A);delay(10000);
lcd.clear();lcd.print("sms sent...."); 
 }
 if(soilval==HIGH)
 {
  lcd.clear();lcd.print("DRY SOIL");delay(1000);
 }
     delay(1000);
  temp1=analogRead(A0);delay(1000);
    temp1=temp1/2;
    lcd.clear();lcd.print("Temp:");lcd.print(temp1);delay(1000);
if(temp1>50)
{
 lcd.clear(); lcd.print("HIGH TEMPRATURE");delay(1000); 
 lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);
lcd.clear();lcd.print("sending message");delay(1000);
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print(number);
Serial.print('"');
Serial.print("\r\n");delay(1000);
Serial.print("HIGH TEMPRATURE:");Serial.print(temp1);
Serial.print(" Voltage:");
Serial.print(voltage);
Serial.print(" pH value: ");
Serial.print(pHValue);delay(100);
Serial.write(0x1A);delay(10000);
lcd.clear();lcd.print("sms sent....");  
}
else
{
  lcd.clear(); lcd.print("NORMAL TEMPRATURE");delay(1000);   
} 
  
}





double avergearray(int* arr, int number){
  int i;
  int max,min;

   
  double avg;
  long amount=0;
  if(number<=0){
    Serial.println("Error number for the array to avraging!/n");
    return 0;
  }
  if(number<5){   //less than 5, calculated directly statistics
    for(i=0;i<number;i++){
      amount+=arr[i];
    }
    avg = amount/number;
    return avg;
  }else{
    if(arr[0]<arr[1]){
      min = arr[0];max=arr[1];
    }
    else{
      min=arr[1];max=arr[0];
    }
    for(i=2;i<number;i++){
      if(arr[i]<min){
        amount+=min;        //arr<min
        min=arr[i];
      }else {
        if(arr[i]>max){
          amount+=max;    //arr>max
          max=arr[i];
        }else{
          amount+=arr[i]; //min<=arr<=max
        }
      }//if
    }//for
    avg = (double)amount/(number-2);
  }//if
  return avg;
}
