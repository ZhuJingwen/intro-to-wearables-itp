# Tutorial: Arduino MKRWifi1010 Firmware Update

1. Download and install the [hourly Arduino IDE build](https://www.arduino.cc/en/Main/Software#hourly).

<img src="https://user-images.githubusercontent.com/5662216/55283576-7ce07380-5334-11e9-8b9c-6883b31c07a7.png" alt="hourly Arduino IDE build screenshot" width="500">

2. Launch the hourly IDE release and use the IDE's library manager (Sketch -> Include Library -> Manage Libraries ...) to install/update the following libraries: WiFiNINA, ArduinoBLE

3. Plug in the MKR WiFi 1010 board into your PC with a USB cable.

4. Select MKR WiFi 1010 as the board and it's serial port in the Tools menu of the IDE.

5. Open the WiFiNINA Firmware Updater example sketch: File -> Examples -> WiFiNINA -> Tools -> FirmwareUpdater

<img src="https://user-images.githubusercontent.com/5662216/55283578-941f6100-5334-11e9-948e-3384e8281b8b.png" alt="WiFiNINA Firmware Updater path screenshot" width = "500">

6. Upload the sketch onto your board.

7. If the Serial Monitor is open, close it.

8. Launch the "WiFi 101 / NINA Firmware Updater" from the Tools menu of the IDE

<img src="https://user-images.githubusercontent.com/5662216/55283579-9681bb00-5334-11e9-963d-25d9917aef01.png" alt="Firmware Updater path screenshot" width = "500">


9. Select the Serial Port for your board. The latest version of firmware for the NINA will be automatically selected.

<img src="https://user-images.githubusercontent.com/5662216/55283583-98e41500-5334-11e9-86ac-63a2a89302ae.png" alt="Firmware Updater screenshot" width = "500">

10. Click the "Update Firmware" button, and wait for the update to complete.

<img src="https://user-images.githubusercontent.com/5662216/55283585-9bdf0580-5334-11e9-9845-f90c2ee69065.png" alt="Firmware Updater success screenshot" width = "500">

11. Close the Updater.

[Source](http://forum.arduino.cc/index.php?topic=579306.0)

