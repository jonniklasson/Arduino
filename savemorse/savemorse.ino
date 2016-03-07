// Save a file to the EEPROM
#include <EEPROM.h>
#define DOT     0
#define DASH    1
#define M_END   255

int morse_codes[][27] = {
    {DOT, DASH, M_END},             // 'A'
    {DASH, DOT, DOT, DOT, M_END},   // 'B'
    {DASH, DOT, DASH, DOT, M_END},  // 'C'
    {DASH, DOT, DOT, M_END},        // 'D'
    {DOT, M_END},                   // 'E'
    {DOT, DOT, DASH, DOT, M_END},   // 'F'
    {DASH, DASH, DOT, M_END},       // 'G'
    {DOT, DOT, DOT, DOT, M_END},    // 'H'
    {DOT, DOT, M_END},              // 'I'
    {DOT, DASH, DASH, DASH, M_END}, // 'J'
    {DASH, DOT, DASH, M_END},       // 'K'
    {DOT, DASH, DOT, DOT, M_END},   // 'L'
    {DASH, DASH, M_END},            // 'M'
    {DOT, DASH, M_END},             // 'N'
    {DASH, DASH, DASH, M_END},      // 'O'
    {DOT, DASH, DASH, DOT, M_END},  // 'P'
    {DASH, DASH, DOT, DASH, M_END}, // 'Q'
    {DOT, DASH, DOT, M_END},        // 'R'
    {DOT, DOT, DOT, M_END},         // 'S'
    {DASH, M_END},                  // 'T'
    {DOT, DOT, DASH, M_END},        // 'U'
    {DOT, DOT, DOT, DASH, M_END},   // 'V'
    {DOT, DASH, DASH, M_END},       // 'W'
    {DASH, DOT, DOT, DASH, M_END},  // 'X'
    {DASH, DOT, DASH, DASH, M_END}, // 'Y'
    {DASH, DASH, DOT, DOT, M_END},  // 'Z'
    {DASH, M_END}                   // 'alt' (used for space)
};

void EEPROM_SAVE ( void ) {
  // consume array and save it in EEPROM
  // Data is stored in chunks of 4 bites
  // cause that is easier
   int addr = 0;
   int *get_seq;
   for (int i=0; i < 27; i+1) {
    //0 1 2 3 4 5...
      get_seq = morse_codes[i];
      for (int k=0; k < k+3; k++){
        //0 1 2 3
        if ( get_seq[i] == M_END) {
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
