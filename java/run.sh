#!/bin/bash

java -cp out/ -Djava.library.path=../build/ lib.test.Test $1 $2
