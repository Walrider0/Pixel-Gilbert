const int BUTTON_PIN = 2; // Gomb bemenet
const int BUZZER_PIN = 9; // Buzzer kimenet

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Megnézzük, le van-e nyomva a gomb (INPUT_PULLUP miatt LOW az aktív)
  if (digitalRead(BUTTON_PIN) == LOW) {
    playCatMeow();
    delay(300); // Prellmentesítés és várakozás az újabb nyomás előtt
  }
}

// Macskanyávogást emuláló frekvenciamenet
void playCatMeow() {
  // 1. Felvezetés: gyors emelkedés 700 Hz-ről ~1400 Hz-re
  for (int freq = 700; freq < 1400; freq += 25) {
    tone(BUZZER_PIN, freq);
    delay(4);
  }

  // 2. A nyávogás teteje / nyújtás (~1400 Hz - 1200 Hz környékén kis lebegtetés)
  for (int freq = 1400; freq > 1150; freq -= 10) {
    tone(BUZZER_PIN, freq);
    delay(8);
  }

  // 3. Lecsengés: lassú ereszkedés 1150 Hz-ről 500 Hz-re
  for (int freq = 1150; freq > 500; freq -= 15) {
    tone(BUZZER_PIN, freq);
    delay(10);
  }

  // Hang kikapcsolása a végén
  noTone(BUZZER_PIN);
}