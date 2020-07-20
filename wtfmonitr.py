import pandas
import serial
from tqdm import tqdm
from time import sleep

rm = pandas.read_csv("/root/Desktop/remote-menu.csv")

print("Starting the thing.")
s = serial.Serial('/dev/ttyACM2',115200)
for i in tqdm(range(len(rm._id))):
    data = str(rm.frequency[i])+":"+str(rm.main_frame[i].replace(" ",""))+',:'+str(rm.main_frame[i].count(",")+1)
    s.write(data.encode())
#    print(data)
    sleep(5)
          
