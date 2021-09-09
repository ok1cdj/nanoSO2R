// NanoSO2R box by OK1CDJ - keep it simple stupid
// implements  Open Two Radio Switching Protocol by K1XM https://www.k1xm.org/OTRSP/
// tested with N1MM 
// GNU GPL v.3

// TODO add MIC switching and foot switch input

#define RE1 11
#define RE2 12
char commandEnd  = '\r';
String command;


void setup() {
  pinMode(RE1, OUTPUT);
  pinMode(RE2, OUTPUT);
  digitalWrite(RE1, 1);
  digitalWrite(RE2, 1);
  Serial.begin(9600); // Start serial communication at 9600 bps
}

void loop() {
  if (Serial.available())
  { // If data is available to read,
    command = Serial.readStringUntil(commandEnd);
    command.toUpperCase();
    parseCommand(command);
  }
  delay(10); // Wait 10 milliseconds for next reading
}


void parseCommand(String comm)
{

  if(comm.equals("?NAME")){
             Serial.println("NanoSO2R");
        }
        else if(command.equals("RX1")){
              digitalWrite(RE1, 1);
              digitalWrite(RE2, 1);
            //send_message();
        }
        else if(command.equals("RX2")){
              digitalWrite(RE1, 0);
              digitalWrite(RE2, 1);
            //send_message();
        }
        else if(command.equals("RX1S")){
              digitalWrite(RE1, 0);
              digitalWrite(RE2, 0);
            //send_message();
        }
        else if(command.equals("RX2S")){
              digitalWrite(RE1, 0);
              digitalWrite(RE2, 0);
            //send_message();
        }

        
  //Serial.println(comm);
  
}



