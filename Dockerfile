FROM gcc:latest

WORKDIR /towersproblem

COPY script.c

RUN gcc -o towersproblem script.c

CMD ["./towersproblem"]
