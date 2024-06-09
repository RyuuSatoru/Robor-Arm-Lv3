#include <Servo.h>

Servo XoayServo;     // Servo cho trục xoay
Servo RightServo;     // Servo cho nghiêng lên/xuống
Servo LeftServo;   // Servo cho độ cao
Servo GapServo;     // Servo cho gắp

bool isCalibrating = true;
bool isReceivingData = false;
bool newDataReceived = false; // Biến để kiểm tra dữ liệu mới

void setup() {
  // Khởi tạo các servo và cổng serial
  XoayServo.attach(A0);    // Chân 8 trên Sensor Shield
  RightServo.attach(A1);   // Chân 9 trên Sensor Shield
  LeftServo.attach(A2);   // Chân 10 trên Sensor Shield
  GapServo.attach(A3);    // Chân 11 trên Sensor Shield

  Serial.begin(9600);  // Bắt đầu giao tiếp serial

  // Cho phép servo xoay về vị trí ban đầu
  XoayServo.write(0);
}

void loop() {
  if (isCalibrating) {
    // Thời gian calibrating (10 giây)
    delay(10000);
    isCalibrating = false;
    Serial.println("Calibration complete.");
  } else if (Serial.available() > 0 && !newDataReceived) {
    // Đọc dữ liệu tọa độ từ máy tính
    String data = Serial.readStringUntil('\n');
    data.trim(); // Xóa các khoảng trắng thừa

    // Phân tích dữ liệu tọa độ
    int xPos, yPos;
    sscanf(data.c_str(), "%d %d", &xPos, &yPos);

    // Giới hạn giá trị tọa độ
    xPos = constrain(xPos, 0, 600);

    // Chuyển giá trị tọa độ từ khoảng 0-600 sang góc 50-120 độ
    int baseServoPos = map(xPos, 0, 600, 50, 120);

    // Điều khiển các servo dựa trên các góc
    RightServo.write(80);
    delay(4000); 
    XoayServo.write(baseServoPos);
    delay(4000); 
    RightServo.write(130);
    delay(4000); 
    GapServo.write(140);
    delay(4000); 
    LeftServo.write(80);
    delay(4000); 
    GapServo.write(90);
    delay(4000); 
    RightServo.write(80);
    delay(4000); 
    XoayServo.write(0);
    delay(4000); 
    GapServo.write(140);
    delay(4000);
    GapServo.write(90);
    delay(4000);
    // Đánh dấu rằng đã nhận dữ liệu và thực hiện hành động
    isReceivingData = true;
    newDataReceived = true;
  }
  if (newDataReceived) {
    // Đặt lại biến để cho phép lấy dữ liệu mới
    newDataReceived = false;
    isReceivingData = false;
    delay(5000); // Chờ 5 giây trước khi lặp lại chu kỳ
  }
}
