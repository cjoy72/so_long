#!/bin/bash

# Build the binary if it doesn't exist
if [ ! -f "./so_long" ]; then
    echo "🎮 Binary not found. Building so_long..."
    make
fi

# Launch the game with test map
MAP_FILE="maps/test.ber"

if [ -f "$MAP_FILE" ]; then
    echo "🚀 Launching so_long with $MAP_FILE..."
    ./so_long "$MAP_FILE"
else
    echo "❌ Error: Map file $MAP_FILE not found."
    exit 1
fi
