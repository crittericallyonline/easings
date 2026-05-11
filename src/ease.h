#ifndef EASE_H
#define EASE_H

#ifdef __cplusplus
extern "C" {
#endif

double bounce(double t);
double tri(double t);
double bell(double t);
double pop(double t);
double tap(double t);
double pulse(double t);
double spike(double t);
double inverse(double t);
double popElastic(double t);
double tapElastic(double t);
double pulseElastic(double t);
double instant(double t);
double linear(double t);
double inQuad(double t);
double outQuad(double t);
double inOutQuad(double t);
double outInQuad(double t);
double inCubic(double t);
double outCubic(double t);
double inOutCubic(double t);
double outInCubic(double t);
double inQuart(double t);
double outQuart(double t);
double inOutQuart(double t);
double outInQuart(double t);
double inQuint(double t);
double outQuint(double t);
double inOutQuint(double t);
double outInQuint(double t);
double inExpo(double t);
double outExpo(double t);
double inOutExpo(double t);
double outInExpo(double t);
double inCirc(double t);
double outCirc(double t);
double inOutCirc(double t);
double outInCirc(double t);
double inBounce(double t);
double outBounce(double t);
double inOutBounce(double t);
double outInBounce(double t);
double inSine(double t);
double outSine(double t);
double inOutSine(double t);
double outInSine(double t);
double inElastic(double t);
double outElastic(double t);
double inOutElastic(double t);
double outInElastic(double t);
double inBack(double t);
double outBack(double t);
double inOutBack(double t);
double outInBack(double t);

#ifdef __cplusplus
}
#endif

#endif