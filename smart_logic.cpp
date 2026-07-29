#include "smart_logic.h"
#include "config.h"
#include "radar.h"

int fillPercent = 0;

String binStatus = "Unknown";

void updateSmartLogic()
{
    // Расчет процента заполнения
    fillPercent = map(
        filteredDistance,
        EMPTY_DISTANCE,
        FULL_DISTANCE,
        0,
        100
    );

    fillPercent = constrain(fillPercent, 0, 100);

    // Определение статуса
    if (fillPercent < 25)
    {
        binStatus = "🟢 Empty";
    }
    else if (fillPercent < 50)
    {
        binStatus = "🟡 Half Full";
    }
    else if (fillPercent < 80)
    {
        binStatus = "🟠 Almost Full";
    }
    else
    {
        binStatus = "🔴 Full";
    }
}