#include <math.h>
#include <stdint.h>

const int x = 32;

byte a[x];
byte b[x];
byte c[x];
byte d[x];

byte compare(byte one[x], byte two[x]);

void setup() {
  
  Serial.begin(9600);
  while (!Serial){;}
  
  Serial.println("Serial connection initialized!");  
  
  for (int i = 0; i < x; i++){
      a[i] = B00000000;
      b[i] = B11111111;
      c[i] = B01111111;
      d[i] = B00000001;
    }
   
   Serial.println(abs(a[x]/2-b[x]/2));
   
   Serial.print("Similarity value of all white and all black: ");
   Serial.println(compare(a,b));
   Serial.print("Similarity value of all white and all white: ");
   Serial.println(compare(a,a));
   Serial.print("Similarity of half tone and all white: ");
   Serial.println(compare(a,c));
   Serial.print("Similarity of 1 bit gray and all white: ");
   Serial.println(compare(a,d));
         
}

void loop() {
  // put your main code here, to run repeatedly: 
  
}

byte compare(byte one[x], byte two[x]){
    
  Serial.println("Beginning comparison");
  
  signed char result[x];
  byte place = x;
  
  
  for (int i = 0; i < x; i++){    
   result[i] = (one[i]/2)-(two[i]/2);
   result[i] = abs(result[i]);
   Serial.print(i);
   Serial.print("   ");
   Serial.println(result[i]);
   }
   
   Serial.println();
  
  while (place != 0){
    
    byte wrt = B0;
    byte rd = B0;
    
    /*
    Serial.println(place); 
    
    Serial.print(wrt);
    Serial.print("   ");
    Serial.println(rd);
    */
    
    Serial.println("Break here");
    
   while (rd < place - 2){
     
     Serial.print(result[rd]);
     Serial.print(" + ");
     Serial.print(result[rd+1]);
     Serial.print(" = ");
     Serial.print((result[rd]+result[rd+1])/2);
     
     result[wrt] = (result[rd] + result[rd+1])/2;
     
     Serial.print("   ");
     Serial.println(result[wrt]);
     
     wrt++;
     rd += 2;
    
    /* 
     Serial.print(wrt);
     Serial.print("   ");
     Serial.println(rd);
   */
   }
   
   place = place/2;
   
  }
 
 return result[0];
  
}
