// Ultrasonic Parking Assistance System

const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 8;
const int buzzerPin = 11;

long duration;
float distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Measure return pulse
  duration = pulseIn(echoPin, HIGH, 30000);

  // Convert time to distance in centimeters
  if (duration == 0) {
    distance = 999;
  } else {
    distance = duration * 0.0343 / 2;
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // VERY CLOSE: continuous warning
  if (distance <= 10) {

    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(100);

  }

  // CLOSE: fast beeping
  else if (distance <= 20) {

    digitalWrite(ledPin, HIGH);

    digitalWrite(buzzerPin, HIGH);
    delay(100);

    digitalWrite(buzzerPin, LOW);
    delay(100);

  }

  // APPROACHING: slow beeping
  else if (distance <= 40) {

    digitalWrite(ledPin, HIGH);

    digitalWrite(buzzerPin, HIGH);
    delay(200);

    digitalWrite(buzzerPin, LOW);
    delay(500);

  }

  // SAFE DISTANCE
  else {

    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(100);

  }
}