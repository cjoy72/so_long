#!/bin/bash

# If running outside of repo directory (e.g. piped via curl)
if [ ! -f "Makefile" ] || [ ! -d "maps" ]; then
    TMP_DIR=$(mktemp -d)
    echo "📦 Downloading and setting up so_long..."
    trap 'rm -rf "$TMP_DIR"' EXIT
    git clone --depth 1 https://github.com/cjoy72/so_long.git "$TMP_DIR" || exit 1
    cd "$TMP_DIR" || exit 1
    make || exit 1
    echo "🚀 Launching so_long with maps/test.ber..."
    ./so_long maps/test.ber
    echo "🧹 Cleaned up temporary files."
    exit 0
fi

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
    EXIT_CODE=$?
else
    echo "❌ Error: Map file $MAP_FILE not found."
    exit 1
fi

# Auto-cleanup if --clean or -c flag is passed
if [ "$1" == "--clean" ] || [ "$1" == "-c" ]; then
    echo "🧹 Cleaning up built files..."
    make fclean
fi

exit $EXIT_CODE
