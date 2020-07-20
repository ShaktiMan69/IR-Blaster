#include <IRremote.h>

IRsend irsend;
void setup() {
  Serial.begin(115200);
  
}

void loop() {
  if(Serial.available() > 0)
  {
    String data = Serial.readString();
    int len = data.length();
    int st = data.indexOf(":");
    int lst = data.lastIndexOf(":");
    long freq = data.substring(0,st).toInt()/1000;
    unsigned int rd[data.substring(lst+1,len).toInt()];
    data = data.substring(st+1,lst);
    int t=0,r=0;
    for(int i=0;i<=data.length();i++){
      if(data.charAt(i)==','){
        rd[t] = data.substring(r,i).toInt();
        r=(i+1);
        t++;
      }
    }
  irsend.sendRaw(rd,t,freq);
  } 
}
