
const int RED_PIN = 10;
const int GREEN_PIN = 11;
const int BLUE_PIN = 12;

const int BUTTON_PIN = 4;

int red = 0;
int green = 0;
int blue = 0;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  red = random(0, 256);
  green = random(0, 256);
  blue = random(0, 256);
}

/** Jitters the intensity of a LED */
int jitter(int value) {
  return abs((value + random(-50, 50)) % 256);
}

bool isButtonPressed() {
  return digitalRead(BUTTON_PIN) == LOW;
}

void loop() {

  if (isButtonPressed()) {   
    red = jitter(red);
    green = jitter(green);
    blue = jitter(blue);
  
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
  } else {
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0);
  }

  delay(10);
}

