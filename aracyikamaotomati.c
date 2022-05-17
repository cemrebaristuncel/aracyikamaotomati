#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int b1 = 7;
int b2 = 8;
int b3 = 13;
int b4 = 14;
int b5 = 15;
int b6 = 16;
int b7 = 17;
int toplam = 0;
int toplam_yedek = 0;
int toplam_yedek2 = 0;
int flag = 0;
int flag2 = 0;
int flag3 = 0;
int sayac = 0;
int sayac2 = 0;
int beslirasayaci = 0;
int onlirasayaci = 0;
int yirmilirasayaci = 0;
int ellilirasayaci = 0;
int yuzlirasayaci = 0;
long sayiuret;
long sayiuret1;
int m1 = 0;
int m2 = 0;
int m3 = 0;
int m4 = 0;
int m5 = 0;
int m6 = 0;
int m7 = 0;
int bolumsonucu = 0;
int beslik_adet = 10;
int onluk_adet = 15;
int yirmilik_adet = 20;
int ellilik_adet = 10;
int yuzluk_adet = 5;
int ko_kalan = 30;
int y_kalan = 20;
int ku_kalan = 15;
int c_kalan = 20;
int ko_fiyat = 15;
int y_fiyat = 10;
int ku_fiyat = 5;
int c_fiyat = 50;
int led1 = 6;
int led2 = 9;
int kasadakipara = (beslik_adet)*5 + (onluk_adet)*10 + (yirmilik_adet)*20 + (ellilik_adet)*50 + (yuzluk_adet)*100;



void setup() {
  
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(b3,INPUT);
  pinMode(b4,INPUT);
  pinMode(b5,INPUT);
  pinMode(b6,INPUT);
  pinMode(b7,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  randomSeed(103);
  
 
  lcd.begin(16, 2);
  lcd.print("Bakiyeniz ");
}

void loop() {
  	
  
   m1 = digitalRead(b1);
   m2 = digitalRead(b2);
   m3 = digitalRead(b3);
   m4 = digitalRead(b4);
   m5 = digitalRead(b5);
   m6 = digitalRead(b6);
   m7 = digitalRead(b7);
  
   
   
if(flag == 0)
{  
  if(m1 == 1 )
  {  
    sayac2 = 0;
  	delay(225);
    toplam +=5;
    beslik_adet++;
    kasadakipara += 5;
    beslirasayaci++;
    delay(225);
      lcd.setCursor(0, 1);
  lcd.print("->");
      lcd.setCursor(3, 1);
  lcd.print(toplam);
   
    
  }
    if(m2 == 1 )
  {  
    sayac2 = 0;
  	delay(225);
    toplam +=10;
    onluk_adet++;
    kasadakipara += 10;
     onlirasayaci++;
      delay(225);
      lcd.setCursor(0, 1);
     lcd.print("->");
      lcd.setCursor(3, 1);
  lcd.print(toplam);
   
    
  }  
    if(m3 == 1 )
  {  
    sayac2 = 0;
  	delay(225);
    toplam +=20;
      yirmilik_adet++;
      kasadakipara += 20;
     yirmilirasayaci++;
      delay(225);
      lcd.setCursor(0, 1);
      lcd.print("->");
      lcd.setCursor(3, 1);
  
  lcd.print(toplam);
   
    
  } 
    if(m4 == 1 )
  {  
    sayac2 = 0;
  	delay(225);
    toplam +=50;
      ellilik_adet++;
      kasadakipara += 50;
      ellilirasayaci++;
      delay(225);
      lcd.setCursor(0, 1);
      lcd.print("->");
      lcd.setCursor(3, 1);
  
  lcd.print(toplam);
   
    
  } 
         if(m5 == 1 )
  {  
    sayac2 = 0;
  	delay(225);
    toplam +=100;
      yuzluk_adet++;
      kasadakipara += 100;
      yuzlirasayaci++;
      delay(225);
      lcd.setCursor(0, 1);
      lcd.print("->");
      lcd.setCursor(3, 1);
  
  lcd.print(toplam);
   
    
  } 
 if(m7 == 1 )
  {    
 	lcd.clear();
    toplam = 0;
   if(sayac2 == 0){
   kasadakipara -= beslirasayaci*5 + onlirasayaci*10 + yirmilirasayaci*20 + ellilirasayaci*50 + yuzlirasayaci*100;
    beslik_adet -= beslirasayaci;
    onluk_adet -= onlirasayaci;
    yirmilik_adet -= yirmilirasayaci;
    ellilik_adet -= ellilirasayaci;
    yuzluk_adet -= yuzlirasayaci;
    sayac2 = 1;
    }
    lcd.print("Bakiyeniz ");
    lcd.setCursor(0, 1);
    lcd.print("->");
    lcd.setCursor(3, 1);
    lcd.print(toplam);
    beslirasayaci = 0;
    onlirasayaci = 0;
    yirmilirasayaci = 0;
    ellilirasayaci = 0;
    yuzlirasayaci = 0;
  } 

           if(m6 == 1 )
  {  
    toplam_yedek = toplam;         
	lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Girdiginiz tutar ");
    lcd.setCursor(0, 1);
    lcd.print("->");
    lcd.setCursor(3, 1);
    lcd.print(toplam);
    kasadakipara += toplam;
    delay(1500);
    lcd.clear();
    lcd.print("Hizmet seciniz");
   
  	flag = 1;
    
    
	
    
  }
  
}
  
  if(flag == 1){

   
 
    if(m1 == 1)
    {
      if(toplam < 15){
        lcd.clear();
        lcd.print("Yetersiz Bakiye");}
      else {
      	lcd.clear();
      	delay(225);
    	ko_kalan -= 1;
      	toplam -= 15;
        kasadakipara -= 15;
        lcd.print("Secim:Kopukleme"); 
        lcd.setCursor(0,1);
        lcd.print("Kalan bakiye");
        lcd.setCursor(13,1);
        lcd.print(toplam);
        
        
        flag2=1;
      	
    }
    }
    if(m2 == 1)
    {
      if(toplam < 10){
        lcd.clear();
        lcd.print("Yetersiz Bakiye");}
      else {
      	lcd.clear();
      	delay(225);
    	y_kalan -= 1;
      	toplam -= 10;
        kasadakipara -= 10;
        lcd.print("Secim:Yikama"); 
        lcd.setCursor(0,1);
        lcd.print("Kalan bakiye");
        lcd.setCursor(13,1);
        lcd.print(toplam);
        flag2=1;
    }
    }
    if(m3 == 1)
    {
      if(toplam < 5){
        lcd.clear();
        lcd.print("Yetersiz Bakiye");}
      else {
      	lcd.clear();
      	delay(225);
    	ku_kalan -= 1;
      	toplam -= 5;
        kasadakipara -= 5;
        lcd.print("Secim:Kurulama"); 
        lcd.setCursor(0,1);
        lcd.print("Kalan bakiye");
        lcd.setCursor(13,1);
        lcd.print(toplam);
        flag2=1;
    }
    }
    if(m4 == 1)
    {   
        if(toplam < 50){
        lcd.clear();
        lcd.print("Yetersiz Bakiye");}
      else {
        lcd.clear();
      	delay(225);
    	c_kalan -= 1;
      	toplam -= 50;
        kasadakipara -= 50;
        lcd.print("Secim:Cilalama"); 
        lcd.setCursor(0,1);
        lcd.print("Kalan bakiye");
        lcd.setCursor(13,1);
        lcd.print(toplam);
        flag2=1;
      }
    }
    if(m7 == 1){
    if(flag3 == 1)
    {
    lcd.clear();
    lcd.print("Para iade edildi");
    delay(1500);
    lcd.clear();
    lcd.print("Bakiyeniz");
    lcd.setCursor(0,1);
    lcd.print("->");
    lcd.setCursor(3, 1);
    lcd.print(toplam_yedek);
    delay(2000);
    lcd.clear();
    lcd.print("Hizmet seciniz");
    flag = 1;
    ko_kalan = 30;
    y_kalan = 20;
    ku_kalan = 15;
    c_kalan = 20;
    flag2 = 0;  
    }
    else{
    flag = 0;
    ko_kalan = 30;
    y_kalan = 20;
    ku_kalan = 15;
    c_kalan = 20;
    flag2 = 0;
      }  
      
    
    }
     
     
    if(m6 == 1 && flag2 == 1)
    {
      
        sayiuret = random(1,5);
        delay(300);
      digitalWrite(led2, LOW);
      digitalWrite(led1, LOW);
      lcd.clear();
      
      if(sayiuret == 2){
      flag3 = 1;
      ko_kalan = 30;
      y_kalan = 20;
      ku_kalan = 15;
      c_kalan = 20;
      toplam = toplam_yedek;
      digitalWrite(led1, HIGH);
      lcd.print("PARA SIKISTI!");
      delay(1500);
      
      lcd.clear();
      
      }
      else{
      digitalWrite(led2, HIGH);
 
        toplam_yedek2 =toplam;
        if(kasadakipara > toplam_yedek2){
        if(yuzluk_adet >0){
          
        if((toplam_yedek2)>=100){
        bolumsonucu = toplam_yedek2/100;
    
          if(yuzluk_adet >= bolumsonucu ){
            yuzluk_adet -= bolumsonucu;
            toplam_yedek2 -= bolumsonucu*100;
          }
        
        else{
        toplam_yedek2 -= yuzluk_adet*100;
        yuzluk_adet = 0;
        
        }
        
        
        } 
        }
        if(ellilik_adet >0){
        if((toplam_yedek2)>=50){
        lcd.clear();
        bolumsonucu = toplam_yedek2/50;
        
        if(ellilik_adet >= bolumsonucu ){
            ellilik_adet -= bolumsonucu;
            toplam_yedek2 -= bolumsonucu*50;
          }
        
        else{
        toplam_yedek2 -= ellilik_adet*50;
        ellilik_adet = 0;
        
        }
        }
        }
        if(yirmilik_adet >0){
        if((toplam_yedek2)>=20){
        bolumsonucu = toplam_yedek2/20;
        if(yirmilik_adet >= bolumsonucu ){
            yirmilik_adet -= bolumsonucu;
            toplam_yedek2 -= bolumsonucu*20;
          }
        
        else{
        toplam_yedek2 -= yirmilik_adet*20;
        yirmilik_adet = 0;
        
        }
        }
        }
        if(onluk_adet >0){
        if((bolumsonucu)>=0){
        bolumsonucu = toplam_yedek2/10;
          
        if(onluk_adet >= bolumsonucu ){
            onluk_adet -= bolumsonucu;
            toplam_yedek2 -= bolumsonucu*10;
            
          }
        
        else{
        toplam_yedek2 -= onluk_adet*10;
        onluk_adet = 0;
        
        }
        }
        }
        if(beslik_adet >0){
        if((toplam_yedek2)>=5){
        bolumsonucu = toplam_yedek2/5;
        if(beslik_adet >= bolumsonucu ){
            beslik_adet -= bolumsonucu;
            toplam_yedek2 -= bolumsonucu*5;
          }
        
        else{
        toplam_yedek2 -= beslik_adet*5;
        beslik_adet = 0;
        
        }
        }
        }
        }
      else{
      lcd.print("Kasada para yok");
      lcd.clear();
      }
       
       lcd.clear();
       lcd.print("Para ustu");
       lcd.setCursor(0,1);
       lcd.print("->"); 
       lcd.setCursor(3,1);
       lcd.print(toplam);
       delay(2000);
       toplam_yedek2 = 0;
       flag = 0;
       lcd.clear();
       lcd.print("Yeni musteri");
       lcd.setCursor(0,1);
       lcd.print("Bekleniyor...");
       delay(1500);
      }
      
      
      
    }
    
  }
       

}

