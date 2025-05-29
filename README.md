# Sequence Generator (C++)

A flexible and interactive **sequence generator** written in C++.  
Generates values from a defined numerical range with customizable **step size** and **value transformation functions**.

## Features

- User-defined start value, step size, and upper limit
- Built-in transformation functions:
  - `normal`: returns the number as-is
  - `square`: returns the square (n²)
  - `cube`: returns the cube (n³)
  - `sign`: returns the sign of the number: -1, 0, or 1
  - `neu`: placeholder for your custom transformation logic
- Uses a function pointer to apply the selected transformation
- Clean, simple loop structure using a struct

## Author
Created by **Kilian**
