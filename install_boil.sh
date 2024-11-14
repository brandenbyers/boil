#!/bin/bash

# Default templates directory
DEFAULT_TEMPLATE_DIR="$HOME/.boil/templates"
# Default installation directory
DEFAULT_INSTALL_DIR="/usr/local/bin"
# Flag for default installation
USE_DEFAULTS=false

# Function to display usage
usage() {
  echo "Usage: $0 [--defaults|-d]"
  echo "  --defaults, -d    Install with default settings without prompts"
  exit 1
}

# Parse arguments
while [[ "$#" -gt 0 ]]; do
  case $1 in
    --defaults|-d) USE_DEFAULTS=true ;;
    --help|-h) usage ;;
    *) echo "Unknown parameter: $1"; usage ;;
  esac
  shift
done

# Prompt for templates directory if not using defaults
if [ "$USE_DEFAULTS" = false ]; then
  read -p "Enter templates directory [$DEFAULT_TEMPLATE_DIR]: " TEMPLATE_DIR
  TEMPLATE_DIR=${TEMPLATE_DIR:-$DEFAULT_TEMPLATE_DIR}
else
  TEMPLATE_DIR=$DEFAULT_TEMPLATE_DIR
fi

# Create templates directory with error handling
if ! mkdir -p "$TEMPLATE_DIR"; then
  echo "Error: Failed to create templates directory '$TEMPLATE_DIR'."
  exit 1
fi

# Copy initial templates with error handling
if ! cp -r templates/* "$TEMPLATE_DIR/"; then
  echo "Error: Failed to copy templates to '$TEMPLATE_DIR'."
  exit 1
fi

# Prompt for installation directory if not using defaults
if [ "$USE_DEFAULTS" = false ]; then
  read -p "Enter installation directory for 'boil' command [$DEFAULT_INSTALL_DIR]: " INSTALL_DIR
  INSTALL_DIR=${INSTALL_DIR:-$DEFAULT_INSTALL_DIR}
else
  INSTALL_DIR=$DEFAULT_INSTALL_DIR
fi

# Check if installation directory is writable
if [ ! -w "$INSTALL_DIR" ]; then
  echo "Installation directory '$INSTALL_DIR' requires sudo permissions."
  SUDO='sudo'
else
  SUDO=''
fi

# Ensure the install directory is in the PATH
if [[ ":$PATH:" != *":$INSTALL_DIR:"* ]]; then
  echo "Warning: '$INSTALL_DIR' is not in your PATH."
fi

# Copy boil script with sudo if necessary
if ! $SUDO cp boil.sh "$INSTALL_DIR/boil"; then
  echo "Error: Failed to copy 'boil' to '$INSTALL_DIR'."
  exit 1
fi

# Change permissions with sudo if necessary
if ! $SUDO chmod +x "$INSTALL_DIR/boil"; then
  echo "Error: Failed to make 'boil' executable."
  exit 1
fi

echo "Installation complete."