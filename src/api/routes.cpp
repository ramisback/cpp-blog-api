#ifndef CROW_H
#define CROW_H
#include "../../include/crow_all.h"
#endif
#include "routes.h"
#include <iostream>

void routes(crow::SimpleApp &app) {

    CROW_ROUTE(app, "/").methods(crow::HTTPMethod::GET)([]() {
        std::string greeting = "Hello, World!";
        return "<div><h1>" + greeting + "</h1></div>";
    });

    // Health Check Endpoint
    CROW_ROUTE(app, "/health").methods(crow::HTTPMethod::GET)([]() {
        crow::json::wvalue response;
        std::string        responseTime = "15ms";

        bool databaseCheck = false;

        response["details"]["database"]["status"] =
            databaseCheck ? "up" : "down";
        response["details"]["database"]["response_time"] = responseTime;
        response["status"]                               = "serving";

        char   buffer[25];
        time_t t = time(nullptr);
        strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%SZ", gmtime(&t));
        response["timestamp"] = buffer;

        return response;
    });
}