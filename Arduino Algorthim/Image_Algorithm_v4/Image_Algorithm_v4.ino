const int x = 256;
const int threshold = 13;

byte a[x];
byte b[x];

byte compare(byte one[x], byte two[x]);

void setup(){

  Serial.begin(9600); 

  while (!Serial){
    delay(1);
  }

  Serial.println("Serial connection established");

  for (int i = 0; i < x; i++){
    //byte him = random(256);
    //byte her = random(256);

    a[i] = B0;
    b[i] = B0; 
  }

  Serial.println("Finished preparing arrays");

  Serial.println("Comparing arrays a and b.");

  Serial.print("Similarity: ");

  Serial.println(compare(a, b));

}

void loop(){

}

byte compare(byte one[x], byte two[x]){

  Serial.println("Beginning comparison");

  signed char diff = B0;
  byte result = 0;

  for (int i = 0; i < x; i++){
    diff = (one[i]/2) - (two[i]/2);

    Serial.print(diff);
    Serial.print(" -> ");

    diff = abs(diff);

    Serial.println(diff);

    if (diff <= threshold){
      if(result != 255){
        result++;
      }
      Serial.println("Hit!");
    }
  }

  Serial.print("Result is ");
  Serial.println(result);

  return result;

}

