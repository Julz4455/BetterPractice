#!/bin/bash

./build.sh

cp ./libs/arm64-v8a/libbetter-practice.so ./libbetter-practice.so
cp ./libs/arm64-v8a/libbeatsaber-hook_1_0_12.so ./libbeatsaber-hook_1_0_12.so

zip "better-practice_v0.1.0.zip" "./libbetter-practice.so" "./libbeatsaber-hook_1_0_12.so" "./bmbfmod.json"

rm -rf ./libbetter-practice.so ./libbeatsaber-hook_1_0_12.so
