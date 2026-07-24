#include <WiFi.h>
#include <WebServer.h>

HardwareSerial radar(2);
WebServer server(80);

//=========================
// НАСТРОЙКИ WIFI
//=========================

const char* ssid = "your wifi name";
const char* password = "your wifi pasword";

//=========================
// ПЕРЕМЕННЫЕ
//=========================

String statusText = "Нет данных";

int moveDistance = 0;
int moveEnergy = 0;

int staticDistance = 0;
int staticEnergy = 0;

int detectDistance = 0;

//=========================
// ГЛАВНАЯ СТРАНИЦА
//=========================

void handleRoot()
{

String page = R"rawliteral(

<!DOCTYPE html>

<html>

<head>

<meta charset="UTF-8">

<meta http-equiv="refresh" content="1">

<title>Smart Waste Bin</title>

<style>

body{

background:#202124;

color:white;

font-family:Arial;

text-align:center;

}

.card{

width:340px;

margin:auto;

margin-top:40px;

background:#2f2f2f;

padding:25px;

border-radius:18px;

}

h1{

color:#00ff88;

}

.value{

font-size:28px;

margin:12px;

}

</style>

</head>

<body>

<div class="card">

<h1>🗑 Smart Waste Bin</h1>

)rawliteral";

page += "<div class='value'>Статус: <b>" + statusText + "</b></div>";

page += "<div class='value'>Движение: <b>";
page += String(moveDistance);
page += " см</b></div>";

page += "<div class='value'>Энергия движения: <b>";
page += String(moveEnergy);
page += "</b></div>";

page += "<div class='value'>Стоит: <b>";
page += String(staticDistance);
page += " см</b></div>";

page += "<div class='value'>Энергия стояния: <b>";
page += String(staticEnergy);
page += "</b></div>";

page += "<div class='value'>Общее расстояние: <b>";
page += String(detectDistance);
page += " см</b></div>";

page += R"rawliteral(

</div>

</body>

</html>

)rawliteral";

server.send(200,"text/html",page);

}

//=========================
// SETUP
//=========================

void setup()
{

Serial.begin(115200);

radar.begin(256000,SERIAL_8N1,16,17);

WiFi.begin(ssid,password);

Serial.print("Подключение");

while(WiFi.status()!=WL_CONNECTED)
{
delay(500);
Serial.print(".");
}

Serial.println();
Serial.println("WiFi OK");

Serial.print("IP: ");
Serial.println(WiFi.localIP());

server.on("/",handleRoot);

server.begin();

}
//=========================
// ЧТЕНИЕ HLK-LD2410B
//=========================

void readRadar()
{
  while (radar.available())
  {
    if (radar.read() == 0xF4)
    {
      byte data[18];
      data[0] = 0xF4;

      while (radar.available() < 17);

      for (int i = 1; i < 18; i++)
        data[i] = radar.read();

      byte status = data[8];

      uint16_t moveDist = data[9] | (data[10] << 8);
      byte moveEng = data[11];

      uint16_t staticDist = data[12] | (data[13] << 8);
      byte staticEng = data[14];

      uint16_t detectDist = data[15] | (data[16] << 8);

      moveDistance = moveDist;
      moveEnergy = moveEng;

      staticDistance = staticDist;
      staticEnergy = staticEng;

      detectDistance = detectDist;

      switch (status)
      {
        case 0:
          statusText = "Нет цели";
          break;

        case 1:
          statusText = "Движение";
          break;

        case 2:
          statusText = "Неподвижная цель";
          break;

        case 3:
          statusText = "Движение + неподвижная цель";
          break;

        default:
          statusText = "Неизвестно";
          break;
      }
    }
  }
}

//=========================
// LOOP
//=========================

void loop()
{
  readRadar();
  server.handleClient();
}