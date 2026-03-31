int buttonPin = 2; 
int ledPin = 13;
int buzzerPin = 8;
int lastButtonState = HIGH; // 이전 버튼 상태 저장 (초기값 HIGH)
bool isAlert = false; // 현재 ALERT 상태 (처음에는 꺼져있음)

void setup() {
  // 아무것도 안 누르면 HIGH
  // 버튼 누르면 LOW
  pinMode(buttonPin, INPUT_PULLUP);

  // LED 출력 설정
  pinMode(ledPin, OUTPUT);

  // 부저 출력 설정
  pinMode(buzzerPin, OUTPUT);

  // 시리얼 통신 시작 (로그 출력용)
  Serial.begin(9600);
}

void loop() {

  // 현재 버튼 상태 읽기
  int currentButtonState = digitalRead(buttonPin);

  // 버튼이 눌린 순간 감지
  // HIGH -> LOW
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    // ALERT 상태 반전
    isAlert = !isAlert;

    // 상태에 따라 로그 출력
    if (isAlert) {
      Serial.println("ALERT ON");
    } else {
      Serial.println("ALERT OFF");
    }

    // 버튼 튐 방지 (중복 입력 방지)
    delay(200);
  }

  // 현재 상태를 다음 비교 위해 저장
  lastButtonState = currentButtonState;

  // 상태에 따라 출력 제어
  if (isAlert) {
    // ALERT 상태면 LED, 부저 울림
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    // 아니면 둘 다 꺼짐
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
}
