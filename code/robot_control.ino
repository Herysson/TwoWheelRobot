const int buzPin = 2;
const int ledPin1 = 7;
const int ledPin2 = 8;

int valSpeed = 255;

// Motor 1 (esquerdo)
const int M1_IN1 = 5;
const int M1_IN2 = 6;

// Motor 2 (direito)
const int M2_IN1 = 10;
const int M2_IN2 = 11;

void setup() {
  Serial.begin(9600);

  pinMode(buzPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  pinMode(M1_IN1, OUTPUT);
  pinMode(M1_IN2, OUTPUT);
  pinMode(M2_IN1, OUTPUT);
  pinMode(M2_IN2, OUTPUT);

  stopMotors();
}

void loop() {
  while (Serial.available() > 0) {
    char command = Serial.read();
    Serial.println(command);

    switch (command) {
      case 'F': forward(valSpeed); break;
      case 'B': backward(valSpeed); break;
      case 'R': turnRight(valSpeed); break;
      case 'L': turnLeft(valSpeed); break;

      case 'G': forwardLeft(valSpeed); break;
      case 'H': forwardRight(valSpeed); break;
      case 'I': backwardLeft(valSpeed); break;
      case 'J': backwardRight(valSpeed); break;

      case 'S': stopMotors(); break;

      case 'Y':
        digitalWrite(buzPin, HIGH); delay(200);
        digitalWrite(buzPin, LOW);  delay(80);
        digitalWrite(buzPin, HIGH); delay(300);
        digitalWrite(buzPin, LOW);
        break;

      case 'X': 
        digitalWrite(ledPin1, HIGH); 
        digitalWrite(ledPin2, HIGH);
        break;
      case 'x': 
        digitalWrite(ledPin1, LOW); 
        digitalWrite(ledPin2, LOW); 
        break;

      case '0': SetSpeed(0); break;
      case '1': SetSpeed(25); break;
      case '2': SetSpeed(50); break;
      case '3': SetSpeed(75); break;
      case '4': SetSpeed(100); break;
      case '5': SetSpeed(125); break;
      case '6': SetSpeed(150); break;
      case '7': SetSpeed(175); break;
      case '8': SetSpeed(200); break;
      case '9': SetSpeed(255); break;
    }
  }
}

// ------------------ Movimentos ------------------

void forward(int spd) {
  analogWrite(M1_IN1, 0);
  analogWrite(M1_IN2, spd);
  analogWrite(M2_IN1, 0);
  analogWrite(M2_IN2, spd);
}

void backward(int spd) {
  analogWrite(M1_IN1, spd);
  analogWrite(M1_IN2, 0);
  analogWrite(M2_IN1, spd);
  analogWrite(M2_IN2, 0);
}

void turnRight(int spd) {
  analogWrite(M1_IN1, 0);
  analogWrite(M1_IN2, spd);
  analogWrite(M2_IN1, spd);
  analogWrite(M2_IN2, 0);
}

void turnLeft(int spd) {
  analogWrite(M1_IN1, spd);
  analogWrite(M1_IN2, 0);
  analogWrite(M2_IN1, 0);
  analogWrite(M2_IN2, spd);
}

void forwardLeft(int spd) {
  int slow = spd / 4;
  analogWrite(M1_IN1, 0);
  analogWrite(M1_IN2, slow);
  analogWrite(M2_IN1, 0);
  analogWrite(M2_IN2, spd);
}

void forwardRight(int spd) {
  int slow = spd / 4;
  analogWrite(M1_IN1, 0);
  analogWrite(M1_IN2, spd);
  analogWrite(M2_IN1, 0);
  analogWrite(M2_IN2, slow);
}

void backwardLeft(int spd) {
  int slow = spd / 4;
  analogWrite(M1_IN1, slow);
  analogWrite(M1_IN2, 0);
  analogWrite(M2_IN1, spd);
  analogWrite(M2_IN2, 0);
}

void backwardRight(int spd) {
  int slow = spd / 4;
  analogWrite(M1_IN1, spd);
  analogWrite(M1_IN2, 0);
  analogWrite(M2_IN1, slow);
  analogWrite(M2_IN2, 0);
}

void stopMotors() {
  analogWrite(M1_IN1, 0);
  analogWrite(M1_IN2, 0);
  analogWrite(M2_IN1, 0);
  analogWrite(M2_IN2, 0);
}

// ------------------ Velocidade ------------------
void SetSpeed(int val) {
  valSpeed = constrain(val, 0, 255);
}
