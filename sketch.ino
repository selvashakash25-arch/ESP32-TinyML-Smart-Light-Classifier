
#define LDR_PIN 34
#define LED_PIN 2

String classifyLight(int lightValue) {
  if (lightValue < 1000) {
    return "DARK";
  } else if (lightValue < 2500) {
    return "NORMAL";
  } else {
    return "BRIGHT";
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("ESP32 TinyML Smart Light Classifier");
  Serial.println("Author: SELVASH");
}

void loop() {
  int lightValue = analogRead(LDR_PIN);
  String result = classifyLight(lightValue);

  Serial.print("Light value: ");
  Serial.print(lightValue);
  Serial.print(" | Class: ");
  Serial.println(result);

  if (result == "DARK") {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(1000);
}
