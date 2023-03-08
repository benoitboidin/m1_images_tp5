#include "threshold.h"
#include "histogram.h"
#include "stif.h"
#include <stdlib.h>

unsigned char *threshold_std(unsigned char *channel, int size, unsigned char th) {
    unsigned char *chan = (unsigned char *)malloc(sizeof(unsigned char) * size);
    for(int i = 0; i < size; i++) {
        chan[i] = channel[i] < th? 0: 255;
    }
    return chan;
}
unsigned char *threshold_mean(unsigned char *channel, int size) {
    return threshold_std(channel, size, stif_mean(channel, size));
}

unsigned char *threshold_median(unsigned char *channel, int size) {
    return threshold_std(channel, size, stif_median(channel, size));
}

unsigned char *threshold_lmean(unsigned char *channel, int width, int height, int half_width) {
    unsigned char *chan = (unsigned char *)malloc(sizeof(unsigned char) * width * height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int ind= j * width + i;
            float lmean = stif_lmean(channel, width, height, i, j, half_width);
            chan[ind] = channel[ind] < lmean ? 0: 255;
        }
    }
    return chan;
}

unsigned char *threshold_percent(unsigned char *channel, int size, float percent) {
    unsigned char *chan = (unsigned char *)malloc(sizeof(unsigned char) * size);
    float *histogram = histogram_make(channel, size);
    histogram_normalize(histogram);
    histogram_cumulate(histogram);

    for(int i = 0; i < size; i++) {
        chan[i] = histogram[channel[i]] < percent? 0: 255;
    }
    free(histogram);
    return chan;
}
