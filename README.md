# Boil

Boil is a tool for quickly setting up "workout" sessions with different C programming boilerplate templates. It allows you to generate project structures based on predefined templates.

## Installation

### macOS and Linux

```bash
# Clone the repository
git clone https://github.com/yourusername/boil.git
cd boil

# Run the installation script
sudo ./install_boil.sh
```

This script installs the `boil` tool to `/usr/local/bin`.

## Usage

To create a new project using the `sdl3` template:

```bash
boil sdl3 MyProject
```

This generates a new project named `MyProject` based on the `sdl3` template.

## Adding New Templates

To add new templates to your local installation:

1. Create a new directory in the boil template directory, ()`~/.boil/templates/my_new_template` by default) with the name of your template.

2. Add your boilerplate files to the new template directory. Use `{{PROJECT_NAME}}` as a placeholder where you want the project name to be inserted.

Example:

```c
// main.c
#include <stdio.h>

int main() {
  printf("Welcome to {{PROJECT_NAME}}!\n");
  return 0;
}
```

3. The `boil` tool replaces all instances of `{{PROJECT_NAME}}` with the name provided when generating a new project.

## Notes

- Templates are simple directory structures with files that can contain the `{{PROJECT_NAME}}` placeholder.
- The tool is intended for non-production, quick coding "workouts", and, flat template structures.
- Additional templates can be added by the user as needed.
