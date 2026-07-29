#include "filter.h"
#include "config.h"

static int distanceBuffer[FILTER_SIZE];

static int bufferIndex = 0;

static bool bufferFilled = false;

int movingAverageFilter(int value)
{
    distanceBuffer[bufferIndex] = value;

    bufferIndex++;

    if (bufferIndex >= FILTER_SIZE)
    {
        bufferIndex = 0;
        bufferFilled = true;
    }

    long sum = 0;

    int count = bufferFilled ? FILTER_SIZE : bufferIndex;

    for (int i = 0; i < count; i++)
    {
        sum += distanceBuffer[i];
    }

    if (count == 0)
        return value;

    return sum / count;
}