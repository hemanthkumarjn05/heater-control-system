#define RED_PIN    8
#define GREEN_PIN  7
#define BLUE_PIN   6
#define BUZZER_PIN 9
#define HEATER_PIN 10
#define NTC_PIN    A0

int temperature = 0;
String state = "Idle";

void setup() 
{
  Serial.begin(9600);

  pinMode(HEATER_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // Ensure all outputs start LOW
  digitalWrite(HEATER_PIN, LOW);
  noTone(BUZZER_PIN);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
}

// Helper function to set RGB color
void setLEDColor(bool red, bool green, bool blue)
{
  digitalWrite(RED_PIN, red);
  digitalWrite(GREEN_PIN, green);
  digitalWrite(BLUE_PIN, blue);
}

void loop() 
{
  int analogVal = analogRead(NTC_PIN);
  temperature = map(analogVal, 1000, 100, -24, 80); // Adjust to match your slider range

  if (temperature < 25) 
  {
    state = "Idle";
    digitalWrite(HEATER_PIN, LOW);
    noTone(BUZZER_PIN);
    setLEDColor(LOW, LOW, LOW);  // LED OFF
  }
  else if (temperature >= 25 && temperature < 45) 
  {
    state = "Heating";
    digitalWrite(HEATER_PIN, HIGH);
    noTone(BUZZER_PIN);
    setLEDColor(LOW, HIGH, LOW);  // GREEN
  }
  else if (temperature >= 45 && temperature < 48) 
  {
    state = "Stabilizing";
    digitalWrite(HEATER_PIN, HIGH);
    noTone(BUZZER_PIN);
    setLEDColor(LOW, HIGH, LOW);  // GREEN
  }
  else if (temperature >= 48 && temperature <= 50)
  {
    state = "Target Reached";
    digitalWrite(HEATER_PIN, LOW);
    noTone(BUZZER_PIN);
    setLEDColor(LOW, LOW, HIGH);  // BLUE
  }
  else 
  {
    state = "Overheat";
    digitalWrite(HEATER_PIN, LOW);
    setLEDColor(HIGH, LOW, LOW);  // RED
    tone(BUZZER_PIN, 1000);       // Continuous beep
  }

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" °C\tState: ");
  Serial.print(state);
  Serial.print("\tHeater: ");
  Serial.println(digitalRead(HEATER_PIN) ? "ON" : "OFF");

  delay(1000);  // Delay for 1 second
}
