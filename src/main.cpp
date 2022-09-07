#include <iostream>
#include <fstream>

#include "sortingAlgs.h"

// Maximum size of 2147483647(2^31 - 1)
size_t size {1000000};

int runs {5};

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
double sort(const bool random, const bool log) {
    Algorithm algorithm(size);
    runtime = 0;

    if (!algorithm.getName().compare("Merge") && size > 16772287) {
        std::cerr << "WARNING: Merge sort will be significantly slower because heap allocation "
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
        if (log) {
            std::clog << "Sort:         " << algorithm.getName() << '\n'
                      << "Average time: " << averageTime << ' ' << timeScale << '\n'
                      << "Total time:   " << runtime << ' ' << timeScale << '\n' << std::endl;
        }
        return averageTime * timeScaleDivisor;
    } else {
        double time = algorithm.sort(random).count();
        getTimeScale(time);
        time /= timeScaleDivisor;
        std::cout << algorithm.getName() << " sort took " << time << ' ' << timeScale << std::endl;
        if (log) {
            std::clog << "Sort:         " << algorithm.getName() << '\n'
                      << "Time:         " << time << ' ' << timeScale << std::endl;
        }
        return time * timeScaleDivisor;
    }
}

int main() {
    const bool random = false;
    const bool log = true;

    std::ofstream out("log.txt");
    std::clog.rdbuf(out.rdbuf());

    if (log) {
        std::clog << "# of runs:    " << runs << '\n'
                  << "Array size:   " << size << '\n'
                  << "Randomized:   " << (random ? "Yes" : "No") << '\n' << std::endl;
    }

    if (size > 2147483647) {
        size = 2147483647;
        std::cerr << "WARNING: Array size was greater than 2147483647, "
                  << "has been set to 2147483647" << std::endl;
    }

    // sort<Bubble>(random, log);
    // sort<Comb>(random, log);
    sort<Counting>(random, log); // Some errors with multiple sorts, cannot figure out.
    // sort<Exchange>(random, log);
    // sort<Heap>(random, log);
    // sort<Insertion>(random, log);
    // sort<Merge>(random, log);
    // sort<Quick>(random, log);
    // sort<Selection>(random, log);
    // sort<Shell>(random, log);
}
