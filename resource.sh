#!/bin/bash

python ./generate-resources.py

mkdir -p ./build/resources/
mv ./resources/*.zip ./build/resources/
