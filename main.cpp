#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <chrono>
//fdlkmslmfkslkmf
std::vector<int> generateVec(int size) {
    std::vector<int> v(size);
    for (int i = 0; i < size; ++i) {
        v[i] = std::rand()%10000;

    }
    return v;

}

void sortVec(std::vector<int>& v) {
    int i, j, key;
    for (i = 1; i < v.size(); ++i) {
        key = v[i];
        j = i-1;

        while(j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j = j-1;
        }
        v[j+1] = key;
    }
}


int main() {
    const int vectorSize = 6;
    int size = 120000;
    // Create 6 vectors and generate random numbers for each
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> vec1 = generateVec(size);
    std::vector<int> vec2 = generateVec(size);
    std::vector<int> vec3 = generateVec(size);
    std::vector<int> vec4 = generateVec(size);
    std::vector<int> vec5 = generateVec(size);
    std::vector<int> vec6 = generateVec(size);

    std::thread t1(sortVec, std::ref(vec1));
    std::thread t2(sortVec, std::ref(vec2));
    std::thread t3(sortVec, std::ref(vec3));
    std::thread t4(sortVec, std::ref(vec4));
    std::thread t5(sortVec, std::ref(vec5));
    std::thread t6(sortVec, std::ref(vec6));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Total Execution Time: " << duration.count() << " seconds." << std::endl;
	std::cout << "Arr size is " << size << '\n';

    return 0;
}

