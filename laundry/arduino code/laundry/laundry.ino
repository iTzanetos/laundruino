int photoRPin = 0; 
int minLight;
int maxLight;
int lightLevel;
int adjustedLightLevel;
long previousMillis=0 ;       
long interval = 20000; // tweet is posted after 20" from the time the photodiode sensed DARKNESS
unsigned long currentMillis ;
 
void setup()   { 
 Serial.begin(9600); // set up Serial library at 9600 bps 
  
 lightLevel=analogRead(photoRPin);
 minLight=lightLevel-20;
 maxLight=lightLevel;
 
}

  void loop(){
    // check to see if it's time to blink the LED; that is, if the
  // difference between the current time and last time you blinked
  // the LED is bigger than the interval at which you want to
  // blink the LED.
    
 lightLevel=analogRead(photoRPin);
 if(minLight>lightLevel){
 minLight=lightLevel;
 //digitalWrite(13, HIGH); // sto 0
 }
 if(maxLight<lightLevel){
 maxLight=lightLevel;
 //digitalWrite(13, LOW); // sto 100
 }
 
 //Adjust the light level to produce a result between 0 and 100.If value below/over 0/100 it's set to 0/100.
 adjustedLightLevel = map(lightLevel, minLight, maxLight, 0, 100);  
 
 //Send the adjusted Light level result to Serial port (processing)
 if(adjustedLightLevel<20){   
   do{
   currentMillis = millis();
  // Serial.println(currentMillis);
   }while(currentMillis - previousMillis < interval );
   
 Serial.println("laundry's done! ");
 previousMillis=currentMillis;
 
 }

  delay(50);
  }
