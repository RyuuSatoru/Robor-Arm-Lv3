Japanese:
ロボットアーム3軸
I. 構成要素
ロボットフレーム（木材、プラスチック、金属など、ニーズに応じて選択可能）
サーボモータ（MG90S、SG90、MG996Rなど、MG996R推奨）
Arduino（市場に出回っている任意のArduinoボード）
電源（5V-9V）
サーボシールド（PCA9685、HUB360など。ない場合は、サーボモータに外部電源を供給する必要があります）
カメラ（Logitechカメラまたは所有している任意のカメラ推奨）
Raspberry Pi 3以降（予算がない場合は、ラップトップまたはデスクトップに接続する）
グリッパー（長方形のオブジェクトを想定。同様の形状、明るい色推奨）
キューブ（暗い色で反射しない素材。カメラが認識しやすいように）
照明（状況に応じて。部屋が暗い場合は、照明を使用するのが最適）
カメラと照明のマウント（マットに合わせて調整可能）

II. 動作
ロボットはカメラを使用して平面をスキャンします。
その後、取得した座標情報に基づいてArduinoに結果を送信します。
Arduinoは結果を受け取り、アルゴリズムを使用して角度を計算します。
Arduinoから信号を受信したサーボモータが動作し、オブジェクトを把持します。
オブジェクトは右から左へ把持されます。
すべてのオブジェクトを把持したら、動作を停止します。

III. 注意事項
コードは現在テスト中です。まだ不具合がある可能性があります。
個人用のコードであるため、使用する前に他人に確認することをお勧めします。
コードは使用環境に合わせて調整する必要があります。
カメラの座標は常に同じとは限らないため、誤差が生じる可能性があります。
脳を使用する（もちろん、脳は非常に役立ちます。活用してください。）

English:
3-DOF ROBOTIC ARM

I. Construction
Robotic frame (can be made of wood, plastic, or metal depending on your needs)
Servos (MG90S, SG90, MG996R, ... MG996R is recommended)
Arduino (any Arduino on the market)
Power supply (5V-9V)
Servo shield (PCA9685, HUB360, ... if not, provide external power for servos)
Camera (Logitech cam or any cam you have is recommended)
Raspberry Pi 3 or higher (if you don't have money, just connect the wire to your laptop or desktop)
Rectangular box (I'm setting up a rectangular object, you can find an equivalent object, light color)
Pad (should be dark, non-reflective, for easy camera recognition)
Light (optional, if your room is dark, it is best to use a light)
Camera and light support shaft (should be adjusted according to the pad)

II. Operation
The robot works by scanning a flat surface with the camera
Then, based on the coordinate position obtained, the result is returned to the Arduino
After receiving the result, the Arduino uses algorithms to calculate the angle
The servos will operate and pick up the object after receiving a signal from the Arduino
Will pick up objects from right to left
After picking up everything, the operation will pause

III. Notes
The code is still under testing and may contain errors
The code is personal, so ask for advice before taking it back to upload
The code should be customized to your environment
There will always be errors because not everyone puts the cam in the same coordinates
Use your brain (of course, brains are very useful, use them)

Vietnamese:
ROBOT ARM BẬC 3	
I. Cấu tạo
- Khung robot( có thể sử dụng gỗ, nhựa hay kim loại tùy thuộc vào nhu cầu của bạn)
- Servo( MG90S, SG90, MG996R,...khuyên dùng MG996R)
- Adruino( bất kì adruino có mặt trên thị trường)
- Nguồn(5V-9V)
- Servo shield(PCA9685,HUB360,...nếu không thì cấp nguồn ngoài cho servo)
- Camera(khuyên dùng logitech cam hoặc bất cứ cam gì bạn có)
- Raspberry Pi 3 trở lên( nếu không có tiền thì cứ gắn dây vào laptop hoặc Desktop)
- Vật gắp(tôi đang setup vật hình chữ nhật, bạn có thể tìm vật tương đương, màu sáng)
- Miếng lót( nên là màu tối, không phản sáng, để cam dễ nhận diện)
- Đèn( tùy trường hợp, nếu phòng bạn tối thì tốt nhất nên dùng đèn)
- Trục đỡ cam và đèn( nên điều chỉnh phù hợp theo miếng lót)

II. Hoạt động
- Robot hoạt động dựa trên việc dùng camera quét trên một mặt phẳng
- Sau đó dựa vào vị trí tọa độ thu được trả kết quả cho adruino
- Adruino sau khi có được kết quả thì dùng các thuật toán tính ra độ
- Servo sau khi được Adruino gửi tín hiệu sẽ hoạt động và gắp vật
- Sẽ gắp vật từ phải sang trái
- Sau khi gắp hết sẽ tạm dừng hoạt động

III. Lưu ý
- Code vẫn đang trong quá trình thử nghiệm nên vẫn còn sai sót
- Code cá nhân nên mọi người hỏi ý kiến trước khi lấy về up
- Code nên được tùy chỉnh tùy theo môi trường của bạn
- Sẽ luôn có sai số vì không phải ai cũng để cam có tọa độ giống nhau
- Dùng não( tất nhiên, não rất hữu dụng, hãy dùng nó)


