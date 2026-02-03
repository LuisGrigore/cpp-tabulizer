#!/bin/bash
# =====================================================
# init.sh - Library initialization script
# =====================================================

# Check that exactly one argument was passed
if [ $# -ne 1 ]; then
    echo "Usage: $0 [-include_src | -build_only | -python]"
    exit 1
fi

ARG=$1

# Paths
ROOT_DIR=$(pwd)
TOOLS_DIR="$ROOT_DIR/tools/initializer"
CPP_MAKEFILE="$TOOLS_DIR/cpp/Makefile"
ROOT_MAKEFILE="$ROOT_DIR/Makefile"

# Function to clean everything except include and src
clean_except_include_src() {
    echo "Cleaning project, keeping only include/* and src/*..."
    find . -mindepth 1 ! -regex './include\(/.*\)?' \
                     ! -regex './src\(/.*\)?' \
                     ! -name "init.sh" \
                     ! -name "Makefile" \
                     -exec rm -rf {} +
}

# Function to clean everything except include and build
clean_except_include_build() {
    echo "Cleaning project, keeping only include/* and build/*..."
    find . -mindepth 1 ! -regex './include\(/.*\)?' \
                     ! -regex './build\(/.*\)?' \
                     -exec rm -rf {} +
    rm -rf ./build/obj
}

case "$ARG" in
    -python)
        echo "Not supported."
        ;;

    -include_src)
        echo "Preparing project to include only src and include..."

        # Replace Makefile
        if [ -f "$CPP_MAKEFILE" ]; then
            echo "Copying C++ Makefile..."
            cp "$CPP_MAKEFILE" "$ROOT_MAKEFILE"
        else
            echo "Error: C++ Makefile not found at $CPP_MAKEFILE"
            exit 1
        fi

        # Clean everything except include/*, src/*, and Makefile
        clean_except_include_src
        echo "Done."
        ;;

    -build_only)
        echo "Preparing project for build_only..."

        # Replace Makefile
        if [ -f "$CPP_MAKEFILE" ]; then
            echo "Copying C++ Makefile..."
            cp "$CPP_MAKEFILE" "$ROOT_MAKEFILE"
        else
            echo "Error: C++ Makefile not found at $CPP_MAKEFILE"
            exit 1
        fi

        # Clean everything except include/* and src/*
        clean_except_include_src

        # Run make
        echo "Running make..."
        if make; then
            echo "Build successful. Cleaning everything except include/* and build/*..."
            clean_except_include_build
            echo "Done."
        else
            echo "Error: build failed."
            exit 1
        fi
        ;;

    *)
        echo "Unrecognized option: $ARG"
        echo "Usage: $0 [-include_src | -build_only | -python]"
        exit 1
        ;;
esac
