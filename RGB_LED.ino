const int R_PIN = 4;
const int G_PIN = 12;
const int B_PIN = 14;

const float SPEED_D = 65536.0f;
const float MAX_SPEED_N = 256.0f;
const float C_SPEED = 1.0f / SPEED_D;
const int MAX = 1023;

float r = 0, rd = 0, rs = 0, g = 0, gd = 0, gs = 0, b = 0, bd = 0, bs = 0;

void setup() {
  Serial.begin(115200);
  
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);

  r = random(MAX);
  g = random(MAX);
  b = random(MAX);

  rs = random(1, int(SPEED_D / MAX_SPEED_N + 1)) / SPEED_D;
  gs = random(1, int(SPEED_D / MAX_SPEED_N + 1)) / SPEED_D;
  bs = random(1, int(SPEED_D / MAX_SPEED_N + 1)) / SPEED_D;

  rd = rs * (random(2) * 2 - 1);
  gd = gs * (random(2) * 2 - 1);
  bd = bs * (random(2) * 2 - 1);

  Serial.println();
  Serial.print("rs: 1/");
  Serial.println(1/rs);
  Serial.print("gs: 1/");
  Serial.println(1/gs);
  Serial.print("bs: 1/");
  Serial.println(1/bs);
}

void loop() {
  analogWrite(R_PIN, MAX - r);
  analogWrite(G_PIN, MAX - g);
  analogWrite(B_PIN, MAX - b);

  rd = getDir(r, rd, rs);
  gd = getDir(g, gd, gs);
  bd = getDir(b, bd, bs);

  r += rd;
  g += gd;
  b += bd;
}

float getDir(float val, float dir, float c_speed) {
  if (val >= MAX)
    return -c_speed;
  else if (val <= 0)
    return c_speed;

  return dir;
}

