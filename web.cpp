#include "web.h"
#include "smart_logic.h"
#include "radar.h"

WebServer* webServer = nullptr;

void handleData()
{
    String json = "{";

    json += "\"distance\":" + String(filteredDistance) + ",";
    json += "\"percent\":" + String(fillPercent) + ",";
    json += "\"status\":\"" + binStatus + "\",";
    json += "\"radar\":\"" + radarStatus + "\"";

    json += "}";

    webServer->send(200, "application/json", json);
}

void handleRoot()
{
    String page = R"rawliteral(
<!DOCTYPE html>
<html>

<head>

<meta charset="UTF-8">

<title>Smart Waste Bin</title>

<style>

body{
background:#1f1f1f;
font-family:Arial;
text-align:center;
color:white;
margin-top:40px;
}

.card{
width:380px;
margin:auto;
background:#2d2d2d;
padding:25px;
border-radius:20px;
box-shadow:0px 0px 20px rgba(0,0,0,0.35);
}

h1{
color:#00ff88;
}

.value{
font-size:24px;
margin:18px;
}

.progress{
width:100%;
height:28px;
background:#555;
border-radius:15px;
overflow:hidden;
margin-top:20px;
}

.bar{
height:100%;
background:#00d26a;
width:0%;
transition:0.3s;
}

</style>

</head>

<body>

<script>

async function updateData()
{
    const response = await fetch('/data');
    const data = await response.json();

    document.getElementById("percent").innerHTML = data.percent + "%";
    document.getElementById("status").innerHTML = data.status;
    document.getElementById("distance").innerHTML = data.distance + " cm";
    document.getElementById("radar").innerHTML = data.radar;

    document.querySelector(".bar").style.width =
    data.percent + "%";
}

setInterval(updateData,500);

updateData();

</script>

<div class="card">

<h1>🗑 Smart Waste Bin</h1>

<div class="value">

📊 Fill Level:

<b id="percent">0%</b>

</div>

<div class="progress">

<div class="bar"></div>

</div>

<div class="value">

🗑 Bin Status:

<b id="status">Loading...</b>

</div>

<div class="value">

📏 Distance:

<b id="distance">0 cm</b>

</div>

<div class="value">

📡 Radar:

<b id="radar">Loading...</b>

</div>

</div>

</body>

</html>
)rawliteral";

    webServer->send(200, "text/html", page);
}

void initWeb(WebServer &server)
{
    webServer = &server;

    webServer->on("/", handleRoot);

    webServer->on("/data", handleData);

    webServer->begin();
}

void updateWeb(WebServer &server)
{
    server.handleClient();
}