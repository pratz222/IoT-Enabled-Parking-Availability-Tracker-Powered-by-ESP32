#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define IR1 D3  // Replace with your actual pin numbers
#define IR2 D4
#define IR3 D0
#define CONNECT_TIME 10000
#define TIMEOUTTIME 5000

char* ssid = "Pratz";
char* password = "12345678";
ESP8266WebServer server(80);

String header;

size_t currentTime = millis();
size_t previousTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);

  Serial.print("Attempting to connect to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() != WL_CONNECTED){
    Serial.println("Connection failed");
    while (1);
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("ESP8266 IP address: ");
  Serial.println(WiFi.localIP().toString());
  server.on("/", HTTP_GET, handleRoot);
  server.begin();
}

void handleRoot() {
  String content = "<!DOCTYPE html><html>";
  content += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  content += "<meta charset=\"UTF-8\">";
  content += "<meta http-equiv=\"refresh\" content=\"5\" >";
  content += "<link rel=\"icon\" href=\"data:,\">";
  content += "<link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css\" integrity=\"sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T\" crossorigin=\"anonymous\">";
  content += "<link rel=\"stylesheet\" href=\"https://use.fontawesome.com/releases/v5.6.3/css/all.css\" integrity=\"sha384-UHRtZLI+pbxtHCWp1t77Bi1L4ZtiqrqD80Kn4Z8NTSRyMA2Fd33n5dQ8lWUE00s/\" crossorigin=\"anonymous\">";
  content += "<script src=\"https://code.jquery.com/jquery-3.3.1.slim.min.js\" integrity=\"sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo\" crossorigin=\"anonymous\"></script>";
  content += "<script src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js\" integrity=\"sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1\" crossorigin=\"anonymous\"></script>";
  content += "<script src=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js\" integrity=\"sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM\" crossorigin=\"anonymous\"></script>";
  content += "<style>";
  content += "body {font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center; background-image: url('https://assets-global.website-files.com/6377bec3d275e7c7574cf149/646215e43d9b89a515a5083a_Blog%20Image%20Frame%20(28).png'); background-size: cover;}";
  content += "html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center; }";
  content += ".mybtn { padding: 16px 40px; font-size: 30px; }";
  content += ".par { font-size: 16px; }";
  content += "p { text-align: center; }";
  content += ".SLOT1, .SLOT2, .SLOT3 { text-align: center; border: none; margin: 2px; padding: 16px 40px; font-size: 30px; }";
  content += "</style></head>";
  content += "<body>";
  content += "<br></br>";
  content += "<h1 style=\"text-align:center;\" class=\"display-4\"> Parking Availability System </h1>";
  content += "<br />";
  
  int SLOT1 = digitalRead(IR1);
  content += "<br></br>";
  content += "<p class=\"par\">SLOT1 - Parking Availability </p>";
  if (SLOT1 == 1)
    content += "<p> <span class=\"SLOT1\" style=\"background-color: #198754!important; color:#f8f9fa!important;\"> Available </span></p>";
  else
    content += "<p> <span class=\"SLOT1\" style=\"background-color: #f44336!important; color:#212529!important;\"> Busy </span></p>";
  
  int SLOT2 = digitalRead(IR2);
  content += "<br></br>";
  content += "<p class=\"par\">SLOT2 - Parking Availability </p>";
  if (SLOT2 == 1)
    content += "<p> <span class=\"SLOT2\" style=\"background-color: #198754!important; color:#f8f9fa!important;\"> Available </span></p>";
  else
    content += "<p> <span class=\"SLOT2\" style=\"background-color: #f44336!important; color:#212529!important;\"> Busy </span></p>";
    
  int SLOT3 = digitalRead(IR3);
  content += "<br></br>";
  content += "<p class=\"par\">SLOT3 - Parking Availability </p>";
  if (SLOT3 == 1)
    content += "<p> <span class=\"SLOT3\" style=\"background-color: #198754!important; color:#f8f9fa!important;\"> Available </span></p>";
  else 
    content += "<p> <span class=\"SLOT3\" style=\"background-color: #f44336!important; color:#212529!important;\"> Busy </span></p>";
  content += "</body></html>";
  server.send(200, "text/html", content);
}

void loop() {
  server.handleClient();
  
  delay(1);
  
}
