## USB main features
Hot pluggable - plug and play  
Self configured  
Some devices are dorectly bus-powered  
USB is Host-controlled - single Host per bus  
Every USB product is programmed to have a vendor ID and product ID (VID/PID)  
A uniques address is assigned by the Host to the device during device enumeration (initial negotiation/recognition). This address will change everytime you disconnect and reconnect the device to the Host.  
USB is a polled bus - the bus gets frequently sampled by both Host and devices without including any interrupt mechanism in the USB controller. And according to the state found on the bus after sampling the bus, specific actions or events happen.  


## Power delivery specs
VBUS voltage normally = ~5V
Bus powered (VBUS)
USB2.0 - upto 500mA
USB3.X - upto 900mA  

USB bus powered devices can draw power from the bus depending on the state of the USB device:  
Not configured, Configured, Suspended(Idle)  


## USB 2.0 speeds - HS - 480Mbps  
Bit stuffing - insetion of non-info bits into the data. In USB HS/FS insert a 0 after 6 consecutive 1s.  

## USB Host controllers: USB 2.0 - EHCI  

## Frames
The time between 2 SOF signals is called a Frame.  
SOF Data SOF Data  
SOF is used to keep data on the bus in sync. This should not be confused with SOP (Sync) field, which is the first field in every pkt.  
We already saw some techniques used to keep the bus in sync, namely bit stuffing and NRZI encoding.
Additional method to keep the bus in sync is grouping the signals on the bus into frames or let's say grouping the packets into frames.  
A Frame consists of multiple pkts.  
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



## Endpoints
This topic is tightly related to USB firmware development.  
Only on devices not Host. An end point is a logical entity that can be seen as data center or as data receiver related to a specific functionality. This depends, of course, on the end point type or let's say more simply, it depends on the direction of the data - Do we want to send some data to the host or do we want to receive data from the host?  
Or we can say an end point can be seen as a buffer or temporary data storage until the data is consumed by the host or by the device, depending on the direction of the data.  
Evevry device has multiple endpoints.  
Every EP has a direction depending on the direction of the data. The direction of EP is named from the Host's perspective:  
If data flows out of device into the Host, it is IN EP and the data is IN data. Similarly, if the data flows from Host to a device EP, it is OUT EP and the data is OUT data.  
IN: device to Host  
OUT: Host to device  

Devices can have upto 16 IN and 16 OUT EPs.  
IN EP-2 means EP-2 that sends data from device to Host.  
Actually the phrase or the term that 'an endpoint sends data to the host' is not very accurate. Actually, in endpoints, simply put, the data available on the bus and the host fetches the data whenever it needs them. But let's keep the things simple now. It's a very, very, very important idea.  

Now let's summarize a bit.
The very simple intuition behind endpoints is every endpoint will be responsible for sending or receiving
data related to a specific functionality in the USB device.
  
In endpoint and out endpoint are totally two different endpoints.
I excluded endpoint zero. This sentence is not totally correct for endpoint zero because you can't configure the endpoint zero as freely as the other endpoints, but we will see that later.


## Packets
A pkt is the smallest unit of data txed in USB. Packets are grouped into Frames (see above). The bytes of a pkt are txed LSB first.  
Every pkt should start with a SOP (Sync) field.  
Pkt fields:  
Sync (SOP) ... Data ... EOP   
... - metadata about the data(payload) and the pkt itself.    


## Packet types and fields
The type of a pkt depends on its content and purpose.  
Basically we have 3 (+1) types of packets:  
  
SOF pkt (Start Of Frame pkt):  
This is not really a type of pkt, even though it gets mentioned as a type coz it has a special usage. Remember we already talked about Frames earlier. SOF simply tells when a new Frame has started. SOF signal is sent every 1 millisecond in full speed USB devices.  
  
Don't get confused between SOF pkt and SOP (Sync) signal.  
SOP (Sync) signal is a sequence of J,K bus states to tell that a new pkt will be sent now. SOP is the first field in any pkt including SOF pkt.  
SOF is a pkt that contains meaningful data.  





