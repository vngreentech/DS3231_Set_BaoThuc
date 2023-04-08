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

void tru_ngay_gio(int &ngay, int &gio)
{
  if (hang == 0){ // - NGÀY
    ngay --;
    if (ngay < 1)
      ngay = 31; } 
  else if (hang == 1){ // - GIỜ
    gio --;
    if (gio < 0)
      gio = 23; }  
}
void tru_thang_phut(int &thang, int &phut)
{
  if (hang == 0){ // - THÁNG
    thang --;
    if (thang < 1)
      thang = 12; } 
  else if (hang == 1){  // - PHÚT
    phut --;
    if (phut < 0)
      phut = 59; }  
}
void cong_ngay_gio(int &ngay, int &gio)
{
  if (hang == 0){ // + NGÀY
    ngay ++;
    if (ngay > 31)
      ngay = 1;  } 
  else if (hang == 1){ // + GIỜ
    gio ++;
    if (gio > 23)
      gio = 0; }  
}
void cong_thang_phut(int &thang, int &phut)
{
  if (hang == 0){ // + THÁNG
    thang ++;
    if (thang > 12)
      thang = 1; } 
  else if (hang == 1){ // + PHÚT
    phut ++;
    if (phut > 59)
      phut = 0; }  
}

void hien_thi_bt(int &ngay, int &thang, int &gio, int &phut)
{
  if (ngay < 10){
    lcd.setCursor(6,0); lcd.print("0");
    lcd.setCursor(7,0); lcd.print(ngay); }
  else {lcd.setCursor(6,0); lcd.print(ngay);}

  lcd.setCursor(8,0); lcd.print("/");

  if (thang < 10){
    lcd.setCursor(9,0); lcd.print("0"); 
    lcd.setCursor(10,0); lcd.print(thang);} 
  else {lcd.setCursor(9,0); lcd.print(thang);}

  if (gio < 10){
    lcd.setCursor(6,1); lcd.print("0");
    lcd.setCursor(7,1); lcd.print(gio);} 
  else {lcd.setCursor(6,1); lcd.print(gio);}

  lcd.setCursor(8,1); lcd.print(":");

  if (phut < 10){
    lcd.setCursor(9,1); lcd.print("0"); 
    lcd.setCursor(10,1); lcd.print(phut);} 
  else {lcd.setCursor(9,1); lcd.print(phut);}    

  lcd.setCursor(contro_bt, hang); 
  lcd.cursor();
  delay(50);
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
        congtru_tong = 0;  
      else
        congtru_tong++;     
      menu_tong();
    }
    
    else if (demtong == 2 && (congtru_tong == 1 or congtru_tong == 2))   // + CON TRỎ ở SET DATE và TIME
    {
      contro ++;
      if (contro > 15)
        contro = 0;
    }

    else if (demtong == 3) // - ở ngày, tháng, năm, giờ, phút, giây và + con trỏ Báo Thức   
    {
      if(congtru_tong == 1) // - ở NGÀY, THÁNG, NĂM
      {
        if ((contro == 0 or contro == 1)){ //NGÀY
          ngay --;
          if (ngay < 1)
            ngay = 31;
        }
        else if ((contro == 3 or contro == 4)){ //THÁNG
          thang --;
          if (thang < 1)
            thang = 12;
        }

          else if (contro == 6){ //NĂM NGHÌN
            namng --;
            if (namng < 0)
              namng = 9;
          }
          else if (contro == 7){ //NĂM TRĂM
            namtr --;
            if (namtr < 0)
              namtr = 9;
          }
          else if (contro == 8){ //NĂM CHỤC
            namch --;
            if (namch < 0)
              namch = 9;
          }
          else if (contro == 9){ //NĂM ĐƠN VỊ
            namdv --;
            if (namdv < 0)
              namdv = 9;
          }
      }
      else if (congtru_tong == 2) // - ở GIỜ : PHÚT : GIÂY
      {
        if ((contro == 0 or contro == 1)){ //GIỜ
          gio --;
          if (gio < 0)
            gio = 23;
        }
        else if ((contro == 3 or contro == 4)){ //PHÚT
          phut --;
          if (phut < 0)
            phut = 59;
        }
        else if ((contro == 6 or contro == 7)){ //GIÂY
          giay --;
          if (giay < 0)
            giay = 59;  
        }
      }
      else if (congtru_tong == 3) // + CON TRỎ ở BÁO THỨC
      {
        contro_bt ++;
        if (hang == 0){
          if (contro_bt > 10)
          { contro_bt = 6;
            hang = 1; }
        } else {
          if (contro_bt > 15)
          { contro_bt = 6;
            hang = 0; }       
        }
      }
    } 

    else if (demtong == 2 && congtru_tong == 3) //Lên ở MENU BÁO THỨC
    {
      congtru_menubaothuc ++;
      if (congtru_menubaothuc > 5)
        {congtru_menubaothuc = 0;}
      menu_baothuc();
    }  
    
    else if (demtong == 4 && congtru_tong == 3) // - BÁO THỨC | NGÀY/THÁNG & GIỜ/PHÚT
    {
      if(contro_bt == 6 or contro_bt == 7) // Ngày or Giờ
      {
        if (congtru_menubaothuc == 1) // - NGÀY & GIỜ 1
          tru_ngay_gio(ngay1, gio1);
        else if (congtru_menubaothuc == 2) // - NGÀY & GIỜ 2
          tru_ngay_gio(ngay2, gio2); 
        else if (congtru_menubaothuc == 3) // - NGÀY & GIỜ 3
          tru_ngay_gio(ngay3, gio3); 
        else if (congtru_menubaothuc == 4) // - NGÀY & GIỜ 4
          tru_ngay_gio(ngay4, gio4); 
        else if (congtru_menubaothuc == 5) // - NGÀY & GIỜ 5
          tru_ngay_gio(ngay5, gio5);                                      
      }
      else if (contro_bt == 9 or contro_bt == 10) // Tháng or phút
      {
        if (congtru_menubaothuc == 1) // - THÁNG & PHÚT 1
          tru_thang_phut(thang1, phut1);
        else if (congtru_menubaothuc == 2) // - THÁNG & PHÚT 2
          tru_thang_phut(thang2, phut2);
        else if (congtru_menubaothuc == 3) // - THÁNG & PHÚT 3
          tru_thang_phut(thang3, phut3);
        else if (congtru_menubaothuc == 4) // - THÁNG & PHÚT 4
          tru_thang_phut(thang4, phut4);
        else if (congtru_menubaothuc == 5) // - THÁNG & PHÚT 5
          tru_thang_phut(thang5, phut5);                              
      }
    }                                         
  delay(100);
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
        congtru_tong = 3;  
      else
        congtru_tong--; 
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

    else if (demtong == 3) // + Ở Ngày, tháng, năm, giờ, phút, giây và - con trỏ Báo Thức
    {
      if(congtru_tong == 1) // + ở NGÀY, THÁNG, NĂM
      {
        if (contro == 0 or contro == 1){ // + NGÀY ở DATE
          ngay ++;
          if (ngay > 31)
            ngay = 1; }
        else if (contro == 3 or contro == 4){ // + THÁNG ở DATE
          thang ++;
          if (thang > 12)
            thang = 1; }
        else if (contro == 6){ // + NĂM NGHÌN
          namng ++;
          if (namng > 9)
            namng = 0; }
        else if (contro == 7){// + NĂM TRĂM
          namtr ++;
          if (namtr > 9)
            namtr = 0; }
        else if (contro == 8){// + NĂM CHỤC
          namch ++;
          if (namch > 9)
            namch = 0; }
        else if (contro == 9){// + NĂM ĐƠN VỊ
          namdv ++;
          if (namdv > 9)
            namdv = 0; }
      }
      else if(congtru_tong == 2) //+ ở GIỜ : PHÚT :GIÂY
      {
        if (contro == 0 or contro == 1){ //GIỜ
          gio ++;
          if (gio > 23)
            gio = 0;     }

        else if (contro == 3 or contro == 4){ //PHÚT
          phut ++;
          if (phut > 59)
            phut = 0;  }

        else if (contro == 6 or contro == 7){ //GIÂY
          giay ++;
          if (giay > 59)
            giay = 0;  }
      }
      else if(congtru_tong == 3) // - CON TRỎ ở BÁO THỨC
      {
        contro_bt --;
        if (hang == 0){
          if (contro_bt < 6)
          { contro_bt = 15;
            hang = 1; }
        } else {
          if (contro_bt < 6)
          { contro_bt = 10;
            hang = 0; }        
        } 
      }   
    }

    else if (demtong == 2 && congtru_tong == 3) //Xuống ở MENU BÁO THỨC
    {
      congtru_menubaothuc --;
      if (congtru_menubaothuc < 0)
        {congtru_menubaothuc = 5;}
      menu_baothuc();
    } 

    else if (demtong == 4 && congtru_tong == 3)  // + BÁO THỨC | NGÀY/THÁNG & GIỜ/PHÚT
    {
      if(contro_bt == 6 or contro_bt == 7) // Ngày or Giờ
      {
        if (congtru_menubaothuc == 1) // + NGÀY & GIỜ 1
          cong_ngay_gio(ngay1, gio1);
        else if (congtru_menubaothuc == 2) // + NGÀY & GIỜ 2
          cong_ngay_gio(ngay2, gio2); 
        else if (congtru_menubaothuc == 3) // + NGÀY & GIỜ 3
          cong_ngay_gio(ngay3, gio3); 
        else if (congtru_menubaothuc == 4) // + NGÀY & GIỜ 4
          cong_ngay_gio(ngay4, gio4); 
        else if (congtru_menubaothuc == 5) // + NGÀY & GIỜ 5
          cong_ngay_gio(ngay5, gio5);                                      
      }
      else if (contro_bt == 9 or contro_bt == 10) // Tháng or phút
      {
        if (congtru_menubaothuc == 1) // + THÁNG & PHÚT 1
          cong_thang_phut(thang1, phut1);
        else if (congtru_menubaothuc == 2) // + THÁNG & PHÚT 2
          cong_thang_phut(thang2, phut2);
        else if (congtru_menubaothuc == 3) // + THÁNG & PHÚT 3
          cong_thang_phut(thang3, phut3);
        else if (congtru_menubaothuc == 4) // + THÁNG & PHÚT 4
          cong_thang_phut(thang4, phut4);
        else if (congtru_menubaothuc == 5) // + THÁNG & PHÚT 5
          cong_thang_phut(thang5, phut5);                              
      }
    }                                                          
  delay(100);
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
    else if (demtong == 2) //Chọn các mục ở MENU TỔNG
    {
      if(congtru_tong == 0){ //Nhấn BACK từ Menu tổng về màn hình
        demtong = 0;
        manhinh(); }
      else if(congtru_tong == 1 or congtru_tong == 2) // chọn menu tổng DATE or TIME
        chonmenu_tong();
      else if(congtru_tong == 3) //Menu BÁO THỨC
        menu_baothuc();
    }                                           
      
    else if (demtong == 4) //Thoát CON TRỎ từ SET DATE or TIME ra
    {
      if (congtru_tong == 1) //Thoát CON TRỎ từ SET DATE ra
      { demtong = 2;
        chonmenu_tong(); }
      else if (congtru_tong == 2) //Thoát CON TRỎ từ SET TIME ra
      { demtong = 2;
        chonmenu_tong(); }
      else if (congtru_tong == 3 && (contro_bt == 12 or contro_bt == 13 
              or contro_bt == 14 or contro_bt == 15)) //Thoát từ SET BT ra menu báo thức
      {
        menu_baothuc();
        demtong = 2;
        congtru_tong = 3;
        contro_bt = 6;
        hang = 0;
        lcd.noCursor();
      }
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

    else if (demtong == 3 && congtru_tong == 3) //Chọn MENU Báo Thức 
      {
        if(congtru_menubaothuc == 0){ //từ Menu BÁO THỨC về Menu TỔNG
          demtong = 1;
          congtru_menubaothuc = 0;
          menu_tong();}

        else if(congtru_menubaothuc == 1 or congtru_menubaothuc == 2 or congtru_menubaothuc == 3 
                or congtru_menubaothuc == 4 or congtru_menubaothuc == 5) //chọn menu BT
        {
          chonmenu_baothuc();
        }
      }

    else if (demtong == 5 && congtru_tong == 3 && (congtru_menubaothuc == 1 or congtru_menubaothuc == 2
            or congtru_menubaothuc == 3 or congtru_menubaothuc == 4 or congtru_menubaothuc == 5))  //Từ chức năng SET ra
      {
        chonmenu_baothuc();
        demtong = 3;
      }

    if(dembaothuc == 1){ //Đang có BÁO THỨC
      dembaothuc = 0;
      demtong = 0; }

  delay(100);
  }
  macdinh = gtmenu;
}

if (demtong == 0 && congtru_tong == 0) // MÀN HÌNH
{
  manhinh();
  lcd.noCursor();
}
else if ((demtong == 2 or demtong == 3) && congtru_tong != 3) //Hiển thị SETUP DATE or TIME
{
  if(congtru_tong == 1) // SET DATE
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
  else if (congtru_tong == 2) // SET TIME
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
}
else if ((demtong == 3 or demtong == 4) && congtru_tong == 3) //Hiển thị SETUP BÁO THỨC
{
  if(congtru_menubaothuc == 1) //BT 1
    hien_thi_bt(ngay1, thang1, gio1, phut1);  
  else if(congtru_menubaothuc == 2) //BT 2
    hien_thi_bt(ngay2, thang2, gio2, phut2);  
  else if(congtru_menubaothuc == 3) //BT 3
    hien_thi_bt(ngay3, thang3, gio3, phut3);  
  else if(congtru_menubaothuc == 4) //BT 4
    hien_thi_bt(ngay4, thang4, gio4, phut4);                    
  else if(congtru_menubaothuc == 5) //BT 5
    hien_thi_bt(ngay5, thang5, gio5, phut5);      
}

if (demtong == 0){ // CHỈ KHI Ở MÀN HÌNH CHÍNH MỚI HIỆN BÁO THỨC
  // Thực thi BÁO THỨC
  if ((t.date == ngay1 or t.date == ngay2 or t.date == ngay3 or t.date == ngay4 or t.date == ngay5) && 
      (t.mon == thang1 or t.mon == thang2 or t.mon == thang3 or t.mon == thang4 or t.mon == thang5) && 
      (t.hour == gio1 or t.hour == gio2 or t.hour == gio3 or t.hour == gio4 or t.hour == gio5) && 
      (t.min == phut1 or t.min == phut2 or t.min == phut3 or t.min == phut4 or t.min == phut5) && t.sec == 1)      
  { dembaothuc = 1; }
} else dembaothuc = 0; // NẾU ĐANG Ở CÁC MENU HAY SETUP THÌ KHÔNG BÁO THỨC

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