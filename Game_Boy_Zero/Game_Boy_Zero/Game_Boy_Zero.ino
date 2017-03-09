
#include <Bounce.h>

#define NUM_KEYS 12

struct Key {
  char keycode;
  Bounce* bounce;
};

Key keys[NUM_KEYS];

Key key(char keycode, int pin) {
  Key *ret = new Key;
  ret->keycode = keycode;
  ret->bounce = new Bounce(pin, 10);
  pinMode(pin, INPUT_PULLUP);
  return *ret;
}

void setupKeys() {
  keys[0] = key('w', 0);
  keys[1] = key('s', 1);
  keys[2] = key('a', 2);
  keys[3] = key('d', 3);
  keys[4] = key('p', 4);
  keys[5] = key('l', 5);
  keys[6] = key('o', 6);
  keys[7] = key('k', 7);
  keys[8] = key('x', 8);
  keys[9] = key('z', 9);
  keys[10] = key('q',10);
  keys[11] = key('e',11);
}

void setup() {
  setupKeys();
  Keyboard.begin();
  //  pinMode(0, INPUT_PULLUP);
}

void loop() {
  for (int i = 0; i < NUM_KEYS; i++) {
    keys[i].bounce->update();
    if (keys[i].bounce->fallingEdge()) {
      Keyboard.press(keys[i].keycode);
    } else if (keys[i].bounce->risingEdge()) {
      Keyboard.release(keys[i].keycode);
    }
  }
}
