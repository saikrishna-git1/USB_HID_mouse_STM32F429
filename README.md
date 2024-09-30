## USB main features
Hot pluggable - plug and play
Self configured
Some devices are dorectly bus-powered


## USB 2.0 speeds - HS - 480Mbps  
Bit stuffing - insetion of non-info bits into the data. In USB HS/FS insert a 0 after 6 consecutive 1s.  

## USB Host controllers: USB 2.0 - EHCI  

## Frames
We already saw some techniques used to keep the bus in sync, namely bit stuffing and NRZI encoding.
Additional method to keep the bus in sync is grouping the signals on the bus into frames or let's say grouping the packets into frames.  
Every frame is determined simply by a start of frame SOF signal on the bus. Here on this diagram or in this figure, we can see this SOF or start of frame signal is sent 
every 1 millisecond in full speed USB devices.
Every USB device connected to the to the bus is allowed to use a specific portion of the frame.
For example, if we have a USB mouse, a USB keyboard and a USB camera connected to our PC.
If we monitor the data on the bus, the camera will obviously have the most portion of the data in each frame.
This is, of course, because the camera sends a lot of data where the mouse and keyboard will have small portions in every single frame.

Nevertheless, the camera is not allowed to consume the entire frame without giving the chance for the keyboard and the mouse to send their data.
This is because every single device has a specific minimum portion in every single frame reserved for this device.
So this means frames help to divide the bandwidth of the bus between the connected devices.

I will repeat this example again later and talk about it in more details when we talk about USB bandwidth allocation or management.
