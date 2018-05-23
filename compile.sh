#!/bin/bash
rm ./whitefox_gem.bin
docker run -e keymap=gem -e keyboard=whitefox --rm -v $('pwd'):/qmk:rw qmk-base
