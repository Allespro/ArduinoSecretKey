/*
void setup() 
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); 
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}
void loop() {
  if (Serial.available() > 0)
  {
    String ch;
    ch = Serial.readString();
    ch.trim();
    if(ch == "DePapia"){
        digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
        Serial.print("DebugMeNow");
    }
  }
  delay(20);                       // wait
}
*/

void setup() 
{
  Serial.begin(9600);
  Serial.print("password");
}
void loop() {
  
  //delay(10000);                 
}
