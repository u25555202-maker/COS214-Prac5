FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    g++ \
    make \
    gdb \
    valgrind \
    git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /CampusGuard
COPY . .

RUN make

CMD ["make"]
