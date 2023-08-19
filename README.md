# CPP Blog API

A robust and efficient set of RESTful APIs designed to power personal blogs and online journaling platforms. Built using C++, these APIs provide a seamless backend infrastructure for creating, managing, and interacting with personal blog content.

## Getting Started

To get started with and run project locally, there are two ways you can get started:

### 1. Running by compiling on linux/macos

#### Install Dependencies

1. [GCC](https://gcc.gnu.org/install/): Compiler used for compiling C++ code.
2. [MAKEFILE](https://www.gnu.org/software/make/manual/html_node/Introduction.html): Build tool for that works on [Linux](https://linuxhint.com/install-make-ubuntu/) as well as [Windows](https://linuxhint.com/run-makefile-windows/).
3. [CMAKE](https://cmake.org/install/): A cross-pltform tool for building and testing software.

#### How to compile and run

1. Create a folder in code with name `build`.
2. Open command line and change directory and enter into build folder `cd build/`.
3. Now generate cmake tool configuration files and build project by running `cmake ../ && make` to build project.
4. Finally to run `make run`.
5. To test `make tests` or `ctest` command inside build folder.

### 2. Running Using Dockerfile

[Install docker](https://docs.docker.com/engine/install/) and use dockerfile to run locally, [follow these instructuns](https://dzone.com/articles/how-to-run-docker-container-on-your-local-machine) to setup docker and run or if using vscode follow [tutorial](https://www.youtube.com/watch?v=4I8CRAzPLD4).

## Features

- :white_large_square: High-Performance C++ Backend
- :white_large_square: RESTful API Design
- :white_large_square: Customizable and Extensible
- :white_large_square: Authentication and Security
- :white_large_square: Pagination and Sorting
- :white_large_square: SQL Database Support
- :white_large_square: NoSQL Database Support
- :white_large_square: API Documentation

<!-- white_check_mark -->
## Contributing

I encourage and welcome contributions to project from the open-source community. Whether you spot a bug, have an idea for an enhancement, or want to add new features, feel free to submit a pull request.

## License

This project is distributed under the MIT license. For more details, please refer to the [LICENSE](./LICENSE) file.
