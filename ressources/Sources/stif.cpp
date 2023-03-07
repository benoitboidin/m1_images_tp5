#include "stif.h"
#include <math.h>

float stif_mean(unsigned char *channel, int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++) 
    {
        sum += channel[i];
    }

    return sum / size;
}

float stif_variance(unsigned char *channel, int size)
{
    float mean = stif_mean(channel, size);
    float sum_delta = 0;
    for (int i = 0; i < size; i++) 
    {
        sum_delta += (channel[i] - mean) * (channel[i] - mean);
    }

    return sum_delta / size;
}

float stif_entropy(unsigned char *channel, int size)
{

    int *histogram = new int[256];
    for (int i = 0; i < 256; i++) 
    {
        histogram[i] = 0;
    }

    for (int i = 0; i < size; i++) 
    {
        histogram[channel[i]]++;
    }

    for (int i = 0; i < 256; i++) 
    {
        histogram[i] /= size;
    }

    float sum = 0;
    for (int i = 0; i < 256; i++)
    {
        if (histogram[i] != 0)
            {
                sum += histogram[i] * log(histogram[i]); 
            }
    }

    return -sum;
}

int stif_median(unsigned char *channel, int size)
{
    int *histogram = new int[256];
    for (int i = 0; i < 256; i++) 
    {
        histogram[i] = 0;
    }

    for (int i = 0; i < size; i++) 
    {
        histogram[channel[i]]++;
    }

    int median = 0;
    int sum = 0;
    while (sum < size / 2) 
    {
        sum += histogram[median];
        median++;
    }

    delete[] histogram;
    return median;
}
