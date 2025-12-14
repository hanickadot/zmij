#include <benchmark/benchmark.h>
#include "zmij.h"
#include "original/zmij.cc"

static void DtoA_constexpr(benchmark::State& state) {
  // Code inside this loop is measured repeatedly
  for (auto _ : state) {
    std::array<char, 64> buffer;
    for (double i = -10000.0; i < 10000.0; i += 23.47) {
      zmij::dtoa(i, buffer.data());
    }
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(buffer);
  }
}

static void DtoA_original(benchmark::State& state) {
  // Code inside this loop is measured repeatedly
  for (auto _ : state) {
    std::array<char, 64> buffer;
    for (double i = -10000.0; i < 10000.0; i += 23.47) {
      orig::zmij::dtoa(i, buffer.data());
    }
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(buffer);
  }
}

// Register the function as a benchmark
BENCHMARK(DtoA_original);
BENCHMARK(DtoA_constexpr);

// Run the benchmark
BENCHMARK_MAIN();