int count = 0;
int ctr = 0, oldCtr = 0;
bool out = true;
int startTime = millis();
void setup()
{
  Serial.begin(115200);
  pinMode(D2,OUTPUT);
}
void loop()
{
  if(Serial.available())
  { 
    Serial.println("1");
    count = 0; // Reset count to zero// Keep reading Byte by Byte from the Buffer till the Buffer is empty
    {
      Serial.println("2");
      if(millis() - startTime > 500){ 
        startTime = millis();
        oldCtr = ctr;
        ctr++;
        digitalWrite(D2,HIGH);
        //out = !(out);
      }
      Serial.println("3");
      //digitalWrite(D2,out);
      //out = !out;
      char input = Serial.read();
      Serial.print(input);
      count++; //
      delay(5); //
    }
    Serial.println();
    Serial.print("Tag Length : ");
    Serial.print(count);
    Serial.println(" Bytes");

    
  }
  //Serial.println("4");
  //if(ctr == oldCtr && millis() - startTime > 500){//ctr same for more than 500 ms
  else if(millis() - startTime > 3000){
      digitalWrite(D2,LOW);
  }
}
