#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int cong = 5;
int tru = 6;
int macdinh = 1;
int tro = 0;
int hang = 0;

void setup() 
{
  Serial.begin(9600);
 
  lcd.init();
  lcd.backlight();

  pinMode(cong, INPUT_PULLUP);
  pinMode(tru, INPUT_PULLUP);
}

void loop() 
{
  int gtcong = digitalRead(cong);
  Serial.print("Cộng: "); Serial.print(gtcong); Serial.print("   ");
  int gttru = digitalRead(tru);
  Serial.print("Trừ: "); Serial.print(gttru); Serial.print("   ");

if (gtcong != macdinh)
{
  if (gtcong == 0)
  {
    tro ++;
    if (tro > 15)
    {
      tro = 0;
      if (hang == 0)
      {
        hang = 1;
      } else {
        hang = 0;   
      }
    }
  } 
  gtcong = macdinh;
  delay(100);
}

if(gttru != macdinh)
{
  if (gttru == 0)
  {
    tro--;
    if (tro < 0)
    {
      tro = 15;
      if (hang == 0)
      {
        hang = 1;
      } else {
        hang = 0;   
      }
    }
  }  
  gttru = macdinh;
  delay(100);
}

Serial.print("Trỏ: "); Serial.println(tro);

  lcd.setCursor(0,0);
  lcd.print("GREEN TECHNOLOGY");
  lcd.setCursor(0,1);
  lcd.print("LIKE & SUBSCRIBE");  
  
  lcd.setCursor(tro, hang); 
  lcd.cursor();
  delay(50);
}