/*
 *  __  __                      _  __              
 * |  \/  |                    | |/ /              
 * | \  / | __ _  ___ _ __ ___ | ' / ___ _   _ ___ 
 * | |\/| |/ _` |/ __| '__/ _ \|  < / _ \ | | / __|
 * | |  | | (_| | (__| | | (_) | . \  __/ |_| \__ \
 * |_|  |_|\__,_|\___|_|  \___/|_|\_\___|\__, |___/
 *                                       __/ |    
 *                                      |___/     
 * 
 * A small Macro side Keyboard based on a Teensy 3.1
 * 2018 by Bitlischieber 
 *
 */

int keyState =  0;
int keyStatebefore = 0;

void setup() {
  
  /*
   * Electrical connections:
   * -----------------------
   * 
   * Row1 = Digital 0 
   * Row2 = Digital 1
   * Row3 = Digital 2
   * 
   * Col1 = Digital 3
   * Col2 = Digital 4
   * Col3 = Digital 5
   * Col4 = Digital 6
   * 
   */

  // 3 rows
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(0, HIGH);  
  digitalWrite(1, HIGH);  
  digitalWrite(2, HIGH);  
  
  // 4 columns
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  keyState = 0;
  
  // Scan key matrix
  digitalWrite(0, LOW);
  delay(1);
  if (digitalRead(3) == 0) keyState |=  (1<<0);
  if (digitalRead(4) == 0) keyState |=  (1<<1);
  if (digitalRead(5) == 0) keyState |=  (1<<2);
  if (digitalRead(6) == 0) keyState |=  (1<<3);
  digitalWrite(0, HIGH);  
  
  digitalWrite(1, LOW);  
  delay(1);
  if (digitalRead(3) == 0) keyState |=  (1<<4);
  if (digitalRead(4) == 0) keyState |=  (1<<5);
  if (digitalRead(5) == 0) keyState |=  (1<<6);
  if (digitalRead(6) == 0) keyState |=  (1<<7);
  digitalWrite(1, HIGH);  
  
  digitalWrite(2, LOW); 
  delay(1); 
  if (digitalRead(3) == 0) keyState |=  (1<<8);
  if (digitalRead(4) == 0) keyState |=  (1<<9);
  if (digitalRead(5) == 0) keyState |=  (1<<10);
  if (digitalRead(6) == 0) keyState |=  (1<<11);
  digitalWrite(2, HIGH);

  // Process keys
  
  /* Pin map:
   * 
   * |----|----|----|----|----|----|\
   * |  2 |  1 | 32 | 16 |512 |256 | \
   * |----|----|----|----|----|----| |
   * |  8 |  4 |128 | 64 |2048|1024| | 
   * |----|----|----|----|----|----| |
   *  \-----------------------------\|
   *  
   * Teensy keyboard functions see: https://www.pjrc.com/teensy/td_keyboard.html
   */
  
   if(keyState > 0) {
    if(keyStatebefore != keyState) {
      switch(keyState) {
        case (1<<0):
          // 1
          // Word: Subscript
          Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT);
          Keyboard.press(KEY_3);
          Keyboard.send_now();
          Keyboard.set_modifier(0);
          Keyboard.set_key1(0);
          Keyboard.send_now();
          break;
        case (1<<1):
          // 2
          // Word: Superscript
          Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT);
          Keyboard.press(KEY_1);
          Keyboard.send_now();
          Keyboard.set_modifier(0);
          Keyboard.set_key1(0);
          Keyboard.send_now();
          break;
        case (1<<2):
          // 4
          // VS:  Insert snippet
          Keyboard.set_modifier(MODIFIERKEY_CTRL);
          Keyboard.press(KEY_K);
          Keyboard.send_now();
          Keyboard.set_modifier(0);
          Keyboard.set_key1(0);
          Keyboard.send_now();
          delay(50);
          Keyboard.set_modifier(MODIFIERKEY_CTRL);
          Keyboard.press(KEY_X);
          Keyboard.send_now();
          Keyboard.set_modifier(0);
          Keyboard.set_key1(0);
          Keyboard.send_now();
          break;
        case (1<<3):
          // 8
          // VS: Build solution
          Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT);
          Keyboard.press(KEY_B);
          Keyboard.send_now();
          Keyboard.set_modifier(0);
          Keyboard.set_key1(0);
          Keyboard.send_now();
          break;
        case (1<<4):
          // 16
          // Explorer: Open, goto d:\work
          Keyboard.set_modifier(MODIFIERKEY_GUI);
          Keyboard.press(KEY_E);
          Keyboard.send_now();
          Keyboard.set_modifier(0);
          Keyboard.set_key1(0);
          Keyboard.send_now();
          delay(500);
          Keyboard.set_modifier(MODIFIERKEY_ALT);
          Keyboard.press(KEY_E);
          Keyboard.send_now();
          Keyboard.set_modifier(0);
          Keyboard.set_key1(0);
          Keyboard.send_now();
          Keyboard.println("D:\\work");
          break;
        case (1<<5):
          // 32
          // Type admin credentials
           Keyboard.print(".\administrator");
           Keyboard.press(KEY_TAB);
           Keyboard.send_now();
           Keyboard.set_key1(0);
           Keyboard.send_now();
           delay(100);
           Keyboard.println("not my credentials");
          break;
        case (1<<6):
          // 64
          // VS:  Uncomment section
          Keyboard.set_modifier(MODIFIERKEY_CTRL);
          Keyboard.press(KEY_K);
          Keyboard.send_now();
          Keyboard.set_modifier(0);
          Keyboard.set_key1(0);
          Keyboard.send_now();
          delay(50);
          Keyboard.set_modifier(MODIFIERKEY_CTRL);
          Keyboard.press(KEY_U);
          Keyboard.send_now();
          Keyboard.set_modifier(0);
          Keyboard.set_key1(0);
          Keyboard.send_now();
          break;
        case (1<<7):
          // 128
          // VS: Comment section
          Keyboard.set_modifier(MODIFIERKEY_CTRL);
          Keyboard.press(KEY_K);
          Keyboard.send_now();
          Keyboard.set_modifier(0);
          Keyboard.set_key1(0);
          Keyboard.send_now();
          delay(50);
          Keyboard.set_modifier(MODIFIERKEY_CTRL);
          Keyboard.press(KEY_C);
          Keyboard.send_now();
          Keyboard.set_modifier(0);
          Keyboard.set_key1(0);
          Keyboard.send_now();
          break;
        case (1<<8):
          // 256
          // Explorer: Open CMD for current folder 
          Keyboard.set_modifier(MODIFIERKEY_ALT);
          Keyboard.press(KEY_E);
          Keyboard.send_now();
          Keyboard.set_modifier(0);
          Keyboard.set_key1(0);
          Keyboard.send_now();
          delay(100);
          Keyboard.println("cmd");
          break;
        case (1<<9):
          // 512
          // Explorer: New folder
          Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT);
          Keyboard.press(KEY_N);
          Keyboard.send_now();
          Keyboard.set_modifier(0);
          Keyboard.set_key1(0);
          Keyboard.send_now();
          break;
        case (1<<10):
          // 1024
          // not yet assigned
          break;
        case (1<<11):
          // 2048
          // not yet assigned
          break;
        default:
          break;
      } // switch
    } // key changes
  } // key was pressed
  
  keyStatebefore = keyState;
    
} // loop



