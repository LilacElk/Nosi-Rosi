
#define B0 4
#define B1 5
#define B2 6
#define B3 7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT);
  pinMode (B0, OUTPUT);
  pinMode (B1, OUTPUT);
  pinMode (B2, OUTPUT);
  pinMode (B3, OUTPUT);
  pinMode(9, INPUT); //IR Sensor object detection
  pinMode(2, INPUT); //IR Sensor
  pinMode(3, INPUT); //IR Sensor

}

void loop() {
  // put your main code here, to run repeatedly:
  int Right = digitalRead(2);
  int Left = digitalRead(3);
  Serial.println (Right);
  Serial.println (Left);
  int obstacle = digitalRead(9);
  Serial.println(obstacle);



  if (obstacle == 1) {
    digitalWrite (10, LOW);
    digitalWrite (11, LOW);
    digitalWrite (12, LOW);
    digitalWrite (13, LOW);
    digitalWrite(B0, LOW);
    digitalWrite(B1, LOW);
    digitalWrite(B2, LOW);
    digitalWrite(B3, LOW);
  }
  else if (obstacle == 0) {

    if (Right == 1 && Left == 1) {
      forward();
      digitalWrite(B0, HIGH);
      digitalWrite(B1, LOW);
      digitalWrite(B2, HIGH);
      digitalWrite(B3, LOW);

    }
    if (Right == 0 && Left == 0) {
      stoprobot();
      digitalWrite(B0, LOW);
      digitalWrite(B1, LOW);
      digitalWrite(B2, LOW);
      digitalWrite(B3, LOW);
    }
    if (Right == 0 && Left == 1) {
      right();
      digitalWrite(B0, HIGH);
      digitalWrite(B1, LOW);
      digitalWrite(B2, HIGH);
      digitalWrite(B3, HIGH);
    }
    if (Right == 1 && Left == 0) {
      left();
      digitalWrite(B0, LOW);
      digitalWrite(B1, LOW);
      digitalWrite(B2, HIGH);
      digitalWrite(B3, LOW);
    }

  }
}


void forward() {
  digitalWrite (10, LOW);
  digitalWrite (11, HIGH);
  digitalWrite (12, LOW);
  digitalWrite (13, HIGH);
  Serial.println("forward");
}
void right() {
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  Serial.println("right");
}
void left() {
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  Serial.println("left");
}
void stoprobot() {
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  Serial.println("stop");

}
