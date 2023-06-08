#!/bin/bash

cmake -S . -B ./build -DPYBIND11_PYTHON_VERSION=3.10

cd ./build && make 
