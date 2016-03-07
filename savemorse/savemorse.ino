// Save a file to the EEPROM
#include <EEPROM.h>
#define DOT     0
#define DASH    1
#define M_END   255

uint8_t morse_codes[][27] = {
    {DOT, DASH, M_END,  0},             // 'A'
    {DASH, DOT, DOT,  DOT},             // 'B'
    {DASH, DOT, DASH,  DOT},            // 'C'
    {DASH, DOT, DOT, M_END},            // 'D'
    {DOT, M_END, 0, 0},                 // 'E'
    {DOT, DOT, DASH, DOT},              // 'F'
    {DASH, DASH, DOT, M_END},           // 'G'
    {DOT, DOT, DOT, DOT},               // 'H'
    {DOT, DOT, M_END, 0},               // 'I'
    {DOT, DASH, DASH, DASH},            // 'J'
    {DASH, DOT, DASH, M_END},           // 'K'
    {DOT, DASH, DOT, DOT},              // 'L'
    {DASH, DASH, M_END, 0},             // 'M'
    {DOT, DASH, M_END, 0},              // 'N'
    {DASH, DASH, DASH, M_END},          // 'O'
    {DOT, DASH, DASH,  DOT},            // 'P'
    {DASH, DASH, DOT, DASH},            // 'Q'
    {DOT, DASH, DOT, M_END},            // 'R'
    {DOT, DOT, DOT,  M_END},            // 'S'
    {DASH, M_END, 0, 0},                // 'T'
    {DOT, DOT, DASH, M_END},            // 'U'
    {DOT, DOT, DOT,   DASH},            // 'V'
    {DOT, DASH, DASH, M_END},           // 'W'
    {DASH, DOT, DOT,   DASH},           // 'X'
    {DASH, DOT, DASH,  DASH},           // 'Y'
    {DASH, DASH, DOT,   DOT},           // 'Z'
    {DASH, M_END, 0, 0}                       // 'alt' (used for space)
};

void EEPROM_SAVE ( void ) {
  // consume array and save it in EEPROM
  // stops saving at M_END 
   uint8_t addr = 0;
   uint8_t *get_seq;
   for (int i=0; i < 27; i+1) {
    //0 1 2 3 4 5...
      get_seq = morse_codes[i];
      for (int k=0; k < k+3; k++){
        //0 1 2 3
        if ( get_seq[i] == M_END) {
          EEPROM.write(addr, get_seq[i]);
          addr++;
          break;  
        }
        EEPROM.write(addr, get_seq[i]);
        addr++;      
      }
   }   
}

// Could add some code to test the memory here, if the data is there then don't
void setup() {
  // put your setup code here, to run once:
  EEPROM_SAVE();

}

void loop() {
  // put your main code here, to run repeatedly:

}
