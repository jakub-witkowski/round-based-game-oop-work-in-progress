#ifndef TRAIN_H
#define TRAIN_H

#include <vector>
#include "unit.h"

void train(int (*r)(int min, int max), char aff, long* g, std::vector<Unit*>& u);

#endif