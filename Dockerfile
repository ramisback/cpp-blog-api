# Stage 1: Build stage
FROM ubuntu:22.04 AS builder

# Update and upgrade the system packages
RUN apt-get -qq update --fix-missing
RUN apt-get -qq upgrade

# Install required build tools and dependencies
RUN apt-get -qq install -y gcc
RUN apt-get -qq install wget 
RUN apt-get -qq install build-essential
RUN apt-get -qq install libboost-all-dev
RUN apt-get -qq install libssl-dev

# Download and install the latest version of CMake
RUN wget -q https://github.com/Kitware/CMake/releases/download/v3.27.2/cmake-3.27.2.tar.gz && \
    tar -xf cmake-3.27.2.tar.gz && \
    cd cmake-3.27.2 && \
    ./bootstrap && make && make install && \
    cd .. && rm -r cmake-3.27.2*

# Install additional libraries for memory allocation optimization
RUN apt-get -qq install libtcmalloc-minimal4 && \
    ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so

# Copy the source code into the container's /usr/src/app directory
COPY . /usr/src/app

# Set the working directory to /usr/src/app
WORKDIR /usr/src/app

# Run CMake to generate build files and Make to build the application
RUN cmake . && make


# Stage 2: Runtime stage
FROM scratch AS runtime

# Copy the built executable from the builder stage to the runtime stage
COPY --from=builder /usr/src/app/blog_backend /

# Set the default command to run the application when the container starts
CMD ["./blog_backend"]

# Define metadata for the image
LABEL Name=blog_backend Version=0.0.1
