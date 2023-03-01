#include "histogram.h"

float *histogram_make(unsigned char *channel, int size){

    float *hist = (float *)malloc(sizeof(float) * HISTOGRAM_NLEV);
    for (int i = 0; i < HISTOGRAM_NLEV; i++){
        hist[i] = 0;
    }
    
    for (int i = 0; i < size; i++){
        hist[channel[i]]++;
    }
    
    return hist;
}

float *histogram_make_local(unsigned char *channel, int width, int height,
				   int i, int j, int half_width){

    float *hist = (float *)malloc(sizeof(float) * HISTOGRAM_NLEV);
    for (int i = 0; i < HISTOGRAM_NLEV; i++){
        hist[i] = 0;
    }

    for (int y = j - half_width; y <= j + half_width; y++){
        for (int x = i - half_width; x <= i + half_width; x++){
            if (x >= 0 && x < width && y >= 0 && y < height){
                hist[channel[y * width + x]]++;
            }
        }
    }
}

float *histogram_dup(float *hist){
    float *new_hist = (float *)malloc(sizeof(float) * HISTOGRAM_NLEV);
    
    for (int i = 0; i < HISTOGRAM_NLEV; i++){
        new_hist[i] = hist[i];
    }
    
    return new_hist; 
}

void histogram_cumulate(float *hist){
    for (int i = 1; i < HISTOGRAM_NLEV; i++){
        hist[i] += hist[i-1];
    }
}

void histogram_normalize(float *hist){
    for (int i = 0; i < HISTOGRAM_NLEV; i++){
        hist[i] /= HISTOGRAM_NLEV;
    }
}