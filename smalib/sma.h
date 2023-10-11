/**
* MSA test task
* https://en.wikipedia.org/wiki/Moving_average#Simple_moving_average
* @TODO : 1)   Реализовать функцию, реализующую алгоритм
*              простого скользящего среднего
*              для типа данных float и double
*         2)   Проверить корректность работы функции
*         3)   Сравнить производительность в зависимости
*              от длины окна усреднения и от типа
*              используемых данных (double, float).
*              Производительность измерять в единицах отсчеты/сек.
*              Длина входных данных порядка 1 млн отсчетов.
*              Окна длиной 4, 8, 16, 32, 64, 128.
*         4)   Результаты сравнения производительности представит
*              в виде электронной таблицы и графика в Excel.
* @author : Таразанов Максим */


#ifndef SMA_TEST_TASK_SMA_H
#define SMA_TEST_TASK_SMA_H

#include <iostream>
#include <vector>
#include <span>
#include <numeric>
#include <random>

namespace sma {
    template<std::floating_point T>
    std::vector<T> simpleMovingAverage(std::span<T> data, int windowSize) {
        auto smaArr = std::vector<T>(data.size() - windowSize + 1);
        T c = 1. / windowSize;
        smaArr[0] = std::accumulate(data.begin(), data.begin() + windowSize, 0) * c;

        auto smaArrPrev = smaArr.begin();
        auto dataPlus = data.begin() + windowSize;
        auto dataMinus = data.begin();
        for (T &t: std::span<T>(smaArr.begin() + 1, smaArr.end()))
            t = *(smaArrPrev++) + (*(dataPlus++) - *(dataMinus++)) * c;

        return smaArr;
    }

    template<std::floating_point T>
    void printArr(std::vector<T> arr) {
        if (arr.begin() == arr.end()) {
            std::cout << "Vector is empty\n";
            return;
        }
        for (T t: arr)
            std::cout << t << " ";
        std::cout << '\n';
    }

    template<std::floating_point T>
    std::vector<T> generateArr(int len) {
        auto arr = std::vector<T>(len);
        std::random_device rd;
        std::uniform_real_distribution<T> dist(0., 10.);
        for (T &t: arr)
            t = dist(rd);

        return arr;
    }
}

#endif//SMA_TEST_TASK_SMA_H