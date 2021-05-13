#define D1 10  //밝기 조절 LED핀
#define D2 11  //ON OFF LED핀
String str = "";
bool stringComplete = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  Serial.begin(9600);  
}
void loop() {
    while (Serial.available())
    {
      char buf = (char)Serial.read();
      if(buf != '\n')
      {
        str += buf;
      }
      else
      {
        if (str.equals("led_on")) {
          digitalWrite(D2, HIGH);
          str = "";
        }
        else if(str.equals("led_off"))
        {
          digitalWrite(D2, LOW);
          str = "";
        }
        else if(str.equals("off"))
        {
          analogWrite(D1, 0);
          str = "";
        }
        else if(str.equals("20"))
        {
          analogWrite(D1, 51);
          str = "";
        }
        else if(str.equals("40"))
        {
          analogWrite(D1, 102);
          str = "";
        }
        else if(str.equals("60"))
        {
          analogWrite(D1, 153);
          str = "";
        }
        else if(str.equals("80"))
        {
          analogWrite(D1, 204);
          str = "";
        }
        else if(str.equals("on"))
        {
          digitalWrite(D1, 255);
          str = "";
        }
        
      }
    }
}
