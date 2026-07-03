#include <Servo.h>

const int ENA = 6;
const int IN1 = 8;
const int IN2 = 7;
const int ENB = 6;
const int IN3 = 4;
const int IN4 = 2;

const int trigPin = A5;
const int echoPin = A4;

const int irLeft = A0;
const int midIR = A1;
const int irRight = A2;

const int buzzer = A3;
const int switchObs = 12;
const int switchLine = 13;
const int switchBluetooth = 3;

Servo myServo;

void setup() {
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(irLeft, INPUT);
  pinMode(midIR, INPUT);
  pinMode(irRight, INPUT);

  pinMode(switchObs, INPUT_PULLUP);
  pinMode(switchLine, INPUT_PULLUP);
  pinMode(switchBluetooth, INPUT_PULLUP);

  myServo.attach(11);
  myServo.write(110);
}

long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH, 25000);
  if (duration == 0) return 999;
  return duration * 0.034 / 2;
}

void forward(int speed) {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void backward() {
  analogWrite(ENA, 170);
  analogWrite(ENB, 170);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void pivotLeft() {
  analogWrite(ENA, 160);
  analogWrite(ENB, 160);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void pivotRight() {
  analogWrite(ENA, 160);
  analogWrite(ENB, 160);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void lineTurnLeft() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void lineTurnRight() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void runObstacleAvoidance() {
  long frontDist = getDistance();

  if (digitalRead(midIR) == 0 || frontDist <= 25) {
    stopMotors();
    tone(buzzer, 1000, 100);
    delay(100);
    noTone(buzzer);

    backward();
    delay(500);
    stopMotors();
    delay(100);

    myServo.write(40);
    delay(400);
    long leftDist = getDistance();

    myServo.write(180);
    delay(400);
    long rightDist = getDistance();

    myServo.write(110);
    delay(200);

    if (leftDist > 15 || rightDist > 15) {
      if (leftDist > rightDist) {
        pivotLeft();
      } else {
        pivotRight();
      }
      delay(600);
    } else {
      backward();
      delay(500);
    }
    stopMotors();
  } else {
    forward(200);
  }
}

void lineFollowing() {
  int left = digitalRead(irLeft);
  int right = digitalRead(irRight);

  if (left == 0 && right == 0) {
    forward(175);
  } else if (left == 0 && right == 1) {
    lineTurnRight();
  } else if (left == 1 && right == 0) {
    lineTurnLeft();
  } else {
    stopMotors();
  }
  delay(90);
  stopMotors();
  delay(90);
}

void handleBluetoothCommand(char cmd) {
  switch (cmd) {
    case 'F': forward(180); break;
    case 'B': backward(); break;
    case 'R': pivotLeft(); break;
    case 'L': pivotRight(); break;
    case 'S': stopMotors(); break;
    case 'H': tone(buzzer, 1000, 300); break;
    default: break;
  }
}

void loop() {
  bool obsMode = digitalRead(switchObs) == LOW;
  bool lineMode = digitalRead(switchLine) == LOW;
  bool btMode = digitalRead(switchBluetooth) == LOW;

  if (obsMode && !lineMode && !btMode) {
    runObstacleAvoidance();
  } else if (!obsMode && lineMode && !btMode) {
    lineFollowing();
  } else if (!obsMode && !lineMode && btMode) {
    if (Serial.available()) {
      char cmd = Serial.read();
      handleBluetoothCommand(cmd);
      delay(30);
    }
  } else {
    stopMotors();
  }

  delay(50);
}
