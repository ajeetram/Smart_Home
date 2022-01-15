# Smart_Home
The Smart Home Automation System is an integrated framework to provide people with an easy-to-use home automation system. Which can be operated based on speech commands. The system is constructed in such a way that it is easy to install, configure, run, and maintain by any type of person. The system is operated as the voice command is given through a microphone, so that the NodeMCU is performing an action on the basis of voice commands. The speech is mapped through commands using the Google Assistant Voice Service, developed by Google.

When a person gives a voice command through Google Assistant, the command is converted into text form, and Google Assistant then sends this text command to NodeMCU via the Blynk cloud service.  The converted text is then compared with the defined commands in the command configuration file to see if there are any matches. If there is a match, the command associated with the voice command is then executed, and based on that command, an action is performed, like turning on or off a light or fan.
Also, it shows that if anybody enters the room, the PIR motion sensor detects the movement and turns on the LED light. After turning on the light, if there is no movement for 5 minutes, the light is automatically turned off.

# Advantages

- Embed a speech control interface for controlling the electrical appliances for physically challenged people.
- Low-cost and easy to install  and configure.
- Fire detection capability to identify fire hazards and promptly send notifications through
Blynk cloud service, enhancing safety measures.


#  Components/Skills Required
- Node MCU ESP8266
- Motion Sensor
- CO Sensor
- Relay
- LED Light
- FAN
- Blynk App
- C/C++ Programming language