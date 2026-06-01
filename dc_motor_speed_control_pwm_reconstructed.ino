const int sensorPin = A0;   // Potentiometer or analog temperature sensor input
const int motorPin = 9;     // PWM output pin connected to motor driver

int sensorValue = 0;
int pwmValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Read analog value from potentiometer / temperature sensor analogy
  sensorValue = analogRead(sensorPin);

  // Convert analog range 0-1023 to PWM range 0-255
  pwmValue = map(sensorValue, 0, 1023, 0, 255);

  // Generate PWM signal to control DC motor speed
  analogWrite(motorPin, pwmValue);

  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" | PWM Value: ");
  Serial.println(pwmValue);

  delay(500);
}
