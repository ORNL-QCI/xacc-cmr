# XACC D-Wave SAPI Embedding Algorithm

This repository provides an XACC Embedding Algorithm implementation that wraps the D-Wave C SAPI findEmbedding routine. 

# Build

In order to build this project, you must have access to the D-Wave SAPI C Pack. Install dwave_sapi.h to /usr/local/include and libdwave_sapi.so 
to /usr/local/lib. 

Install XACC by following the instructions at [XACC Build Instructions](https://ornl-qci.github.io/xacc/build/)

Once you've installed these prerequisites, run the following

```bash
$ git clone https://github.com/ORNL-QCI/xacc-dwsapi-embedding
$ cd xacc-dwsapi-embedding && mkdir build && cd build
$ cmake ..
$ make install
```

This will place libxacc-dwsapi-embedding.so in your $XACC_INSTALL_DIR/lib, ready to be used in applications that 
build off XACC to program and execute on the D-Wave QPU.
