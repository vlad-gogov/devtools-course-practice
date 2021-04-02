// Copyright 2021 Gogov Vladislav

#include "include/dheap.h"

#include <stdexcept>
#include <algorithm>
#include <vector>

Dheap::Dheap(int base_) : base(base_) {
    if (base_ <= 1)
        throw std::runtime_error("Base must be greater than 1");
}

Dheap::Dheap(int base_, const std::vector<int> weight_) : base(base_) {
    weight = weight_;
    hilling();
}

void Dheap::swap(int i, int j) {
    std::swap(weight[i], weight[j]);
}

int Dheap::findMinChild(int node) const {
    if (node * base + 1 >= weight.size())
        return -1;
    int firstChild = node * base + 1;
    int lastChild =
        std::min(static_cast<int>(weight.size()) - 1,
                 base * (node + 1));
    int minChild = firstChild;
    for (int i = firstChild + 1; i <= lastChild; i++) {
        if (weight[i] < weight[minChild])
            minChild = i;
    }
    return minChild;
}

void Dheap::diving(int node) {
    int minChild = findMinChild(node);
    while ((minChild != -1) && (weight[minChild] < weight[node])) {
        swap(minChild, node);
        node = minChild;
        minChild = findMinChild(node);
    }
}

void Dheap::emersion(int node) {
    while (node > 0) {
        int parentChild = (node - 1) / base;
        if (weight[parentChild] > weight[node]) {
            swap(node, parentChild);
            node = parentChild;
        } else {
            break;
        }
    }
}

void Dheap::hilling() {
    int size = static_cast<int>(weight.size());
    for (int i = size - 1; i >= 0; i--)
        diving(i);
}

int Dheap::popMin() {
    int min = weight.front();
    weight.front() = weight.back();
    diving(0);
    return min;
}

int Dheap::topMin() const {
    return weight.front();
}

void Dheap::insert(int value) {
    weight.push_back(value);
    emersion(weight.back());
}

int Dheap::getBase() const {
    return base;
}

size_t Dheap::getSize() const {
    return weight.size();
}

const std::vector<int>& Dheap::getWeight() const {
    return weight;
}