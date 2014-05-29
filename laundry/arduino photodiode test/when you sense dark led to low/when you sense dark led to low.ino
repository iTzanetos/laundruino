int photoRPin = 0; 
int minLight;
int maxLight;
int lightLevel;
int adjustedLightLevel;
int led = 13;


void setup() {
 Serial.begin(9600);
 pinMode(13, OUTPUT);
 
 //Setup the starting light level limits
 lightLevel=analogRead(photoRPin);
 minLight=lightLevel-20;
 maxLight=lightLevel;
}

void loop(){
 //auto-adjust the minimum and maximum limits in real time
 lightLevel=analogRead(photoRPin);
 if(minLight>lightLevel){
 minLight=lightLevel;
 //digitalWrite(13, HIGH); // sto 0
 }
 if(maxLight<lightLevel){
 maxLight=lightLevel;
 //digitalWrite(13, LOW); // sto 100
 }
 
 //Adjust the light level to produce a result between 0 and 100.
 adjustedLightLevel = map(lightLevel, minLight, maxLight, 0, 100);  
 
 //Send the adjusted Light level result to Serial port (processing)
 Serial.println(adjustedLightLevel);
 if(adjustedLightLevel<20){
    digitalWrite(13, LOW); // sto SKOTADI to led svhnei
 }
 if(adjustedLightLevel>20){
    digitalWrite(13, HIGH); // sto FWS
 }
 
 //slow down the transmission for effective Serial communication.
 delay(50);
}
