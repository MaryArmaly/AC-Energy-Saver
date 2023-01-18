# AC_Energy_Saver

ENERGY SAVER

Submitters:

Mary Armaly

Luai Okal

Bshara Batres


The project’s description:

 An open-source smart remote that can control an air conditioner and receive commands via the Internet. The remote consists of an Esp32 controller, IR transmitter, IR receiver, sensors (described below) and LED strip that simulates the air conditioner controlled by our smart remote.
The controller uses the open-source application HOME ASSISTANT for Android, and the ESPHome extension to send commands to the air conditioner and create automations.



Features in our project:

•	DHT sensor: Measures the current temperature of the room. 

•	PIR sensor:  Detects motion in the sensor’s range.

•	High sensitivity sound microphone sensor: Detects voices.

•	BLE iTag Button: It connects to the esp32 using the BLE features of ESPHome, works as a remote control which can turn ON/OFF the AC by pressing it’s button. It can 
help people with disabilities, elderly people…

•	Wi-Fi: We used the HomeAssistant’s Wi-Fi feature to check if there is a Phone connected to the Wi-Fi in the room.

•	Providing better, more accurate cooling/heating as compared to regular AC units that maintain optimal temperatures only around the AC unit, it maintains optimal temperatures around the esp32 (the AC remote temperature), since the temperature sensor is connected to the esp32.

•	Special modes: Shabbat Shalom mode and Sleep mode.


How does our air conditioner simulator work?

Every color represents a temperature range and AC mode (cool/heat) as follows:

•	Heat: 

o	18°C - 20°C: yellow

o	21°C - 23°C: Orange

o	24°C - 26°C: Darker Orange

o	27°C - 29°C: Red



•	Cool:  

o	18°C - 20°C: Blue

o	21°C - 23°C: Lighter blue

o	24°C - 26°C: Lighter blue

o	27°C - 29°C: White


*Minimum AC temperature: 18°C

*Maximum AC temperature: 29°C

The fan’s speed is represented by the color’s clarity and strength, that is, when the fan is faster, the color is clearer and stronger. The user can control the fan’s speed by Increase_fan_speed and Decrease_fan_speed buttons.
Heat and Cool modes: The user can choose in which mode the AC will work by turning ON one of the Cool and Heat toggles. By turning ON one of them the second will be turned OFF automatically, and by turning OFF one of them the second will be turned ON automatically.


The remote’s functionality:

Our smart remote control receives commands from the HomeAssistant application via the internet (Wi-Fi), translates them into IR commands and sends them to the AC using the IR transmitter. In addition, the automations we created can trigger the esp to send IR commands to the AC automatically.

Note:

 To find the remote’s commands decoding, we used the IR-receiver by pressing the remote’s buttons being directed to the receiver. 
The commands decoding of the actual AC remote controller differ from the AC simulator (the LED strip) remote controller,  by using the IR-receiver we found the actual AC remote controller commands decoding and used them to control the actual AC.


How does our AC work as an energy saver? 

•	In case the AC is turned ON and no one is in the room (by checking the PIR sensor, the high sensitivity sound microphone sensor for a certain time and making sure there is no Wi-Fi connections via the phone’s Ip), the AC will be turned OFF automatically.


•	While the AC is turned ON, when on:

	Cool Mode:

If the temperature measured by the temperature sensor is less than the AC temperature, the AC will be turned OFF temporarily until the temperature measured by the temperature sensor is greater or equal to the AC temperature, then it will be turned ON automatically, that is the AC rests in between.


	Heat Mode:

If the temperature measured by the temperature sensor is greater than the AC temperature, the AC will be turned OFF temporarily until the temperature measured by the temperature sensor is less or equal to the AC temperature, then it will be turned ON automatically, that is the AC rests in between.



Special modes:

•	Sleep mode:

 While sleeping, there is no motions and sounds in the room, to avoid turning OFF the AC automatically by the automations we created, the user has to turn ON the sleep mode, so some automations (the automations which are responsible for turning the AC OFF when the room is empty) will be disabled until the sleep mode is turned OFF. 
     
          o	In case the user forgot to turn OFF the sleep mode, there is a time which is determined by the user, so that the sleep mode will be turned OFF at the specified time automatically.


•	Shabbat shalom mode:

 This mode is intended to allow the AC to be used by Shabbat-observant Jews on Shabbat and Jewish holidays. The mode overrides the usual operation and automations of the AC and makes them comply with the rules of Halakha while saving energy.
In our AC, this mode has an ON/OFF toggle, Shabbat entrance and Shabbat exit times determined by the user. If Shabbat shalom mode is turned ON, the AC will be turned ON at the Shabbat entrance time and some automations (the automations which are responsible for turning the AC OFF) will be disabled until the Shabbat exit time. At the Shabbat exit time, the Shabbat Shalom mode will be turned off and the AC will return to the usual operation. 



The app interface:


![image](https://user-images.githubusercontent.com/110840404/195196898-e19e1a7c-b003-400f-9942-a9dbe3534c2c.png)    ![image](https://user-images.githubusercontent.com/110840404/195196928-5cbe776d-14b9-4e62-ba81-a737a29e47df.png)

  


What we have in GitHub:

•	Automations: A folder containing all the automation files code which we created in the HomeAssistant. 
Note: Files belonging to the same automation have the same automation number.


•	Documentation: A folder containing “Project activation documentation.pdf” file.


•	UnitTests: A folder containing all the files testing code of the sensors.
Note: These files are Arduino files, we used them only to check if the sensors work correctly.


•	README.


•	Secrets: A template file containing fields to fill in order to run the project (keys/wifi-passwords).


•	User interface documentation: A file containing explanation of app user interface, LED strip status and parameters.



•	energysaverb: A file containing the code which is installed on the esp32 through the ESPHome in HomeAssistant.




Applications and Libraries:

•	For building and using the project we used HomeAssistant with ESPHome add on.


•	Arduino libraries:

o	DHT Sensor Library (version: 1.4.4)

o	Adafruit Unified Sensor (version: 1.1.6)

o	IRremote (version: 3.8.0)

o	IRremoteESP8266 (version: 2.8.2)


