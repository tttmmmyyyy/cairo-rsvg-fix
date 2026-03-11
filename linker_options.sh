#!/bin/sh

# Check for existance of pkg-config
if ! command -v pkg-config >/dev/null 2>&1; then
  echo "Error: pkg-config is not installed." >&2
  exit 1
fi

# Get linker options
libs=`pkg-config --libs librsvg-2.0`

# Check error
if [ $? -ne 0 ]; then
  echo "Error: pkg-config failed." >&2
  exit 1
fi

fix_ld_flags="$libs"
echo "fix.ld_flags=$fix_ld_flags"
