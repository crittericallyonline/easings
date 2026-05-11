#include "ease.h"

#include <math.h>
#ifndef abs
#define abs(x) ((x) < 0 ? -(x) : (x))
#endif

#ifndef M_PI
#define M_PI           3.14159265358979323846  /* pi */
#endif

inline float interpolate(float x, float a, float b) {return (b - a) * x + a;}
inline float bounce(float t) {return 4 * t * (1 - t);}
inline float tri(float t) {return 1.0f - abs(2 * t - 1);}
inline float bell(float t) {return inOutQuint(tri(t));}
inline float instant(float t) {return 1;}
inline float linear(float t) {return t;}
inline float inQuad(float t) {return t * t;}
inline float outQuad(float t) {return -t * (t - 2);}
inline float inOutQuad(float t) {
    t *= 2;
    return t < 1 ? 0.5 * pow(t, 2) : 1 - 0.5 * pow(2 - t, 2);
}
inline float outInQuad(float t) {
    t *= 2;
    return t < 1 ? 0.5 - 0.5 * pow(1 - t, 2) : 0.5 + 0.5 * pow(t - 1, 2);
}
inline float inCubic(float t) {return pow(t, 3);}
inline float outCubic(float t) {return 1 - pow(1 - t, 3);}
inline float inOutCubic(float t) {
    t *= 2;
    return t < 1 ? 0.5 - 0.5 * pow(1 - t, 2) : 0.5 + 0.5 * pow(t - 1, 3);
}
inline float outInCubic(float t) {
    t *= 2;
    return t < 1 ? 0.5 - 0.5 * pow(1 - t, 3) : 0.5 + 0.5 * pow(t - 1, 3);
}
inline float inQuart(float t) {return pow(t, 4);}
inline float outQuart(float t) {return 1 - pow(1 - t, 4);}
inline float inOutQuart(float t) {
    t *= 2;
    return t < 1 ? 0.5 * pow(t, 4) : 1 - 0.5 * pow(2 - t, 4);
}
inline float outInQuart(float t) {
    t *= 2;
    return t < 1 ? 0.5 - 0.5 * pow(1 - t, 4) : 0.5 + 0.5 * pow(t - 1, 4);
}
inline float inQuint(float t) {return pow(t, 5);}
inline float outQuint(float t) {return 1 - pow(1 - t, 5);}
inline float inOutQuint(float t) {
    t *= 2;
    return t < 1 ? 0.5 * pow(t, 5) : 1 - 0.5 * pow(2 - t, 5);
}
inline float outInQuint(float t) {
    t *= 2;
    return t < 1 ? 0.5 - 0.5 * pow(1 - t, 5) : 0.5 + 0.5 * pow(t - 1, 5);
}
inline float inExpo(float t) {return pow(1000.0, t - 1) - 0.001f;}
inline float outExpo(float t) {return 1.001f - pow(1000.0, -t);}
inline float inOutExpo(float t) {
    t *= 2;
    return t < 1 ? 0.5 * pow(1000.0, t - 1) - 0.0005 : 1.0005 - 0.5 * pow(1000.0, 1 - t);
}
inline float outInExpo(float t) {return t < 0.5 ? outExpo(t * 2) : inExpo(t * 2 - 1) * 0.5 + 0.5;}
inline float inCirc(float t) {return 1 - sqrt(1 - t * t);}
inline float outCirc(float t) {return sqrt(-t * t + 2 * t);}
inline float inOutCirc(float t) {
    t *= 2;
    return t < 1 ? 0.5 - 0.5 * sqrt(1 - t * t) : 0.5 + 0.5 * sqrt(1 - t * t);
}
inline float outInCirc(float t) {return t < 0.5 ? outCirc(t * 2) * 0.5 : inCirc(t * 2 - 1) * 0.5 + 0.5;}
inline float outBounce(float t) {
    if(t < 1.0f / 2.75f)
        return 7.5625f * t * t;
	else if (t < 2 / 2.75) {
		t = t - 1.5 / 2.75;
		return 7.5625 * t * t + 0.75;
    }
	else if(t < 2.5 / 2.75) {
		t = t - 2.25 / 2.75;
		return 7.5625 * t * t + 0.9375;
    }
    t = t - 2.625 / 2.75;
    return 7.5625 * t * t + 0.984375;
}
inline float inBounce(float t) {return 1 - outBounce(1 - t);}
inline float inOutBounce(float t) {return t < 0.5 ? inBounce(t * 2) * 0.5 : outBounce(t * 2 - 1) * 0.5 + 0.5;}
inline float outInBounce(float t) {return t < 0.5 ? outBounce(t * 2) * 0.5 : inBounce(t * 2 - 1) * 0.5 + 0.5;}
inline float inSine(float t) {return 1 - cos(t * (M_PI * 0.5));}
inline float outSine(float t) {return sin(t * (M_PI * 0.5));}
inline float inOutSine(float t) {return 0.5 - 0.5 * cos(t * M_PI);}
inline float outInSine(float t) {return t < 0.5 ? outSine(t * 2) * 0.5 : inSine(t * 2 - 1) * 0.5 + 0.5;}
