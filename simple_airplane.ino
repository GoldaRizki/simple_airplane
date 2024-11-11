    #include <Servo.h>

    int vertical, horizontal, batas_kanan, batas_kiri, derajat_awal, nilai_flap_kanan, nilai_flap_kiri, horizontal_result;
    long horizontal_mapping;

    Servo flap_kanan, flap_kiri;

    void setup() {
        // put your setup code here, to run once:
        Serial.begin(9600);
        pinMode(3, INPUT);

        batas_kanan = 510;
        batas_kiri = 514;
        derajat_awal = 45;

        flap_kanan.attach(5);
        flap_kiri.attach(6);

    }

    void loop() {
        // put your main code here, to run repeatedly:
        vertical = analogRead(A0);
        horizontal = analogRead(A1);


        Serial.print("Vertical: ");
        Serial.print(vertical);

        Serial.print(" | Horizontal: ");
        Serial.print(horizontal);

        if(horizontal > batas_kiri){
          horizontal_result = 1023 - horizontal;
          horizontal_mapping = map(horizontal_result, batas_kiri, 1023, 0, 45);

          flap_kiri.write(derajat_awal + horizontal_mapping);
          flap_kanan.write(derajat_awal - horizontal_mapping);

        }else if(horizontal < batas_kanan){
          horizontal_result = batas_kanan - horizontal;
          horizontal_mapping = map(horizontal_result, 0, batas_kanan, 0, 45);

          flap_kiri.write(derajat_awal - horizontal_mapping);
          flap_kanan.write(derajat_awal + horizontal_mapping);

        }

    }
