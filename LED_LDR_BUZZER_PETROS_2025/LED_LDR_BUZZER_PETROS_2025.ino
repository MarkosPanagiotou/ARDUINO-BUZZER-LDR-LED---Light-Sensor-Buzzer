// Pin setup
const int LDR_PIN = A0;     
const int LED_PIN = 13;     
const int BUZZER_PIN = 12;   


const int THRESHOLD = 500;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  int lightLevel = analogRead(LDR_PIN);  
  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  if (lightLevel > THRESHOLD) {
    
    digitalWrite(LED_PIN, HIGH);
    
    tone(BUZZER_PIN, 1000);   
    delay(300);               
    noTone(BUZZER_PIN);       
    delay(300);               
  } 
  else {
    
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
  }

  delay(100);  
}