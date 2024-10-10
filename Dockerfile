# first stage: Generate data using Python slim
FROM python:3.9-slim AS data-gen

WORKDIR /app/data_gen

COPY data_gen/ ./

RUN python generate_data.py

# second stage: Process data using C++
FROM ubuntu:focal

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get -qy update && \
    apt-get -qy install \
    make \
    cmake \
    gcc \
    g++ \
    libeigen3-dev

WORKDIR /app

COPY data_proc/CMakeLists.txt data_proc/main.cpp ./data_proc/

RUN cd data_proc && \
    mkdir build && cd build && \
    cmake .. && \
    make

COPY --from=data-gen /app/data_gen/data.csv ./data_gen/

CMD ["./data_proc/build/csv_mean", "./data_gen/data.csv"]
