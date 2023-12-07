#ifndef TRAIN_H
#define TRAIN_H

#include <vector>
#include <functional>
#include "unit.h"

//void train(int (*r)(int min, int max), char aff, long* g, std::vector<Unit*>& u);
void train(std::function<int(int,int)> r, char aff, long* g, std::vector<Unit*>& u);

#endif