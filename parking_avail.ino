#include <WiFi.h>    //initial declaration of libs to get basic codes in the form of keywords

#define IR1 26
#define IR2 27
#define IR3 28
#define CONNECT_TIME 10000
#define TIMEOUTTIME 5000

const char* ssid = "Pratz";
const char* password = "12345678";
WiFiServer server(80);

String header;

size_t currentTime = millis();
size_t previousTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);


  Serial.print("Attempting to connect to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  size_t start_time = millis();
  size_t dot_time = millis();
  while ((WiFi.status() != WL_CONNECTED) && (start_time + CONNECT_TIME) > millis()) {
    if (dot_time + 250 < millis()) {
      Serial.print(".");
      dot_time = millis();
    }
  }
  if (WiFi.status() != WL_CONNECTED){
    Serial.println("Connection failed");
    while (1);
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("ESP32 IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");
    String currentLine = "";

    while (client.connected() && currentTime - previousTime <= TIMEOUTTIME) {
      currentTime = millis();
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        header += c;

            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<meta charset=\"UTF-8\">");
            client.println("<meta http-equiv=\"refresh\" content=\"5\" >");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css\" integrity=\"sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T\" crossorigin=\"anonymous\">");
            client.println("<link rel=\"stylesheet\" href=\"https://use.fontawesome.com/releases/v5.6.3/css/all.css\" integrity=\"sha384-UHRtZLI+pbxtHCWp1t77Bi1L4ZtiqrqD80Kn4Z8NTSRyMA2Fd33n5dQ8lWUE00s/\" crossorigin=\"anonymous\">");

            client.println("<script src=\"https://code.jquery.com/jquery-3.3.1.slim.min.js\" integrity=\"sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo\" crossorigin=\"anonymous\"></script>");
            client.println("<script src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js\" integrity=\"sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1\" crossorigin=\"anonymous\"></script>");
            client.println("<script src=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js\" integrity=\"sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM\" crossorigin=\"anonymous\"></script>");

            client.println("<style>");
            client.println("body {font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center; background-image: url('https://assets-global.website-files.com/6377bec3d275e7c7574cf149/646215e43d9b89a515a5083a_Blog%20Image%20Frame%20(28).png'); background-size: cover;}");
            client.println("html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center; }");
            client.println(".mybtn {padding: 16px 40px; font-size: 30px;} ");
            client.println(".par { font-size: 16px;}");
            client.println("p {text-align: center;}");
            // IMPPPPPPPPPPPPPPP
            client.println(".SLOT1, .SLOT2, .SLOT3 { text-align: center; border: none; margin: 2px; padding: 16px 40px; font-size: 30px; }");
            client.println("</style></head>");
            client.println("<body>");
            client.println("<br></br>");
            client.println("<h1 style=\"text-align:center;\" class=\"display-4\"> Parking Availability System </h1>");
            client.println("<br />");
   
            int SLOT1 = digitalRead(IR1);
            client.println("<br></br>");
            client.println("<p class=\"par\">SLOT1 - Parking Availibility </p>");
            if ( SLOT1 == 1)
              client.println("<p> <span class=\"SLOT1\" style=\"background-color: #198754!important; color:#f8f9fa!important;\"> " Available " </span></p>");         
            else
              client.println("<p> <span class=\"SLOT1\" style=\"background-color: #ffc107!important; color:#212529!important;\"> " Busy " </span></p>");

            int SLOT2 = digitalRead(IR2);
            client.println("<br></br>");
            client.println("<p class=\"par\">SLOT2 - Parking Availibility </p>");
            if ( SLOT2 == 1)
              client.println("<p> <span class=\"SLOT2\" style=\"background-color: #198754!important; color:#f8f9fa!important;\"> " Available " </span></p>");         
            else
              client.println("<p> <span class=\"SLOT2\" style=\"background-color: #ffc107!important; color:#212529!important;\"> " Busy " </span></p>");

            int SLOT3 = digitalRead(IR3);
            client.println("<br></br>");
            client.println("<p class=\"par\">SLOT3 - Parking Availibility </p>");
            if ( SLOT3 == 1)
              client.println("<p> <span class=\"SLOT3\" style=\"background-color: #198754!important; color:#f8f9fa!important;\"> " Available " </span></p>");         
            else
              client.println("<p> <span class=\"SLOT3\" style=\"background-color: #ffc107!important; color:#212529!important;\"> " Busy " </span></p>");

           client.println("</body></html>");
            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    header = "";
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
  delay(1);
}
