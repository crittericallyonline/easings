#ifndef EASINGS_H
#define EASINGS_H

#ifdef __cplusplus
extern "C" {
#endif

inline float bounce(float t);
inline float tri(float t);
inline float bell(float t);
inline float instant(float t);
inline float linear(float t);
inline float inQuad(float t);
inline float outQuad(float t);
inline float inOutQuad(float t);
inline float outInQuad(float t);
inline float inCubic(float t);
inline float outCubic(float t);
inline float inOutCubic(float t);
inline float outInCubic(float t);
inline float inQuart(float t);
inline float outQuart(float t);
inline float inOutQuart(float t);
inline float outInQuart(float t);
inline float inQuint(float t);
inline float outQuint(float t);
inline float inOutQuint(float t);
inline float outInQuint(float t);
inline float inExpo(float t);
inline float outExpo(float t);
inline float inOutExpo(float t);
inline float outInExpo(float t);
inline float inCirc(float t);
inline float outCirc(float t);
inline float inOutCirc(float t);
inline float outInCirc(float t);
inline float outBounce(float t);
inline float inBounce(float t);
inline float inOutBounce(float t);
inline float outInBounce(float t);
inline float inSine(float t);
inline float outSine(float t);
inline float inOutSine(float t);
inline float outInSine(float t);

#ifdef __cplusplus
}
#endif

#endif