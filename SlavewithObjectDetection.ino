#define B0 4
#define B1 5
#define B2 6
#define B3 7


void setup() {
  // put your setup code here, to run once:
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT);
  pinMode (B0, INPUT);
  pinMode (B1, INPUT);
  pinMode (B2, INPUT);
  pinMode (B3, INPUT);
  Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int D0 = digitalRead(B0);
  int D1 = digitalRead (B1);
  int D2 = digitalRead (B2);
  int D3 = digitalRead (B3);
  if ((D0 == 1) && (D1 == 0) && (D2 == 1) && (D3 == 0)) {
    forward();
    Serial.println("Robot Move Forward");
  }
  if ((D0 == 1) && (D1 == 0) && (D2 == 1) && (D3 == 1)) {
    right();
    Serial.println("Robot Move Right");
  }
  if ((D0 == 0) && (D1 == 0) && (D2 == 1) && (D3 == 0)) {
    left();
    Serial.println("Robot Move Left");
  }
  if ((D0 == 0) && (D1 == 0) && (D2 == 0) && (D3 == 0)){
    stoprobot();
    Serial.println("Stop");
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
