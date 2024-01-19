FROM --platform=linux/amd64 alpine:latest

WORKDIR /projectfinal

COPY script.c .

RUN apk add --no-cache build-base

RUN gcc -o script script.c

CMD ["./script"]
