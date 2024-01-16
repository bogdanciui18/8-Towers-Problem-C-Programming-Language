FROM gcc:latest

WORKDIR /projectfinal

COPY script.c

RUN gcc -o projectfinal script.c

CMD ["./projectfinal"]
