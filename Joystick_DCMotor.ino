const int SW_pin = 2; //digital pin connected to switch output
const int X_pin = 0; //analog pin connect to X output
const int Y_pin = 1; //analog pin connected to Y output

//Motor stuff
#define ENABLE 5
#define DIRA 3
#define DIRB 4

//Lights
#define WHITE 8
#define GREEN 9

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);

  pinMode(WHITE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  digitalWrite(WHITE, LOW);
  digitalWrite(GREEN, LOW);
  
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  
  Serial.begin(9600);

}

void loop() {
  Serial.print("X-axis");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis");
  Serial.print(analogRead(Y_pin));
  Serial.print("\n");
  if (analogRead(X_pin) > 340) { //fan blows air in and green light is on when X axis on joystick is greater than 340
    digitalWrite(GREEN, HIGH);
    digitalWrite(WHITE, LOW);
    digitalWrite(ENABLE, HIGH);
    digitalWrite(DIRA, HIGH);
    digitalWrite(DIRB, LOW);
  }
  else { //fan blows air out and white light is on when X axis on joystick is less than or equal to 340
    digitalWrite(WHITE, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(ENABLE, HIGH);
    digitalWrite(DIRA, LOW);
    digitalWrite(DIRB, HIGH);
  }
  delay(100);

}
