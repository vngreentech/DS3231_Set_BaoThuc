#include <Arduino.h>

#include <DS3231.h>
#include <LiquidCrystal_I2C.h>

DS3231  rtc(SDA, SCL);

LiquidCrystal_I2C lcd(0x27,16,2);

int cong = 4; int tru = 5; int menu = 6;
int demmenu = 0;
int gtcong, gttru, gtmenu;

int ngay = 1;
int thang = 1;
int namdv = 0; int namc = 0; int namt = 0; int namn = 0; int namtong;
int gio = 1; int phut = 0; int giay = 0;

void thoigian()
{
//  // Send Day-of-Week
//  Serial.print(rtc.getDOWStr());
//  Serial.print(" ");  
//  // Send date
//  Serial.print(rtc.getDateStr());
//  Serial.print(" -- ");
//  // Send time
//  Serial.println(rtc.getTimeStr());  
//  // Wait one second before repeating :)
//  delay (1000);

  lcd.setCursor(0,0);
  lcd.print("DATE: ");
  lcd.setCursor(0,1);
  lcd.print("TIME: ");
  lcd.setCursor(6,0);
  lcd.print(rtc.getDateStr());
  lcd.setCursor(6,1);
  lcd.print(rtc.getTimeStr());  
}

void setngay()
{
  gtcong = digitalRead(cong);
  gttru = digitalRead(tru);
  if (gtcong == 0)
  {
    if (ngay == 31)
    { ngay = 1; }
    else
    { ngay = ngay + 1;  }
  }
  
  if (gttru == 0)
  {
    if (ngay == 1)
    { ngay = 31; }
    else
    { ngay = ngay - 1;  }
  }
  rtc.setDate(ngay, thang, namtong);
  lcd.setCursor(0,0);
  lcd.print("  CAI DAT NGAY  ");
  lcd.setCursor(0,1);
  lcd.print("    NGAY: ");
  if (ngay >= 1 &&  ngay <= 9)
  {
    lcd.setCursor(10,1);
    lcd.print(ngay);
    lcd.setCursor(11,1);
    lcd.print("     ");   
  }
  else if (ngay >= 10 &&  ngay <= 31)
  {
    lcd.setCursor(10,1);
    lcd.print(ngay);
    lcd.setCursor(12,1);
    lcd.print("    ");   
  }

  delay(200);  
}

void setthang()
{
  gtcong = digitalRead(cong);
  gttru = digitalRead(tru);
  if (gtcong == 0)
  {
    if (thang == 12)
    { thang = 1; }
    else
    { thang = thang + 1;  }
  }
  
  if (gttru == 0)
  {
    if (thang == 1)
    { thang = 12; }
    else
    { thang = thang - 1;  }
  }
  rtc.setDate(ngay, thang, namtong);
  lcd.setCursor(0,0);
  lcd.print(" CAI DAT THANG  ");
  lcd.setCursor(0,1);
  lcd.print("   THANG: ");
  if (thang >= 1 &&  thang <= 9)
  {
    lcd.setCursor(10,1);
    lcd.print(thang);
    lcd.setCursor(11,1);
    lcd.print("     ");   
  }
  else if (thang >= 10 &&  thang <= 12)
  {
    lcd.setCursor(10,1);
    lcd.print(thang);
    lcd.setCursor(12,1);
    lcd.print("    ");   
  }
  delay(200);  
}

void setnamn()
{
  gtcong = digitalRead(cong);
  gttru = digitalRead(tru);
  if (gtcong == 0)
  {
    if (namn == 9000)
    { namn = 0; }
    else
    { namn = namn + 1000;  }
  }
  
  if (gttru == 0)
  {
    if (namn == 0)
    { namn = 9000; }
    else
    { namn = namn - 1000;  }
  }
  
  lcd.setCursor(0,0);
  lcd.print("CAI DAT NAM:");
  if (namn == 0)
  {
    lcd.setCursor(12,0);
    lcd.print(namn);
    lcd.setCursor(13,0);
    lcd.print("000");
  }
  else
  {
    lcd.setCursor(12,0);
    lcd.print(namn);    
  }
  lcd.setCursor(0,1);
  lcd.print("NAM NGIN: ");
  lcd.setCursor(10,1);
  lcd.print(namn);
  lcd.setCursor(14,1);
  lcd.print("  ");
  delay(200);   
}

void setnamt()
{
  gtcong = digitalRead(cong);
  gttru = digitalRead(tru);
  if (gtcong == 0)
  {
    if (namt == 900)
    { namt = 0; }
    else
    { namt = namt + 100;  }
  }
  
  if (gttru == 0)
  {
    if (namt == 0)
    { namt = 900; }
    else
    { namt = namt - 100;  }
  }

  lcd.setCursor(0,0);
  lcd.print("CAI DAT NAM: ");
  lcd.setCursor(12,0);
  lcd.print(namt + namn);
  lcd.setCursor(0,1);
  lcd.print("NAM TRAM: ");
  lcd.setCursor(10,1);
  lcd.print(namt);
  lcd.setCursor(13,1);
  lcd.print("  ");
  delay(200);   
}

void setnamc()
{
  gtcong = digitalRead(cong);
  gttru = digitalRead(tru);
  if (gtcong == 0)
  {
    if (namc == 90)
    { namc = 0; }
    else
    { namc = namc + 10;  }
  }
  
  if (gttru == 0)
  {
    if (namc == 0)
    { namc = 90; }
    else
    { namc = namc - 10;  }
  }

  lcd.setCursor(0,0);
  lcd.print("CAI DAT NAM:");
  lcd.setCursor(12,0);
  lcd.print(namc + namt + namn);
  lcd.setCursor(0,1);
  lcd.print("NAM CHUC: ");
  lcd.setCursor(10,1);
  lcd.print(namc);
  lcd.setCursor(12,1);
  lcd.print("    ");
  delay(200);  
}

void setnamdv()
{
  gtcong = digitalRead(cong);
  gttru = digitalRead(tru);
  if (gtcong == 0)
  {
    if (namdv == 9)
    { namdv = 0; }
    else
    { namdv = namdv + 1;  }
  }
  
  if (gttru == 0)
  {
    if (namdv == 0)
    { namdv = 9; }
    else
    { namdv = namdv - 1;  }
  }

  lcd.setCursor(0,0);
  lcd.print("CAI DAT NAM:");
  lcd.setCursor(12,0);
  lcd.print(namdv + namc + namt + namn);
  lcd.setCursor(0,1);
  lcd.print("NAM DON VI: ");
  lcd.setCursor(12,1);
  lcd.print(namdv);
  lcd.setCursor(13,1);
  lcd.print("   ");
  namtong = namn + namt + namc + namdv;
  Serial.println(namtong);
  rtc.setDate(ngay, thang, namtong);
  delay(200);  
}

void setgio()
{
  gtcong = digitalRead(cong);
  gttru = digitalRead(tru);
  if (gtcong == 0)
  {
    if (gio == 23)
    { gio = 0; }
    else
    { gio = gio + 1;  }
  }
  
  if (gttru == 0)
  {
    if (gio == 0)
    { gio = 23; }
    else
    { gio = gio - 1;  }
  }
  lcd.setCursor(0,0);
  lcd.print("  CAI DAT GIO   ");
  lcd.setCursor(0,1);
  lcd.print("    GIO: ");
  if (gio >= 0 &&  gio <= 9)
  {
    lcd.setCursor(9,1);
    lcd.print(gio);
    lcd.setCursor(10,1);
    lcd.print("      ");   
  }
  else if (gio >= 10 &&  gio <= 24)
  {
    lcd.setCursor(9,1);
    lcd.print(gio);
    lcd.setCursor(11,1);
    lcd.print("      ");   
  }
  rtc.setTime(gio, phut, giay);
  delay(200);  
}

void setphut()
{
  gtcong = digitalRead(cong);
  gttru = digitalRead(tru);
  if (gtcong == 0)
  {
    if (phut == 60)
    { phut = 0; }
    else
    { phut = phut + 1;  }
  }
  
  if (gttru == 0)
  {
    if (phut == 0)
    { phut = 60; }
    else
    { phut = phut - 1;  }
  }
  lcd.setCursor(0,0);
  lcd.print("  CAI DAT PHUT  ");
  lcd.setCursor(0,1);
  lcd.print("    PHUT: ");
  if (phut >= 0 &&  phut <= 9)
  {
    lcd.setCursor(10,1);
    lcd.print(phut);
    lcd.setCursor(11,1);
    lcd.print("     ");   
  }
  else if (phut >= 10 &&  phut <= 60)
  {
    lcd.setCursor(10,1);
    lcd.print(phut);
    lcd.setCursor(12,1);
    lcd.print("     ");   
  }
  rtc.setTime(gio, phut, giay);
  delay(200);  
}

void setgiay()
{
  gtcong = digitalRead(cong);
  gttru = digitalRead(tru);
  if (gtcong == 0)
  {
    if (giay == 60)
    { giay = 0; }
    else
    { giay = giay + 1;  }
  }
  
  if (gttru == 0)
  {
    if (giay == 0)
    { giay = 60; }
    else
    { giay = giay - 1;  }
  }
  lcd.setCursor(0,0);
  lcd.print("  CAI DAT GIAY  ");
  lcd.setCursor(0,1);
  lcd.print("    GIAY: ");
  if (giay >= 0 &&  giay <= 9)
  {
    lcd.setCursor(10,1);
    lcd.print(giay);
    lcd.setCursor(11,1);
    lcd.print("     ");   
  }
  else if (giay >= 10 &&  giay <= 60)
  {
    lcd.setCursor(10,1);
    lcd.print(giay);
    lcd.setCursor(12,1);
    lcd.print("     ");   
  }
  rtc.setTime(gio, phut, giay);
  delay(200);  
}

void luusetup()
{
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("SAVE SETTING");
  lcd.setCursor(2,1);
  lcd.print("PROGRESS....");
}

void setup()
{

  Serial.begin(115200);

  rtc.begin();  
//  rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
//  rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format)
//  rtc.setDate(5, 1, 2014);   // Set the date to January 1st, 2014

  lcd.init();
  lcd.backlight();

  pinMode(cong, INPUT_PULLUP);
  pinMode(tru, INPUT_PULLUP);
  pinMode(menu, INPUT_PULLUP);
}

void loop()
{
  gtmenu = digitalRead(menu);
  Serial.print("Menu: "); Serial.print(gtmenu); Serial.print("    ");
  if(gtmenu == 0)
  {
    demmenu = demmenu + 1;
  }

  Serial.print("Đếm menu: "); Serial.println(demmenu);
  delay(200);
  if (demmenu == 0)  {thoigian();}
//  if (demmenu == 1)  {setthu();}
  if (demmenu == 1)  {setngay();}
  if (demmenu == 2)  {setthang();}
  if (demmenu == 3)  {setnamn();}
  if (demmenu == 4)  {setnamt();}
  if (demmenu == 5)  {setnamc();}
  if (demmenu == 6)  {setnamdv();}
  if (demmenu == 7)  {setgio();}
  if (demmenu == 8)  {setphut();}    
  if (demmenu == 9)  {setgiay();}
  if (demmenu == 10)  
  {
    luusetup();
    delay(500);
    demmenu = 0; 
  }
  delay(100);
}