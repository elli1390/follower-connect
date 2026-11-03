import time
import serial

#the confirmed outgoing Bluetooth COM port
port = "COM4"
baud_rate = 115200

try:
    #open the serial connection to the ESP32
    ser = serial.Serial(port, baud_rate, timeout = 1)
    time.sleep(2) #allow the connection to settle
    print(f "Successfully connected to {port} at {baud_rate} baud!")

    #keep the script running so that the connection stays open
    while True:
        time.sleep(1)

except KeyboardInterrupt:
    ser.close()
    print("\nConnection was closed safely")
except Exception as e:
    print(f"Failed to connect: {e}")