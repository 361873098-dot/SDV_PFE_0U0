#!/bin/sh
#set -x

dmesg -c > /dev/null
echo 8 > /proc/sys/kernel/printk
#insmod ./s32gep.ko dyndbg
insmod ./s32gep.ko

sleep 0.1
echo '/proc/iomem:'
cat /proc/iomem | grep s32gep

echo '/proc/interrupts:'
cat /proc/interrupts | grep -e CPU0 -e s32gep
