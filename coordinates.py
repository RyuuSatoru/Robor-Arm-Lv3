import cv2
import numpy as np
import serial
import time

# Mở cổng serial
ser = serial.Serial('COM6', 9600) 

# Mở máy ảnh
cap = cv2.VideoCapture(0)  #cam 0 mặc định

while True:
    ret, frame = cap.read()  # Đọc một khung hình từ máy ảnh

    if not ret:
        break

    # Chuyển hình ảnh sang xám
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Lọc Gaussian
    blurred = cv2.GaussianBlur(gray, (5, 5), 0)

    # Phát hiện cạnh bằng phương pháp Canny
    edges = cv2.Canny(blurred, 50, 150)

    # Tìm các đường viền
    contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    for contour in contours:
        # Tìm đa giác xấp xỉ cho đường viền
        epsilon = 0.04 * cv2.arcLength(contour, True)
        approx = cv2.approxPolyDP(contour, epsilon, True)

        # Nếu đa giác có 4 đỉnh, đó có thể là hình vuông hoặc chữ nhật
        if len(approx) == 4:
            # Vẽ đa giác lên hình ảnh
            cv2.drawContours(frame, [approx], 0, (0, 0, 255), 2)

            # Tính tọa độ trung tâm
            M = cv2.moments(contour)
            if M["m00"] != 0:
                cx = int(M["m10"] / M["m00"])
                cy = int(M["m01"] / M["m00"])

                # Hiển thị tọa độ trung tâm
                text = f'Center: ({cx}, {cy})'
                cv2.putText(frame, text, (cx - 40, cy - 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)

                # Gửi tọa độ qua cổng serial
                data = f"{cx},{cy}\n"
                ser.write(data.encode())

    # Hiển thị hình ảnh từ máy ảnh
    cv2.imshow('Camera', frame)

    # Thoát khỏi vòng lặp nếu nhấn phím 'q'
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Đóng cổng serial và giải phóng tài nguyên
ser.close()
cap.release()
cv2.destroyAllWindows()
