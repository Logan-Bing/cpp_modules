*This project has been created as part of the 42 curriculum by llugez*

The cpp module 2 introduce us what is float type under the hood and some new concepts in c++ like Otrhodox canonical form class, overload operator, static<cast> and more...

# 1) Float/Fixed

## What is a float

A float is the representation of the decimal number for computer.
This is the classic definition but under the hood it's more complex.
The type float is write on 4 bytes (32 bit), this bits are split in 3 part with for each a different "use".

Representation of float in 32 bit :
```bash
s eeeeeeee mmmmmmmmmmmmmmmmmmmmmmm
```

- s: Define the sign 0 = positiv | 1 = negativ.
- e: Define the exponent.
- m: Define the mantisse (value after the ".").

# 2) Ressources
