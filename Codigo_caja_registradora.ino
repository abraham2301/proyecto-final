#include <LiquidCrystal.h>
#include<Servo.h>
#include <SPI.h>
#include <MFRC522.h>

Servo myservo;  


#define RST_PIN         2         // Configurable, see typical pin layout above
#define SS_PIN          53          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 
LiquidCrystal lcd (12,11,4,5,6,7); // rs, e, d4, d5, d6,

byte LecturaUID[4];
byte Usuario1[4]= {0x10, 0x01, 0xFD, 0xA9} ; //tarjeta
byte Usuario2[4]= {0x38, 0x6C, 0xBB, 0x6E} ; //llavero

void setup() {

  myservo.attach(8);
    lcd.begin(16,2);
  Serial.begin(9600);   
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  Serial.println("IDENTIFIQUESE");
  analogWrite(9,80);
  lcd.setCursor(0,0);
  lcd.print("BIENVENIDO");
  lcd.setCursor(0,1);
  lcd.print("      A SUPER 24");
  delay(5000);
  lcd.clear();
  lcd.print("    GRUPO 3    ");
  delay(5000);
  lcd.clear();
}

void loop() {
 lcd.setCursor(0,0); 
 lcd.print("EXAMEN FINAL");
  
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
    return;
  
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
    return;

  Serial.print ("UID:");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
   if (mfrc522.uid.uidByte[i] < 0x10){
    Serial.print(" 0"); 
   }
   else{
    Serial.print(" ");
   }
  Serial.print(mfrc522.uid.uidByte[i], HEX);
  LecturaUID[i]=mfrc522.uid.uidByte[i];
  }
  
  Serial.print("\t");

  if(comparaUID(LecturaUID, Usuario1)) {
    Serial.println("BIENVENIDO USUARIO 1");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("GRACIAS POR     ");
    lcd.setCursor(0,1);
    lcd.print("       SU COMPRA"); 
    myservo.write(45);
    delay(5000);    
        lcd.clear(); 
     
}  
  else if(comparaUID(LecturaUID, Usuario2)) {
    Serial.println("BIENVENIDO USUARIO 2");
    lcd.setCursor(0,0);
    lcd.print("VUELVA          ");
    lcd.setCursor(0,1);
    lcd.print("          PRONTO");
    delay(5000);
    myservo.write(0);
    lcd.clear();
  }   
 else {
    Serial.println("NO TE CONOZCO");
    lcd.clear();
    lcd.print(0,0);
    lcd.print("CERRANDO        ");
    lcd.setCursor(0,1);
    lcd.print("            CAJA");
    myservo.write(180);
    delay(5000);
    lcd.clear();
           mfrc522.PICC_HaltA();  
} 
}
boolean comparaUID(byte lectura[],byte usuario[])
{
  for (byte i = 0; i < mfrc522.uid.size; i++) {
  if(lectura[i] != usuario[i])
    return(false);  
  }
  return(true);  
}
