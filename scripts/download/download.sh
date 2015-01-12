#!/bin/bash
openocd -f /usr/share/openocd/scripts/board/stm32f429discovery.cfg \
        -c init \
        -c "reset halt" \
        -c "flash write_image erase ../../Debug/szpp.elf" \
        -c reset run \
        -c shutdown \
        -d 3 2> .download.log

[[ $? -eq 0 ]] || echo "Download failed! See .download.log"

