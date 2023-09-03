FROM ubuntu:jammy
ENV LANG=C.UTF-8
RUN : \
    && apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
        dumb-init \
        build-essential \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* \
    && :

WORKDIR /aoc
COPY . .
RUN make test

ENTRYPOINT ["dumb-init", "--"]
CMD ["make", "run-test"]
