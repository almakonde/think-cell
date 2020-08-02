FROM gcc:7.2.0

USER root

# apt-get only goes up to CMake 3.7 !!!
# RUN apt-get update && apt-get -y install ninja-build && apt-get -y install cmake

# apt-get can run the snap deamon !!!!!
# RUN apt-get update && apt-get -y install ninja-build && apt install snapd && snap install cmake --classic

# need to pull the pre-built binaries
RUN apt-get update && apt-get -y install ninja-build && wget -c https://github.com/Kitware/CMake/releases/download/v3.18.1/cmake-3.18.1-Linux-x86_64.tar.gz -O - | tar -xz
ENV PATH="/cmake-3.18.1-Linux-x86_64/bin:${PATH}"
