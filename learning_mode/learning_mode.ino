#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

const int led_pin[3][2] = { {9, 4},{8, 5},{7, 6} };
const int dT = 5000; 
const int a[3][2] = { {1, 0},{0, 0},{0, 0} };
const int b[3][2] = { {1, 0},{1, 0},{0, 0} };
const int c[3][2] = { {1, 1},{0, 0},{0, 0} };
const int d[3][2] = { {1, 1},{0, 1},{0, 0} };
const int e[3][2] = { {1, 0},{0, 1},{0, 0} };
const int f[3][2] = { {1, 1},{1, 0},{0, 0} };
const int g[3][2] = { {1, 1},{1, 1},{0, 0} };
const int h[3][2] = { {1, 0},{1, 1},{0, 0} };
const int i[3][2] = { {0, 1},{1, 0},{0, 0} };
const int j[3][2] = { {0, 1},{1, 1},{0, 0} };
const int k[3][2] = { {1, 0},{0, 0},{1, 0} };
const int l[3][2] = { {1, 0},{1, 0},{1, 0} };
const int m[3][2] = { {1, 1},{0, 0},{1, 0} };
const int n[3][2] = { {1, 1},{0, 1},{1, 0} };
const int o[3][2] = { {1, 0},{0, 1},{1, 0} };
const int p[3][2] = { {1, 1},{1, 0},{1, 0} };
const int q[3][2] = { {1, 1},{1, 1},{1, 0} };
const int r[3][2] = { {1, 0},{1, 1},{1, 0} };
const int s[3][2] = { {0, 1},{1, 0},{1, 0} };
const int t[3][2] = { {0, 1},{1, 1},{1, 0} };
const int u[3][2] = { {1, 0},{0, 0},{1, 1} };
const int v[3][2] = { {1, 0},{1, 0},{1, 1} };
const int w[3][2] = { {0, 1},{1, 1},{0, 1} };
const int x[3][2] = { {1, 1},{0, 0},{1, 1} };
const int y[3][2] = { {1, 1},{0, 1},{1, 1} };
const int z[3][2] = { {1, 0},{0, 1},{1, 1} };
const int (*const letters[])[2] = { a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z };
const String le[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

void setup() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      pinMode(led_pin[i][j], OUTPUT);
    }
  }
  tmrpcm.speakerPin=9;
  Serial.begin(9600);
  if(!SD.begin(SD_ChipSelectPin))
  {
  Serial.println("SD fail");
  return;
  }
  tmrpcm.setVolume(5);
  
}

void displayLetter(const int (*pattern)[2]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      digitalWrite(led_pin[i][j], pattern[i][j]);
    }
  }
}

void loop() {
  for (int k = 0; k < 26; k++) {
    tmrpcm.play((le[k]+".wav").c_str());
    displayLetter(letters[k]);
    delay(dT);
  }
}