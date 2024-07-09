# Calculator Project

## Overview

This project is an implementation of an ArrayList in C. It is an array which automatically resizes when it fills and allows for some stack-like functions and queue-like functions for convenience. It also allows for storing a variety of different datatype, rather than being limited to one pre-defined data type. I'm planning to update implementation to use a ring buffer system for memory efficiency in the future.

## Features

- createArrayList
    - Creates a new ArrayList
- arraylist_get
    - Retrieves the value at a given index position
- arraylist_peek
    - Retrieve the last index position
- arraylist_push
    - Appends a value to the last index position
- arraylist_pop(ArrayList *arr);
    - Deletes the last index position and returns it's value
- arraylist_shift
    - Deletes the first index position and returns it's value
- arraylist_unshift
    - Inserts a value at the first index position
- arraylist_insertAt(ArrayList *arr, int idx, ALValue data);
    - Inserts a value at the given index position
- arraylist_deleteAt
    - Deletes the value at a given index position

## Requirements

- A C compiler (e.g., clang, GCC)
- Make (optional, for using the provided Makefile)

## Getting Started

1. **Clone the repository:**

   ```sh
   git clone https://github.com/eireworm/C-ArrayList.git
   cd "C ArrayList"
   ```

2. **Compile the code:**

   Using `make` (if Makefile is provided):

   ```sh
   make
   ```

## Usage

Import the header file into your project. You can then create and use it's functions described above. Data is encapsulated in the given ALValue union.
   ```c
   #include "arraylist.h"

   int main() {
       ArrayList al = createArrayList(1);

       ALValue v1;
       v1.datatype = INT_TYPE;
       v1.i = 11;

       arraylist_push(&al, v1);
       arraylist_push(&al, v1);
       arraylist_peek(&al);
       arraylist_pop(&al);
       arraylist_unshift(&al, v1);
       arraylist_shift(&al);
       arraylist_insertAt(&al, 1, v1);
       arraylist_deleteAt(&al, 1);

       return 0;
   }
   ```


## Project Root Structure

- **README.md**: Provide an overview of the project, build instructions, and usage.
- **LICENSE**: Specify the project's license.
- **Makefile**: Include instructions to build the project.
- **src/**: Source files (e.g., `.c` files).
- **include/**: Header files (e.g., `.h` files).
- **lib/**: External libraries or static libraries.
- **bin/**: Compiled binaries (can be generated during the build process).
- **obj/**: Object files (can be generated during the build process).
- **test/**: Unit tests and test-related code.
- **docs/**: Documentation files.
- **config/**: Configuration files and scripts.

```
project/
├── README.md
├── LICENSE
├── Makefile
├── src/
│   ├── main.c
│   ├── arraylist.c
├── include/
│   └── arraylist.h
├── lib/
├── bin/
│   └── main
├── obj/
│   └── arraylist.o
├── test/
│   ├── test_arraylist.c
└── docs/
    ├── api_reference.md
    └── design_doc.md
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Theory based on explanation by the Primeagen on his course _The Last Algorithms Course You'll Need_.

