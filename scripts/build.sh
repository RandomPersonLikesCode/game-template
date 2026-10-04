#!/data/data/com.termux/files/usr/bin/env sh

set -xe

# Script to assemble and copy

./gradlew assembleDebug && cp app/build/outputs/apk/debug/app-debug.apk ~/storage/downloads
