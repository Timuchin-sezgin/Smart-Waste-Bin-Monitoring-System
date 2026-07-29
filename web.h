#ifndef WEB_H
#define WEB_H

#include <Arduino.h>
#include <WebServer.h>

void initWeb(WebServer &server);
void updateWeb(WebServer &server);

void handleRoot();
void handleData();

#endif