FROM alpine:latest

RUN apk update && \
	apk add --no-cache build-base git clang && \
    rm -rf /var/cache/apk/*

WORKDIR /app

RUN git clone https://github.com/ArtAlee/parvpo.git . 

RUN clang++ -std=c++20 -o res main.cpp

CMD ./res > result.txt

