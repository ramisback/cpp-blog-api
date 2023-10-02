#include "include/crow_all.h"
#include <iostream>

int main(int argc, char *argv[]) {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/").methods(crow::HTTPMethod::GET)(
        []() { return "<div><h1>Hello, World.</h1></div>"; });

    char *port = getenv("PORT");
    uint16_t iPort = static_cast<uint16_t>(port ? std::stoi(port) : 18080);
    CROW_LOG_INFO << "App running on port: " << iPort;
    app.port(iPort).multithreaded().run();
}
