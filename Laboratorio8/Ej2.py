import serial
import time
import struct
arduinoData=serial.Serial('com5',9600)
time.sleep(1)
while True:
    while arduinoData.in_waiting==0:
        pass
    dataPacket=arduinoData.readline()
    dataPacket=str(dataPacket,'utf-8')
    dataPacket=dataPacket.strip('\r\n')
    dataPacket=dataPacket.split(',')
    temp=int(dataPacket[0])
    #hum=float(dataPacket[1])
    x=struct.pack('i',temp)
    arduinoData.write(x)
    print(dataPacket)