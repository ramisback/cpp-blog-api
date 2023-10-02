#include "include/crow_all.h"
#include "src/hello.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    crow::SimpleApp app;

    std::function<std::string()> respondWithGreeting = []() {
        std::string greeting = hello("Hello, World!");
        return "<div><h1>" + greeting + "</h1></div>";
    };

    CROW_ROUTE(app, "/").methods(crow::HTTPMethod::GET)(respondWithGreeting);

    char    *port = getenv("PORT");
    uint16_t iPort =
        static_cast<uint16_t>(port != NULL ? std::stoi(port) : 18080);
    CROW_LOG_INFO << "App running on port: " << iPort;
    app.port(iPort).multithreaded().run();
}
