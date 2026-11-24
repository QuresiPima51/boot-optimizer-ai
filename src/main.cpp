// main.cpp — entry point. Wires config and subsystems together.

#include "bootoptimizerai/settings.h"
#include "bootoptimizerai/scan.h"
#include "bootoptimizerai/classify.h"
#include "bootoptimizerai/tune.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    bootoptimizerai::Settings settings = bootoptimizerai::Settings::load_default();
    bootoptimizerai::Scan scan(settings.store_path);
    bootoptimizerai::Classify classify(settings.store_path);
    bootoptimizerai::Tune tune(settings.store_path);
    std::fprintf(stderr, "[boot-optimizer-ai] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
