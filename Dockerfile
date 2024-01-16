FROM gcc:latest

WORKDIR /towersproblem

COPY scrirpt.c

RUN gcc -o towersproblem script.c

CMD ["./script"]
