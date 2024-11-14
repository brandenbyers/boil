#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

# Templates directory (can be overridden by an environment variable)
TEMPLATE_DIR="${BOIL_TEMPLATE_DIR:-"$HOME/.boil/templates"}"

# Function to generate a default project name
generate_project_name() {
  BASE_NAME="project_$(date +%Y%m%d)"
  COUNT=1
  while [ -d "$BASE_NAME$COUNT" ]; do
    COUNT=$((COUNT + 1))
  done
  echo "$BASE_NAME$COUNT"
}

# Function to display usage
usage() {
  echo "Usage: boil <template> [project_name]"
  exit 1
}

# Check arguments
if [ $# -lt 1 ]; then
  usage
fi

TEMPLATE_NAME="$1"
PROJECT_NAME="$2"

# Generate project name if not provided
if [ -z "$PROJECT_NAME" ]; then
  PROJECT_NAME=$(generate_project_name)
fi

# Validate project name (allowing alphanumeric, underscores, and hyphens)
if [[ ! "$PROJECT_NAME" =~ ^[a-zA-Z0-9_-]+$ ]]; then
  echo "Error: Invalid project name. Use only letters, numbers, underscores, and hyphens."
  exit 1
fi

# Check if template exists
if [ ! -d "$TEMPLATE_DIR/$TEMPLATE_NAME" ]; then
  echo "Error: Template '$TEMPLATE_NAME' not found in '$TEMPLATE_DIR'."
  exit 1
fi

# Create project directory
if ! mkdir -p "$PROJECT_NAME"; then
  echo "Error: Failed to create project directory '$PROJECT_NAME'."
  exit 1
fi

# Copy template files
if ! cp -r "$TEMPLATE_DIR/$TEMPLATE_NAME/." "$PROJECT_NAME/"; then
  echo "Error: Failed to copy template files."
  exit 1
fi

# Replace placeholders in files
PLACEHOLDER="{{PROJECT_NAME}}"
find "$PROJECT_NAME" -type f | while read -r file; do
  if grep -q "$PLACEHOLDER" "$file"; then
    # Determine OS for sed compatibility
    if [[ "$OSTYPE" == "darwin"* ]]; then
      sed -i "" "s/$PLACEHOLDER/$PROJECT_NAME/g" "$file"
    else
      sed -i "s/$PLACEHOLDER/$PROJECT_NAME/g" "$file"
    fi
  fi
done

echo "Project '$PROJECT_NAME' created using template '$TEMPLATE_NAME'."