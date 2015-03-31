/*
 * berta.h
 *
 *  Created on: Mar 31, 2015
 *      Author: jsrolon
 */

#ifndef BERTA_H_
#define BERTA_H_

// Global Include Files
#include <math.h>
#include <stdlib.h>
#define _GNU_SOURCE 1
#include <stdio.h>
#include <string.h>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <assert.h>
#include <algorithm>
using std::min;
using std::max;
using std::swap;
using std::sort;

inline float Clamp(float val, float low, float high) {
    if (val < low) return low;
    else if (val > high) return high;
    else return val;
}


inline int Clamp(int val, int low, int high) {
    if (val < low) return low;
    else if (val > high) return high;
    else return val;
}

#endif /* BERTA_H_ */
