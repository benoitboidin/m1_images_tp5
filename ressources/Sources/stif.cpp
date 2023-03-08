#include "stif.h"
#include "histogram.h"
#include <math.h>

float hist_mean(float *histogram) {
    float sum = 0;
    for(int i = 0; i < HISTOGRAM_NLEV; i++)
        sum += histogram[i] * i;

    return sum;
}

float hist_variance(float *histogram, float mean) {
    float sum_delta = 0;
    for (int i = 0; i < HISTOGRAM_NLEV; i++) 
        sum_delta += histogram[i] * (i - mean);
    return sum_delta;
}

float hist_entropy(float *histogram) {
    float sum = 0;
    for (int i = 0; i < 256; i++) 
        if (histogram[i] != 0)
                sum += histogram[i] * log(histogram[i]); 
    return -sum;
}

float hist_median(float *histogram) {

    float val = histogram[HISTOGRAM_NLEV] * 0.5;

 
    for(int i = 0; i < HISTOGRAM_NLEV; i++) {
        if(histogram[i] >= histogram[HISTOGRAM_NLEV-1] * 0.5) {
            return i;
        }
    }
    return -1; // Should never happen.
}

float stif_mean(unsigned char *channel, int size)
{
    float *histogram = histogram_make(channel, size);
    histogram_normalize(histogram);

    float sum = hist_mean(histogram);
    free(histogram);
    return sum;
}

float stif_variance(unsigned char *channel, int size)
{
    float *histogram = histogram_make(channel, size);
    histogram_normalize(histogram);

    float mean = stif_mean(channel, size);
    float sum_delta = hist_variance(histogram, mean);
    free(histogram);
    return sum_delta;
}

float stif_entropy(unsigned char *channel, int size)
{
    float *histogram = histogram_make(channel, size);
    histogram_normalize(histogram);

    float entropy = hist_entropy(histogram);
    free(histogram);
    return entropy;
}

int stif_median(unsigned char *channel, int size) {
    float *histogram = histogram_make(channel, size);
    histogram_cumulate(histogram);

    int median = hist_median(histogram);
    free(histogram);
    return median; 
}

float stif_lmean(unsigned char *channel, int width, int height, int i, int j, int half_width) {
    float *histogram = histogram_make_local(channel, width, height, i, j, half_width);
    histogram_normalize(histogram);
    float sum = hist_mean(histogram);
    free(histogram);
    return sum;
}

float stif_lvariance(unsigned char *channel, int width, int height, int i, int j, int half_width) {
    float *histogram = histogram_make_local(channel, width, height, i, j, half_width);
    histogram_normalize(histogram);

    float mean = stif_lmean(channel, width, height, i, j, half_width);
    float sum_delta = hist_variance(histogram, mean);
    free(histogram);
    return sum_delta;
}

float stif_lentropy(unsigned char *channel, int width, int height, int i, int j, int half_width) {
    float *histogram = histogram_make_local(channel, width, height, i, j, half_width);
    histogram_normalize(histogram);

    float entropy = hist_entropy(histogram);
    free(histogram);
    return entropy;
}

int stif_lmedian(unsigned char *channel, int width, int height, int i, int j, int half_width) {
    float *histogram = histogram_make_local(channel, width, height, i, j, half_width);
    histogram_cumulate(histogram);

    int median = hist_median(histogram);
    free(histogram);
    return median; 
}
