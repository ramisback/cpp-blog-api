# Use Ubuntu 23.10 as the base image for our build stage
FROM ubuntu:23.10 AS build

# Update the package lists, install necessary packages and libraries, and create a symbolic link
RUN apt-get -qq update --fix-missing && \
    apt-get -qq install build-essential libboost-all-dev libssl-dev cmake libtcmalloc-minimal4 && \
    ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so

# Define development stage, set working directory, for devcontainers runtime environment
FROM build AS development
COPY . /usr/src/app
WORKDIR /usr/src/app
RUN cmake . && make
EXPOSE 18080

# Create production stage from a minimal base, copy the compiled application, and set default command
FROM scratch AS production
COPY --from=development /usr/src/app/blog_backend /
EXPOSE 18080
CMD ["./blog_backend"]
LABEL Name=blog_backend Version=0.0.1
