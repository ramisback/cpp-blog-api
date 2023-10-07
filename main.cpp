#ifndef CROW_H
#define CROW_H
#include "include/crow_all.h"
#endif
#include "./src/api/routes.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    crow::SimpleApp app;
    routes(app);
    char    *port = getenv("PORT");
    uint16_t iPort =
        static_cast<uint16_t>(port != NULL ? std::stoi(port) : 18080);
    CROW_LOG_INFO << "App running on port: " << iPort;
    app.port(iPort).multithreaded().run();
}
