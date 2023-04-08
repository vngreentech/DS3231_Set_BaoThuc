#include <Arduino.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <DS3231.h>
DS3231  rtc(SDA, SCL);
Time  t;

int len = 6; int gtlen;  // Lên là trừ
int xuong = 5; int gtxuong; // Xuống là cộng
int menu = 7; int gtmenu; 
int macdinh = 1;
int coi = 8;

int contro = 0; int contro_bt = 6; int hang = 0;

int congtru_tong = 0; int congtru_menubaothuc = 0;
int demtong = 0;  int dembaothuc = 0;

int ngay = 1; int thang = 1; int namng = 0; int namtr = 0; int namch = 0; int namdv = 0; int namtong = 0; //SETUP DATE
int gio = 0; int phut = 0; int giay = 0; //SETUP TIME

int gio1 = 0; int phut1 = 0; int ngay1 = 1; int thang1 = 1; //BÁO THỨC 1
int gio2 = 0; int phut2 = 0; int ngay2 = 1; int thang2 = 1; //BÁO THỨC 2
int gio3 = 0; int phut3 = 0; int ngay3 = 1; int thang3 = 1; //BÁO THỨC 3
int gio4 = 0; int phut4 = 0; int ngay4 = 1; int thang4 = 1; //BÁO THỨC 4
int gio5 = 0; int phut5 = 0; int ngay5 = 1; int thang5 = 1; //BÁO THỨC 5

void manhinh()  // HIỂN THỊ MÀN HÌNH CHÍNH
{
  lcd.setCursor(0,0);
  lcd.print("DATE: ");
  lcd.setCursor(0,1);
  lcd.print("TIME: ");
  lcd.setCursor(6,0);
  lcd.print(rtc.getDateStr());
  lcd.setCursor(6,1);
  lcd.print(rtc.getTimeStr());  
}

void menu_tong() // HIỂN THỊ MENU TỔNG
{
  if (congtru_tong == 0)
  {
    lcd.clear();
    lcd.print(">BACK");
    lcd.setCursor(0, 1);
    lcd.print(" DATE");  
  }
  else if (congtru_tong == 1)
  {
    lcd.clear();
    lcd.print(" BACK");
    lcd.setCursor(0, 1);
    lcd.print(">DATE");    
  }
  else if (congtru_tong == 2)
  {
    lcd.clear();
    lcd.print(">TIME");
    lcd.setCursor(0, 1);
    lcd.print(" BAO THUC");   
  }
  else if (congtru_tong == 3)
  {
    lcd.clear();
    lcd.print(" TIME");
    lcd.setCursor(0, 1);
    lcd.print(">BAO THUC");    
  }
}

void chonmenu_tong() // CHỌN MENU TỔNG
{
  switch (congtru_tong) 
  {
    case 0:
      //BACK
      break;
    case 1:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SETUP DATE");
      lcd.setCursor(12,1);
      lcd.print("BACK");      
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SETUP TIME");
      lcd.setCursor(12,1);
      lcd.print("BACK");       
      break;
    case 3:
      // BÁO THỨC
      break;                       
  }
}

void menu_baothuc() // HIỂN THỊ MENU BÁO THỨC
{
  if (congtru_menubaothuc == 0)
  {
    lcd.clear();
    lcd.print(">BACK");
    lcd.setCursor(0, 1);
    lcd.print(" BAO THUC 1");  
  }
  else if (congtru_menubaothuc == 1)
  {
    lcd.clear();
    lcd.print(" BACK");
    lcd.setCursor(0, 1);
    lcd.print(">BAO THUC 1");    
  }
  else if (congtru_menubaothuc == 2)
  {
    lcd.clear();
    lcd.print(">BAO THUC 2");
    lcd.setCursor(0, 1);
    lcd.print(" BAO THUC 3");    
  } 
  else if (congtru_menubaothuc == 3)
  {
    lcd.clear();
    lcd.print(" BAO THUC 2");
    lcd.setCursor(0, 1);
    lcd.print(">BAO THUC 3");    
  } 
  else if (congtru_menubaothuc == 4)
  {
    lcd.clear();
    lcd.print(">BAO THUC 4");
    lcd.setCursor(0, 1);
    lcd.print(" BAO THUC 5");    
  } 
  else if (congtru_menubaothuc == 5)
  {
    lcd.clear();
    lcd.print(" BAO THUC 4");
    lcd.setCursor(0, 1);
    lcd.print(">BAO THUC 5");    
  }        
}

void chonmenu_baothuc() // CHỌN MENU BÁO THỨC
{
  switch (congtru_menubaothuc) 
  {
    case 0:
      //BACK
      break;
    case 1:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("DATE: ");
      lcd.setCursor(0,1);
      lcd.print("TIME: ");
      lcd.setCursor(12,1);
      lcd.print("BACK");
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("DATE: ");
      lcd.setCursor(0,1);
      lcd.print("TIME: "); 
      lcd.setCursor(12,1);
      lcd.print("BACK");      
      break;
    case 3:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("DATE: ");
      lcd.setCursor(0,1);
      lcd.print("TIME: "); 
      lcd.setCursor(12,1);
      lcd.print("BACK");      
      break;
    case 4:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("DATE: ");
      lcd.setCursor(0,1);
      lcd.print("TIME: ");
      lcd.setCursor(12,1);
      lcd.print("BACK");       
      break;
    case 5:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("DATE: ");
      lcd.setCursor(0,1);
      lcd.print("TIME: ");
      lcd.setCursor(12,1);
      lcd.print("BACK");       
      break;                             
  }
}

void tb_baothuc()
{
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("THONG BAO");
  lcd.setCursor(2,1);
  lcd.print("CO BAO THUC");  
}

void setup() 
{
  Serial.begin(9600);
  rtc.begin();
  
  lcd.init();
  lcd.backlight();
  
  pinMode(len, INPUT_PULLUP);
  pinMode(xuong, INPUT_PULLUP);
  pinMode(menu, INPUT_PULLUP);
  pinMode(coi, OUTPUT);
  
}

void loop() 
{
  t = rtc.getTime();
  
  gtlen = digitalRead(len);  
  gtxuong = digitalRead(xuong);  
  gtmenu = digitalRead(menu);
  // Serial.print("LÊN: "); Serial.print(gtlen); Serial.print("    ");
  // Serial.print("XUỐNG: "); Serial.print(gtxuong); Serial.print("    ");
  // Serial.print("Menu: "); Serial.println(gtmenu);

if (gtlen != macdinh)  // NÚT LÊN
{
  if (gtlen == 0) // Khi nhấn nút lên
  {
    if (demtong == 1)   // LÊN Ở MENU TỔNG  
    {
      if (congtru_tong >= 3)
      { 
        congtru_tong = 0;  
      }
      else
      { 
        congtru_tong++;  
      }   
      menu_tong();
    }
    
    else if (demtong == 2 && (congtru_tong == 1 or congtru_tong == 2))   // + CON TRỎ ở SET DATE và TIME
    {
      contro ++;
      if (contro > 15)
      {
        contro = 0;
      }
    }

    else if (demtong == 3 && congtru_tong == 3)   // + CON TRỎ ở BÁO THỨC
    {
      contro_bt ++;
      if (hang == 0){
        if (contro_bt > 10)
        {
          contro_bt = 6;
          hang = 1;
        }
      } else {
        if (contro_bt > 15)
        {
          contro_bt = 6;
          hang = 0;
        }       
      }
    }
    
    else if (demtong == 3 && congtru_tong == 1)   // - ở NGÀY, THÁNG, NĂM
    {
      if ((contro == 0 or contro == 1)){ //NGÀY
        ngay --;
        if (ngay < 1){
          ngay = 31;
        }
      }
      else if ((contro == 3 or contro == 4)){ //THÁNG
        thang --;
        if (thang < 1){
          thang = 12;
        }
      }

        else if (contro == 6){ //NĂM NGHÌN
          namng --;
          if (namng < 0){
            namng = 9;
          }
        }
        else if (contro == 7){ //NĂM TRĂM
          namtr --;
          if (namtr < 0){
            namtr = 9;
          }
        }
        else if (contro == 8){ //NĂM CHỤC
          namch --;
          if (namch < 0){
            namch = 9;
          }
        }
        else if (contro == 9){ //NĂM ĐƠN VỊ
          namdv --;
          if (namdv < 0){
            namdv = 9;
          }
        }

    }

    else if (demtong == 3 && congtru_tong == 2 ) // - ở GIỜ : PHÚT : GIÂY
    {
      if ((contro == 0 or contro == 1)){ //GIỜ
        gio --;
        if (gio < 0){
          gio = 23;
        }
      }
      else if ((contro == 3 or contro == 4)){ //PHÚT
        phut --;
        if (phut < 0){
          phut = 59;
        }
      }
      else if ((contro == 6 or contro == 7)){ //GIÂY
        giay --;
        if (giay < 0){
          giay = 59;
        }    
      }
    }  

    else if (demtong == 2 && congtru_tong == 3) //Lên ở MENU BÁO THỨC
    {
      congtru_menubaothuc ++;
      if (congtru_menubaothuc > 5){
        congtru_menubaothuc = 0;
      }
      menu_baothuc();
    }  
    
    else if (demtong == 4 && congtru_tong == 3) // - BÁO THỨC | NGÀY/THÁNG & GIỜ/PHÚT
    {
      if (congtru_menubaothuc == 1 && (contro_bt == 6 or contro_bt == 7)){ // - NGÀY & GIỜ 1
        if (hang == 0){ // NGÀY
          ngay1 --;
          if (ngay1 < 1){
            ngay1 = 31;
          }     
        }
        else if (hang == 1){ // GIỜ
          gio1 --;
          if (gio1 < 0){
            gio1 = 23;
          } 
        }
      }
      else if (congtru_menubaothuc == 1 && (contro_bt == 9 or contro_bt == 10)){ // - THÁNG & PHÚT 1
        if (hang == 0){ //THÁNG
          thang1 --;
          if (thang1 < 1){
            thang1 = 12;
          }  
        }   
        else if (hang == 1){ //PHÚT
          phut1 --;
          if (phut1 < 0){
            phut1 = 59;
          } 
        }
      }
      else if (congtru_menubaothuc == 2 && (contro_bt == 6 or contro_bt == 7)){// - NGÀY & GIỜ 2
        if (hang == 0){ // NGÀY
          ngay2 --;
          if (ngay2 < 1){
            ngay2 = 31;
          }     
        }
        else if (hang == 1){ // GIỜ
          gio2 --;
          if (gio2 < 0){
            gio2 = 23;
          } 
        }      
      }
      else if (congtru_menubaothuc == 2 && (contro_bt == 9 or contro_bt == 10)){// - THÁNG & PHÚT 2
        if (hang == 0){ //THÁNG
          thang2 --;
          if (thang2 < 1){
            thang2 = 12;
          }  
        }   
        else if (hang == 1){ //PHÚT
          phut2 --;
          if (phut2 < 0){
            phut2 = 59;
          } 
        }
      }
      else if (congtru_menubaothuc == 3 && (contro_bt == 6 or contro_bt == 7)){// - NGÀY & GIỜ 3
        if (hang == 0){ // NGÀY
          ngay3 --;
          if (ngay3 < 1){
            ngay3 = 31;
          }     
        }
        else if (hang == 1){ // GIỜ
          gio3 --;
          if (gio3 < 0){
            gio3 = 23;
          } 
        }
      }
      else if (congtru_menubaothuc == 3 && (contro_bt == 9 or contro_bt == 10)){// - THÁNG & PHÚT 3
        if (hang == 0){ //THÁNG
          thang3 --;
          if (thang3 < 1){
            thang3 = 12;
          }  
        }   
        else if (hang == 1){ //PHÚT
          phut3 --;
          if (phut3 < 0){
            phut3 = 59;
          } 
        }
      }
      else if (congtru_menubaothuc == 4 && (contro_bt == 6 or contro_bt == 7)){// - NGÀY & GIỜ 4
        if (hang == 0){ // NGÀY
          ngay4 --;
          if (ngay4 < 1){
            ngay4 = 31;
          }     
        }
        else if (hang == 1){ // GIỜ
          gio4 --;
          if (gio4 < 0){
            gio4 = 23;
          } 
        }
      }
      else if (congtru_menubaothuc == 4 && (contro_bt == 9 or contro_bt == 10)){// - THÁNG & PHÚT 4
        if (hang == 0){ //THÁNG
          thang4 --;
          if (thang4 < 1){
            thang4 = 12;
          }  
        }   
        else if (hang == 1){ //PHÚT
          phut4 --;
          if (phut4 < 0){
            phut4 = 59;
          } 
        }
      }
      else if (congtru_menubaothuc == 5 && (contro_bt == 6 or contro_bt ==7)){// - NGÀY & GIỜ 5
        if (hang == 0){ // NGÀY
          ngay5 --;
          if (ngay5 < 1){
            ngay5 = 31;
          }     
        }
        else if (hang == 1){ // GIỜ
          gio5 --;
          if (gio5 < 0){
            gio5 = 23;
          } 
        }
      }
      else if (congtru_menubaothuc == 5 && (contro_bt == 9 or contro_bt == 10)){// - THÁNG & PHÚT 5
        if (hang == 0){ //THÁNG
          thang5 --;
          if (thang5 < 1){
            thang5 = 12;
          }  
        }   
        else if (hang == 1){ //PHÚT
          phut5 --;
          if (phut5 < 0){
            phut5 = 59;
          } 
        }
      }
    }                                         

    delay(200);
  }
  macdinh = gtlen;
}

if (gtxuong != macdinh) // NÚT XUỐNG
{
  if (gtxuong == 0) //Khi nhấn nút xuống
  {
    if (demtong == 1)   // XUỐNG Ở MENU TỔNG
    {
      if (congtru_tong <= 0)
      { 
        congtru_tong = 3;  
      }
      else
      { 
        congtru_tong--;  
      }
      menu_tong();
    }
    
    else if (demtong == 2 && (congtru_tong == 1 or congtru_tong == 2))   // - CON TRỎ ở SET DATE và TIME
    {
      contro --;
      if (contro < 0)
      {
        contro = 15;
      }
    }

    else if (demtong == 3 && congtru_tong == 3) // - CON TRỎ ở BÁO THỨC
    {
      contro_bt --;
      if (hang == 0){
        if (contro_bt < 6)
        {
          contro_bt = 15;
          hang = 1;        
        }
      } else {
        if (contro_bt < 6)
        {
          contro_bt = 10;
          hang = 0;        
        }        
      }    
    }
    
    else if (demtong == 3 && congtru_tong == 1)   // + ở NGÀY, THÁNG, NĂM
    {
      if (contro == 0 or contro == 1){ // + NGÀY ở DATE
        ngay ++;
        if (ngay > 31){
          ngay = 1;
        }
      }
      else if (contro == 3 or contro == 4){ // + THÁNG ở DATE
        thang ++;
        if (thang > 12){
          thang = 1;
        }        
      }
      else if (contro == 6){ // + NĂM NGHÌN
        namng ++;
        if (namng > 9){
          namng = 0;
        }
      }
      else if (contro == 7){// + NĂM TRĂM
        namtr ++;
        if (namtr > 9){
          namtr = 0;
        }
      }
      else if (contro == 8){// + NĂM CHỤC
        namch ++;
        if (namch > 9){
          namch = 0;
        }
      }
      else if (contro == 9){// + NĂM ĐƠN VỊ
        namdv ++;
        if (namdv > 9){
          namdv = 0;
        }
      }
    }

    else if (demtong == 3 && congtru_tong == 2) //+ ở GIỜ : PHÚT :GIÂY
    {
      if (contro == 0 or contro == 1){ //GIỜ
        gio ++;
        if (gio > 23){
          gio = 0;
        }      
      }
      else if (contro == 3 or contro == 4){ //PHÚT
        phut ++;
        if (phut > 59){
          phut = 0;
        }
      }
      else if (contro == 6 or contro == 7){ //GIÂY
        giay ++;
        if (giay > 59){
          giay = 0;
        }
      }
    } 

    else if (demtong == 2 && congtru_tong == 3) //Xuống ở MENU BÁO THỨC
    {
      congtru_menubaothuc --;
      if (congtru_menubaothuc < 0){
        congtru_menubaothuc = 5;
      }
      menu_baothuc();
    } 

    else if (demtong == 4 && congtru_tong == 3)  // + BÁO THỨC | NGÀY/THÁNG & GIỜ/PHÚT
    {
      if (congtru_menubaothuc == 1 && (contro_bt == 6 or contro_bt == 7)){ // + NGÀY & GIỜ 1
        if (hang == 0){ //NGÀY
          ngay1 ++;
          if (ngay1 > 31){
            ngay1 = 1;
        }      
        } else if (hang == 1){ //GIỜ
          gio1 ++;
          if (gio1 > 23){
            gio1 = 0;
          } 
        }
      }
      else if(congtru_menubaothuc == 1 && (contro_bt == 9 or contro_bt == 10)){// + THÁNG & PHÚT 1
        if (hang == 0){ //THÁNG
          thang1 ++;
          if (thang1 > 12){
            thang1 = 1;
          }      
        } else if (hang == 1){ //PHÚT
          phut1 ++;
          if (phut1 > 59){
            phut1 = 0;
          } 
        }
      }
      else if(congtru_menubaothuc == 2 && (contro_bt == 6 or contro_bt == 7)){// + NGÀY & GIỜ 2
        if (hang == 0){ //NGÀY
          ngay2 ++;
          if (ngay2 > 31){
            ngay2 = 1;
        }      
        } else if (hang == 1){ //GIỜ
          gio2 ++;
          if (gio2 > 23){
            gio2 = 0;
          } 
        }
      }
      else if(congtru_menubaothuc == 2 && (contro_bt == 9 or contro_bt == 10)){// + THÁNG & PHÚT 2
        if (hang == 0){ //THÁNG
          thang2 ++;
          if (thang2 > 12){
            thang2 = 1;
          }      
        } else if (hang == 1){ //PHÚT
          phut2 ++;
          if (phut2 > 59){
            phut2 = 0;
          } 
        }
      }
      else if(congtru_menubaothuc == 3 && (contro_bt == 6 or contro_bt == 7)){// + NGÀY & GIỜ 3
        if (hang == 0){ //NGÀY
          ngay3 ++;
          if (ngay3 > 31){
            ngay3 = 1;
        }      
        } else if (hang == 1){ //GIỜ
          gio3 ++;
          if (gio3 > 23){
            gio3 = 0;
          } 
        }
      }
      else if(congtru_menubaothuc == 3 && (contro_bt == 9 or contro_bt == 10)){// + THÁNG & PHÚT 3
        if (hang == 0){ //THÁNG
          thang3 ++;
          if (thang3 > 12){
            thang3 = 1;
          }      
        } else if (hang == 1){ //PHÚT
          phut3 ++;
          if (phut3 > 59){
            phut3 = 0;
          } 
        }
      }
      else if(congtru_menubaothuc == 4 && (contro_bt == 6 or contro_bt == 7)){// + NGÀY & GIỜ 4
        if (hang == 0){ //NGÀY
          ngay4 ++;
          if (ngay4 > 31){
            ngay4 = 1;
        }      
        } else if (hang == 1){ //GIỜ
          gio4 ++;
          if (gio4 > 23){
            gio4 = 0;
          } 
        }
      }
      else if(congtru_menubaothuc == 4 && (contro_bt == 9 or contro_bt == 10)){// + THÁNG & PHÚT 4
        if (hang == 0){ //THÁNG
          thang4 ++;
          if (thang4 > 12){
            thang4 = 1;
          }      
        } else if (hang == 1){ //PHÚT
          phut4 ++;
          if (phut4 > 59){
            phut4 = 0;
          } 
        }
      }
      else if(congtru_menubaothuc == 5 && (contro_bt == 6 or contro_bt == 7)){// + NGÀY & GIỜ 5
        if (hang == 0){ //NGÀY
          ngay5 ++;
          if (ngay5 > 31){
            ngay5 = 1;
        }      
        } else if (hang == 1){ //GIỜ
          gio5 ++;
          if (gio5 > 23){
            gio5 = 0;
          } 
        }
      }
      else if (congtru_menubaothuc == 5 && (contro_bt == 9 or contro_bt == 10)){// + THÁNG & PHÚT 5
        if (hang == 0){ //THÁNG
          thang5 ++;
          if (thang5 > 12){
            thang5 = 1;
          }      
        } else if (hang == 1){ //PHÚT
          phut5 ++;
          if (phut5 > 59){
            phut5 = 0;
          } 
        }
      }
    }                                                          

    delay(200);
  }
  macdinh = gtxuong;
}

if (gtmenu != macdinh)    // NÚT MENU
{  
  if (gtmenu == 0) //Khi nhấn nút
  {  
    demtong ++;

    if (demtong == 1) //Ở menu tổng
    { 
      menu_tong(); 
    }
      else if (demtong == 2 && congtru_tong == 0) //Nhấn BACK từ Menu tổng về màn hình
      {
        demtong = 0;
        manhinh(); 
      }       

    else if (demtong == 2 && (congtru_tong == 1 or congtru_tong == 2)) // chọn menu tổng DATE or TIME
    {
      chonmenu_tong();
    }                                      
      
      else if (demtong == 4 && congtru_tong == 1) //Thoát CON TRỎ từ SET DATE ra
      {
        demtong = 2;
        chonmenu_tong();
      }       
      else if (demtong == 4 && congtru_tong == 2) //Thoát CON TRỎ từ SET TIME ra
      {
        demtong = 2;
        chonmenu_tong();        
      }
    
    else if (demtong == 3 && (congtru_tong == 2 or congtru_tong == 1) && // Thoát từ SET DATE or TIME ra
            (contro == 12 or contro == 13 or contro == 14 or contro == 15)) 
      {
        demtong = 1;
        congtru_tong = 0;
        contro = 0;
        menu_tong();
        lcd.noCursor();
      }      

    else if (demtong == 2 && congtru_tong == 3) //Menu BÁO THỨC
    {
      menu_baothuc();
    }

      else if (demtong == 3 && congtru_tong == 3 && congtru_menubaothuc == 0) //từ Menu BÁO THỨC về Menu TỔNG
      {
        demtong = 1;
        congtru_menubaothuc = 0;
        menu_tong();
      }

      else if (demtong == 3 && congtru_tong == 3 && (congtru_menubaothuc == 1 or congtru_menubaothuc == 2 
              or congtru_menubaothuc == 3 or congtru_menubaothuc == 4 or congtru_menubaothuc == 5)) //chọn menu BT
      {
        chonmenu_baothuc();
      }

      else if (demtong == 5 && congtru_tong == 3 && (congtru_menubaothuc == 1 or congtru_menubaothuc == 2
              or congtru_menubaothuc == 3 or congtru_menubaothuc == 4 or congtru_menubaothuc == 5))  //Từ chức năng SET ra
      {
        chonmenu_baothuc();
        demtong = 3;
      }

      else if (demtong == 4 && congtru_tong == 3 && (contro_bt == 12 or 
              contro_bt == 13 or contro_bt == 14 or contro_bt == 15)) //Thoát từ SET BT ra menu báo thức
      {
        menu_baothuc();
        demtong = 2;
        congtru_tong = 3;
        contro_bt = 6;
        hang = 0;
        lcd.noCursor();
      }

    if(dembaothuc == 1){ //Đang có BÁO THỨC
      dembaothuc = 0;
      demtong = 0;
    }

    delay(100);
  }
  macdinh = gtmenu;
}

if (demtong == 0 && congtru_tong == 0) // MÀN HÌNH
{
  manhinh();
  lcd.noCursor();
}
else if ((demtong == 2 or demtong == 3) && congtru_tong == 1) //SETUP DATE
{
  if (ngay < 10){
    lcd.setCursor(0,1); lcd.print("0");
    lcd.setCursor(1,1); lcd.print(ngay);
  } else {
    lcd.setCursor(0,1); lcd.print(ngay);    
  }
  lcd.setCursor(2,1); lcd.print("/");
  if (thang < 10){
    lcd.setCursor(3,1); lcd.print("0"); 
    lcd.setCursor(4,1); lcd.print(thang);
  } else {
    lcd.setCursor(3,1); lcd.print(thang);    
  }
  lcd.setCursor(5,1); lcd.print("/"); 
  lcd.setCursor(6,1); lcd.print(namng); lcd.setCursor(7,1); lcd.print(namtr);
  lcd.setCursor(8,1); lcd.print(namch); lcd.setCursor(9,1); lcd.print(namdv);  
  namtong = (namng * 1000) + (namtr * 100) + (namch * 10) + namdv;

  lcd.setCursor(contro, 1); 
  lcd.cursor();
  delay(50);  

  rtc.setDate(ngay, thang, namtong);
}

else if ((demtong == 2 or demtong == 3) && congtru_tong == 2) //SETUP TIME
{
  if (gio < 10){
    lcd.setCursor(0,1); lcd.print("0");
    lcd.setCursor(1,1); lcd.print(gio);
  } else {
    lcd.setCursor(0,1); lcd.print(gio);
  }
  lcd.setCursor(2,1); lcd.print(":");
  if (phut < 10){
    lcd.setCursor(3,1); lcd.print("0"); 
    lcd.setCursor(4,1); lcd.print(phut);
  } else {
    lcd.setCursor(3,1); lcd.print(phut);    
  }  
  lcd.setCursor(5,1); lcd.print(":");
  if (giay < 10){
    lcd.setCursor(6,1); lcd.print("0"); 
    lcd.setCursor(7,1); lcd.print(giay);
  } else {
    lcd.setCursor(6,1); lcd.print(giay);    
  }

  lcd.setCursor(contro, 1); 
  lcd.cursor();
  delay(50);

  rtc.setTime(gio, phut, giay);   
}

else if ((demtong == 3 or demtong == 4) && congtru_tong == 3 && congtru_menubaothuc == 1) //BÁO THỨC 1
{
  if (ngay1 < 10){
    lcd.setCursor(6,0); lcd.print("0");
    lcd.setCursor(7,0); lcd.print(ngay1);
  } else {
    lcd.setCursor(6,0); lcd.print(ngay1);    
  } 
  lcd.setCursor(8,0); lcd.print("/");
  if (thang1 < 10){
    lcd.setCursor(9,0); lcd.print("0"); 
    lcd.setCursor(10,0); lcd.print(thang1);
  } else {
    lcd.setCursor(9,0); lcd.print(thang1);    
  }

  if (gio1 < 10){
    lcd.setCursor(6,1); lcd.print("0");
    lcd.setCursor(7,1); lcd.print(gio1);
  } else {
    lcd.setCursor(6,1); lcd.print(gio1);
  }
  lcd.setCursor(8,1); lcd.print(":");
  if (phut1 < 10){
    lcd.setCursor(9,1); lcd.print("0"); 
    lcd.setCursor(10,1); lcd.print(phut1);
  } else {
    lcd.setCursor(9,1); lcd.print(phut1);    
  }

  lcd.setCursor(contro_bt, hang); 
  lcd.cursor();
  delay(50);        
}
else if ((demtong == 3 or demtong == 4) && congtru_tong == 3 && congtru_menubaothuc == 2) //BÁO THỨC 2
{
  if (ngay2 < 10){
    lcd.setCursor(6,0); lcd.print("0");
    lcd.setCursor(7,0); lcd.print(ngay2);
  } else {
    lcd.setCursor(6,0); lcd.print(ngay2);    
  } 
  lcd.setCursor(8,0); lcd.print("/");
  if (thang2 < 10){
    lcd.setCursor(9,0); lcd.print("0"); 
    lcd.setCursor(10,0); lcd.print(thang2);
  } else {
    lcd.setCursor(9,0); lcd.print(thang2);    
  }

  if (gio2 < 10){
    lcd.setCursor(6,1); lcd.print("0");
    lcd.setCursor(7,1); lcd.print(gio2);
  } else {
    lcd.setCursor(6,1); lcd.print(gio2);
  }
  lcd.setCursor(8,1); lcd.print(":");
  if (phut2 < 10){
    lcd.setCursor(9,1); lcd.print("0"); 
    lcd.setCursor(10,1); lcd.print(phut2);
  } else {
    lcd.setCursor(9,1); lcd.print(phut2);    
  }

  lcd.setCursor(contro_bt, hang); 
  lcd.cursor();
  delay(50);        
}
else if ((demtong == 3 or demtong == 4) && congtru_tong == 3 && congtru_menubaothuc == 3) //BÁO THỨC 3
{
  if (ngay3 < 10){
    lcd.setCursor(6,0); lcd.print("0");
    lcd.setCursor(7,0); lcd.print(ngay3);
  } else {
    lcd.setCursor(6,0); lcd.print(ngay3);    
  } 
  lcd.setCursor(8,0); lcd.print("/");
  if (thang3 < 10){
    lcd.setCursor(9,0); lcd.print("0"); 
    lcd.setCursor(10,0); lcd.print(thang3);
  } else {
    lcd.setCursor(9,0); lcd.print(thang3);    
  }

  if (gio3 < 10){
    lcd.setCursor(6,1); lcd.print("0");
    lcd.setCursor(7,1); lcd.print(gio3);
  } else {
    lcd.setCursor(6,1); lcd.print(gio3);
  }
  lcd.setCursor(8,1); lcd.print(":");
  if (phut3 < 10){
    lcd.setCursor(9,1); lcd.print("0"); 
    lcd.setCursor(10,1); lcd.print(phut3);
  } else {
    lcd.setCursor(9,1); lcd.print(phut3);    
  }

  lcd.setCursor(contro_bt, hang); 
  lcd.cursor();
  delay(50);        
}
else if ((demtong == 3 or demtong == 4) && congtru_tong == 3 && congtru_menubaothuc == 4) //BÁO THỨC 4
{
  if (ngay4 < 10){
    lcd.setCursor(6,0); lcd.print("0");
    lcd.setCursor(7,0); lcd.print(ngay4);
  } else {
    lcd.setCursor(6,0); lcd.print(ngay4);    
  } 
  lcd.setCursor(8,0); lcd.print("/");
  if (thang4 < 10){
    lcd.setCursor(9,0); lcd.print("0"); 
    lcd.setCursor(10,0); lcd.print(thang4);
  } else {
    lcd.setCursor(9,0); lcd.print(thang4);    
  }

  if (gio4 < 10){
    lcd.setCursor(6,1); lcd.print("0");
    lcd.setCursor(7,1); lcd.print(gio4);
  } else {
    lcd.setCursor(6,1); lcd.print(gio4);
  }
  lcd.setCursor(8,1); lcd.print(":");
  if (phut4 < 10){
    lcd.setCursor(9,1); lcd.print("0"); 
    lcd.setCursor(10,1); lcd.print(phut4);
  } else {
    lcd.setCursor(9,1); lcd.print(phut4);    
  }

  lcd.setCursor(contro_bt, hang); 
  lcd.cursor();
  delay(50);        
}
else if ((demtong == 3 or demtong == 4) && congtru_tong == 3 && congtru_menubaothuc == 5) //BÁO THỨC 5
{
  if (ngay5 < 10){
    lcd.setCursor(6,0); lcd.print("0");
    lcd.setCursor(7,0); lcd.print(ngay5);
  } else {
    lcd.setCursor(6,0); lcd.print(ngay5);    
  } 
  lcd.setCursor(8,0); lcd.print("/");
  if (thang5 < 10){
    lcd.setCursor(9,0); lcd.print("0"); 
    lcd.setCursor(10,0); lcd.print(thang5);
  } else {
    lcd.setCursor(9,0); lcd.print(thang5);    
  }

  if (gio5 < 10){
    lcd.setCursor(6,1); lcd.print("0");
    lcd.setCursor(7,1); lcd.print(gio5);
  } else {
    lcd.setCursor(6,1); lcd.print(gio5);
  }
  lcd.setCursor(8,1); lcd.print(":");
  if (phut5 < 10){
    lcd.setCursor(9,1); lcd.print("0"); 
    lcd.setCursor(10,1); lcd.print(phut5);
  } else {
    lcd.setCursor(9,1); lcd.print(phut5);    
  }

  lcd.setCursor(contro_bt, hang); 
  lcd.cursor();
  delay(50);        
}

if (demtong == 0){ // CHỈ KHI Ở MÀN HÌNH CHÍNH MỚI HIỆN BÁO THỨC
  // Thực thi BÁO THỨC
  if ((t.date == ngay1 or t.date == ngay2 or t.date == ngay3 or t.date == ngay4 or t.date == ngay5) && 
      (t.mon == thang1 or t.mon == thang2 or t.mon == thang3 or t.mon == thang4 or t.mon == thang5) && 
      (t.hour == gio1 or t.hour == gio2 or t.hour == gio3 or t.hour == gio4 or t.hour == gio5) && 
      (t.min == phut1 or t.min == phut2 or t.min == phut3 or t.min == phut4 or t.min == phut5) && t.sec == 1)      
  {
    dembaothuc = 1;
  }
} else { // NẾU ĐANG Ở CÁC MENU HAY SETUP THÌ KHÔNG BÁO THỨC
  dembaothuc = 0;
}

if (dembaothuc == 1){
  tb_baothuc();
  digitalWrite(coi, HIGH);
  delay(500);
  digitalWrite(coi, LOW);
  delay(50);
}

  Serial.print("Đếm tổng: "); Serial.print(demtong); Serial.print("    ");
  Serial.print("+/- tổng: "); Serial.print(congtru_tong); Serial.print("    ");
  Serial.print("CT Báo thức: "); Serial.print(contro_bt); Serial.print("    ");
  Serial.print("Đếm Báo thức: "); Serial.print(dembaothuc); Serial.print("    ");
  Serial.print("Hàng: "); Serial.print(hang); Serial.print("    ");   
  Serial.print("+/- menu báo thức: "); Serial.print(congtru_menubaothuc); Serial.print("    ");
  Serial.print("Con trỏ: "); Serial.println(contro);

} //KẾT LOOP