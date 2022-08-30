#include <iostream>

#include "sortingAlgs.h"

// Maximum size of 2147483647(2^31 - 1)
size_t size {2147483647};

int runs {1};

double runtime {0};
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
    } else if (time < 3600000000000) {
        timeScale = "minutes";
        timeScaleDivisor = 60000000000;
    } else {
        timeScale = "hours";
        timeScaleDivisor = 3600000000000;
    }
}

template <class Algorithm>
double sort(const bool random) {
    Algorithm algorithm(size);
    runtime = 0;

    if (!algorithm.getName().compare("Merge") && size > 16772287) {
        std::cout << "WARNING: Merge sort will be significantly slower because heap allocation "
                  << "will be used rather than stack allocation. Use a size less than 16,772,288 "
                  << "for faster and more accurate results." << std::endl;
    }

    // Sometimes the first sort will be slower because of memory stuff
    // So this will get all the dealt with by doing an extra sort before giving back a time
    // Unless the array is large. It can still make a noticable difference, but with slower sorts it takes awhile and I'm impatient
    if (size < 100000) {
        algorithm.sort(random);
    }

    // Run x sorts and print out the time for each one, then the average time if there are more than one
    if (runs > 1) {
        for (int i = 0; i < runs; ++i) {
            double time = algorithm.sort(random).count();
            if (i == 0) {
                getTimeScale(time);
            }
            time /= timeScaleDivisor;
            runtime += time;
            // std::cout << algorithm.getName() << " sort " << i + 1 << " took " << time << ' ' << timeScale << std::endl;
        }
        double averageTime = runtime / runs;
        std::cout << algorithm.getName() << " sort average time: " << averageTime << ' ' << timeScale << std::endl;

        return averageTime * timeScaleDivisor;
    } else {
        double time = algorithm.sort(random).count();
        getTimeScale(time);
        time /= timeScaleDivisor;
        std::cout << algorithm.getName() << " sort took " << time << ' ' << timeScale << std::endl;

        return time * timeScaleDivisor;
    }
}

int main() {
    const bool random = false;

    // sort<Bubble>(random);
    // sort<Comb>(random);
    // sort<Exchange>(random);
    // sort<Insertion>(random);
    // sort<Merge>(random);
    sort<Quick>(random);
    // sort<Selection>(random);
    // sort<Shell>(random);
}
