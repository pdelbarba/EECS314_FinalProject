#include <math.h>

const int x = 16;
const int n = 20;

byte a[x][x];
byte b[x][x];
byte c[x][x];
byte d[x][x];

double compare(byte one[][x], byte two[][x]);

void setup() {
  
  Serial.begin(9600);
  while (!Serial){;}
  
  Serial.println("Serial connection initialized!");  
  
  for (int i = 0; i < x; i++){
     for (int j = 0; j < x; j++){
      a[i][j] = B00000000;
      b[i][j] = B11111111;
      c[i][j] = B01111111;
      d[i][j] = B00000001;
        
     }
    }
   
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

double compare(byte one[][x], byte two[][x]){
 
  double d1, d2, d3, d4, sum, average, result, total;
  
  total = 0;
  
  int width = x;
    
  for (int i = 0; i < x; i++){
    for (int j = 0; j < x; j++){
      
      d1 = 0;
      d2 = 0;
      d3 = 0;
      d4 = 0;
      sum = 0;
      average = 0;
      result = 0;
   
      d1 = double(one[i][j]) - double(two[i][j]);
      //Serial.println(d1); 
      d2 = double(one[i+1][j]) - double(two[i+1][j]);
      d3 = double(one[i+1][j+1]) - double(two[i+1][j+1]);
      d1 = double(one[i][j+1]) - double(two[i][j+1]);

      d1 *= d1;
      //Serial.println(d1);
      d2 *= d2;
      d3 *= d3;
      d4 *= d4;
      
      sum = d1 + d2 + d3 + d4;
      //Serial.println(sum);
      
      average = sum/4;
      //Serial.println(average);
      
      result = sqrt(average);
      //Serial.println(result);
      
      total += result;
    }
  }  
  return total;
}
