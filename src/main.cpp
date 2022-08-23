#include <cfloat>
#include <iostream>
#include <float.h>

#include "sortingAlgs.h"

size_t size {1000000};
int runs {1};
double runtime {0};
int timeScalePick {0};
double timeScaleDivisor;
std::string timeScale;

void getTimeScale(double time) {
    if (time < 1000) {
        timeScale = "nanoseconds";
        timeScaleDivisor = 1;
    } else if (time < 1000000) {
        timeScale = "microseconds";
        timeScaleDivisor = 1000;
    } else if (time < 1000000000) {
        timeScale = "milliseconds";
        timeScaleDivisor = 1000000;
    } else if (time < 60000000000) {
        timeScale = "seconds";
        timeScaleDivisor = 1000000000;
    } else {
        timeScale = "minutes";
        timeScaleDivisor = 60000000000;
    }
}

template <class Algorithm>
double sort(bool random) {
    Algorithm algorithm(size);

    // Sometimes the first sort will be slower because of memory stuff
    // So this will get all the dealt with by doing an extra sort before giving back a time
    algorithm.sort(random);

    // Run x sorts and print out the time for each one, then the average time if there are more than one
    if (runs > 1) {
        for (int i = 0; i < runs; ++i) {
            double time = algorithm.sort(true).count();
            if (i == 0) {
                getTimeScale(time);
            }
            time /= timeScaleDivisor;
            runtime += time;
            std::cout << algorithm.getName() << " sort " << i + 1 << " took " << time << ' ' << timeScale << std::endl;
        }
        double averageTime = runtime / runs;
        std::cout << algorithm.getName() << " sort average time: " << averageTime << ' ' << timeScale << std::endl;

        return averageTime;
    } else {
        double time = algorithm.sort(true).count();
        getTimeScale(time);
        time /= timeScaleDivisor;
        std::cout << algorithm.getName() << " sort took " << time << ' ' << timeScale << std::endl;

        return time;
    }
}

int main() {
    sort<Quick>(true);
}
