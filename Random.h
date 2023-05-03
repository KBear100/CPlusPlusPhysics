#pragma once
#include <random>

inline void seedRandom(int seed) { srand(seed); }

inline int random() { return rand(); }
inline int random(int max) { return random() % max; } // exclusive (0 <-> (max - 1))
inline int random(int min, int max) { return min + random((max - min) + 1); } // inclusive (min <-> max)

inline float randomf() { return (float)rand() / RAND_MAX; } // 0.0 <-> 1.0
inline float randomf(float max) { return randomf() * max; } // 0.0 <-> max
inline float randomf(float min, float max) { return min + randomf(max - min); } // min <-> max
