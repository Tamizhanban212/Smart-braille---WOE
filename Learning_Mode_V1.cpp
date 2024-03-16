const int led_pin[3][2] = { {2, 3},{4, 5},{6, 7} };
const int dT = 5000; 
const int a[3][2] = { {1, 0},{0, 0},{0, 0} };
const int b[3][2] = { {1, 0},{1, 0},{0, 0} };
const int c[3][2] = { {1, 1},{0, 0},{0, 0} };

void setup() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      pinMode(led_pin[i][j], OUTPUT);
    }
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      if (a[i][j] == 1) {
        digitalWrite(led_pin[0][j], HIGH);  
      } 
      else {
        digitalWrite(led_pin[0][j], LOW);  
      }
    }
  }

  delay(dT);
  
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      if (b[i][j] == 1) {
        digitalWrite(led_pin[1][j], HIGH);  
      } 
      else {
        digitalWrite(led_pin[1][j], LOW);  
      }
    }
  }
  
  delay(dT); 
  

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      if (c[i][j] == 1) {
        digitalWrite(led_pin[2][j], HIGH);  
      } else {
        digitalWrite(led_pin[2][j], LOW);  
      }
    }
  }
  
  delay(dT);  
}