# RFM92W
Sender and receiver example of LoRa rfm92w

This repo is just a different code structure/organization from https://github.com/anthonywebb/RFM92 implementation. There is no need to make this a library since there are better rfm LoRa antennas out there with good documentation. But if you are stuck already with rfm92w like me, I added all of anthonywebb's LoRa related code into a single `rfm92w.h` file just for personal clarity. 

## Implementation
Add all the sender code to one ESP8266 and all the receiver code to the other. The single `rfm92w.h` file contains everything and therefore common to both directories:sender and receiver. That's it! Anthonywebb code works!  
