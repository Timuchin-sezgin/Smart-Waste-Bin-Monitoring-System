#include "radar.h"
#include "config.h"
#include "filter.h"

HardwareSerial radar(2);

int moveDistance = 0;
int moveEnergy = 0;

int staticDistance = 0;
int staticEnergy = 0;

int detectDistance = 0;

int filteredDistance = 0;

String radarStatus = "No Target";

void initRadar()
{
    radar.begin(256000, SERIAL_8N1, RADAR_RX, RADAR_TX);
}
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
            {
                data[i] = radar.read();
            }

            byte targetState = data[8];

            moveDistance = data[9] | (data[10] << 8);
            moveEnergy = data[11];

            staticDistance = data[12] | (data[13] << 8);
            staticEnergy = data[14];

            detectDistance = data[15] | (data[16] << 8);

            //=========================
            // Moving Average Filter
            //=========================

            filteredDistance = movingAverageFilter(staticDistance);

            switch (targetState)
            {
                case 0:
                    radarStatus = "No Target";
                    break;

                case 1:
                    radarStatus = "Moving";
                    break;

                case 2:
                    radarStatus = "Stationary";
                    break;

                case 3:
                    radarStatus = "Moving + Stationary";
                    break;

                default:
                    radarStatus = "Unknown";
                    break;
            }
        }
    }
}