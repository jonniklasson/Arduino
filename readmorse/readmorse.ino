#include <ctype.h>
#include <string.h>
#include <EEPROM.h>
#define PIN_BUZZER  12
#define PIN_LED     13
#define DELAY_DIT   50
#define DELAY_DAH   200
#define DELAY_PAUSE 100 //delay between letter same
#define FREQ_BUZZ   800 //Herz
#define DOT     0
#define DASH    1


int readprom ( int index ) {
  // 0 , 4 ... 0 1 2 3 , 4 5 6 7
  //morse_codes[0] -> 0,1,2,3
  //morse_codes[1] -> 4,5,6,7
  //morse_codes[2] -> 8,9,10,11
  //morse_codes[3] -> 12,13,14,15
  // index * 4 -> index * 4 + 3
  int morse[4];
  int count = 0;
  for ( int i = index * 4; i < i + 4; i ++) {
    morse[count] = EEPROM.read(i);
    count++;
  }
  return morse[];
  
}

void play_sentence(char *sentence) {
    size_t seq_len = strlen(sentence);
    int i;
    for(i = 0; i < seq_len; i++) {
//        printf("sequence index: %d\n", i);
        int *morse = get_morse_sequence(sentence[i]);
        play_letter(morse);
    }
    delay(2000);// wait for a second
}

int *get_morse_sequence(char letter) {
    char uppercase_letter = toupper(letter);
    // 'A' in ASCII = 65, 'B' = 66, etc. 
    int lookup = uppercase_letter - 65;
    if(lookup < 0 || lookup > 26) {
        lookup = 26;
    }
    return(readprom[lookup]);
}

void play_letter(int *code) {
    int step = 0;
    while(code[step] != M_END) {
        //printf("%d", code[step]);
        if(code[step] == 0) {
        blink(DELAY_DIT);
      } else if (code[step] == 1) {
        blink(DELAY_DAH);
    }
        step++;
    };
}


void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  play_sentence("sos");

}
