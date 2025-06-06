#define ENA 10  // Right motor speed
#define IN1 7   // Right motor direction
#define IN2 6   // Right motor direction
#define ENB 5   // Left motor speed
#define IN3 8   // Left motor direction
#define IN4 3   // Left motor direction

#define IR_SENSOR_RIGHT 13  // Right IR sensor
#define IR_SENSOR_LEFT 2    // Left IR sensor

#define BASE_SPEED 100  // Base PWM speed

void setup() {
  Serial.begin(9600);
  pinMode(IR_SENSOR_RIGHT, INPUT);  // Declare right IR sensor as input
  pinMode(IR_SENSOR_LEFT, INPUT);   // Declare left IR sensor as input
  pinMode(ENA, OUTPUT);             // Declare L298 Pin ENA as output
  pinMode(IN1, OUTPUT);             // Declare L298 Pin IN1 as output
  pinMode(IN2, OUTPUT);             // Declare L298 Pin IN2 as output
  pinMode(ENB, OUTPUT);             // Declare L298 Pin ENB as output
  pinMode(IN3, OUTPUT);             // Declare L298 Pin IN3 as output
  pinMode(IN4, OUTPUT);             // Declare L298 Pin IN4 as output
  
  // Initialize motors off
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
  analogWrite(ENA, 0); analogWrite(ENB, 0);
  Serial.println("Starting line-following on carpet...");
  delay(3000);  // Delay for stabilization
}

void loop() {
  int right = digitalRead(IR_SENSOR_RIGHT);  // Read right sensor
  int left = digitalRead(IR_SENSOR_LEFT);    // Read left sensor
  
  Serial.print("Sensors: Right=");
  Serial.print(right);
  Serial.print(" Left=");
  Serial.println(left);
  
  // Line-following logic (black line: HIGH=1, white: LOW=0)
  if ((right == 0) && (left == 0)) {
    forword();  // Both on white: move forward
    Serial.println("Action: Moving forward");
  } else if ((right == 1) && (left == 0)) {
    turnRight();  // Right on black, left on white: turn right
    Serial.println("Action: Turning right");
  } else if ((right == 0) && (left == 1)) {
    turnLeft();   // Left on black, right on white: turn left
    Serial.println("Action: Turning left");
  } else if ((right == 1) && (left == 1)) {
    Stop();       // Both on black: stop
    Serial.println("Action: Stopped");
  }
}

void forword() {  // Move forward
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);  // Right motor forward
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);  // Left motor forward
  analogWrite(ENA, BASE_SPEED);
  analogWrite(ENB, BASE_SPEED);
}

void turnRight() {  // Turn right
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);  // Right motor backward
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);  // Left motor forward
  analogWrite(ENA, BASE_SPEED);
  analogWrite(ENB, BASE_SPEED);
}

void turnLeft() {  // Turn left
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);  // Right motor forward
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);  // Left motor backward
  analogWrite(ENA, BASE_SPEED);
  analogWrite(ENB, BASE_SPEED);
}

void Stop() {  // Stop
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);   // Right motor off
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);   // Left motor off
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
