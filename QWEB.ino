/*
 * ESP8266 NodeMCU Real Time Graphs Demo
 * Updates and Gets data from webpage without page refresh
 * https://circuits4you.com
 */

//#define DEBUG_TOKEN_TEST

#include <WiFi.h>
#include <WebServer.h>
//#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include <FuGPS.h>

#include "index.h" //Our HTML webpage contents with javascripts
#include "config.h" //Configuration Page
#include "device.h" //Device Page
#include "logger.h" //Logger Page

#define LED LED_BUILTIN //On board LED

const size_t capacity = JSON_OBJECT_SIZE(20) + 28;
const size_t smallcapacity = JSON_OBJECT_SIZE(5) + 28;

//DynamicJsonDocument doc(capacity);
//DynamicJsonDocument smalldoc(smallcapacity);

// Declare a buffer to hold the result
char json_output[300];
char small_json_output[128];

HardwareSerial& gps = Serial2;
FuGPS fuGPS(gps);
bool gpsAlive = false;

//SSID and Password of your WiFi router
const char* ssid = "TELUS4659";
const char* password = "2bqfrhrzbc";


WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)
//AsyncWebServer server(80);

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

void handleConfig() {
 String c = CONFIG_page; //Read HTML contents
 server.send(200, "text/html", c); //Send web page

  fuGPS.sendCommand(PMTK_API_Q_DGPS_MODE);
  fuGPS.sendCommand(PMTK_API_Q_SBAS_ENABLED);
  Serial.println("DGBS,SBAS Query Cmd Sent");
}

void handleLogger() {
 String l = LOGGER_page; //Read HTML contents
 server.send(200, "text/html", l); //Send web page

 //Get Logger Details
  fuGPS.sendCommand(PMTK_LOCUS_QUERY_STATUS);
  Serial.println("PMTK_LOCUS_QUERY_STATUS Cmd Sent");
}

void handleDevice() {
 String d = DEVICE_page; //Read HTML contents
 server.send(200, "text/html", d); //Send web page

//Get GPS Device Details
  fuGPS.sendCommand(PMTK_Q_RELEASE);
  Serial.println("PMTK_Q_RELEASE Cmd Sent");

}

void handleCommand() {
  String cmdresponse = "None";
  String t_state = server.arg("Response"); //Refer  xhttp.open("GET", "setLED?LEDstate="+led, true);
  Serial.println(t_state);
  if(t_state == "104")
 {
  fuGPS.sendCommand(FUGPS_PMTK_CMD_FULL_COLD_START);
  cmdresponse = "FUGPS_PMTK_CMD_FULL_COLD_START Sent"; //Feedback parameter 
 }
 else if (t_state == "103")
 {
  fuGPS.sendCommand(FUGPS_PMTK_CMD_COLD_START);
  cmdresponse = "FUGPS_PMTK_CMD_COLD_START Sent"; //Feedback parameter  
 }
  else if (t_state == "102")
 {
  fuGPS.sendCommand(FUGPS_PMTK_CMD_WARM_START);
  cmdresponse = "FUGPS_PMTK_CMD_WARM_START Sent"; //Feedback parameter  
 }
  else if (t_state == "101")
 {
  fuGPS.sendCommand(FUGPS_PMTK_CMD_HOT_START);
  cmdresponse = "FUGPS_PMTK_CMD_HOT_START Sent"; //Feedback parameter  
 }
  else if (t_state == "605")
 {
 fuGPS.sendCommand(PMTK_Q_RELEASE);
  //cmdresponse = String(fuGPS.ProductModel) + " " + String (fuGPS.FWString);  //FW String test
  cmdresponse = "PMTK_Q_RELEASE Cmd Sent";
 }
  if(t_state == "251488")
 {
  fuGPS.sendCommand(FUGPS_PMTK_SET_NMEA_BAUDRATE_4800);
  cmdresponse = "FUGPS_PMTK_SET_NMEA_BAUDRATE_4800 Sent"; //Feedback parameter 
 }
   if(t_state == "251960")
 {
  fuGPS.sendCommand(FUGPS_PMTK_SET_NMEA_BAUDRATE_9600);
  cmdresponse = "FUGPS_PMTK_SET_NMEA_BAUDRATE_9600 Sent"; //Feedback parameter 
 }
   if(t_state == "251144")
 {
  fuGPS.sendCommand(FUGPS_PMTK_SET_NMEA_BAUDRATE_14400);
  cmdresponse = "FUGPS_PMTK_SET_NMEA_BAUDRATE_14400 Sent"; //Feedback parameter 
 }
    if(t_state == "251144")
 {
  fuGPS.sendCommand(FUGPS_PMTK_SET_NMEA_BAUDRATE_19200);
  cmdresponse = "FUGPS_PMTK_SET_NMEA_BAUDRATE_19200 Sent"; //Feedback parameter 
 }
  server.send(200, "text/plane", cmdresponse); //Send web page
  Serial.println(cmdresponse);
}

void handleADC() {
 //has fix
 //is alive - Green/Red indicator?
  
//char values_json[] = " {\"Latitude\": latValue, \"Longitude\": lonValue}"; //Original message

DynamicJsonDocument doc(capacity);

doc["model"] = fuGPS.ProductModel;
doc["fw"] = fuGPS.FWString;
doc["build"] = fuGPS.BuildID;
doc["latitude"] = fuGPS.Latitude;
doc["longitude"] = fuGPS.Longitude;
doc["altitude"] = fuGPS.Altitude;
doc["accuracy"] = fuGPS.Accuracy;
doc["quality"] = fuGPS.Quality;
doc["sats"] = fuGPS.Satellites;
doc["speed"] = fuGPS.Speed;
doc["course"] = fuGPS.Course;
doc["years"] = fuGPS.Years;
doc["months"] = fuGPS.Months;
doc["days"] = fuGPS.Days;
doc["hours"] = fuGPS.Hours;
doc["minutes"] = fuGPS.Minutes;
doc["seconds"] = fuGPS.Seconds;
doc["dgps"] = fuGPS.DGPSMode;
doc["sbas"] = fuGPS.SBASEnabled;

Serial.print("DGPS Mode: ");
Serial.println(fuGPS.DGPSMode); 
Serial.print("SBAS Mode: ");
Serial.println(fuGPS.SBASEnabled); 

serializeJson(doc, json_output);

Serial.println(json_output);

 digitalWrite(LED,!digitalRead(LED)); //Toggle LED on data request ajax
 //server.send(200, "text/plane", adcValue); //Send ADC value only to client ajax request
 //server.send(200, "text/plane", LonValue); //Send ADC value only to client ajax request
 server.send(200, "text/plane", json_output); //Send ADC value only to client ajax request
 
}

void handleLogData() {

DynamicJsonDocument logdoc(smallcapacity);

logdoc["serial"] = fuGPS.LogSerial;
logdoc["type"] = fuGPS.LogType;
logdoc["status"] = fuGPS.LogStatus;
logdoc["number"] = fuGPS.LogNumber;
logdoc["percent"] = fuGPS.LogPercent;

Serial.println(fuGPS.LogSerial); 
Serial.println(fuGPS.LogType); 
Serial.println(fuGPS.LogStatus); 
Serial.println(fuGPS.LogNumber);
Serial.println(fuGPS.LogPercent);

serializeJson(logdoc, small_json_output);

Serial.println(small_json_output);

digitalWrite(LED,!digitalRead(LED)); //Toggle LED on data request ajax

server.send(200, "text/plane", small_json_output); //Send ADC value only to client ajax request

}

//==============================================================
//                  SETUP
//==============================================================
void setup(void){
  Serial.begin(115200);
  gps.begin(9600);

  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  //Get GPS Device Details
  //fuGPS.sendCommand(PMTK_Q_RELEASE);
  //Serial.println("PMTK_Q_RELEASE Cmd Sent");

  //Onboard LED port Direction output
  pinMode(LED_BUILTIN,OUTPUT); 
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
 
  server.on("/", handleRoot);                       //handle root location. This is display page
  server.on("/config", handleConfig);              //handle Config Page
  server.on("/readADC", handleADC);                //This page is called by java Script AJAX
  server.on("/readCommand", handleCommand);        //This page is called by java Script AJAX
  server.on("/device", handleDevice);             //handle Details Page
  server.on("/logger", handleLogger);             //handle Logger Page
  server.on("/readLogger", handleLogData);             //handle Logger Data
  

  server.begin();                  //Start server
  Serial.println("HTTP server started");


  
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  server.handleClient();          //Handle client requests

     /// Valid NMEA message ////
    if (fuGPS.read())
    {
        // We don't know, which message was came first (GGA or RMC).
        // Thats why some fields may be empty.

        gpsAlive = true;

        //if (fuGPS.hasFix() == true)
        //{
        #ifdef DEBUG_TOKEN_TEST
        byte tokenIdx = 0;
        while (const char * token = fuGPS.getField(tokenIdx++))
        {
            Serial.print("Token [" + String(tokenIdx) + "]: ");
            Serial.println(token);
        }
             Serial.println();
        #endif
       //     Serial.print("Model: ");
        //    Serial.println(fuGPS.ProductModel);
            // Data from GGA message
           // Serial.print("Accuracy (HDOP): ");
           // Serial.println(fuGPS.Accuracy);

            //Serial.print("Altitude (above sea level): ");
            //Serial.println(fuGPS.Altitude);

            // Data from GGA or RMC
            //Serial.print("Location (decimal degrees): ");
            //Serial.println("https://www.google.com/maps/search/?api=1&query=" + String(fuGPS.Latitude, 6) + "," + String(fuGPS.Longitude, 6));
       // }
    }


    // Default is 10 seconds
    if (fuGPS.isAlive() == false)
    {
        if (gpsAlive == true)
        {
            gpsAlive = false;
            Serial.println("GPS module not responding with valid data.");
            Serial.println("Check wiring or restart.");
        }
    }
    //// NMEA ////
}
