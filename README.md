# CPP Blog API

[![Build](https://github.com/ramisback/cpp-blog-api/actions/workflows/docker.yml/badge.svg)](https://github.com/ramisback/cpp-blog-api/actions/workflows/docker.yml)
[![Tests](https://github.com/ramisback/cpp-blog-api/actions/workflows/tests.yml/badge.svg)](https://github.com/ramisback/cpp-blog-api/actions/workflows/tests.yml)
[![CodeQL](https://github.com/ramisback/cpp-blog-api/actions/workflows/github-code-scanning/codeql/badge.svg)](https://github.com/ramisback/cpp-blog-api/actions/workflows/github-code-scanning/codeql)
[![Linting](https://github.com/ramisback/cpp-blog-api/actions/workflows/lint.yml/badge.svg)](https://github.com/ramisback/cpp-blog-api/actions/workflows/lint.yml)

A robust and efficient set of RESTful APIs designed to power personal blogs and online journaling platforms. Built using C++, these APIs provide a seamless backend infrastructure for creating, managing, and interacting with personal blog content.

## Getting Started

To get started with and run project locally, there are two ways you can get started:

### Project Setup

#### 1. Running in container [Easiest Way]

1. Install [Visual Studio Code](https://code.visualstudio.com/)
2. Download and install [Docker Desktop](https://www.docker.com/products/docker-desktop).
3. Follow [How to run in Devcontainers](docs/how-to-run-in-dev-containers.md)

#### 2. Running by compiling on linux/macos

1. [GCC](https://gcc.gnu.org/install/): Compiler used for compiling C++ code.
2. [MAKEFILE](https://www.gnu.org/software/make/manual/html_node/Introduction.html): Build tool for that works on [Linux](https://linuxhint.com/install-make-ubuntu/) as well as [Windows](https://linuxhint.com/run-makefile-windows/).
3. [CMAKE](https://cmake.org/install/): A cross-pltform tool for building and testing software.

## How to compile and run

1. Create a folder in code with name `build`.
2. Open command line and change directory and enter into build folder `cd build/`.
3. Now generate cmake tool configuration files and build project by running `cmake ../ && make` to build project.
4. Finally to run `make run`.
5. To test `make tests` or `ctest` command inside build folder.

## Features

- :white_large_square: High-Performance C++ Backend
- :white_large_square: RESTful API Design
- :white_large_square: Customizable and Extensible
- :white_large_square: Authentication and Security
- :white_large_square: Pagination and Sorting
- :white_large_square: NoSQL Database Support
- :white_large_square: API Documentation

<!-- white_check_mark -->
## Contributing

I encourage and welcome contributions to project from the open-source community. Whether you spot a bug, have an idea for an enhancement, or want to add new features, feel free to submit a pull request.

## License

This project is distributed under the MIT license. For more details, please refer to the [LICENSE](./LICENSE) file.
