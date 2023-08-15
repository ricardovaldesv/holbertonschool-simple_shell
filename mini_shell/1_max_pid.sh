#!/bin/bash

/** Get the maximum PID value */
max_pid=$(cat /proc/sys/kernel/pid_max)

/** Print the maximum PID value */
echo "The maximum process ID can be: $max_pid"
