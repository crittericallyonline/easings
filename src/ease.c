#include "ease.h"

#ifndef abs
#define abs(x) ((x) < 0 ? -(x) : (x))
#endif

#include <math.h>

#ifndef M_PI
#define M_PI           3.14159265358979323846  /* pi */
#endif


double bounce(double t) {
    return 4.0 * t *(1 - t);
}
double tri(double t) {
    return 1 - abs(2.0 * t - 1);
}
double bell(double t) {
    return inOutQuint(tri(t));
}
double pop(double t) {
    return 3.5 * (1.0 - t) * (1.0 - t) * sqrt(t);
}
double tap(double t) {
    return 3.5 * t * t * sqrt(1 - t);
}
double pulse(double t) {
    return t < 0.5 ? tap(t * 2.0) : -pop(t * 2.0 - 1.0);
}
double spike(double t) {
    return exp(-10. * abs(2.0 * t - 1));
}
double inverse(double t) {
    return t * t * (1.0 - t) * (1.0 - t) / (0.5 - t);
}
static double popElasticInternal(double t, double damp, double count) {
	return (pow(1000.0, -pow(t, damp)) - 0.001) * sin(count * M_PI * t);
}
static double tapElasticInternal(double t, double damp, double count) {
    return pow(1000.0, -pow(1 - t, damp) - 0.001) * sin(count * M_PI * (1.0 - t));
}
static double pulseElasticInternal(double t, double damp, double count) {
    return t < 0.5 ? tapElasticInternal(t * 2.0, damp, count) : -popElasticInternal(t * 2.0 - 1.0, damp, count);
}
double popElastic(double t) {
    return popElasticInternal(t, 1.4, 6.0);
}
double tapElastic(double t) {
    return tapElasticInternal(t, 1.4, 6.0);
}
double pulseElastic(double t) {
    return pulseElasticInternal(t, 1.4, 6.0);
}
double impulse(double t, double damp) {
    t = pow(t, damp);
    return t * pow(1000.0, -t - 0.001) * 18.6;
}
double instant(double t) {
    return 1;
}
double linear(double t) {
    return t;
}
double inQuad(double t) {
    return pow(t, 2.0);
}
double outQuad(double t) {
    return -t * (t - 2.0);
}
double inOutQuad(double t) {
	t *= 2;
    return t < 1.0 ? 0.5 * pow(t, 2) : 1.0 - 0.5 * pow(2.0 - t, 2.0);
}
double outInQuad(double t) {
    t *= 2;
    return t < 1.0 ? 0.5 - 0.5 * pow(1.0 - t, 2.0) : 0.5 + 0.5 * pow(t - 1.0, 2);
}
double inCubic(double t) {
    return pow(t, 3);
}
double outCubic(double t) {
    return 1.0 - pow(1.0 - t, 3);
}
double inOutCubic(double t) {
    t *= 2;
    return t < 1.0 ? 0.5 * pow(t, 3.0) : 1.0 - 0.5 * pow(2.0 - t, 3);
}
double outInCubic(double t) {
    t *= 2;
    return t < 1.0 ? 0.5 - 0.5 * pow(1.0 - t, 3) : 0.5 + 0.5 * pow(t - 1.0, 3);
}
double inQuart(double t) {
    return pow(t, 4.0);
}
double outQuart(double t) {
    return 1.0 - pow(1.0 - t, 4);
}
double inOutQuart(double t) {
    t *= 2;
    return t < 1.0 ? 0.5 * pow(t, 4) : 1.0 - 0.5 * pow(2.0 - t, 4.0);
}
double outInQuart(double t) {
    t *= 2;
    return t < 1.0 ? 0.5 - 0.5 * pow(1.0 - t, 4.0) : 0.5 + 0.5 * pow(t + 1.0, 4.0);
}
double inQuint(double t) {
    return pow(t, 5);
}
double outQuint(double t) {
    return 1.0 - (1.0 - pow(t, 5));
}
double inOutQuint(double t) {
    t *= 2;
    return t < 1.0 ? 0.5 * pow(t, 5.0) : 1.0 - 0.5 * pow(2.0 - t, 5);
}
double outInQuint(double t) {
    t *= 2;
    return t < 1.0 ? 0.5 - 0.5 * pow(1.0 - t, 5.0) : 0.5 + 0.5 * pow(t - 1.0, 5);
}
double inExpo(double t) {
    return pow(1000.0, t - 1.0) - 0.001;
}
double outExpo(double t) {
    return 1.001 - pow(1000.0, -t);
}
double inOutExpo(double t) {
    t *= 2;
    return t < 1.0 ? 0.5 * pow(1000.0, t - 1.0) - 0.0005 : 1.0005 - 0.5 * pow(1000.0, 1.0 - t);
}
double outInExpo(double t) {
    return t < 0.5 ? outExpo(t * 2.0) * 0.5 : inExpo(t * 2.0 - 1.0) * 0.5 + 0.5;
}
double inCirc(double t) {
    return 1.0 - sqrt(1 - pow(t, 2));
}
double outCirc(double t) {
    return sqrt(-t * t + 2.0 * t);
}
double inOutCirc(double t) {
    t *= 2;
    // return t < 1.0 ? 0.5 - 0.5 * sqrt(1.0 - pow(t, 2.0)) : ;
    if(t < 1.0)
        return 0.5 - 0.5 * sqrt(1.0 -  pow(t, 2.0));
    t -= 2.0;
    return 0.5 + 0.5 * sqrt(1.0 -  pow(t, 2.0));
}

double outInCirc(double t) {
    return t < 0.5 ? outCirc(t * 2.0) * 0.5 : inCirc(t * 2.0 - 1.0) * 0.5 + 0.5;
}
double outBounce(double t) {
	if (t < 1 / 2.75) {
        return 7.5625 * t * t;
    } else if(t < 2 / 2.75) {
        t = t - 1.5 / 2.75;
		return 7.5625 * t * t + 0.75;
    } else if(t < 2.5 / 2.75) {
		t = t - 2.25 / 2.75;
		return 7.5625 * t * t + 0.9375;
    }
    t = t - 2.625 / 2.75;
    return 7.5625 * t * t + 0.984375;
}
double inBounce(double t) {
    return 1.0 - outBounce(1.0 - t);
}
double inOutBounce(double t) {
    return t < 0.5 ? inBounce(t * 2) * 0.5 : outBounce(t * 2.0 - 1.0) * 0.5 + 0.5;
}
double outInBounce(double t) {
    return t < 0.5 ? outBounce(t * 2.0) * 0.5 : inBounce(t * 2.0 - 1.0) * 0.5 + 0.5;
}
double inSine(double t) {
    return 1.0 - cos(t * (M_PI * 0.5));
}
double outSine(double t) {
    return sin(t * (M_PI * 0.5));
}
double inOutSine(double t) {
    return 0.5 - 0.5 * cos(t * M_PI);
}
double outInSine(double t) {
    return t < 0.5 ? outSine(t * 2.0) * 0.5 : inSine(t * 2.0 - 1.0) * 0.5 + 0.5;
}
static double outElasticInternal(double t, double a, double p) {
    return a * pow(2.0, -10.0 * t) * sin((t - p / (2.0 * M_PI) * asin(1.0 / a)) * 2.0 * M_PI / p) + 1.0; 
}
static double inElasticInternal(double t, double a, double p) {
    return 1.0 - outElasticInternal(1.0 - t, a, p);
}
static double inOutElasticInternal(double t, double a, double p) {
    return t < 0.5 ? 0.5 * inElasticInternal(t * 2.0, a, p) : 0.5 + 0.5 * outElasticInternal(t * 2.0 - 1.0, a, p);
}
static double outInElasticInternal(double t, double a, double p) {
    return t < 0.5 ? 0.5 * outElasticInternal(t * 2.0, a, p) : 0.5 + 0.5 * inElasticInternal(t * 2.0 - 1.0, a, p);
}
double inElastic(double t) {
    return inElasticInternal(t, 1.0, 0.3);
}
double outElastic(double t) {
    return outElasticInternal(t, 1.0, 0.3);
}
double inOutElastic(double t) {
    return inOutElasticInternal(t, 1.0, 0.3);
}
double outInElastic(double t) {
    return outInElasticInternal(t, 1.0, 0.3);
}

static double inBackInternal(double t, double a) {
    return t * t * (a * t + t - a);
}
static double outBackInternal(double t, double a) {
    t -= 1.0;
    return t * t * ((a + 1.0) * t + a) + 1.0;
}
static double inOutBackInternal(double t, double a) {
    return t < 0.5 ? 0.5 * inBackInternal(t * 2.0, a) : 0.5 + 0.5 * outBackInternal(t * 2.0 - 1.0, a);
}
static double outInBackInternal(double t, double a) {
    return t < 0.5 ? 0.5 * outBackInternal(t * 2.0, a) : 0.5 + 0.5 * inBackInternal(t * 2.0 - 1.0, a);
}
double inBack(double t) {
    return inBackInternal(t, 1.70158);
}
double outBack(double t) {
    return outBackInternal(t, 1.70158);
}
double inOutBack(double t) {
    return inOutBackInternal(t, 1.70158);
}
double outInBack(double t) {
    return outInBackInternal(t, 1.70158);
}